#include "Sprite.h"


Sprite::Sprite(std::string texPath)
{
	spriteTex.loadFromFile(texPath);
	sprite.setTexture(spriteTex);
}

void Sprite::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}