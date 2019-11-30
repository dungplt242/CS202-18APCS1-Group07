#include "game_state.h"

void Game_state::render()
{
	if (current_level == nullptr) {
		set_pos({ 1, 1 }, { 44, 150 });
		Console::clear_screen();
		draw_rect('=');
		current_level = std::make_shared<Game_level>();
	}
	current_level ->render();

}

void Game_state::do_tick()
{

}

void Game_state::import_from_file(const std::string& file_path)
{

}

void Game_state::export_to_file(const std::string& file_path)
{
}

void Game_state::process_input(const char & ch)
{
	current_level->process_input(ch);
}
