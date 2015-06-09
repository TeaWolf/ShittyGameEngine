// Teawolf

#include "play_state.h"

const std::string PlayState::s_play_id = "PLAY";

void PlayState::update()
{}

void PlayState::render()
{}

bool PlayState::on_enter()
{
	std::clog << "Entering " << s_play_id << " state" << std::endl;
	return true;
}

bool PlayState::on_exit()
{
	std::clog << "Exiting " << s_play_id << " state" << std::endl;
	return true;
}
