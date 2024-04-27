#pragma once

#include "./Data.h"
#include "./Page.hpp"
#include "./File.h"

//����� ������ � ������� ���������
class MainPage : public Page<Data> {
private:

	int indexPage{}; //������ ������� ��������
	int maxIndex{}; //���������� �������
	void SortedShow(Data& data); //���������� ����
	void ShowBooks(Data& data);	//������� �����
	void DeleteBook(Data& data); //������� �����
	void Search(Data& data); //����� �����
	void ShowItemsMenu(vector<string> items, bool zero = false, bool tab = false); //������� ������ ����
public:
	void Update(Data& data, int index); //������� �������� � ������ �������
	void Show(Data& data, Context context) override; //������� ��������
};

//����� ������ �� ��������� �� ���������� ����� �����
class AddBookPage : public Page<Data> {
public:
	void Show(Data& data, Context context) override; //������� ��������
};

//������ ������ �� ��������� � ����������
class DiagramPage : public Page<Data> {
public:
	void Show(Data& data, Context context) override; //������� ��������
};

//����� ������ �� ��������� ������
class ReportPage : public Page<Data> {
public:
	void Show(Data& data, Context context) override; //������� ��������
};