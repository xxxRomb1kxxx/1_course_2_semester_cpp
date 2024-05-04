#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


int main() {

	sf::Texture sex_boy_texture;
	sex_boy_texture.loadFromFile("src/egor_kreed.jpg");
	sf::RenderWindow window(sf::VideoMode(1920,1080), "SFML works!");
	sf::CircleShape shape(300.f);
	shape.setPosition(650, 0);
	shape.setTexture(&sex_boy_texture);
	sf::Music music;
	music.openFromFile("src/song.ogg");
	music.play();
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("src/background.jpg")) {
		return EXIT_FAILURE;
	}
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	sf::Font font;
	font.loadFromFile("src/sorcerer.otf");
	sf::Text text("SWAG", font, 20);
	text.setPosition(930,650);

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(backgroundSprite);
		window.draw(shape);
		window.draw(text);
		window.display();

	}

	return 0;
}
