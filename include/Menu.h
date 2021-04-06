#pragma once
#include "Resourses.h"
#include "Board.h"
#include <SFML/Graphics.hpp>

class Menu 
{
public :
	virtual ~Menu();
	static Menu& getInstance();
	virtual void draw(sf::RenderWindow& window, bool GamOver, bool winning) ;
	void PrintGameOver(sf::RenderWindow& window);
	void PrintWin(sf::RenderWindow& window);
private:
	Menu();
	bool handleClick(const sf::Event::MouseButtonEvent& event,sf::RenderWindow& window);
	void checkTheChoice(sf::RenderWindow& window);
	std::vector<sf::Text> m_text;
	sf::Text m_win;
	sf::Sprite m_sprite;
	sf::Sprite m_spritegameOver;
	sf::Sprite m_spritewin;
	Resourses m_res;
	Board m_board;
};

