#pragma once
#include "Item.h"
#include "Rect.h"

class StationaryItem : public Item
{
public:
	StationaryItem();
	StationaryItem(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~StationaryItem() = 0;
	//Rect m_rect;

private:
};
