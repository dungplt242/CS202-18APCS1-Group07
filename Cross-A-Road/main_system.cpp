#include "main_system.h"
#include <memory>

void Game_module::show_main()
{

}

void Game_module::start_game(std::shared_ptr<Game_state> start_state)
{
	load_game(start_state);

	// the main game loop
	while (true) {
		// process input

		// update
		current_state.do_tick();
		// render
		current_state.render();
		break;
	}
}

void Game_module::load_game(std::shared_ptr<Game_state> load_state)
{

}

void Game_module::save_game()
{

}