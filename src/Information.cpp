#include "Information.h"
#include "Controller.h"
#include "Macro.h"

Information::Information()
{
	for (int i = 0; i < 5; i++)
	{
		m_info.push_back(sf::Text(m_str[i] + getTheInfo(i), m_res.getFontTexture()));
		m_info[i].setPosition((i * (Width/5)), 0);
		m_info[i].setScale(1, 1);
		m_info[i].setColor(sf::Color::White);
		m_info[i].setStyle(sf::Text::Bold );
		m_info[i].setOutlineColor(sf::Color::Cyan);
		m_info[i].setOutlineThickness(-2);
	}
}

Information& Information::getInstance()
{
	static Information instance;
	return  instance;
}

void Information::updateInformation()
{
	for (int i = 0; i < 5; i++)
		m_info[i].setString(m_str[i] + getTheInfo(i));
}

std::string Information::getTheInfo(int i) const
{
	auto& control = Controller::getInstance();
	switch (i)
	{
	case 0:
		return std::to_string(control.getLevel());
	case 1:
		return std::to_string(control.getLive());
	case 2:
		return std::to_string(control.getPoints());
	case 3:
		return std::to_string(control.getStones());
	case 4:
		if (control.getTime() > 0)
			return std::to_string(control.getTime() - control.getTimmer().getElapsedTime().asSeconds());
		else
			return "FREE";
	}
	return " ";
}

void Information::draw(sf::RenderWindow& window)
{
	for (auto& info : m_info)
		window.draw(info);
}
