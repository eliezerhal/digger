#pragma once
#include "Item.h"

class Rect : public Item
{
public:
	Rect();
	Rect(sf::Vector2f, sf::Vector2f, sf::Vector2f, sf::Color color);
	virtual ~Rect();
	virtual void draw(sf::RenderWindow& window);
	virtual char getItem() const;
	void initRect();

protected:
	sf::RectangleShape m_rec;
};