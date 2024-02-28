#include "Menu.h"

void Menu::initVariables()
{
	selectedItem = 0;

	if (!img.loadFromFile("number.png"))
	{
		cout << "Error loading menu!" << endl;
		exit(1);
	}
	texture.loadFromImage(img);
	number.setTexture(texture);
	number.setPosition(100.f, 100.f);

	if (!img.loadFromFile("guesser.png"))
	{
		cout << "Error loading menu!" << endl;
		exit(1);
	}
	texture2.loadFromImage(img);
	guesser.setTexture(texture2);
	guesser.setPosition(250.f, 200.f);

	if (!font.loadFromFile("PTR.ttf")) {
		cout << "Error loading font!" << endl;
		exit(1);
	}

	options[0].setFillColor(sf::Color::Black);
	options[1].setFillColor(sf::Color::White);

	options[0].setCharacterSize(70);
	options[1].setCharacterSize(70);

	options[0].setFont(font);
	options[1].setFont(font);

	options[0].setOutlineColor(sf::Color::Black);
	options[1].setOutlineColor(sf::Color::Black);

	options[0].setOutlineThickness(1.f);
	options[1].setOutlineThickness(1.f);

	options[0].setString("Play");
	options[1].setString("Exit");

	options[0].setPosition(sf::Vector2f(335.f, 380.f));
	options[1].setPosition(sf::Vector2f(335.f, 470.f));
}

Menu::Menu()
{
	this->initVariables();
}

void Menu::clearMenu()
{
	sf::String temp;
	temp.clear();

	number.setColor(sf::Color::Transparent);
	guesser.setColor(sf::Color::Transparent);
	options[0].setString(temp);
	options[1].setString(temp);
}

int Menu::PressedOption()
{
	return selectedItem;
}

void Menu::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		options[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		options[selectedItem].setFillColor(sf::Color::Black);
	}
}

void Menu::moveDown()
{
	if (selectedItem + 1 < 2)
	{
		options[selectedItem].setFillColor(sf::Color::White);
		selectedItem++;
		options[selectedItem].setFillColor(sf::Color::Black);
	}
}

void Menu::displayMenu(sf::RenderWindow& window)
{
	window.draw(number);
	window.draw(guesser);
	window.draw(options[0]);
	window.draw(options[1]);
}
