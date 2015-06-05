// TeaWolf

#include "game.h"


int main(int agrc, char**)
{
	Game game;

	// Attempt to initialize the game
	if (!game.init("The fucking game", 0, 0, 640, 480, false))
	{
		game.clean();
		exit(EXIT_FAILURE);
	}
	
	// Run the game loop
	while(game.is_running())
	{
		game.handle_events();
		game.update();
		game.render();
		
		SDL_Delay(10);
	}
	
	game.clean();

	return 0;
}
