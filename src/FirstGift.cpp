#include "FirstGift.h"
#include "Controller.h"

FirstGift::FirstGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Gift(location, size, scale, color) {}

FirstGift::~FirstGift() {}

void FirstGift::getGift()
{
	auto& control = Controller::getInstance();
	control.setLive();
}
