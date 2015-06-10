// Teawolf

#pragma once

#include <iostream>
#include <vector>

#include "game_state.h"

class GameStateMachine
{
public:
	static GameStateMachine* instance();

	void push_state(GameState* state);
	void pop_state();
	void change_state(GameState* state);

	void update();
	void render();

	void clean();

private:
	GameStateMachine() = default;
	~GameStateMachine() = default;
	static GameStateMachine* s_instance;

	std::vector<GameState*> m_game_states;
};
