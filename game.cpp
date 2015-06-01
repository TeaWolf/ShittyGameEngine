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
		std::clog << "Renderer ceration successful" << std::endl;
	
	// The game has officialy started
	m_running = true;

	std::clog << "Done initializing" << std::endl;

	// Load the cat
	std::clog << "Loading the man asset" << std::endl;
	
	SDL_Surface* temp_surface = SDL_LoadBMP("../assets/frames.bmp");
	m_texture = SDL_CreateTextureFromSurface(m_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	// Set the destination rect to the same values as teh source
	m_dest_rect.x = m_source_rect.x = 0;
	m_dest_rect.y = m_source_rect.y = 0;
	m_dest_rect.w = m_source_rect.w = 104;
	m_dest_rect.h = m_source_rect.h = 156;

	std::clog << "Done loading the man" << std::endl;

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
	// Animate the texture through a straight line
	m_source_rect.x = 104 * int((SDL_GetTicks() / 100) % 6);		
}

// Update m_renderer and present it to the screen
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	
	// Render that shit!
	SDL_RenderCopyEx(m_renderer, m_texture, &m_source_rect, &m_dest_rect, 0, 0, SDL_FLIP_VERTICAL);	

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
