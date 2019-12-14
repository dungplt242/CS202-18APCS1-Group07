#include "main_system.h"
#include "Windows.h"
#include <conio.h>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include "console.h"
#include "random.h"

void Game_module::show_main()
{
	Random::Init();
	Console::full_screen();
	while (true) {
		Console::clear_screen();
		menu.set_pos({ 1, 10 }, { 40, 160 });
		menu.load_menu();
		switch (menu.get_input()) {
		case MENU_NAME::NEW_GAME:
			start_new_game();
			break;
		case MENU_NAME::LOAD_GAME:
			// Load game
			break;
		case MENU_NAME::SAVE_GAME:
			// Save game
			break;
		case MENU_NAME::SETTINGS:
			// Settings game
			break;
		case MENU_NAME::QUIT:
			exit(0);
		}
	}
	//start_game();
}

void Game_module::do_menu_choice()
{
}

void Game_module::start_new_game()
{
	auto new_state = std::make_shared<Game_state>();
	new_state->init();
	start_game(new_state);
}

void Game_module::start_game(std::shared_ptr<Game_state> start_state)
{
	current_state = start_state;

	std::mutex mtx;
	bool is_running = true, is_pause = false;

	auto main_game_loop = [&](char &ch) //char input 
	{
		while (true) {
			{
				std::lock_guard<std::mutex> locker(mtx);
				if (!is_running) return;
				if (is_pause) continue;
			}
			current_state->update_and_render();
			current_state->process_input(ch);
			ch = '.';
			//std::cout << "Main game loop\n";
			Sleep(5);
		}
	};

	char ch = '.';

	std::thread t1(main_game_loop, std::ref(ch));
	// input loop
	while (true) {
		// process input
		ch = _getch();
		//std::cout << "Input: " << ch << '\n';
		switch (ch) {
		case 'a':
			mtx.lock();
			is_running = false;
			mtx.unlock();
			t1.join();
			return;
		case 'p':
			// Pause menu
			is_pause ^= 1;
		case ESC: 
			// Pause menu
			is_pause ^= 1;
			break;
		}

	}
}

void Game_module::load_game(std::shared_ptr<Game_state> load_state)
{
	current_state = load_state;
}

void Game_module::save_game()
{

}