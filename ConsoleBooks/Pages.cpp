#include "Pages.h"
#include <algorithm>
#include <fstream>

bool isNumeric(string str) {
	if(str.length() >= 9 or str.length()==0){
		return false;
	}
	for (char c : str)
		if (!isdigit(c))
			return false;
	return true;
}

int GetInt() {
	string str{};
	cout << "������� �����: ";
	getline(std::cin, str);
	while (!isNumeric(str)){
		cout << "������������ ����: ";
		getline(std::cin, str);
	}
	return stoi(str);
}

int GetDiapasonInt(int min, int max){
	int num = GetInt();
	while ((min > num) or (num > max)){
		cout << "�������� ��������\n";
		num = GetInt();
	}
	return num;
}

void MainPage::ShowItemsMenu(vector<string>items, bool zero, bool tab){
	for(int i = 0; i < items.size(); i++){
		if(tab)
			cout << '\t';
		cout << i+int(!zero) << ") " << items[i] << '\n';
	}
}

void MainPage::ShowBooks(Data &data){
	for(int i = 0; i < 40; i++)
		cout << "-";
	cout << '\n';
	int count = 4;
	if(indexPage*count >= data.books.size()){
		cout << "�������� �����\n";
	}
	for(int i = (indexPage)*count; (i < (indexPage+1)*count) & (i < data.books.size()); i++){
		Book book = data.books[i];
		cout << "����� �" << i+1<<":\n";
		cout << "\t��������: " << book.name << "\n"
		<< "\t�����: " << book.nameAuthor << "\n"
		<< "\t����: " << book.genre << "\n"
		<< "\t������: " << book.format << "\n"
		<< "\t����: " << book.language << "\n";
		if(book.format == Format::Text){
			cout << "\t����� ��������: ";
		}
		if(book.format == Format::Audio){
			cout << "\t����� �������: ";
		}
		if(book.format == Format::Podcast){
			cout << "\t������ �����: ";
		}
		cout << book.secondAuthor << "\n"
		 << "\t����: " << book.price << "\n";
	}
	this->maxIndex = (data.books.size()+count-1)/count;
	for(int i = 0; i < 40; i++)
		cout << "-";
	if(maxIndex!=0){
		cout << "\n�������� " << indexPage+1 << " �� " << maxIndex<<"\n";
		for(int i = 0; i < 40; i++)
			cout << "-";
	}
	cout << "\n\n";
}

void MainPage::SortedShow(Data &data){

	auto compareGenre = [](const Book& book1, const Book& book2) {
        return book1.genre < book2.genre;
    };

    auto compareAuthor = [](const Book& book1, const Book& book2) {
        return book1.nameAuthor < book2.nameAuthor;
    };

    auto compareFormat = [](const Book& book1, const Book& book2) {
        return book1.format < book2.format;
    };

    auto compareLanguage = [](const Book& book1, const Book& book2) {
        return book1.language < book2.language;
    };

	cout << "����������� ��:\n"
	<< "\t1) �����\n" << "\t2) ������\n" << "\t3) �������\n" << "\t4) �����\n";
	int x = GetInt();
	if(x==1){
		sort(data.books.begin(), data.books.end(), compareGenre);
	}
	else if(x==2){
		sort(data.books.begin(), data.books.end(), compareAuthor);
	}
	else if(x==3){
		sort(data.books.begin(), data.books.end(), compareFormat);
	}
	else if (x==4){
		sort(data.books.begin(), data.books.end(), compareLanguage);
	}
	else{
		Update(data, indexPage);
		return;
	}
	Update(data, 0);
	
}

void MainPage::Update(Data& data, int index){
	this->indexPage = index;
	system("cls");
	Show(data, {});
}

void MainPage::DeleteBook(Data& data){
	cout << "�������� ������ �����\n";
	int index = GetInt()-1;
	if(data.books.size() <= index){
		return;
	}
	Book book = data.books[index];
	data.books.erase(data.books.begin()+index);
	FileBooks file = FileBooks("file.txt");
	file.DeleteBook(book);
}

void MainPage::Search(Data& data){
	Data newData{};
	cout << "������ ��:\n";
	ShowItemsMenu({"������", "��������", "������ ��������", "����"}, false, true);
	int x{};
	x = GetInt();
	string value{};
	if((0 < x) && (x <= 3)){
		cout << "������� �������� ����: ";
		getline(cin, value);
	}
	else if(x==4){
		int vPrice = GetInt();
		value = to_string(vPrice);
	}
	else{
		Update(data, indexPage);
		return;
	}
	for(int i = 0; i < data.books.size(); i++){
		if(((x==1) and (data.books[i].nameAuthor == value)) or ((x==2) and (data.books[i].name == value))
		|| ((x==3) and (data.books[i].secondAuthor == value)) || ((x==4) and (to_string(data.books[i].price) == value))){
				newData.books.push_back(data.books[i]);
			}
	}
	data = newData;
	Update(data, 0);
}

