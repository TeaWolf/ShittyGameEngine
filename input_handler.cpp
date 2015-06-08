// Teawolf

#include "input_handler.h"

// The singleton factory function
InputHandler* InputHandler::m_instance = 0;
InputHandler* InputHandler::instance()
{
	if (m_instance == 0) m_instance = new InputHandler;
	return m_instance;
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
		}
	}
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
	}
	m_joysticks.clear();

	std::clog << "All joysticks closed" << std::endl;

	// Free up memory occupied by the singleton instance
	delete m_instance;
	m_instance = 0;
}
