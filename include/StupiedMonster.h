#pragma once
#include "Monster.h"

class StupiedMonster : public Monster
{
public:
	StupiedMonster(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~StupiedMonster() override;
	virtual void move(sf::Time deltaTime) override;
	size_t rand(size_t min, size_t max);
	void changeDirection();

private:
	int option = 0;
};
