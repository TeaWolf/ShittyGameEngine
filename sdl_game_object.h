// Teawolf

#pragma once

#include "game_object.h"
#include "game.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const ObjectLoadParameters* lparams);

	void update();
	void draw();
	void clean();

protected:
	int m_x;
	int m_y;

	int m_width;
	int m_height;

	std::string m_texture_id;

	int m_current_row;
	int m_current_frame;
};
