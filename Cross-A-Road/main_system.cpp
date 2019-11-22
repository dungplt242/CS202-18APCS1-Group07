#include "main_system.h"
#include <memory>
#include <iostream>

<<<<<<< Updated upstream
=======
void Game_module::show_main()
{
	menu.set_pos({ 1, 5 }, { 25, 80 });
	menu.load_menu();
	menu.get_input();
}

void Game_module::load_game(std::shared_ptr<Game_state> load_state)
{

}

>>>>>>> Stashed changes
void Game_module::start_game(std::shared_ptr<Game_state> start_state)
{

}