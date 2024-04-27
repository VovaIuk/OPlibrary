#pragma once

#include <string>
#include "Data.h"
using namespace std;
//класс работы с файлом
class FileBooks {
public:
	string path{};

	FileBooks();
	FileBooks(string path);
	//запись одной книги
	void Write(Book book);
	//запись данных
	void WriteAll(const Data* data);
	//прочитать данные
	Data* ReadAll();
	//удалить книгу по индексу
	void DeleteBook(int id);
	//удалить книгу по значению
	void DeleteBook(Book book);
};
