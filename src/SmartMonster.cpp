#include "SmartMonster.h"
#include <time.h> 
#include <stdlib.h>
#include <random>
#include "Digger.h"
#include "Controller.h"
#include "Macro.h"
#include <math.h>

SmartMonster::SmartMonster(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Monster(location, size, scale, color) {}

SmartMonster::~SmartMonster(){}

void SmartMonster::move(sf::Time deltaTime)
{
	m_option = getOption();

	switch (m_option)
	{
	case up:
		dir = sf::Vector2f(0, -monSpeed);
		break;
	case down:
		dir = sf::Vector2f(0, monSpeed);
		break;
	case left:
		dir = sf::Vector2f(-monSpeed, 0);
		break;
	case right:
		dir = sf::Vector2f(monSpeed, 0);
		break;
	}
	for (int i = 0; i < 4 ; i++)
		if (i != m_option)
			m_direction[i] = false;
	m_direction[m_option] = true;
	if (!checkingCollision(m_newLoc))
		changeDirection();
	Monster::move(deltaTime);
}

int SmartMonster::getOption()
{
	auto& control = Controller::getInstance();
	sf::Vector2f loc = control.getDigPos();
	if (m_position.x == loc.x || FindDistance(m_position.x, loc.x) <= FindDistance(m_position.y, loc.y))
	{
		if (m_position.y > loc.y)
			return up;
		else
			return down;
	}
	else//if (m_position.y == loc.y)
	{
		if (m_position.x > loc.x)
			return left;
		else
			return right;
	}
}

float SmartMonster::FindDistance(float a, float b)
{
	return abs(a - b);
}

void SmartMonster::changeDirection()
{
	switch (m_option)
	{
	case up:
		m_direction[up] = false;
		m_direction[left] = true;
		m_option = left;
		break;
	case down:
		m_direction[down] = false;
		m_direction[right] = true;
		m_option = right;
		break;
	case left:
		m_direction[left] = false;
		m_direction[down] = true;
		m_option = down;
		break;
	case right:
		m_direction[right] = false;
		m_direction[up] = true;
		m_option = up;
		break;
	}
}
