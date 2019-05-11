#pragma once

#include <SFML/Graphics.hpp>

class Sprite
{
private:
	sf::Texture spriteTex;
	sf::Sprite sprite;

public:
	Sprite(std::string texPath);
	void draw(sf::RenderWindow& window);
};

