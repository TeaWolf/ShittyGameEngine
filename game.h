// TeaWolf

#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "texture_manager.h"
#include "input_handler.h"
#include "game_state_machine.h"

class SDLGameObject;
class Game
{
public:
	static Game* instance();

	bool init(const char* p_title, int p_xpos, int p_ypos, int p_width, int p_height, bool p_fullscreen);

	void handle_events();
	void update();
	void render();

	void quit();

	void clean();

	SDL_Renderer* get_renderer() {return m_renderer;}
	bool is_running() {return m_running;}

private:
	Game() = default;
	~Game() = default;
	static Game* m_instance;

	bool m_running;	

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
