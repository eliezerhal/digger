#include "StupiedMonster.h"
#include <time.h> 
#include <stdlib.h>
#include <random>
StupiedMonster::StupiedMonster(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Monster(location, size, scale, color) {}

StupiedMonster::~StupiedMonster() {}

void StupiedMonster::move(sf::Time deltaTime)
{
	if (!checkingCollision(m_newLoc))
		option = rand(0, 4);
	
	for(int i = 0; i < 4 ; i++)
		if (i != m_option)
			m_direction[i] = false;
	m_direction[option] = true;
	Monster::move(deltaTime);
}

size_t StupiedMonster::rand(size_t min, size_t max)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution <std::mt19937::result_type> dist(min, max);
	return dist(rng);
}

void StupiedMonster::changeDirection()
{
	
	switch (m_option)
	{
	case up:
		m_direction[up] = false;
		m_direction[down] = true;
		break;
	case down:
		m_direction[down] = false;
		m_direction[up] = true;
		break;
	case left:
		m_direction[left] = false;
		m_direction[right] = true;
		break;
	case right:
		m_direction[right] = false;
		m_direction[left] = true;
		break;
	}
	return;
}