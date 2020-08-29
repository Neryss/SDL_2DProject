#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "RenderWindow.hpp"
#include "Entity.hpp"

// void pollEvents(Window &window, Entity &entity)
// {
// 	SDL_Event event;

// 	if(SDL_PollEvent(&event))
// 	{

// 	}
// }

int		main(int argc, char **argv)
{
	if(!init())
		std::cout << "error" << std::endl;
	RenderWindow window("Game v1.0", 1280, 720);
	SDL_Texture *groundTexture = window.loadTexture("res/gfx/tile.png");

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
	Vector2f mousePos(0, 0);
	res = t1 + t2;
	res.print();

	while(!window.isClosed())
	{
		entitiees[1].pollEvents();
		window.pollEvents();
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