#pragma once
#include "StationaryItem.h"
#include "Rect.h"
class Diamond : public StationaryItem
{
public:
	Diamond (sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~Diamond() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual char getItem() const override;
	virtual bool isDead() override;

private:
	sf::Sprite m_sprite;
	Rect m_rect;
};
