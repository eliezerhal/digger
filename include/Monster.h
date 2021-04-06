#pragma once
#include "MobileItem.h"
#include "Rect.h"

class Monster : public MobileItem
{
public:
	Monster(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~Monster() = 0;
	virtual void move(sf::Time deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual char getItem() const override;
	bool checkingCollision(sf::Vector2f loc);
	virtual void changeDirection() = 0;
	void playTheMonsterSound();

protected:
	
	sf::Sprite m_sprite;
	sf::Sprite m_sprite2;
	int m_option = 0;
	bool m_direction[4]{false, false, true, false};
};
