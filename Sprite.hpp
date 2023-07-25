#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
class Sprite
{
public:
	Sprite();
	Sprite(SDL_Renderer* renderer,int posX,int posY, const char* imagePath);
	~Sprite();
	void renderSprite(SDL_Renderer* renderer);
	SDL_Texture* _texture = nullptr;
	SDL_Rect _rect;

private:
	SDL_Surface* _image = nullptr;
	
	
	int _originX, _originY;


};