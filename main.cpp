// TeaWolf

#include "game.h"
#include "player.h"

int main(int agrc, char**)
{
	// Attempt to initialize the game
	if (!Game::instance()->init("The fucking game", 0, 0, 640, 480, false))
	{
		Game::instance()->clean();
		exit(EXIT_FAILURE);
	}

	// Add the player object
	Game::instance()->add_object(new Player(new ObjectLoadParameters(0, 150, 104, 158, "man")));
	
	// Run the game loop
	while(Game::instance()->is_running())
	{
		Game::instance()->handle_events();
		Game::instance()->update();
		Game::instance()->render();
		
		SDL_Delay(10);
	}
	
	Game::instance()->clean();

	return 0;
}
