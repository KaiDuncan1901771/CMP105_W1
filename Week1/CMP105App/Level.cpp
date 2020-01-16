#include "Level.h"

Level::Level(sf::RenderWindow* hwnd)
{
	window = hwnd;

	// initialise game objects
	rect.setSize(sf::Vector2f(100, 90));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	rectGreen.setSize(sf::Vector2f(70, 60));
	rectGreen.setPosition(115, 115);
	rectGreen.setFillColor(sf::Color::Green);

	rectBlue.setSize(sf::Vector2f(40, 30));
	rectBlue.setPosition(130, 130);
	rectBlue.setFillColor(sf::Color::Blue);

	rectBottomRight.setFillColor(sf::Color::Green);
	rectBottomRight.setSize(sf::Vector2f(300, 400));

	circle.setRadius(50);
	circle.setPosition(600, 337.5);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	//Render text
	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading file";
	}

	text.setFont(font);
	text.setString("Hello World");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(600, 0);
	endDraw();
}


Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2f pos = static_cast<sf::Vector2f>(window->getSize());
	sf::Vector2f rectSize = rectBottomRight.getSize();

	rectBottomRight.setPosition(pos - rectSize);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(rect);
	window->draw(rectGreen);
	window->draw(rectBlue);
	window->draw(circle);
	window->draw(text);
	window->draw(rectBottomRight);

	endDraw();
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}