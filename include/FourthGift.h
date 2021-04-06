#pragma once
#include "Gift.h"

class FourthGift : public Gift
{
public:
	FourthGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~FourthGift() override;
	void getGift() override;
};