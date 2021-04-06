#pragma once
#include "Gift.h"

class FifthGift : public Gift
{
public:
	FifthGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color);
	virtual ~FifthGift() override;
	void getGift() override;
};