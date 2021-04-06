#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Macro.h"
#include "Board.h"
#include "Resourses.h"

class Item
{
public:
	Item();
	Item(const sf::Vector2f& location, sf::Vector2f size, sf::Vector2f scale, sf::Color);
	virtual ~Item() = 0;
	virtual void draw(sf::RenderWindow& window);
	virtual char getItem() const;
	void setPosition(const sf::Vector2f& location);
	sf::Vector2f getPosition() const;
	virtual bool isDead();
	void setDead();
	sf::RectangleShape getRec() const;

protected:
	bool m_dead = false;
	sf::RectangleShape m_rec;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	sf::Vector2f m_scale;
	sf::Color m_color;
	sf::RenderWindow  m_window;
	Resourses m_res;
};
