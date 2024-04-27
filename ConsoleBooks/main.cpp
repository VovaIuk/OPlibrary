#include <windows.h>
#include "Pages.h"
#include "Menu.h"


int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Menu menu{};
	menu.AddPage("main", new MainPage());
	menu.AddPage("addBook", new AddBookPage());
	menu.AddPage("diagram", new DiagramPage());
	menu.AddPage("report", new ReportPage());
	menu.ShowPage("main", {});
}

//g++ main.cpp ./Data.cpp ./File.cpp ./Menu.cpp ./Pages.cpp