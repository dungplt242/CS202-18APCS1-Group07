#pragma once
#include "entity.h"
class Obstacle : public Entity {
public:
<<<<<<< Updated upstream
=======
	Obstacle();
	Obstacle(Point loca, Point direction = {0, 1});
	virtual ~Obstacle();
	virtual std::string type_name() = 0;
	virtual int obs_type() = 0;
	static std::shared_ptr<Obstacle> Create(ObstacleType type, Point loca_obs, Point dir);
	void move();
	bool is_far_enough(Point p, int distance);
	void export_to_file(std::ofstream& fo);
	static std::shared_ptr<Obstacle> obs_import_from_file(std::ifstream &fi);
>>>>>>> Stashed changes

private:
	void do_tick();

	int tick_passed;
};

