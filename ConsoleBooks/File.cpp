#include "File.h"
#include <fstream>

FileBooks::FileBooks(string path){
	this->path = path;
}

void FileBooks::WriteAll(const Data* data) {
    ofstream fout(path);
	for (auto &book : data->books) {
		fout << book.genre << '\n';
		fout << book.nameAuthor << '\n';
		fout << book.name << '\n';
		fout << static_cast<int>(book.format) << '\n';
		fout << static_cast<int>(book.language) << '\n';
		fout << book.secondAuthor << '\n';
		fout << book.price << '\n';
	}
	fout.close();
}

Data* FileBooks::ReadAll() {
	Data* data = new Data();
	ifstream fin(path);
	string line;
	while (getline(fin, line)) {
		Book book;
		book.genre = line;
		getline(fin, line);
		book.nameAuthor = line;
		getline(fin, line);
		book.name = line;
		int formatInt = 0;
		getline(fin, line);
		formatInt = stoi(line);
		book.format = static_cast<Format>(formatInt);
		int languageInt = 0;
		getline(fin, line);
		languageInt = stoi(line);
		book.language = static_cast<Language>(languageInt);
		getline(fin, line);
		book.secondAuthor = line;
		getline(fin, line);
		book.price = stoi(line);
		data->books.push_back(book);
	}
	fin.close();
	return data;
}

void FileBooks::Write(Book book) {
    Data* data = ReadAll();
    data->books.push_back(book);
    WriteAll(data);
    delete data;
}

void FileBooks::DeleteBook(int index) {
    Data* data = ReadAll();
    if (index < 0 || index >= data->books.size()) {
        delete data;
        return;
    }
    data->books.erase(data->books.begin() + index);
    WriteAll(data);
    delete data;
}

void FileBooks::DeleteBook(Book book) {
    Data* data = ReadAll();
    for (int i = 0; i < data->books.size(); i++) {
        if (book == data->books[i]) {
            DeleteBook(i);
            break;
        }
    }
    delete data;
}