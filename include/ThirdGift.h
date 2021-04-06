#pragma once
#include "Gift.h"

class ThirdGift : public Gift
{
public:
	ThirdGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~ThirdGift() override;
	void getGift() override;
};