#include <SFML/Graphics.hpp>

int main()
{
	// ---------------------- Initialize --------------------------

	// Circle
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");
	sf::CircleShape circle(50.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(350.0f, 400.0f));
	circle.setOutlineColor(sf::Color::Cyan);
	circle.setOutlineThickness(4.8f);

	// Rectangle
	sf::RectangleShape rectangle;
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setSize(sf::Vector2f(200, 100));
	rectangle.setPosition(sf::Vector2f(400, 100));
	rectangle.setOrigin(rectangle.getSize() / 2.0f);
	rectangle.rotate(30.0f);

	// Heptagon
	sf::CircleShape polygon(60, 7);
	polygon.setPosition(sf::Vector2f(60.0f, 200.0f));
	polygon.setFillColor(sf::Color::Cyan);
	polygon.setOutlineColor(sf::Color::Yellow);
	polygon.setOutlineThickness(4.8f);

	// Convex
	sf::ConvexShape convex;
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(0.f, 0.f));
	convex.setPoint(1, sf::Vector2f(150.f, 10.f));
	convex.setPoint(2, sf::Vector2f(120.f, 90.f));
	convex.setPoint(3, sf::Vector2f(30.f, 100.f));
	convex.setPoint(4, sf::Vector2f(0.f, 50.f));
	convex.setFillColor(sf::Color::Magenta);

	// Lines
	sf::RectangleShape line(sf::Vector2f(800, 3));
	line.setPosition(10, 10);
	line.rotate(45.f);

	// ---------------------- Initialize --------------------------

	while (window.isOpen())
	{
		// ---------------------- Update --------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// ---------------------- Update --------------------------

		// ---------------------- Draw --------------------------
		window.clear();
		window.draw(circle);
		window.draw(rectangle);
		window.draw(polygon);
		window.draw(convex);
		window.draw(line);
		window.display();
		// ---------------------- Draw --------------------------
	}

	return 0;
}