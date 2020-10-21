#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

#define WIDTH 720
#define HEIGHT 360

class RenderWindow
{
public:
	RenderWindow(const char *p_title, int p_w, int p_h);
	SDL_Texture *loadTexture(const char *p_filePath);
	int	getRefreshRate();
	bool init();
	void cleanUp();
	void clear();
	void render(Entity &p_entity);
	void display();
	void pollEvents(SDL_Event &event);
	bool isClosed()
	{
		return(p_closed);
	}
	Vector2f getMousePos()
	{
		return(mousePos);
	}
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	Vector2f mousePos;
	bool p_closed = false;
};

bool init();