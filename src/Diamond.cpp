#include "Diamond.h"

Diamond::Diamond(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:StationaryItem(location, size, scale, color) , m_rect(location, size, scale, color), m_sprite(m_res.getDiamondTexture())
{
	m_scale.x /= m_res.getSizeDiamond().x;
	m_scale.y /= m_res.getSizeDiamond().y;
}

Diamond::~Diamond() {}

void Diamond::draw(sf::RenderWindow& window)
{
	m_rect.draw(window);
	//m_sprite = sf::Sprite(m_res.getDiamondTexture());
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_scale);
	window.draw(m_sprite);
}

char Diamond::getItem() const
{
	return diamond;
}

bool Diamond::isDead()
{
	return m_dead;
}
