// Teawolf

#include "sdl_game_object.h"

// Set up basic class members
SDLGameObject::SDLGameObject(const ObjectLoadParameters* lparams)
: GameObject(lparams), m_pos(lparams->x, lparams->y), m_vel(lparams->vel_x, lparams->vel_y), m_acc(lparams->acc_x, lparams->acc_y)
{
	m_width = lparams->width;
	m_height = lparams->height;

	m_texture_id = lparams->texture_id;

	m_current_row = 0;
	m_current_frame = 0;
}

void SDLGameObject::update()
{
	m_vel += m_acc;
	m_pos += m_vel;
}

void SDLGameObject::draw()
{
	TextureManager::instance()->draw_frame(m_texture_id, m_pos.get_x(), m_pos.get_y(), m_width, m_height, m_current_row, m_current_frame, Game::instance()->get_renderer());
}

void SDLGameObject::clean()
{
	std::clog << "SDLGameObject cleaned up" << std::endl;
}
