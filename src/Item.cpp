#include "Item.h"

Item::Item()
	:m_position(sf::Vector2f(0, 0)){}

Item::Item(const sf::Vector2f& location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	: m_position(location), m_size(size), m_scale(scale), m_color(color)
{
	/*m_scale.x /= m_sprite.getScale().x;
	m_scale.y /= m_sprite.getScale().y;
	*/m_rec.setPosition(m_position);
	m_rec.setSize(m_size);
}

Item::~Item() {}

void Item::draw(sf::RenderWindow& window) {}

char Item::getItem() const
{
	char item = 0;
	return item;
}

void Item::setPosition(const sf::Vector2f& location)
{
	m_position = location;
}

sf::Vector2f Item::getPosition() const
{
	return m_position;
}

bool Item::isDead()
{
	return m_dead;
}

void Item::setDead()
{
	m_dead = true;
}

sf::RectangleShape Item::getRec() const
{
	return m_rec;
}
