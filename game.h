// TeaWolf

#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include "texture_manager.h"

class Game
{
public:
	Game() = default; 
	virtual ~Game() = default;
	
	bool init(const char* p_title, int p_xpos, int p_ypos, int p_width, int p_height, bool p_fullscreen);

	void handle_events();
	void update();
	void render();

	void clean();

	bool is_running() {return m_running;}

protected:
	bool m_running;	

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	int m_current_frame;
};
