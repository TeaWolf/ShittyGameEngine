// Teawolf

#pragma once

#include <iostream>

#include "game_state.h"

class PlayState : public GameState
{
public:
	~PlayState() = default;

	void update();
	void render();

	bool on_enter();
	bool on_exit();

	std::string get_state_id() const {return s_play_id;}

private:
	static const std::string s_play_id;
};
