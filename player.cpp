// Teawolf

#include "player.h"

Player::Player(const ObjectLoadParameters* lparams)
: SDLGameObject(lparams)
{}

void Player::update()
{
	SDLGameObject::update();

	// Animate the player correctly
	m_current_frame = int((SDL_GetTicks() / 100) % 6);      
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
