#include "Stone.h"

Stone::Stone(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:StationaryItem(location, size, scale, color), m_rect(location, size, scale, color), m_sprite(m_res.getStoneTexture())
{
	m_scale.x /= m_res.getSizeStone().x;
	m_scale.y /= m_res.getSizeStone().y;
}

Stone::~Stone() {}

void Stone::draw(sf::RenderWindow& window)
{
	m_rect.draw(window);	
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_scale);
	window.draw(m_sprite);
}

char Stone::getItem() const
{
	return stone;
}

bool Stone::isDead()
{
	return m_dead;
}
