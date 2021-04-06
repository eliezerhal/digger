#include "FifthGift.h"
#include "Controller.h"

FifthGift::FifthGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Gift(location, size, scale, color) {}

FifthGift::~FifthGift() {}

void FifthGift::getGift()
{
	auto& control = Controller::getInstance();
	control.setTime(25);
}