// Teawolf

#pragma once

#include <iostream>

#include "menu_state.h"

class PlayState : public GameState
{
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();

	std::string get_state_id() const {return s_play_id;}

private:
	static const std::string s_play_id;
};
