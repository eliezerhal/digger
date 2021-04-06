#include "FourthGift.h"
#include "Controller.h"

FourthGift::FourthGift(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Gift(location, size, scale, color) {}

FourthGift::~FourthGift() {}

void FourthGift::getGift()
{
	auto& control = Controller::getInstance();
	control.setPoints(10);
}
