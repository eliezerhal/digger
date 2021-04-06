#include "Menu.h"
#include "Macro.h"
#include "Controller.h"
#include <chrono>
#include<thread>

using namespace std::chrono_literals;

Menu::Menu()
{ 
	std::string str[2] = { "new game","exit" };
	for (int i = 0; i < 2; i++)
	{
		m_text.push_back( sf::Text(str[i], m_res.getFontTexture()));
		m_text[i].setPosition(0, Hight / 2 + (i * 100));
		m_text[i].setScale(1,2);
		m_text[i].setStyle(sf::Text::Bold);
	}
	m_spritewin.setTexture(m_res.getWinTexture());
	m_spritegameOver.setTexture(m_res.getGameOverTexture());
	m_sprite.setTexture(m_res.getMenuTexture());
	m_sprite.setScale(1, 1);
	m_sprite.setPosition(0, 0);
}

Menu::~Menu() {}

Menu& Menu::getInstance()
{
	static Menu instance;
	return instance;
}

void Menu::draw(sf::RenderWindow& window,bool GamOver,bool winning)
{ 
	if (winning)
		PrintWin(window);
	if(GamOver)
		PrintGameOver(window);
	window.draw(m_sprite);
	for(int i = 0; i< m_text.size(); i++)	
	window.draw(m_text[i]);
	window.display();
	checkTheChoice(window);
	return;
}

void Menu::PrintGameOver(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_spritegameOver);
	window.display();
	std::this_thread::sleep_for(5s);
	return;
}

void Menu::PrintWin(sf::RenderWindow& window)
{
	auto& control = Controller::getInstance();
	auto win = sf::Text("you won!!!!\n your score is:"+ std::to_string(control.getPoints()), m_res.getFontTexture());
	win.setPosition(Width/4,Hight/2);
	win.setColor(sf::Color::Magenta);
	win.setCharacterSize(100);
    window.clear();
	window.draw(m_spritewin);
	window.draw(win);
	window.display();
	std::this_thread::sleep_for(10s);

}

bool Menu::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	auto& control = Controller::getInstance();
	for (int i = 0; i < m_text.size(); i++)
	{
	if (m_text[i].getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
		switch (i)
		{
		case 0:
			control.resetLevel();
			return true;

		case 1:
			exit(0);

		}
	}
	return false;
}

void Menu::checkTheChoice(sf::RenderWindow& window)
{
	while(window.isOpen())
	{
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				exit(0);
			case sf::Event::MouseButtonReleased:
				if(handleClick(event.mouseButton, window))
				return;
			}
			if (event.key.code == sf::Keyboard::Escape)
				return;
		}
	}
}

