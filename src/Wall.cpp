#include "Wall.h"

Wall::Wall(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:StationaryItem(location, size, scale, color) , m_sprite(m_res.getWallTexture())
{
	m_scale.x /= m_res.getSizeWall().x;
	m_scale.y /= m_res.getSizeWall().y;
}

Wall::~Wall() {}

void Wall::draw(sf::RenderWindow& window)
{
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_scale);
	window.draw(m_sprite);
}

char Wall::getItem() const
{
	return wall;
}