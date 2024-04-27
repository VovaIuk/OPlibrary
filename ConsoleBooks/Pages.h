#pragma once

#include "./Data.h"
#include "./Page.hpp"
#include "./File.h"

//класс работы с главной страницей
class MainPage : public Page<Data> {
private:

	int indexPage{}; //индекс текущей страницы
	int maxIndex{}; //количество страниц
	void SortedShow(Data& data); //сортировка книг
	void ShowBooks(Data& data);	//вывести книги
	void DeleteBook(Data& data); //удалить книгу
	void Search(Data& data); //найти книгу
	void ShowItemsMenu(vector<string> items, bool zero = false, bool tab = false); //вывести пункты меню
public:
	void Update(Data& data, int index); //вывести страницу с новыми данными
	void Show(Data& data, Context context) override; //вывести страницу
};

//класс работы со страницей по добавлению новой книги
class AddBookPage : public Page<Data> {
public:
	void Show(Data& data, Context context) override; //вывести страницу
};

//классы работы со страницей с диаграммой
class DiagramPage : public Page<Data> {
public:
	void Show(Data& data, Context context) override; //вывести страницу
};

//класс работы со страницей отчета
class ReportPage : public Page<Data> {
public:
	void Show(Data& data, Context context) override; //вывести страницу
};