// TeaWolf

#include "Game.h"

// The singleton instance function
Game* Game::m_instance = 0;
Game* Game::instance()
{
	if (m_instance == 0) m_instance = new Game;
	return m_instance;
}

// Initialize SDL, create a window, attach a renderer to it, and set m_running to true
// Returns true if init was successful
bool Game::init(const char* p_title, int p_xpos, int p_ypos, int p_width, int p_height, bool p_fullscreen)
{
	// TODO maybe some better debug output ?
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

	// Initialize input methods
	// TODO make this somehow optional
	InputHandler::instance()->init_joysticks();

	// The game has officialy started
	m_running = true;

	std::clog << "Initialization successful" << std::endl;
	return true;
}

// Query events and update game objects
void Game::handle_events()
{
	InputHandler::instance()->update();
	if (InputHandler::instance()->got_quit())
		quit();
}

// Do Regular game update (like movement)
void Game::update()
{
//	for (GameObject* go : m_game_objects)
//		go->update();
	GameStateMachine::instance()->update();
}

// Update m_renderer and present it to the screen
void Game::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);
	SDL_RenderClear(m_renderer);

//	for (GameObject* go : m_game_objects)
//		go->draw();
	GameStateMachine::instance()->render();

	SDL_RenderPresent(m_renderer);
}

// Meerely quit the game, but do not clear ressources
void Game::quit()
{
	std::clog << "Quitting game..." << std::endl;
	m_running = false;
}

// Clean up all game ressources
void Game::clean()
{
	// TODO get rid of all the game objects once the game is finished
	std::clog << "Cleannig up..." << std::endl;

	// Destroy all input ressources
	InputHandler::instance()->clean();

	// Destroy all states
	GameStateMachine::instance()->clean();

	// Destroy the TextureManager and all it's textures to prevent all hell breaking loose
	TextureManager::instance()->clean();

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
	
	// Free up memory
	delete m_instance;
	Game::m_instance = 0;

	std::clog << "Done cleaning up" << std::endl;
}
