#include "Digger.h"
#include "Controller.h"
#include <iostream>

Digger::Digger() : m_event({}) {}

Digger::Digger(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	: MobileItem(location, size, scale, color), /*m_rect(location, size, scale, color), */m_starsLoc(location), m_sprite(m_res.getDiggerTexture()), m_sprite2(m_res.getDiggerTexture2()), m_event({})
{
	m_scale.x /= m_res.getSizeDigger().x;
	m_scale.y /= m_res.getSizeDigger().y;
}

Digger::~Digger() {}

void Digger::move(sf::Time deltaTime)
{
	if (!m_move)
		return;
	auto loc = m_position;
	int keyOption;
	keyOption = m_event.code;
	switch (keyOption)
	{
	case sf::Keyboard::Up:
		dir = sf::Vector2f(0, -digSpeed);
		break;
	case sf::Keyboard::Down:
		dir = sf::Vector2f(0, digSpeed);
		break;
	case sf::Keyboard::Left:
		m_stright = false;
		dir = sf::Vector2f(-digSpeed, 0);
		break;
	case sf::Keyboard::Right:
		m_stright = true;
		dir = sf::Vector2f(digSpeed, 0);
		break;
	case sf::Keyboard::Space:
		dir = sf::Vector2f(0, 0);
		break;
	}
	
	m_newLoc = m_position + dir * deltaTime.asSeconds();

	if (checkingCollision(m_newLoc))
	{
		setPosition(m_newLoc);
		m_rec.setPosition(m_newLoc);
	}
	m_move = false;
}

void Digger::draw(sf::RenderWindow& window)
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

char Digger::getItem() const
{
	return digger;
}

void Digger::getEvent(sf::Event::KeyEvent event)
{
	m_event = event;
	m_move = true;
}

sf::Vector2f Digger::getLocation() const
{
	return m_position;
}

void Digger::eatingItem()
{
	auto& control = Controller::getInstance();
	control.deleteItem();
}

bool Digger::checkingCollision(sf::Vector2f loc)
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
		eatingItem();
		control.decStones();
		return true;
	case diamond:
		eatingItem();
		control.decDiamonds();
		return true;
	case monster:
		control.continueStage();
		return true;
	case gift:
		control.getGift();
		eatingItem();
		return true;
	case space:
		return true;
	}
	return true;
}
