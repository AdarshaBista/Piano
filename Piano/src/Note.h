#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Note
{
private:
	sf::Sprite keySprite;
	sf::Vector2i position;

	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

public:
	sf::Keyboard::Key key;
	bool isBeingPressed;

public:
	Note(sf::Keyboard::Key key);
	void setTexture(sf::Texture& tex);
	void setPosition(sf::Vector2i pos);
	void setSoundBuffer(std::string path);
	void play();

	void draw(sf::RenderWindow& window);

};

