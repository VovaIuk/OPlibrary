#pragma once

#include <string>
#include "Data.h"
using namespace std;
//����� ������ � ������
class FileBooks {
public:
	string path{};

	FileBooks();
	FileBooks(string path);
	//������ ����� �����
	void Write(Book book);
	//������ ������
	void WriteAll(const Data* data);
	//��������� ������
	Data* ReadAll();
	//������� ����� �� �������
	void DeleteBook(int id);
	//������� ����� �� ��������
	void DeleteBook(Book book);
};
