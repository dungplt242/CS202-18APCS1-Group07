#include "console.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

namespace Console {
	void gotoXY(int x, int y) {
		COORD pos = { y, x };
		SetConsoleCursorPosition(HOUT, pos);
	}
	void clear_screen()
	{
		system("cls");
	}
	void full_screen()
	{
		HWND hWnd = GetConsoleWindow();
		ShowWindow(hWnd, SW_SHOWMAXIMIZED);
		//system("mode 1000");
		//SetConsoleDisplayMode(HOUT, CONSOLE_FULLSCREEN_MODE, NULL);
	}
	void SetColor(int ForgC)
	{
		ForgC = 15 - ForgC;
		WORD wColor;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		//We use csbi for the wAttributes word.
		if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
		{
			//Mask out all but the background attribute, and add in the forgournd color
			wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
			SetConsoleTextAttribute(hStdOut, wColor);
		}
		return;
	}

	void MakeBackgroundSound(bool is_menu)
	{
		std::string st = "Data/Sound/Background2.wav";
		if (is_menu) st = "Data/Sound/Background.wav";
		PlaySoundA((LPCSTR)(st.c_str()), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP );
	}

	void MakeSound(const char* filename)
	{
		PlaySoundA((LPCSTR)(filename), NULL, SND_FILENAME | SND_ASYNC);
		//Sleep(2000);
		//MakeBackgroundSound();
	}

	
	/*
	Name         | Value
	             |
	Black        |   15
	Blue         |   14
	Green        |   13
	Cyan         |   12
	Red          |   11
	Magenta      |   10
	Brown        |   9
	Light Gray   |   8
	Dark Gray    |   7
	Light Blue   |   6
	Light Green  |   5
	Light Cyan   |   4
	Light Red    |   3
	Light Magenta|   2
	Yellow       |   1
	White        |   0
	*/
}