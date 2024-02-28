#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"
#include <cctype>
#include <cstdlib>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>

class Game
{
private:
	//Private Variables
	int answer;
	int numberGuess;
	int option;
	int attempts;

	sf::Font font;
	sf::String playerInput;
	sf::String strTries;
	sf::Text playerText;
	sf::Text escText;
	sf::Text prompts[7];
	sf::Text restartGame;
	sf::Text tries;
	sf::Music BgMusic;

	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::Event ev;
	sf::RectangleShape rectangle;
	Menu menu;
	bool isPlaying;
	bool pauseGame;

	sf::Image img;
	sf::Texture texture, texture2;
	sf::Sprite escKey;
	sf::Sprite makeGuess;


	//Initialization
	void initVariables();
	void initWindow();
	void initMusic();
	void initPlayEnvironment();
	void drawEscapeKey();
	void drawPlayEnvironment();
public:
	Game();
	virtual ~Game();

	void pollEvent();
	const bool isGameRunning();
	void update();
	void render();
};

