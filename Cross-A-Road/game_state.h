#pragma once

#include "game_level.h"
#include <memory>
#include <string>

class Game_state : Window {
public:
	Game_state();
	void render();
	void do_tick();
	void import_from_file(const std::string& file_path);
	void export_to_file(const std::string& file_path);
	void process_input(const char &ch);
private:
	std::shared_ptr<Game_level> current_level = nullptr;
};