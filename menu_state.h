// Teawolf

#pragma once

#include <iostream>

#include "game_state.h"

class MenuState : public GameState
{
public:
	void update();
	void render();

	bool on_enter();
	bool on_exit();

	std::string get_state_id() const {return s_menu_id;}

private:
	
	static const std::string s_menu_id;
};
