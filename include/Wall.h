#pragma once
#include "StationaryItem.h"
#include "Rect.h"

class Wall : public StationaryItem
{
public:
	Wall(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~Wall();
	virtual void draw(sf::RenderWindow& window);
	virtual char getItem() const;

private:
	sf::Sprite m_sprite;
};
