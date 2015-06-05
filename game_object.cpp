// Teawolf`

#include "game_object.h"

// Set up basic class members
void GameObject::init(int x, int y, int width, int height, const std::string& texture_id)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_texture_id = texture_id;

	m_current_row = 0;
	m_current_frame = 0;
}

// Update the GameObject's variables
void GameObject::update()
{
	m_x += 1;
}

// Execute basic rendering
void GameObject::draw(SDL_Renderer* renderer)
{
	TextureManager::instance()->draw_frame(m_texture_id, m_x, m_y, m_width, m_height, m_current_row, m_current_frame, renderer);
}

void GameObject::clean()
{
	std::clog << "Object destroyed" << std::endl;
}
