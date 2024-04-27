#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum class Format {Audio=0,	Podcast=1, Text=2};
ostream& operator <<(ostream& os, const Format format);

enum class Language { English=0, German=1, Rssian=2};
ostream& operator <<(ostream& os, const Language language);

class Book {
public:
	string genre{};
	string nameAuthor{};
	string name{};
	Format format{};
	Language language{};
	string secondAuthor{};
	int price{};
};

bool operator==(Book book1, Book book2);

class Data {
public:
	vector<Book> books{};
};