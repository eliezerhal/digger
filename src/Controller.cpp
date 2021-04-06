#include "Controller.h"
#include "Macro.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <experimental/vector>
#include "FirstGift.h"
#include "SecondGift.h"
#include "ThirdGift.h"
#include "FourthGift.h"
#include "FifthGift.h"
#include <time.h> 
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

Controller::Controller()
	: m_window(sf::VideoMode((unsigned int)Width, (unsigned int)Hight), "Digger Game"), m_hight(0.f), m_width(0.f),m_stones(0),m_firstTime(0), m_grassSprite(m_res.getGrassTexture()),m_music(m_res.getMusicBackround()){}

Controller& Controller::getInstance()
{
	static Controller instance;
	return  instance;
}

Controller::~Controller(){}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Controller::loading()
{
	if (m_level == 1 || !m_live)
	{
		printTheMenu();
		Won = false;
		GamOver = false;
		m_points = 0;
	}
	m_timmer.restart();
	m_board.loadingTheBoard();
	m_curStones = m_stones;
	run();
}

void Controller::initTheData(int hight, int width, int stones, int firstTime)
{
	m_hight = hight;
	m_width = width;
	m_curStones = m_stones = stones;
	m_time = m_firstTime = firstTime;
	float widthSize = Width / m_width;
	float hightSize = (Hight - menu) / m_hight;
	m_scale = sf::Vector2f(widthSize, hightSize);
	m_size = sf::Vector2f(widthSize, hightSize);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Controller::initTheBoard()
{

	for (int i = 0; i < m_hight; i++)
		for (int j = 0; j < m_width; j++)
		{
			setMobileItem(i, j, m_board.getItem(i, j));
			setStaticItem(i, j, m_board.getItem(i, j));
		}
	m_grassSprite.setPosition(0, 0);
}

void Controller::run()
{
	m_music.setVolume(50);
	m_music.setLoop(true);
	m_music.play();
	while (m_window.isOpen())
	{
		m_window.clear();
		draw();
		m_window.display();

		deltaTime = clock.restart();
		for (auto& mobile : m_mobile)
		{
			if (auto event = sf::Event{}; m_window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					m_window.close();
					exit(0);
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space)
					{
						m_temp = (m_time-m_timmer.getElapsedTime().asSeconds());
						m_music.pause();
						printTheMenu();
						m_music.play();
						m_timmer.restart();
						m_time = m_temp;
					}
					if (Digger* dig = dynamic_cast<Digger*>(mobile.get()))
						dig->getEvent(event.key);
					break;
				}
			}
			
			mobile->move(deltaTime);
			if (m_firstTime != -1 && m_firstTime - m_timmer.getElapsedTime().asSeconds() < 0)
				continueStage();
		}
	}
}

char Controller::checkingColision(MobileItem* it)
{
	for (auto& stati : m_static)
		if (it->getRec().getGlobalBounds().intersects(stati->getRec().getGlobalBounds()))
		{
			if (Digger* dig = dynamic_cast<Digger*>(it))
			{
				Wall* wll = dynamic_cast<Wall*>(stati.get());
				if(!wll)
					stati->setDead();
			}
			return stati->getItem();
		}
	for (auto& mobile : m_mobile)
		if (it->getRec().getGlobalBounds().intersects(mobile->getRec().getGlobalBounds()))
			return mobile->getItem();
	
	return space;
}

void Controller::deleteItem()
{
	std::experimental::erase_if(m_static, [](auto& it) {
		return it->isDead(); });
	std::experimental::erase_if(m_mobile, [](auto& it) {
		return it->isDead(); });
}

void Controller::decStones()
{
	m_curStones--;
	if (m_curStones < 0)
		continueStage();
}

void Controller::decDiamonds()
{
	m_diamonds--;
	m_points += 15;
	if (m_diamonds == 0)
	{
		m_window.clear();
		draw();
		m_window.display();
		std::this_thread::sleep_for(2s);
		m_music.stop();
		sf::SoundBuffer winSoundBuffer;
		if (!winSoundBuffer.loadFromFile("winning.wav"))
			EXIT_FAILURE;
		sf::Sound monsterSound(winSoundBuffer);
		monsterSound.setVolume(100);
		monsterSound.play();
		m_points += 20;
		setLevel();
		nextStage();
	}
}

void Controller::getGift()
{
	for (auto& stati : m_static)
		if (stati->isDead())
			if (Gift* gift = dynamic_cast<Gift*>(stati.get()))
				gift->getGift();
}

