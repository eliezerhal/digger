#include "SecondGift.h"
#include "Controller.h"

SecondGift::SecondGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Gift(location, size, scale, color) {}

SecondGift::~SecondGift() {}

void SecondGift::getGift()
{
	auto& control = Controller::getInstance();
	control.setStones(5);
}
