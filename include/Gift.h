#pragma once
#include "StationaryItem.h"

class Gift : public StationaryItem
{
public:
	Gift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~Gift() override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual char getItem() const override;
	virtual bool isDead() override;
	virtual void getGift() = 0;

private:
	sf::Sprite m_sprite;
	Rect m_rect;
};