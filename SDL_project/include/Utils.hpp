#pragma once

#include <SDL2/SDL.h>

namespace utils
{
	//Get the mseconds between frames and scale it up to seconds

	inline float hireTimeInSeconds()
	{
		float t = SDL_GetTicks();
		t *= 0.001f;

		return (t);
	}
}