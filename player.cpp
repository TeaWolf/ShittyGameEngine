// Teawolf

#include "player.h"

Player::Player(const ObjectLoadParameters* lparams)
: SDLGameObject(lparams)
{}

void Player::handle_events()
{
	m_vel.set_x(0.5 * -InputHandler::instance()->x_value(0, 0) * 2);
	m_vel.set_y(0.5 * -InputHandler::instance()->y_value(0, 0) * 2);
}

void Player::update()
{
	m_vel.set_x(0);
	m_vel.set_y(0);

	handle_events();

	// Animate the player correctly
	m_current_frame = int((SDL_GetTicks() / 100) % 6);      

	SDLGameObject::update();
}

void Player::draw(SDL_Renderer* renderer)
{
	SDLGameObject::draw();
}

void Player::clean()
{
	SDLGameObject::clean();
	std::clog << "Player object cleaned up" << std::endl;
}
