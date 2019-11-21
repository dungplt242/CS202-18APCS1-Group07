#pragma once

#include "lane.h"
#include <memory>
#include <vector>

class Game_map {
public:

private:
	std::vector<std::unique_ptr<Lane>> lanes;
};

