// Teawolf

#pragma once

#include "game_object.h"

class Player : public GameObject
{
public:
	void init(int x, int y, int width, int height, const std::string& texture_id);	
	void update();
	void draw(SDL_Renderer* renderer);
	void clean();
};
