#pragma once

#include "Gift.h"

class SecondGift : public Gift
{
public:
	SecondGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~SecondGift() override;
	void getGift() override;
};