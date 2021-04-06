#pragma once
#include "Item.h"
#include "StationaryItem.h"
#include <ctime>

class MobileItem : public Item
{
public:
	MobileItem();
	MobileItem(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~MobileItem() = 0;
	virtual void move(sf::Time deltaTime) = 0;
	virtual bool checkingCollision(sf::Vector2f loc);
	char getCollision(sf::Sprite sprite);
	sf::Vector2f m_newLoc;
	bool rotate[4] = { false };

protected:
	sf::Vector2f dir;
	bool m_stright = true;
};