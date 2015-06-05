// Teawolf

#pragma once

#include <SDL2/SDL.h>
#include "texture_manager.h"

class GameObject
{
public:
	virtual void init(int x, int y, int width, int height, const std::string& texture_id);	
	virtual void update();
	virtual void draw(SDL_Renderer* renderer);
	virtual void clean();

protected:
	int m_x;
	int m_y;

	int m_width;
	int m_height;

	std::string m_texture_id;

	int m_current_row;
	int m_current_frame;
};
