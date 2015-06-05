// Teawolf

#include "player.h"

void Player::init(int x, int y, int width, int height, const std::string& texture_id)
{
	GameObject::init(x, y, width, height, texture_id);
}

void Player::update()
{
	GameObject::update();
	m_y += 1;
}

void Player::draw(SDL_Renderer* renderer)
{
	GameObject::draw(renderer);
}

void Player::clean()
{
	GameObject::clean();
	std::clog << "Player destroyed" << std::endl;
}
