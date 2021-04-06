#include "Gift.h"

Gift::Gift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:StationaryItem(location, size, scale, color), m_rect(location, size, scale, color), m_sprite(m_res.getGiftTexture())
{
	m_scale.x /= m_res.getSizeDiamond().x;
	m_scale.y /= m_res.getSizeDiamond().y;
}

Gift::~Gift() {}

void Gift::draw(sf::RenderWindow& window)
{
	m_rect.draw(window);	
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_scale);
	window.draw(m_sprite);
}

char Gift::getItem() const
{
	return gift;
}

bool Gift::isDead()
{
	return m_dead;
}
