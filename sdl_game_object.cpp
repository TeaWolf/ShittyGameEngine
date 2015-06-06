// Teawolf

#include "sdl_game_object.h"

// Set up basic class members
SDLGameObject::SDLGameObject(const ObjectLoadParameters* lparams)
: GameObject(lparams)
{
	m_x = lparams->x;
	m_y = lparams->y;
	m_width = lparams->width;
	m_height = lparams->height;
	m_texture_id = lparams->texture_id;

	m_current_row = 0;
	m_current_frame = 0;

	// Free up memory
	delete lparams;
}

void SDLGameObject::update()
{}

void SDLGameObject::draw()
{
	TextureManager::instance()->draw_frame(m_texture_id, m_x ,m_y ,m_width, m_height, m_current_row, m_current_frame, Game::instance()->get_renderer());
}

void SDLGameObject::clean()
{
	std::clog << "SDLGameObject cleaned up" << std::endl;

}
