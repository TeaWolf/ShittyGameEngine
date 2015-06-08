// Teawolf

#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "game.h"

class InputHandler
{
public:
	static InputHandler* instance();	

	void init_joysticks();
	bool joysticks_initialized() {return m_joysticks_initialized;}

	void update();
	void clean();
	
private:
	InputHandler() = default;
	~InputHandler() = default;
	static InputHandler* m_instance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_joysticks_initialized;
};
