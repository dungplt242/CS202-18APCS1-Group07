#include "main_system.h"
#include <memory>
#include <iostream>
void Game_module::show_main()
{
	menu.set_pos({ 1, 5 }, { 25, 80 });
	menu.load_menu();
	menu.get_input();
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