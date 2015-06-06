// TeaWolf

#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#include "texture_manager.h"
#include "game_object.h"

class SDLGameObject;
class Game
{
public:
	static Game* instance();

	bool init(const char* p_title, int p_xpos, int p_ypos, int p_width, int p_height, bool p_fullscreen);

	void add_object(GameObject* go);

	void handle_events();
	void update();
	void render();

	void clean();

	SDL_Renderer* get_renderer() {return m_renderer;}
	bool is_running() {return m_running;}

protected:
	Game() = default;
	~Game() = default;
	static Game* m_instance;

	bool m_running;	

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	std::vector<GameObject*> m_game_objects;
};
