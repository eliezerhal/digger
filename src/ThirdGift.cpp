#include "ThirdGift.h"
#include "Controller.h"

ThirdGift::ThirdGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Gift(location, size, scale, color) {}

ThirdGift::~ThirdGift() {}

void ThirdGift::getGift()
{
	auto& control = Controller::getInstance();
	control.setPoints(10);
}
