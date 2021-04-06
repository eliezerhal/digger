#include "StationaryItem.h"

StationaryItem::StationaryItem() {}

StationaryItem::StationaryItem(sf::Vector2f location, sf::Vector2f size, sf::Vector2f scale, sf::Color color)
	:Item(location, size, scale, color) {}

StationaryItem::~StationaryItem() {}