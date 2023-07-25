#include "Sprite.hpp"

Sprite::Sprite(){}
Sprite::Sprite(SDL_Renderer* renderer,int posX,int posY,const char* imagePath)
{
	if (IMG_INIT_PNG)
	{
		IMG_Init(IMG_INIT_PNG);
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		SDL_SetHint(SDL_HINT_RENDER_DRIVER, "direct3d");
		SDL_SetHint(SDL_HINT_RENDER_DIRECT3D_THREADSAFE, "1");

		//Setup and Init the SDL2 image "C:/Users/Killian/Desktop/RPG/x64/Debug/Sprites/Knight front.png"
		_image = IMG_Load(imagePath);
		if (!_image)
		{
			std::cout << "image not loaded" << std::endl;
		}
		_texture = SDL_CreateTextureFromSurface(renderer, _image);
		// Get rectangle dimensions + make png transparent
		int imageWidth, imageHeight;
		SDL_QueryTexture(_texture, nullptr, nullptr, &imageWidth, &imageHeight);
		SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
		_rect.x = posX;
		_rect.y = posY;
		_rect.w = imageWidth;
		_rect.h = imageHeight;


	}
}

Sprite::~Sprite()
{

}

void Sprite::renderSprite(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer,_texture, NULL, &_rect);
}