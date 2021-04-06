#pragma once
#include "MobileItem.h"
#include "Rect.h"
#include "Macro.h"
#include <vector>

class Digger : public MobileItem
{
public:
	Digger();
	Digger(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~Digger() override;
	virtual void move(sf::Time deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual bool checkingCollision(sf::Vector2f loc) override;
	virtual char getItem() const override;
	void getEvent(sf::Event::KeyEvent event);
	sf::Vector2f getLocation() const;
	void eatingItem();

private:
	sf::Vector2f temp;
	sf::Sprite m_sprite;
	sf::Sprite m_sprite2;
	sf::Vector2f m_starsLoc;
	sf::Event::KeyEvent m_event;
	bool m_move = false;
};
