#include "Rect.h"

Rect::Rect() {}

Rect::Rect(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	: Item(location, size, scale, color)
{
	initRect();
}

Rect::~Rect(){}

void Rect::draw(sf::RenderWindow& window)
{
	window.draw(m_rec);
}

char Rect::getItem() const
{
	return space;
}

void Rect::initRect()
{
	m_rec = sf::RectangleShape(m_size);
	m_rec.setPosition(m_position);
	m_rec.setFillColor(m_color);
}



 
