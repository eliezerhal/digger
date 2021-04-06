#include <SFML/Graphics.hpp>
#include "MobileItem.h"
#include "Controller.h"
#include <iostream>

MobileItem::MobileItem(){}

MobileItem::MobileItem(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Item(location, size, scale, color) {}

MobileItem::~MobileItem(){}

char MobileItem::getCollision(sf::Sprite sprite)
{
	Controller& control = Controller::getInstance();
	m_rec.setPosition(m_newLoc);
	return control.checkingColision(this);	
}

bool MobileItem::checkingCollision(sf::Vector2f loc)
{
	if (loc.x < 0 || loc.x > Width - m_size.x)
	{
		if (loc.x < 0)
			rotate[0] = true;
			return false;
	}
	if (loc.y < menu || loc.y > Hight - m_size.y)
		return false;
	return true;
}
