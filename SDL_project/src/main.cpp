#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

void pollEvents(RenderWindow &window, Entity &entity)
{
	SDL_Event event;

	entity.playerMove();
	if(SDL_PollEvent(&event))
	{
		window.pollEvents(event);
		//entity.pollEvents(event);
	}
}

int		main(int argc, char **argv)
{
	if(!init())
		std::cout << "error" << std::endl;
	RenderWindow window("Game v1.0", WIDTH, HEIGHT);
	int windowRefreshRate = window.getRefreshRate();
	std::cout << windowRefreshRate << std::endl;
	SDL_Texture *groundTexture = window.loadTexture("res/gfx/tile.png");
	SDL_Texture *playerTexture = window.loadTexture("res/gfx/player_no_anim.png");

    std::vector<Entity> entitiees = {Entity(Vector2f(1, 1), playerTexture), 
									Entity(Vector2f(15, 0), groundTexture),
									Entity(Vector2f(30, 0), groundTexture)};
	{
		Entity test(Vector2f(100, 20), groundTexture);
		entitiees.push_back(test);
	}

	const float deltaTime = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	while(!window.isClosed())
	{
		int frameTicks = 0;
		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;

		currentTime = newTime;
		accumulator += frameTime;
		while(accumulator >= deltaTime)
		{
			pollEvents(window, entitiees[0]);
			entitiees[1].setPos(window.getMousePos());
			accumulator -= deltaTime;
		}
		window.clear();
		for(Entity &e: entitiees)
			window.render(e);
		window.display();
		frameTicks = SDL_GetTicks();
		if (frameTicks < 1000 / window.getRefreshRate())
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
	}
	window.cleanUp();
	SDL_Quit();
	return(0);
}