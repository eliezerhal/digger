#include "Monster.h"
#include "Controller.h"
#include <SFML/Audio.hpp>

Monster::Monster(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:MobileItem(location, size, scale, color), m_sprite(m_res.getMonsterTexture()), m_sprite2(m_res.getMonsterTexture2())
{
	m_scale.x /= m_res.getSizeMonster().x;
	m_scale.y /= m_res.getSizeMonster().y;
}

Monster::~Monster() {}

void Monster::move(sf::Time deltaTime)
{
	if (m_direction[up])
		dir = sf::Vector2f(0, -monSpeed);
	else if (m_direction[down])
		dir = sf::Vector2f(0, monSpeed);
	else if (m_direction[left])
	{
		m_stright = true;
		dir = sf::Vector2f(-monSpeed, 0);
	}
	else
	{
		m_stright = false;
		dir = sf::Vector2f(monSpeed, 0);
	}
	m_newLoc = m_position + dir * deltaTime.asSeconds();

	if (checkingCollision(m_newLoc))
	{
		setPosition(m_newLoc);
		return;
	}
	changeDirection();
}

void Monster::draw(sf::RenderWindow& window)
{
	if (m_stright)
	{
		m_sprite.setPosition(m_position);
		m_sprite.setScale(m_scale);
		window.draw(m_sprite);
	}
	else
	{
		m_sprite2.setPosition(m_position);
		m_sprite2.setScale(m_scale);
		window.draw(m_sprite2);
	}
}

char Monster::getItem() const
{
	return monster;
}

bool Monster::checkingCollision(sf::Vector2f loc)
{
	
	auto& control = Controller::getInstance();
	if (!MobileItem::checkingCollision(loc))
		return false;
	char it = getCollision(m_sprite);
	switch (it)
	{
	case wall:
		return false;
	case stone:
		return false;
	case diamond:
		return true;
	case monster:
		return true;
	case digger:
	{
		
		sf::SoundBuffer monsterSoundBuffer;
		if (!monsterSoundBuffer.loadFromFile("soundMonster.wav"))
			return EXIT_FAILURE;
		sf::Sound monsterSound(monsterSoundBuffer);
		monsterSound.setVolume(80.f);
		monsterSound.play();
		control.continueStage();
		return true;
	}
	case space:
		return true;
	}
}

