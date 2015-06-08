// Teawolf

#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <array>
#include <iostream>

#include "vector_2d.h"

class InputHandler
{
public:
	static InputHandler* instance();	

	void init_joysticks();
	bool joysticks_initialized() {return m_joysticks_initialized;}

	// stick value must be 0 or 1
	int x_value(int controller, int stick);
	int y_value(int controller, int stick);

	bool got_quit() {return m_got_quit;}

	void update();
	void clean();
	
private:
	InputHandler() = default;
	~InputHandler() = default;
	static InputHandler* m_instance;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_joysticks_initialized;

	std::vector<std::array<Vector2D*, 2>> m_joystick_values;
	static constexpr unsigned long m_joystick_dead_zone = 10000;

	bool m_got_quit;
};
