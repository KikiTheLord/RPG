#pragma once
#include "Game.hpp"
const char* knightPath = "C:/Users/Killian/Desktop/RPG/x64/Debug/Sprites/Knight front.png";

Game::Game(){}
Game::~Game(){}

void Game::init(std::string title, int x, int y, int width, int height, bool fullscreen)
{
	//we also need to load the characters from memory if they are created, else create new characters
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		_window = SDL_CreateWindow("RPG", x, y, width, height, SDL_WINDOW_SHOWN);

		if (_window)
		{
			_renderer = SDL_CreateRenderer(_window, -1, 0);
		}
		if (_renderer)
		{
			SDL_SetRenderDrawColor(_renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(_renderer);
			_isRunning = true;
		}
		initPlayers();

		std::cout << "The End" << std::endl;

	}
	else 
	{ 
		_isRunning = false; 
	}
	//SDL_FreeSurface(image);
	//SDL_DestroyTexture(barbarian1);
	//IMG_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		_isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(_renderer);
	renderCharacters();
	SDL_RenderPresent(_renderer);
}
void Game::clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;

}

bool Game::running()
{
	return _isRunning;
}

void Game::addPlayer(Character &character,Sprite &sprite)
{
	_players.push_back(character);
	_playerSprite.push_back(sprite);
}

void Game::addEnnemy(Character &character, Sprite &sprite)
{
	_ennemies.push_back(character);
	_ennemySprite.push_back(sprite);
}

void Game::initPlayers()
{
		Wizard wizard("Barnabe le sorcier");
		Sprite wizSprite(_renderer,100,100, knightPath);
		addPlayer(wizard,wizSprite);
		Barbarian barbarian("Connard le barbare");
		Sprite barbSprite(_renderer,200,200, knightPath);
		addPlayer(barbarian,barbSprite);
		Character character;
		Sprite charSprite(_renderer,300,300, knightPath);
		addPlayer(character,charSprite);
}

SDL_Renderer* Game::getRenderer()
{
	return _renderer;
}

void Game::renderCharacters()
{
	for (int i = 0; i < _playerSprite.size(); i++)
	{
		_playerSprite[i].renderSprite(_renderer);
	}
	for (int j = 0; j < _ennemySprite.size(); j++)
	{
		_playerSprite[j].renderSprite(_renderer);
	}

}

std::vector<Character> Game::getPlayers()
{
	return _players;
}

std::vector<Character> Game::getEnnemies()
{
	return _ennemies;
}