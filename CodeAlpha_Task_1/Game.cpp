#include "Game.h"

void Game::initVariables()
{
	srand(time(0));
	answer = rand() % 100;
	option = -1;
	pauseGame = false;

	attempts = 0;
	isPlaying = false;
	this->window = nullptr;
	if (!img.loadFromFile("escKey.png"))
	{
		cout << "Img not loaded" << endl;
		exit(1);
	}
	texture.loadFromImage(img);
	escKey.setTexture(texture);
	escKey.setPosition(sf::Vector2f(0.f, 0.f));
	escKey.setScale(sf::Vector2f(0.16f, 0.16f));

	if (!font.loadFromFile("PTR.ttf")) {
		cout << "Error loading font!" << endl;
		exit(1);
	}
	escText.setCharacterSize(20);
	escText.setString("Press escape to quit.");
	escText.setFont(font);
	escText.setOutlineThickness(3.f);
	escText.setOutlineColor(sf::Color::Black);
	escText.setPosition(sf::Vector2f(75.f, 25.f));

	restartGame.setString("Press R to restart.");
	restartGame.setFont(font);
	restartGame.setPosition(sf::Vector2f(600.f, 600.f));
	restartGame.setFillColor(sf::Color(93, 63, 211));
}

void Game::initWindow()
{
	this->video.height = 700;
	this->video.width = 800;
	this->window = new sf::RenderWindow(this->video, "Number Guesser", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initMusic()
{
	if (!BgMusic.openFromFile("8BitLove.mp3")) {
		cout << "Error loading font!" << endl;
		exit(1);
	}
	BgMusic.setVolume(5);
	BgMusic.play();
}

void Game::initPlayEnvironment()
{
	if (!img.loadFromFile("makeGuess.png"))
	{
		cout << "Cant load img" << endl;
		exit(1);
	}
	texture2.loadFromImage(img);
	makeGuess.setTexture(texture2);
	makeGuess.setPosition(sf::Vector2f(115.f, 200.f));
	makeGuess.setScale(sf::Vector2f(0.7f, 0.7f));

	playerText.setFont(font);
	playerText.setOutlineThickness(3.f);
	playerText.setOutlineColor(sf::Color(93, 63, 211));
	playerText.setPosition(sf::Vector2f(370, 405));

	tries.setCharacterSize(20);
	tries.setOutlineThickness(3.f);
	tries.setOutlineColor(sf::Color::Black);
	tries.setFont(font);
	tries.setPosition(sf::Vector2f(650.f, 25.f));
	strTries = "Tries: 0";
	tries.setString(strTries);
	tries.setFillColor(sf::Color::White);

	prompts[0].setFont(font);
	prompts[1].setFont(font);
	prompts[2].setFont(font);
	prompts[3].setFont(font);
	prompts[4].setFont(font);
	prompts[5].setFont(font);
	prompts[6].setFont(font);

	prompts[0].setString("Too High!");
	prompts[1].setString("Too Low!");
	prompts[2].setString("Slightly below the Target!");
	prompts[3].setString("Slightly above the correct Answer!");
	prompts[4].setString("You remain below the Target!");
	prompts[5].setString("You are still surpassing the Target!");
	prompts[6].setString("You Win!!");

	prompts[0].setPosition(sf::Vector2f(330.f, 350.f));
	prompts[1].setPosition(sf::Vector2f(330.f, 350.f));
	prompts[2].setPosition(sf::Vector2f(240.f, 350.f));
	prompts[3].setPosition(sf::Vector2f(185.f, 350.f));
	prompts[4].setPosition(sf::Vector2f(215.f, 350.f));
	prompts[5].setPosition(sf::Vector2f(180.f, 350.f));
	prompts[6].setPosition(sf::Vector2f(328.f, 350.f));

	prompts[0].setOutlineColor(sf::Color::Black);
	prompts[1].setOutlineColor(sf::Color::Black);
	prompts[2].setOutlineColor(sf::Color::Black);
	prompts[3].setOutlineColor(sf::Color::Black);
	prompts[4].setOutlineColor(sf::Color::Black);
	prompts[5].setOutlineColor(sf::Color::Black);
	prompts[6].setOutlineColor(sf::Color::Black);

	prompts[0].setOutlineThickness(1.f);
	prompts[1].setOutlineThickness(1.f);
	prompts[2].setOutlineThickness(1.f);
	prompts[3].setOutlineThickness(1.f);
	prompts[4].setOutlineThickness(1.f);
	prompts[5].setOutlineThickness(1.f);
	prompts[6].setOutlineThickness(1.f);

	rectangle.setFillColor(sf::Color::White);
	rectangle.setPosition(sf::Vector2f(315.f, 400.f));
	rectangle.setSize(sf::Vector2f(150.f, 50.f));
	rectangle.setOutlineThickness(10.f);
	rectangle.setOutlineColor(sf::Color::Black);
}

void Game::drawEscapeKey()
{
	window->draw(escKey);
	window->draw(escText);
}

void Game::drawPlayEnvironment()
{
	window->draw(rectangle);
	window->draw(makeGuess);
	window->draw(restartGame);
	window->draw(tries);
}

Game::Game()
{
	this->initMusic();
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvent()
{
	//Event polling
	while (this->window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::TextEntered:
			if (isPlaying)
			{
				if (ev.key.code == '\b')
				{
					if (playerInput.begin() != playerInput.end())
					{
						playerInput.erase(playerInput.getSize() - 1, 1);
						playerText.setString(playerInput);
					}
				}
				else if (ev.text.unicode >= 48 && ev.text.unicode <= 57)
				{
					if (playerInput.getSize() < 2)
					{
						playerInput += ev.text.unicode;
						playerText.setString(playerInput);
					}
				}
			}
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			else if (ev.key.code == sf::Keyboard::R && pauseGame)
			{
				answer = rand() % 100;
				pauseGame = false;
				restartGame.setFillColor(sf::Color(93, 63, 211));
				option = -1;
			}
			break;
		case sf::Event::KeyReleased:
			if (ev.key.code == sf::Keyboard::Up) {
				menu.moveUp();
				break;
			}
			else if (ev.key.code == sf::Keyboard::Down) {
				menu.moveDown();
				break;
			}
			else if (ev.key.code == sf::Keyboard::Return) {
				if (isPlaying && playerInput.getSize() > 0 && !pauseGame)	//check playerinput.getsize issue
				{
					if (strTries.begin() != strTries.end())
					{
						attempts++;
						if (attempts >= 11)
							strTries.erase(strTries.getSize() - 2, 2);
						else
							strTries.erase(strTries.getSize() - 1, 1);

						strTries += to_string(attempts);
						tries.setString(strTries);
					}

					string str = playerText.getString();
					numberGuess = stoi(str);
					playerInput.clear();
					playerText.setString(playerInput);
					if (answer == numberGuess)
					{
						attempts = 0;
						option = 6;
						pauseGame = true;
						restartGame.setFillColor(sf::Color::Green);
						restartGame.setPosition(sf::Vector2f(275.f, 460.f));
						break;
					}
					else if (numberGuess < answer)
					{
						int diff = answer - numberGuess;
						if (diff > 50)
							option = 1;
						else if (diff > 10 && diff < 50)
							option = 4;
						else if (diff > 0)
							option = 2;
					}
					else
					{
						int diff = numberGuess - answer;
						if (diff > 50)
							option = 0;
						else if (diff > 10 && diff < 50)
							option = 5;
						else if (diff > 0)
							option = 3;
					}
				}
				else if (!isPlaying)
				{
					if (menu.PressedOption() == 0)	//Play
					{
						menu.clearMenu();
						initPlayEnvironment();
						isPlaying = true;
					}
					else
						this->window->close();
				}
				break;
			}
		}
	}
}

const bool Game::isGameRunning()
{
	return window->isOpen();
}

void Game::update()
{
	pollEvent();
}

void Game::render()
{
	window->clear(sf::Color(93, 63, 211));

	//Draw game objects here;
	menu.displayMenu(*window);
	if (option >= 0)
		window->draw(prompts[option]);
	drawPlayEnvironment();
	window->draw(playerText);
	drawEscapeKey();

	window->display();
}
