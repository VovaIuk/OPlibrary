#ifndef PAGE_HPP
#define PAGE_HPP

#include <functional>
#include "./InterfacePage.h"

using FuncNewPage = std::function<void(string, Context)>;

template <typename T>
class Page : public InterfacePage<T> {
protected:
	FuncNewPage _newPage;
public:
	virtual void Show(T& object, Context context) = 0;
	void SetEvent(FuncNewPage newPage) {
		_newPage = newPage;
	}
};

#endif