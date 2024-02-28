#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	//Window
	Game game;

	//GameLoop
	while (game.isGameRunning())
	{
		game.update();
		game.render();
	}

	return 0;
}