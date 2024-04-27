#include "Menu.h"
#include "./Data.h"

using namespace std;

void Menu::ShowPage(string url, Context context) {
    pages[url]->Show(data, context);
}

void Menu::AddPage(std::string url, Page<Data>* page) {
    pages[url] = page;
    FuncNewPage func = std::bind(&Menu::ShowPage, this,
        std::placeholders::_1, std::placeholders::_2);
    pages[url]->SetEvent(func);
}