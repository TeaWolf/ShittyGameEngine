// Teawolf

#pragma once

#include <SDL2/SDL.h>
class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;	
	
	virtual void draw();
	virtual void update();

protected:
	int m_x;
	int m_y;
};
