#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
class Menu
{
	//Private Variables
	sf::Image img;
	sf::Texture texture, texture2;
	sf::Sprite number;
	sf::Sprite guesser;
	sf::Font font;
	sf::Text options[2];
	int selectedItem;

	//Private Functions
	void initVariables();
public:
	Menu();

	void clearMenu();
	int PressedOption();
	void moveUp();
	void moveDown();
	void displayMenu(sf::RenderWindow& window);
};

