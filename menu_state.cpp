// Teawolf

#include "menu_state.h"

const std::string MenuState::s_menu_id = "MENU";

void MenuState::update()
{
	for (auto* go : m_game_objects)
		go->update(); 
}

void MenuState::render()
{
	for (auto* go : m_game_objects)
		go->draw();
}

bool MenuState::on_enter()
{
	std::clog << "Entering " << s_menu_id << " state" << std::endl;

	// Load the button's image
	if (!TextureManager::instance()->load("../assets/blue-button.png", "blue_button", Game::instance()->get_renderer()))
		return false;

	// Load the buttons objects
	// TODO fuck that fucking parameter object
	ObjectLoadParameters* lparams = new ObjectLoadParameters(0, 0, 0, 0, 0, 0, 255, 49, "blue_button");
	m_game_objects.push_back(new MenuButton(lparams));
	lparams->y += 150;
	m_game_objects.push_back(new MenuButton(lparams));
	delete lparams;

	return true;
}

bool MenuState::on_exit()
{
	std::clog << "Exiting " << s_menu_id << " state" << std::endl;

	// Clear all game object ressources
	for (auto* go : m_game_objects)
		go->clean();
	m_game_objects.clear();

	// Clear all loaded textures
	TextureManager::instance()->clear_texture("blue_button");

	return true;
}
