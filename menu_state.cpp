// Teawolf

#include "menu_state.h"

const std::string MenuState::s_menu_id = "MENU";

void MenuState::update()
{}

void MenuState::render()
{}

bool MenuState::on_enter()
{
	std::clog << "Entering " << s_menu_id << " state" << std::endl;
	return true;
}

bool MenuState::on_exit()
{
	std::clog << "Exiting " << s_menu_id << " state" << std::endl;
	return true;
}
