// TeaWolf

#include "game.h"
#include "player.h"
#include "menu_state.h"

constexpr int FPS = 60;
constexpr int DELAY_TIME = 1000.0 / FPS;

int main(int agrc, char**)
{
	// Keep track of frame rate
	Uint32 frame_start, frame_time;

	// Attempt to initialize the game
	if (!Game::instance()->init("The fucking game", 0, 0, 640, 480, false))
	{
		Game::instance()->clean();
		exit(EXIT_FAILURE);
	}

	// Load the initial state
	GameStateMachine::instance()->change_state(new MenuState);
	
	// Run the game loop
	while(Game::instance()->is_running())
	{
		frame_start = SDL_GetTicks();

		Game::instance()->handle_events();
		Game::instance()->update();
		Game::instance()->render();

		// Delay game execution to attain a fixed fps
		frame_time = SDL_GetTicks() - frame_start;
		if (frame_time < DELAY_TIME)
			SDL_Delay(int(DELAY_TIME - frame_time));
	}
	
	Game::instance()->clean();

	return 0;
}
