#include "Note.h"


Note::Note(sf::Keyboard::Key key) : key(key), isBeingPressed(false)
{
}

void Note::setTexture(sf::Texture& tex)
{
	keySprite.setTexture(tex);
}

void Note::setPosition(sf::Vector2i pos)
{
	keySprite.setPosition(sf::Vector2f(pos));
}

void Note::setSoundBuffer(std::string path)
{
	soundBuffer.loadFromFile(path);
	sound.setBuffer(soundBuffer);
	sound.setVolume(100.0f);
}

void Note::play()
{
	sound.play();
}

void Note::draw(sf::RenderWindow& window)
{
	if (isBeingPressed)
		keySprite.setColor(sf::Color(180, 180, 180));
	else
		keySprite.setColor(sf::Color::White);

	window.draw(keySprite);
}
