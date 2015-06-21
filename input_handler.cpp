// Teawolf

#include "input_handler.h"

// The singleton factory function
InputHandler* InputHandler::m_instance = 0;
InputHandler* InputHandler::instance()
{
	if (m_instance == 0) m_instance = new InputHandler;
	return m_instance;
}

InputHandler::InputHandler()
{
	// Iniyialize the mouse button values
	// See if SDL has a SDL_MouseNumButtons or something
	for (int i{0}; i < MOUSE_BUTTON::NUM_MOUSE_BUTTONS; i++)
		m_mouse_button_states[i] = false;

	// TODO maybe initialize the mouse position too
	m_joysticks_initialized = false;
	m_got_quit = false;
}

// Initialize joystick sub stystem and load plugged in joysticks
void InputHandler::init_joysticks()
{
	// Initialize sub system if nescessary
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		std::clog << "Initialized joystick subsystem" << std::endl;
	}
	
	// Load joysticks if there are any
	if (SDL_NumJoysticks() > 0)
	{
		for (int i{0}; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* stick = SDL_JoystickOpen(i);
			if (stick)
			{
				m_joysticks.push_back(stick);
				m_joystick_values.push_back(std::array<Vector2D*, 2>{{new Vector2D{0, 0}, new Vector2D{0, 0}}});
				std::clog << "Joystick opened: " << SDL_JoystickNameForIndex(i) << std::endl;
			}
			else
				std::cerr << "SDL_JoystickOpen error: " << SDL_GetError() << std::endl;
		}

		SDL_JoystickEventState(SDL_ENABLE);
		m_joysticks_initialized = true;
		
		std::clog << "Initialized " << m_joysticks.size() << " joysticks" << std::endl;
	}
	else
		m_joysticks_initialized = false;
}

// stick must be 0 or 1
int InputHandler::x_value(int controller, int stick)
{
	if (m_joystick_values.size() > 0)	
		return m_joystick_values[controller][stick]->get_x();
	return 0;
}
int InputHandler::y_value(int controller, int stick)
{
	if (m_joystick_values.size() > 0)
		return m_joystick_values[controller][stick]->get_y();
	return 0;
}
		

// Get info from the events
void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			m_got_quit = true;
		break;

		case SDL_MOUSEBUTTONDOWN:
			on_mouse_button_down(event);
		break;
		case SDL_MOUSEBUTTONUP:
			on_mouse_button_up(event);
		break;
		case SDL_MOUSEMOTION:
			on_mouse_motion(event);
		break;
		
		case SDL_JOYAXISMOTION:
			on_joystick_axis_move(event);
		break;
		}
	}
}

void InputHandler::on_mouse_button_down(const SDL_Event& event)
{
	switch(event.button.button)
	{
	case SDL_BUTTON_LEFT:
		m_mouse_button_states[MOUSE_BUTTON::LEFT] = true;
	break;
	case SDL_BUTTON_MIDDLE:
		m_mouse_button_states[MOUSE_BUTTON::MIDDLE] = true;
	break;
	case SDL_BUTTON_RIGHT:
		m_mouse_button_states[MOUSE_BUTTON::RIGHT] = true;
	break;
	}
}

void InputHandler::on_mouse_button_up(const SDL_Event& event)
{
	switch(event.button.button)
	{
	case SDL_BUTTON_LEFT:
		m_mouse_button_states[MOUSE_BUTTON::LEFT] = false;
	break;
	case SDL_BUTTON_MIDDLE:
		m_mouse_button_states[MOUSE_BUTTON::MIDDLE] = false;
	break;
	case SDL_BUTTON_RIGHT:
		m_mouse_button_states[MOUSE_BUTTON::RIGHT] = false;
	break;
	}
}

void InputHandler::on_mouse_motion(const SDL_Event& event)
{
	m_mouse_pos.set_x(event.motion.x);
	m_mouse_pos.set_y(event.motion.y);
}

void InputHandler::on_joystick_axis_move(const SDL_Event& event)
{
			int which_cont = event.jaxis.which;

			// TODO please find a better way to write this, this is shit
			// Playstation 3 schematic
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > m_joystick_dead_zone)
					m_joystick_values[which_cont][0]->set_x(1);
				else if (event.jaxis.value < (-m_joystick_dead_zone))
					m_joystick_values[which_cont][0]->set_x(-1);
				else m_joystick_values[which_cont][0]->set_x(0);
			}
			
			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > m_joystick_dead_zone)
					m_joystick_values[which_cont][0]->set_y(1);
				else if (event.jaxis.value < (-m_joystick_dead_zone))
					m_joystick_values[which_cont][0]->set_y(-1);
				else m_joystick_values[which_cont][0]->set_y(0);
			}

			// TODO I've only done the first axis here
}

void InputHandler::clean()
{
	// Close all opened joysticks
	if (m_joysticks_initialized)
	{
		for (auto* stick : m_joysticks)
		{
			if (SDL_JoystickGetAttached(stick))
				SDL_JoystickClose(stick);
		}

		m_joysticks.clear();

		std::clog << "All joysticks closed" << std::endl;
	}

	// Free up memory occupied by the singleton instance
	delete m_instance;
	m_instance = 0;
}
