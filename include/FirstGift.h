#pragma once
#pragma once
#include "Gift.h"

class FirstGift : public Gift
{
public:
	FirstGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~FirstGift() override;
	void getGift() override;
};