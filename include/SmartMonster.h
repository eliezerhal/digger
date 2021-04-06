#pragma once
#include "Monster.h"

class SmartMonster : public Monster
{
public:
	SmartMonster(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~SmartMonster() override;
	virtual void move(sf::Time deltaTime) override;
	int getOption();
	float FindDistance(float a, float b);
	virtual void changeDirection();

private:
};

