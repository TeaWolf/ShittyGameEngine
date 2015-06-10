// Teawolf

#pragma once

#include <iostream>

#include "game_state.h"
#include "game.h"
#include "menu_button.h"

class MenuState : public GameState
{
public:
	~MenuState() = default;

	void update();
	void render();

	bool on_enter();
	bool on_exit();

	std::string get_state_id() const {return s_menu_id;}

protected:
	
	static const std::string s_menu_id;

	std::vector<GameObject*> m_game_objects;
};
