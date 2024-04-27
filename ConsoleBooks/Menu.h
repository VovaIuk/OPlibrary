#pragma once

#include <map>
#include "./Page.hpp"
#include "./Data.h"

using namespace std;

class Menu {
private:
	std::map<string, Page<Data>*> pages{};
	Data data{};
public:
	void ShowPage(string url, Context context);
	void AddPage(string url, Page<Data>* page);
};