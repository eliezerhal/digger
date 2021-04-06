#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Resourses
{
public:
	Resourses();
	sf::Texture& getDiggerTexture();
	sf::Texture& getDiggerTexture2();
	sf::Texture& getMenuTexture();
	sf::Texture& getGameOverTexture();
	sf::Texture& getMonsterTexture();
	sf::Texture& getMonsterTexture2();
	sf::Texture& getStoneTexture();
	sf::Texture& getWallTexture();
	sf::Texture& getGrassTexture();
	sf::Texture& getDiamondTexture();
	sf::Texture& getWinTexture();
	sf::Texture& getGiftTexture();
    sf::Font& getFontTexture();
	sf::SoundBuffer& getMonsterSound();
	sf::Music& getMusicBackround();
	sf::Vector2u getSizeDigger();
	sf::Vector2u getSizeStone();
	sf::Vector2u getSizeDiamond();
	sf::Vector2u getSizeWall();
	sf::Vector2u getSizeMonster();
    sf::Music m_MusicBackround;
	
private:
	sf::SoundBuffer m_soundMonster;
	sf::Texture m_monster;
	sf::Texture m_monster2;
	sf::Texture m_gameOver;
	sf::Texture m_grass;
	sf::Texture m_win;
	sf::Texture m_digger2;
	sf::Texture m_digger;
	sf::Texture m_menu;
	sf::Texture m_stone;
	sf::Texture m_wall;
	sf::Texture m_gift;
	sf::Texture m_diamond;
	sf::Font m_font;	
};
