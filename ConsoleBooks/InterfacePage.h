#pragma once

#include <map>
#include <string>

using namespace std;
using Context = map<string, string>;

template <typename T>
class InterfacePage {
public:
	virtual void Show(T& object, Context context) = 0;
};
