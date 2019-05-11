#include <vector>
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "Note.h"


void initialize(std::vector<Note*>& notes, int keyWidth)
{
	notes.emplace_back(new Note(sf::Keyboard::Num1));
	notes.emplace_back(new Note(sf::Keyboard::Num2));
	notes.emplace_back(new Note(sf::Keyboard::Num3));
	notes.emplace_back(new Note(sf::Keyboard::Num4));
	notes.emplace_back(new Note(sf::Keyboard::Num5));
	notes.emplace_back(new Note(sf::Keyboard::Num6));
	notes.emplace_back(new Note(sf::Keyboard::Num7));
	notes.emplace_back(new Note(sf::Keyboard::Num8));
	notes.emplace_back(new Note(sf::Keyboard::Num9));
	notes.emplace_back(new Note(sf::Keyboard::Num0));
	notes.emplace_back(new Note(sf::Keyboard::Dash));
	notes.emplace_back(new Note(sf::Keyboard::Equal));
	notes.emplace_back(new Note(sf::Keyboard::Tab));
	notes.emplace_back(new Note(sf::Keyboard::Q));
	notes.emplace_back(new Note(sf::Keyboard::W));
	notes.emplace_back(new Note(sf::Keyboard::E));
	notes.emplace_back(new Note(sf::Keyboard::R));
	notes.emplace_back(new Note(sf::Keyboard::T));
	notes.emplace_back(new Note(sf::Keyboard::Y));
	notes.emplace_back(new Note(sf::Keyboard::U));
	notes.emplace_back(new Note(sf::Keyboard::I));
	notes.emplace_back(new Note(sf::Keyboard::O));
	notes.emplace_back(new Note(sf::Keyboard::P));
	notes.emplace_back(new Note(sf::Keyboard::LBracket));
	notes.emplace_back(new Note(sf::Keyboard::RBracket));
	notes.emplace_back(new Note(sf::Keyboard::BackSlash));
	notes.emplace_back(new Note(sf::Keyboard::A));
	notes.emplace_back(new Note(sf::Keyboard::S));
	notes.emplace_back(new Note(sf::Keyboard::D));
	notes.emplace_back(new Note(sf::Keyboard::F));
	notes.emplace_back(new Note(sf::Keyboard::G));
	notes.emplace_back(new Note(sf::Keyboard::H));
	notes.emplace_back(new Note(sf::Keyboard::J));
	notes.emplace_back(new Note(sf::Keyboard::K));
	notes.emplace_back(new Note(sf::Keyboard::L));
	notes.emplace_back(new Note(sf::Keyboard::SemiColon));
	notes.emplace_back(new Note(sf::Keyboard::Quote));
	notes.emplace_back(new Note(sf::Keyboard::LShift));
	notes.emplace_back(new Note(sf::Keyboard::Z));
	notes.emplace_back(new Note(sf::Keyboard::X));
	notes.emplace_back(new Note(sf::Keyboard::C));
	notes.emplace_back(new Note(sf::Keyboard::V));
	notes.emplace_back(new Note(sf::Keyboard::B));
	notes.emplace_back(new Note(sf::Keyboard::N));
	notes.emplace_back(new Note(sf::Keyboard::M));
	notes.emplace_back(new Note(sf::Keyboard::Comma));
	notes.emplace_back(new Note(sf::Keyboard::Period));
	notes.emplace_back(new Note(sf::Keyboard::Slash));
	notes.emplace_back(new Note(sf::Keyboard::RShift));

	// Create key texture
	static sf::Texture keyTexture;
	keyTexture.loadFromFile("assets/textures/key.png");

	for (unsigned int i = 0; i < notes.size(); ++i)
	{
		notes[i]->setTexture(keyTexture);
		notes[i]->setPosition(sf::Vector2i(i * keyWidth, 0));
		notes[i]->setSoundBuffer("assets/sounds/" + std::to_string(i) + ".ogg");
	}
}

int main()
{
	const int WIDTH = 1568;
	const int HEIGHT = 200;
	const int KEY_WIDTH = 32;

	// Create window
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Piano");
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(16);

	// Create piano keys
	std::vector<Note*> notes;
	initialize(notes, KEY_WIDTH);
	
	// Create additional decorations
	Sprite blackKeys("assets/textures/blackKeys.png");
	Sprite labels("assets/textures/labels.png");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				for (Note* note : notes)
				{
					if (note->key == event.key.code)
					{
						note->isBeingPressed = true;
						note->play();
					}
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				for (Note* note : notes)
				{
					if (note->key == event.key.code)
						note->isBeingPressed = false;
				}
			}
		}

		window.clear();

		for (Note* note : notes)
			note->draw(window);
		
		blackKeys.draw(window);
		labels.draw(window);

		window.display();
	}

	// Clean Up
	for (Note* note : notes)
		delete note;
	notes.clear();

	return 0;
}