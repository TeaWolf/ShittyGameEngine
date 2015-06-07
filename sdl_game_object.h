// Teawolf

#pragma once

#include "game_object.h"
#include "game.h"
#include "vector_2d.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const ObjectLoadParameters* lparams);

	void update();
	void draw();
	void clean();

protected:
	Vector2D m_pos;
	Vector2D m_vel;
	Vector2D m_acc;

	int m_width;
	int m_height;

	std::string m_texture_id;

	int m_current_row;
	int m_current_frame;
};
