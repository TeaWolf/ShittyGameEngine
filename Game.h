// TeaWolf

#pragma once

#include <SDL2/SDL.h>
#include <iostream>

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

	SDL_Texture* m_Texture;
	SDL_Rect m_source_rect;
	SDL_Rect m_dest_rect;
};
