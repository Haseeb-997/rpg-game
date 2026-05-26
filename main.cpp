#include <SFML/Graphics.hpp>

int main()
{
	// ---------------------- Initialize --------------------------
	// Anti-aliasing edges ko smooth banati hai taa ke shapes/jagged lines zyada clean dikhein
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);
	// ---------------------- Initialize --------------------------

	// ---------------------- LOAD --------------------------
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		playerSprite.setTexture(playerTexture);

		int Xindex = 0;
		int Yindex = 2;

		playerSprite.setTextureRect(sf::IntRect(Xindex * 64, Yindex * 64, 64, 64));
		playerSprite.setScale(sf::Vector2f(3, 3));
	}
	// ---------------------- LOAD --------------------------

	while (window.isOpen())
	{
		// ---------------------- Update --------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerSprite.setPosition(position + sf::Vector2f(0, -1));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerSprite.setPosition(position + sf::Vector2f(0, 1));
		
		// ---------------------- Update --------------------------

		// ---------------------- Draw --------------------------
		window.clear();
		window.draw(playerSprite);
		window.display();
		// ---------------------- Draw --------------------------
	}

	return 0;
}