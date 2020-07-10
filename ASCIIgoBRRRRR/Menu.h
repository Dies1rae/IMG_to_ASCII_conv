#pragma once
#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;


//func declar
void hidecursor();
void UNhidecursor();
void man_menu_view();
void help_menu_view();
//display main menu
void man_menu_view() {
	hidecursor();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "***|";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 5);
	cout << "Poltavskiy Nick img conv";
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "***|";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 5);
	cout << "Help menu";
	SetConsoleTextAttribute(hConsole, 7);
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "***|" << "Poltavskiy Nick img conv(1)";
	SetConsoleTextAttribute(hConsole, 7);
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "***|" << "SYNOPSIS:";
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe ";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe [OPTION] ... [DATA]";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe [OPTION] ... [DATA] ... [DATA]";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe [OPTION] ... [DATA] ... [DATA] ... [DATA]";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe [OPTION] ... [DATA] ... [DATA] ... [DATA] ... [DATA]";
	SetConsoleTextAttribute(hConsole, 8);
	cout << endl << "***|" << "DESCRIPTION:";
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe start server by default on .\\in .\\out *.jpg";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe /s(service start) ... %FOLDER IN%";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe /s(service start) ... %FOLDER IN% ... %FOLDER OUT%";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe /s(service start) ... %FOLDER IN% ... %FOLDER OUT% ... %FILE TYPE%";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe /?(help menu)";
	cout << endl << "***|" << "		ASCIIgoBRRRRR.exe /man(man menu)";
	cout << endl << "***|" << "		You may find logs on .\\log.txt file";
	SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 9);
	cout << endl << "...by Dies_Irae" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(hConsole, 7);
	UNhidecursor();
}

void help_menu_view() {
	cout << "	Usage: ASCIIgoBRRRRR.exe /s" << endl << endl;
	cout << "	OPTIONS: " << endl;
	cout << "		s - Start server" << endl;
	cout << "		m - man menu" << endl;
	cout << "		You may find logs on .\\log.txt file" << endl;
	cout << "		? - help menu" << endl << endl;
	cout << "	EXAMPLES: " << endl;
	cout << "		ASCIIgoBRRRRR.exe" << endl;
	cout << "		ASCIIgoBRRRRR.exe /s" << endl;
	cout << "		ASCIIgoBRRRRR.exe /s c:\\Users\\Pidor\\in" << endl;
	cout << "		ASCIIgoBRRRRR.exe /s c:\\Users\\Pidor\\in c:\\Users\\Pidor\\out" << endl;
	cout << "		ASCIIgoBRRRRR.exe /s c:\\Users\\Pidor\\in c:\\Users\\Pidor\\out bmp" << endl << endl;
	cout << "		ASCIIgoBRRRRR.exe /h" << endl;
	cout << "		ASCIIgoBRRRRR.exe /?" << endl;
}

void hidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void UNhidecursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);

}