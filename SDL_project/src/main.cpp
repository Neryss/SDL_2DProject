#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
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

	// Entity entities[3] = {Entity(0, 0, groundTexture), 
	// 					  Entity(15, 0, groundTexture),
	// 					  Entity(30, 0, groundTexture)};

    std::vector<Entity> entitiees = {Entity(Vector2f(0, 0), groundTexture), 
			  					     Entity(Vector2f(15, 0), groundTexture),
	 					  			 Entity(Vector2f(30, 0), groundTexture)};
	{
		Entity test(Vector2f(100, 20), groundTexture);

		entitiees.push_back(test);
	}
	//test for first vector operator
	Vector2f t1(0, 0);
	Vector2f t2(10, 10);
	Vector2f res(0, 0);
	res = t1 + t2;
	res.print();
	bool gameRunning = true;

	SDL_Event event;
	//testing purposes
	// Vector2f test(10, 0);
	// test.print();
	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					gameRunning = false;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
							std::cout << "clicked a" << std::endl;
							break;
					}
				case SDL_MOUSEMOTION:
					std::cout << event.motion.x << ',' << event.motion.y << std::endl;
					break;
			}
		}
		window.clear();
		for(Entity &e: entitiees)
		{
			window.render(e);
			//testing vector debugging
			// Vector2f temp(e.getPos());
			// temp.print();
		}
		window.display();
	}
	window.cleanUp();
	SDL_Quit();

	return(0);
}