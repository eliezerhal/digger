#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"

class Information
{
public :
	static Information& getInstance();
	void updateInformation();	//This function updates the information during the game
	void draw(sf::RenderWindow& window);

private:
	Information();
	Resourses m_res;
	std::vector<sf::Text> m_info;
	std::string m_str[5] = { "Level:\n "," Live:\n ","score:\n","Stone:\n","Time:" };
	std::string m_string[3];
	std::string getTheInfo(int i) const;
};