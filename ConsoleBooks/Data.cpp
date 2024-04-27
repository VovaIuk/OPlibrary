#include "Data.h"

ostream& operator <<(ostream& os, const Format format) {
	if (Format::Text == format)
		os << "�����";
	if (Format::Audio == format)
		os << "�����";
	if (Format::Podcast == format)
		os << "�������";
	return os;
}

ostream& operator <<(ostream& os, const Language language) {
	if (Language::English == language)
		os << "����������";
	if (Language::German == language)
		os << "��������";
	if (Language::Rssian == language)
		os << "�������";
	return os;
}

bool operator==(Book book1, Book book2) {
	return book1.genre == book2.genre
		&& book1.nameAuthor == book2.nameAuthor
		&& book1.name == book2.name
		&& book1.format == book2.format
		&& book1.language == book2.language
		&& book1.secondAuthor == book2.secondAuthor
		&& book1.price == book2.price;
}