void Controller::restartGame()
{
	m_static.clear();
	m_mobile.clear();
    restartStage();
}

void Controller::continueStage()
{
	m_window.clear();
	draw();
	m_window.display();
	std::this_thread::sleep_for(2s);
	m_mobile.clear();
	m_restart = false;
	m_curStones = m_stones;
	restartStage();
}

void Controller::restartStage()
{
	m_music.stop();
	sf::SoundBuffer winSoundBuffer;
	if (!winSoundBuffer.loadFromFile("lose.wav"))
		EXIT_FAILURE;
	sf::Sound loseSound(winSoundBuffer);
	loseSound.setVolume(100);
	m_timmer.restart();
	m_time = m_firstTime;
	m_live--;
	if (!m_live)
	{		
		loseSound.play();
		std::cout << "You  failed : Game Over";
		m_live = LIVE;
		m_diamonds = 0;
		GamOver = true;
		nextStage();
	}
	initTheBoard();
	run();
}

void Controller::nextStage()
{
	m_restart = true;
	m_mobile.clear();
	m_static.clear();
	loading();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Controller::draw()
{
	m_window.draw(m_grassSprite);
	for (int i = 0; i < m_static.size(); i++)
		m_static[i]->draw(m_window);
	for (int i = 0; i < m_mobile.size(); i++)
		m_mobile[i]->draw(m_window);
	printTheInformation();
}

void Controller::printTheMenu()
{
	auto& control = Menu::getInstance();
	control.draw(m_window, GamOver,Won);
}


int Controller::getLevel()
{
	return m_level;
}

int Controller::getLive() const
{
	return m_live;
}

int Controller::getPoints() const
{
	return m_points;
}

int Controller::getStones() const
{
	return m_curStones;
}

int Controller::getFirstTime() const
{
	return m_firstTime;
}

int Controller::getTime()
{
	return m_time;
}

sf::Clock Controller::getTimmer()
{
	return m_timmer;
}

void Controller::resetLevel()
{
	m_level = 1;
}

void Controller::setLevel()
{
	m_level++;
}

void Controller::setTime(int spare)
{
	m_firstTime += spare;
}

void Controller::setLive()
{
	m_live++;
}

void Controller::setPoints(int points)
{
	m_points += points;
}

void Controller::setStones(int stones)
{
	m_curStones += stones;
}

void Controller::printTheInformation()
{
	auto& control = Information::getInstance();
	control.updateInformation();
	control.draw(m_window);
}

void Controller::setMobileItem(int i, int j, char item)
{
	switch (item)
	{
	case monster:
		if ((i + j) % 3 == 0)
		{
			m_mobile.push_back(std::make_unique<SmartMonster>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
			break;
		}
		else
		{
			m_mobile.push_back(std::make_unique<StupiedMonster>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
			break;
		}
	case digger:
		m_mobile.push_back(std::make_unique<Digger>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	}
}

void Controller::setStaticItem(int i, int j, char item)
{
	if (!m_restart)
		return;

	switch (item)
	{
	case stone:
		m_static.push_back(std::make_unique<Stone>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	case wall:
		m_static.push_back(std::make_unique<Wall>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	case diamond:
		m_static.push_back(std::make_unique<Diamond>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		m_diamonds++;
		break;
	case gift:
	{srand(time(NULL));
	int gift = rand() % 4;
	switch (gift)
	{
	case 0:
		m_static.push_back(std::make_unique<FirstGift>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	case 1:
		m_static.push_back(std::make_unique<SecondGift>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	case 2:
		m_static.push_back(std::make_unique<ThirdGift>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	case 3:
		m_static.push_back(std::make_unique<FourthGift>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	case 4:
		m_static.push_back(std::make_unique<FifthGift>(sf::Vector2f(j * m_size.x, i * m_size.y), m_size, m_scale, sf::Color::Transparent));
		break;
	}
	}
	case space:
		break;
	}
}

void Controller::wining()
{
	std::cout << "You Won" << std::endl;
	std::cout << "Your Points = " << m_points << std::endl;
	Won = true;
	resetLevel();
	loading();
}

sf::Vector2f Controller::getDigPos()
{
	for (auto& mobile : m_mobile)
		if (Digger* dig = dynamic_cast<Digger*>(mobile.get()))
			return dig->getPosition();
	return sf::Vector2f (0, 0);
}
