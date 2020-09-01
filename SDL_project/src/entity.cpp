#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(Vector2f p_pos, SDL_Texture *p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 16;
	currentFrame.h = 16;
}

void Entity::pollEvents(SDL_Event &event)
{
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_q:
				moveEntity(Vector2f(-50, 0));
				//setPos(Vector2f(getPos().x - 5, getPos().y));
				break;
			case SDLK_d:
				moveEntity(Vector2f(50, 0));
				//setPos(Vector2f(getPos().x + 5, getPos().y));
				break;
			case SDLK_s:
				moveEntity(Vector2f(0, 50));
				//setPos(Vector2f(getPos().x, getPos().y + 5));
				break;
			case SDLK_z:
				moveEntity(Vector2f(0, -50));
				//setPos(Vector2f(getPos().x, getPos().y - 5));
				break;
		}
	}	
}

void Entity::setPos(Vector2f newPos)
{
	pos = newPos;
}

void Entity::moveEntity(Vector2f velocity)
{
	double delta_time = 1.0/60.0;
	printf("%f\n", delta_time);
	Vector2f actualPos = this->getPos();
	Vector2f newPos = actualPos + Vector2f(velocity.x * delta_time, velocity.y * delta_time);
	setPos(newPos);
	newPos.print();
}

SDL_Texture *Entity::getTex()
{
	return(tex);
}

SDL_Rect Entity::getCurrentFrame()
{
	return(currentFrame);
}