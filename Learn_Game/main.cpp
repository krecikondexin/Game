#include <SFML/Graphics.hpp>
#include "Game.h"
#include "MenuState.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "MarioGameState.h"

int main()
{	srand(time(NULL));
	std::shared_ptr<Game> game = std::make_shared<Game>();
	game->pushState(std::make_shared<MarioGameState>(game));
	game->gameLoop();
	return 0;
}