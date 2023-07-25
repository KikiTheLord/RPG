#pragma once
#include "Game.hpp"
#include "Master.hpp"
#include "Character.hpp"


void printVector(std::vector<Character> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].showStats();
    }
}

int main(int argc, char* argv[])
{
	Game* game = nullptr;
	game = new Game;
    Master master(game);
	game->init("RPG GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
    printVector(game->getPlayers());
    master.spawnGoblin("Jean Binbaum");
    printVector(game->getEnnemies());
	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}