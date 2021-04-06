#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Resourses.h"
#include "StupiedMonster.h"
#include "SmartMonster.h"
#include "Stone.h"
#include "Digger.h"
#include "Wall.h"
#include "Diamond.h"
#include "Menu.h"
#include "Board.h"
#include "Rect.h"
#include "StationaryItem.h"
#include <ctime>
#include <memory>
#include "Gift.h"
#include "Information.h"
#include <SFML/Audio.hpp>

class Controller
{
public:
	~Controller();
	static Controller& getInstance();

	//This function loads the game board:
	void loading();	//This function loads the game
	void initTheData(int hight, int width, int stones, int firstTime);
	void initTheBoard();	//This function loads the game board

	//This function loads the game board:
	void run();
	char checkingColision(MobileItem* it);
	void deleteItem();
	void decStones();
	void decDiamonds();
	void getGift();
	void restartGame();
	void continueStage();
	void restartStage();
	void nextStage();
	void wining();	//This function loads the game board
	sf::Vector2f getDigPos();

	//Print functions:
	void printTheInformation();
	void printTheMenu();

	//Geters and Seters:
	int getLevel();
	int getLive() const;
	int getPoints() const;
	int getStones() const;
	int getFirstTime() const;
	int getTime();
	sf::Clock getTimmer();
	void resetLevel();
	void setLevel();
	void setTime(int spare);
	void setLive();
	void setPoints(int points);
	void setStones(int stones);

private:
	//Data members:
	int m_temp;
	int m_firstTime;
	int m_level = 1;
	int m_live = LIVE;
	int m_points = 0;
	int m_stones;
	int m_curStones;
	int m_diamonds = 0;
	int m_time;
	float m_hight;
	float m_width;
	bool m_restart = true;
	bool GamOver = false;
	bool Won = false;
	Resourses m_res;
	Board m_board;
	sf::Music& m_music;
	sf::Sprite m_grassSprite;
	sf::Clock clock;
	sf::Clock m_timmer;
	sf::Time deltaTime;
	std::vector<std::unique_ptr<MobileItem>> m_mobile;
	std::vector<std::unique_ptr<StationaryItem>> m_static;
	sf::RenderWindow m_window;
	sf::RectangleShape m_rectWindows;
	sf::Vector2f m_size;
	sf::Vector2f m_scale;

	//Function member:
	Controller();
	void draw();
	void setMobileItem(int i, int j, char item);
	void setStaticItem(int i, int j, char item);
};

