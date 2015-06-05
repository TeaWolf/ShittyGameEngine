// TeaWolf

#include "Game.h"

// Initialize SDL, create a window, attach a renderer to it, and set m_running to true
// Returns true if init was successful
bool Game::init(const char* p_title, int p_xpos, int p_ypos, int p_width, int p_height, bool p_fullscreen)
{
	std::clog << "Initializing..." << std::endl;

	// General SDL initialisation
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
		std::clog << "SDL initialisation successful" << std::endl;
	
	// Window creation
	m_window = SDL_CreateWindow(p_title, p_xpos, p_ypos, p_width, p_height, p_fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
	if (!m_window)
	{
		std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
		std::clog << "Window creation successful" << std::endl;

	// Renderer creation
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (!m_renderer)
	{
		std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		return false;
	}
	else
		std::clog << "Renderer creation successful" << std::endl;
	
	// TODO something a little better than this (like loading wit the objects
	std::clog << "Loading images..." << std::endl;

	if (TextureManager::instance() -> load("../assets/frames_alpha.png", "man", m_renderer) == false)
		return false;

	std::clog << "Done loading images" << std::endl;
	
	// TODO fuck this
	std::clog << "Loading GameObject and Player test" << std::endl;
	m_obj.init(0, 100, 104, 156, "man");
	m_player.init(0, 200, 104, 156, "man");
	std::clog << "Done loading test obejcts" << std::endl;

	// The game has officialy started
	m_running = true;

	return true;
}

// Query events and update game objects
void Game::handle_events()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		}
	}
}

// Do Regular game update (like movement)
void Game::update()
{
	m_obj.update();
	m_player.update();
}

// Update m_renderer and present it to the screen
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);
	SDL_RenderClear(m_renderer);

	m_obj.draw(m_renderer);
	m_player.draw(m_renderer);

	SDL_RenderPresent(m_renderer);
}

// Clean up all game ressources
void Game::clean()
{
	std::clog << "Cleannig up..." << std::endl;

	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		std::clog << "Renderer destroyed" << std::endl;
	}

	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		std::clog << "Window destroyed" << std::endl;
	}

	SDL_Quit();
	
	std::clog << "Done cleaning up" << std::endl;
}
