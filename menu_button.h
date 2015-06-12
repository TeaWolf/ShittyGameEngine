// Tewolf

#pragma once

#include "sdl_game_object.h"

class MenuButton : public SDLGameObject
{
public:
	MenuButton(const ObjectLoadParameters* lparams, void (*callback)());

	void draw();
	void update();
	void clean();

private:
	enum BUTTON_STATE
	{
		MOUSE_OVER,
		MOUSE_OUT,
		MOUSE_CLICK
	} m_current_state;

	void (*m_callback)();
	
	bool m_depressed;
};
