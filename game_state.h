// Teawolf

#pragma once

#include <string>

class GameState
{
public:
	GameState() = default;
	virtual ~GameState() = default;

	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool on_enter() = 0;
	virtual bool on_exit() = 0;

	virtual std::string get_state_id() const = 0;
};
