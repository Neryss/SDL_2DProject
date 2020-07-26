#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"

int		main(int argc, char **argv)
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG init HAS FAILED. Error: " << SDL_GetError() << std::endl;
	RenderWindow window("Game v1.0", 1280, 720);

	SDL_Texture *groundTexture = window.loadTexture("res/gfx/tile.png");

	Entity platform0(100, 100, groundTexture);

	bool gameRunning = true;

	SDL_Event event;

	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				gameRunning = false;
		}
		window.clear();
		window.render(platform0);
		window.display();
	}
	window.cleanUp();
	SDL_Quit();

	return(0);
}