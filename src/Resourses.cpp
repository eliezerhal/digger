#include "Resourses.h"
#include <iostream>

Resourses::Resourses()
{
	m_digger.loadFromFile("digger.png");
	m_gameOver.loadFromFile("gameover.png");
	m_digger2.loadFromFile("digger2.png");
	m_monster.loadFromFile("monster.png");
	m_monster2.loadFromFile("monster2.png");
	m_menu.loadFromFile("menu.png");
	m_stone.loadFromFile("stone.png");
	m_win.loadFromFile("win.png");
	m_wall.loadFromFile("wall.png");
	m_diamond.loadFromFile("diamond.png");
	m_gift.loadFromFile("gift.png");
	m_grass.loadFromFile("grass.png");
	m_font.loadFromFile("snap.ttf");
	m_soundMonster.loadFromFile("soundMonster.wav");
	m_MusicBackround.openFromFile("MusicBackround.wav");
}

sf::Texture& Resourses::getDiggerTexture()
{
	return m_digger;
}

sf::Texture& Resourses::getWinTexture()
{
	return m_win;
}

sf::Texture& Resourses::getGameOverTexture()
{
	return m_gameOver;
}

sf::Texture& Resourses::getMenuTexture()
{
	return m_menu;
}
sf::Texture& Resourses::getGrassTexture()
{
	return m_grass;
}

sf::Texture& Resourses::getMonsterTexture()
{
	return m_monster;
}

sf::Texture& Resourses::getMonsterTexture2()
{
	return m_monster2;
}

sf::Texture& Resourses::getStoneTexture()
{
	return m_stone;
}

sf::Texture& Resourses::getWallTexture()
{
	return m_wall;
}
sf::Texture& Resourses::getGiftTexture()
{
	return m_gift;
}

sf::Texture& Resourses::getDiggerTexture2()
{
	return m_digger2;
}

sf::Texture& Resourses::getDiamondTexture()
{
	return m_diamond;
}

sf::Font& Resourses::getFontTexture() 
{
	return m_font;
}

sf::SoundBuffer& Resourses::getMonsterSound()
{
	return m_soundMonster;
}



sf::Music& Resourses::getMusicBackround()
{
	return m_MusicBackround;
}


sf::Vector2u Resourses::getSizeDigger()
{
	return m_digger.getSize();
}

sf::Vector2u Resourses::getSizeStone()
{
	return m_stone.getSize();
}


sf::Vector2u Resourses::getSizeDiamond()
{
	return m_diamond.getSize();
}

sf::Vector2u Resourses::getSizeWall()
{
	return m_wall.getSize();
}

sf::Vector2u Resourses::getSizeMonster()
{
	return m_monster.getSize();
}

