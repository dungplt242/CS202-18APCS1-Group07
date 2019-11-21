#pragma once

#include "game_level.h"
#include <memory>
#include <string>

class Game_state {
public:
	void import_from_file(const std::string& file_path);
	void export_to_file(const std::string& file_path);
private:
	Game_level current_level;
};