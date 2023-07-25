#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <limits>
#include <unordered_map>
#define SDL_MAIN_HANDLED
#include "Character.hpp"
#include "Sprite.hpp"

class Game {

public:
	Game();
	~Game();

	void init(std::string title, int x, int y, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	void addPlayer(Character &character, Sprite &sprite);
	void addEnnemy(Character &character, Sprite& sprite);
	void initPlayers();
	SDL_Renderer* getRenderer();
	void renderCharacters();
	
	std::vector<Character> getPlayers();
	std::vector<Character> getEnnemies();
	
private:
	std::vector<Character> _players;
	std::vector<Sprite> _playerSprite;
	std::vector<Character> _ennemies;
	std::vector<Sprite> _ennemySprite;
	bool _isRunning = false;
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;


};