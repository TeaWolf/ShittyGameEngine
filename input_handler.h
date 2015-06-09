// Teawolf

#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <array>
#include <iostream>

#include "vector_2d.h"

// TODO implement buttons for the joysticks
// TODO implement some kind of joystick class to simplify the button arrays and shit
// TODO implement keyboard input
class InputHandler
{
public:
	static InputHandler* instance();	

	void init_joysticks();
	bool joysticks_initialized() {return m_joysticks_initialized;}

	// stick value must be 0 or 1
	int x_value(int controller, int stick);
	int y_value(int controller, int stick);

	enum MOUSE_BUTTON
	{
		LEFT,
		MIDDLE,
		RIGHT,
		NUM_MOUSE_BUTTONS
	};

	bool get_mouse_button_state(MOUSE_BUTTON button) {return m_mouse_button_states[button];}
	const Vector2D& get_mouse_pos() {return m_mouse_pos;}

	bool got_quit() {return m_got_quit;}

	void update();
	void clean();
	
private:
	InputHandler();
	~InputHandler() = default;
	static InputHandler* m_instance;

	// Handle mouse events
	void on_mouse_button_down(const SDL_Event& event);
	void on_mouse_button_up(const SDL_Event& event);
	void on_mouse_motion(const SDL_Event& event);

	// Handle joystick events
	void on_joystick_axis_move(const SDL_Event& event);

	// TODO maybe a vector in case mouse has more buttons
	// TODO look into SDL_MouseNumbuttons
	// TODO maybe implement a way to have many mice (for touch mostly)
	std::array<bool, NUM_MOUSE_BUTTONS> m_mouse_button_states;
	Vector2D m_mouse_pos;

	std::vector<SDL_Joystick*> m_joysticks;
	bool m_joysticks_initialized;

	std::vector<std::array<Vector2D*, 2>> m_joystick_values;
	static constexpr long m_joystick_dead_zone = 10000;

	bool m_got_quit;
};
