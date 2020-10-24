#include "Entity.hpp"
#include "RenderWindow.hpp"
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
	playerMove();
}

void Entity::playerMove()
{
	Vector2f currentAxis = Vector2f(0, 0);

	const Uint8 *keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_A])
		currentAxis -= Vector2f(50, 0);
	if (keyState[SDL_SCANCODE_D])
		currentAxis += Vector2f(50, 0);
	if (keyState[SDL_SCANCODE_W])
		currentAxis -= Vector2f(0, 50);
	if (keyState[SDL_SCANCODE_S])
		currentAxis += Vector2f(0, 50);
	moveEntity(currentAxis);
}

void Entity::setPos(Vector2f newPos)
{
	pos = newPos;
}

void Entity::moveEntity(Vector2f velocity)
{
	double delta_time = 1.0/60.0;
	//printf("%f\n", delta_time);
	Vector2f actualPos = this->getPos();
	Vector2f newPos = actualPos + Vector2f(velocity.x * delta_time, velocity.y * delta_time);
	printf("new pos is : %f, %f\n", newPos.x, newPos.y);
	if (newPos.x < 0)
	{
		newPos.x = 0;
		printf("DEBUG OOF");
	}
	if (newPos.y < 0)
	{
		newPos.y = 0;
		printf("DEBUG OOF");
	}
	if (newPos.y > HEIGHT / (delta_time + 16))
		printf("BIG OOF YIKES\n");
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