void MainPage::Show(Data& data, Context context) {
	system("cls");
	ShowBooks(data);
	ShowItemsMenu({"�����",
	"�����", 
	"�����", 
	"������� �����", 
	"�������� �����",
	"�����", 
	"����������", 
	"�������� ��������� �� �������", 
	"����� �� ������",
	"��������� ������ �� �����"}, true);
	int x = GetInt();
	if(x==0)
		return;
	else if (x == 1){
		if(indexPage > 0)
			Update(data, indexPage-1);
		else
			Update(data, indexPage);
	}
	else if(x==2){
		if(indexPage<maxIndex-1)
			Update(data, indexPage+1);
		else
			Update(data, indexPage);
	}
	else if(x==3){
		DeleteBook(data);
		Update(data, indexPage);
	}
	else if(x == 4){
		_newPage("addBook", {});
	}
	else if(x == 5){
		Search(data);
	}
	else if(x==6){
		SortedShow(data);
	}
	else if(x==7){
		_newPage("diagram", {});
	}
	else if(x==8){
		_newPage("report", {});
	}
	else if(x==9){
		FileBooks file = FileBooks("file.txt");
		Data* newData=file.ReadAll();
		data = *newData;
		delete newData;
		Update(data, 0);
	}
	else{
		Update(data, indexPage);
	}
}

void AddBookPage::Show(Data& data, Context context){
	system("cls");
	FileBooks fileBooks = FileBooks("file.txt");
	Book book{};
	cout << "�������: \n";
	cout << "\t��������: ";
	getline(cin, book.name);
	cout << "\t�����: ";
	getline(cin, book.nameAuthor);
	cout << "\t����: ";
	getline(cin, book.genre);
	cout << "\t������: \n" << "\t\t1) �����\n\t\t2) �������\n\t\t3) �����\n";	
	int format = GetDiapasonInt(1, 3);
	book.format = static_cast<Format>(format-1);
	cout << "\t����: \n" << "\t\t1) ����������\n\t\t2) ��������\n\t\t3) �������\n";
	int language = GetDiapasonInt(1, 3);
	book.language = static_cast<Language>(language-1);
	if(book.format == Format::Audio)
		cout << "\t����� �������: ";
	else if(book.format == Format::Text)
		cout << "\t����� ��������: ";
	else if(book.format == Format::Podcast)
		cout << "\t������ �����: ";
	getline(cin, book.secondAuthor);
	cout << "\t����\n";
	book.price = GetInt();
	data.books.push_back(book);
	fileBooks.Write(book);
	_newPage("main", {});
}

void DiagramPage::Show(Data& data, Context context){
	system("cls");
	cout << "�������� ��������� �� �������:\n";
	int audio{}, text{}, podcast{};
	for(int i = 0; i < data.books.size(); i++){
		if(data.books[i].format == Format::Audio)
			audio++;
		else if(data.books[i].format == Format::Text)
			text++;
		else if(data.books[i].format == Format::Podcast)
			podcast++;
	}
	cout << "\t�����: " << audio << "\n\t�����: " << text << "\n\t�������: " << podcast << '\n';
	system("pause");
	_newPage("main", {});
}

void ReportPage::Show(Data& data, Context context){
	system("cls");
	cout << "������� ��� ������: ";
	string nameAuthor{};
	getline(cin, nameAuthor);
	vector<Book> books{};
	for(int i = 0; i < data.books.size(); i++){
		if(data.books[i].nameAuthor == nameAuthor){
			books.push_back(data.books[i]);
		}
	}
	system("cls");
	ofstream fout("report.txt");
	fout << "�����\n";
	cout << "����� ���������� � ����� \"report.txt\"\n";
	cout << "���������� ���� ������ " << nameAuthor << " = " << books.size() << '\n';
	fout << "���������� ���� ������ " << nameAuthor << " = " << books.size() << '\n';
	for(int i = 0; i < books.size(); i++){
		cout << "�" << i+1 << ": " << books[i].name << '\n';
		fout << "�" << i+1 << ": " << books[i].name << '\n';
	}
	fout.close();
	system("pause");
	_newPage("main", {});
}


