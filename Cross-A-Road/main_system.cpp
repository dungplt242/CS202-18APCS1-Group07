#include "main_system.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

void Game_module::show_main()
{
	start_game();
}

void Game_module::start_game(std::shared_ptr<Game_state> start_state)
{
	load_game(start_state);

	std::mutex mtx;
	bool is_running = true;

	auto main_game_loop = [&]() {
		while (true) {
			mtx.lock();
			if (!is_running) {
				mtx.unlock();
				return;
			}
			mtx.unlock();
			current_state.do_tick();
			current_state.render();
			std::cout << "Main game loop\n";
			Sleep(1000);
		}
	};

	std::thread t1(main_game_loop);
	// input loop
	while (true) {
		// process input
		char ch;
		ch = _getch();
		std::cout << "Input: " << ch << '\n';
		if (ch == 'a') {
			mtx.lock();
			is_running = false;
			mtx.unlock();
			t1.join();
			break;
		}
	}
}

void Game_module::load_game(std::shared_ptr<Game_state> load_state)
{

}

void Game_module::save_game()
{

}