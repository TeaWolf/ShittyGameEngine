// Teawolf

#include "menu_button.h"

MenuButton::MenuButton(const ObjectLoadParameters* lparams, void (*callback)())
: SDLGameObject{lparams}, m_callback{callback}
{
	m_current_state = MOUSE_OUT;
	m_depressed = false;
} 

void MenuButton::draw()
{
	// In this case the row is equal to the state
	m_current_row = m_current_state;

	SDLGameObject::draw();
}

void MenuButton::update()
{
	Vector2D mouse_pos = InputHandler::instance()->get_mouse_pos();

	// Check for collision with the mouse
	if (
		mouse_pos.get_x() > m_pos.get_x() &&
		mouse_pos.get_x() < m_pos.get_x() + m_width &&
		mouse_pos.get_y() > m_pos.get_y() &&
		mouse_pos.get_y() < m_pos.get_y() + m_height
	)
	{
		m_current_state = BUTTON_STATE::MOUSE_OVER;

		if (InputHandler::instance()->get_mouse_button_state(InputHandler::MOUSE_BUTTON::LEFT))
		{
			m_current_state = BUTTON_STATE::MOUSE_CLICK;
			m_depressed = true;
		}
		else if (m_depressed)
		{
			// Call the callback function on mouse button release
			m_depressed = false;
			m_callback();
		}
	}
	else
		m_current_state = BUTTON_STATE::MOUSE_OUT;
	
		
	SDLGameObject::update();
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
