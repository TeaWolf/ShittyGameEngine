// Teawolf

#pragma once

#include "sdl_game_object.h"

class Player : public SDLGameObject
{
public:
	Player(const ObjectLoadParameters* lparams);

	void update();
	void draw(SDL_Renderer* renderer);
	void clean();
};
