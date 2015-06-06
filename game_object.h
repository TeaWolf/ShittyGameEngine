// Teawolf

#pragma once

#include <SDL2/SDL.h>

#include "texture_manager.h"
#include "object_load_parameters.h"

class GameObject
{
public:
	GameObject(const ObjectLoadParameters* lparams) {}
	virtual ~GameObject() {}

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;
};
