#include "game_state.h"

Game_state::Game_state()
{
	set_pos({ 1, 1 }, { 44, 150 });
	Console::clear_screen();
	draw_rect('=');
	current_level = std::make_shared<Game_level>();
}

void Game_state::level_up()
{
	current_level = std::make_shared<Game_level>(current_level->get_level_id() + 1);
	// Message 
}

void Game_state::play_again()
{
	current_level = std::make_shared<Game_level>(current_level->get_level_id());
	// Message 
}

void Game_state::update_and_render()
{
	current_level->update_and_render();
	if (current_level->is_finished()) level_up(); //win
	if (current_level->check_collide()) play_again(); //lose
}

void Game_state::import_from_file(const std::string& file_path)
{
	std::ifstream fi;
	fi.open(file_path); 
	current_level->import_from_file(fi);
	fi.close();
}

void Game_state::export_to_file(const std::string& file_path)
{
	std::ofstream fo;
	fo.open(file_path); 
	current_level->export_to_file(fo);
	fo.close();
}

void Game_state::process_input(const char & ch)
{
	current_level->process_input(ch);
}
