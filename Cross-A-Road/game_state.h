#pragma once

#include "game_level.h"
#include <memory>
#include <string>

class Game_state : Window {
public:
	void render();
	void do_tick();
	void import_from_file(const std::string& file_path);
	void export_to_file(const std::string& file_path);
private:
	Game_level current_level;
};