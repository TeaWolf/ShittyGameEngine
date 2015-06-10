// Teawolf

#include "game_state_machine.h"

// Singleton factory
GameStateMachine* GameStateMachine::s_instance = 0;
GameStateMachine* GameStateMachine::instance()
{
	if (s_instance == 0) s_instance = new GameStateMachine;
	return s_instance;
}

// Add a state on top of the other ones
void GameStateMachine::push_state(GameState* state)
{
	// Make sure to not push the same state a second time
	if (!m_game_states.empty())
		if (m_game_states.back()->get_state_id() == state->get_state_id())
		{
			std::cerr << "Tried to push state " << state->get_state_id() << " twice" << std::endl;
			return;
		}

	// Add it to the states
	m_game_states.push_back(state);
	m_game_states.back()->on_enter();
	
	std::clog << "Pushed state " << state->get_state_id() << std::endl;
}

// Remove the last state that was added
void GameStateMachine::pop_state()
{
	if (m_game_states.empty())
		std::cerr << "Tried to pop state when there are none" << std::endl;
	else
		if (!m_game_states.back()->on_exit())
			std::cerr << m_game_states.back()->get_state_id() << " on_exit() failed" << std::endl;
		else
		{
			std::clog << "Poping " << m_game_states.back()->get_state_id() << "..." << std::endl;

			delete m_game_states.back();
			m_game_states.pop_back();
		}
}	

// Change the game state, erasing the previous one
void GameStateMachine::change_state(GameState* state)
{
	if (!m_game_states.empty())
	{
		// Do not change to the same state
		if (m_game_states.back()->get_state_id() == state->get_state_id())
		{
			std::cerr << "Tried to change to the same state" << std::endl;
			return;
		}

		std::clog << "Changing state from " << m_game_states.back()->get_state_id() << " to " << state->get_state_id() << "..." << std::endl;

		pop_state();
	}

	push_state(state);
}		
		
void GameStateMachine::update()
{
	if (!m_game_states.empty())
		m_game_states.back()->update();
}

void GameStateMachine::render()
{
	if (!m_game_states.empty())
		m_game_states.back()->render();
}

// Free up ressources
void GameStateMachine::clean()
{
	// Clean up all individual states
	for (int i{0}; i < m_game_states.size(); i++)
		pop_state();

	// Destroy the current instance
	delete s_instance;
	s_instance = 0;
}
