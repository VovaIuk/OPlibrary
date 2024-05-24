#include "Data.h"

ostream& operator <<(ostream& os, const Format format) {
	if (Format::Text == format)
		os << "234324234";
	if (Format::Audio == format)
		os << "234324234";
	if (Format::Podcast == format)
		os << "324324";
	return os;
}

ostream& operator <<(ostream& os, const Language language) {
	if (Language::English == language)
		os << "234234";
	if (Language::German == language)
		os << "234";
	if (Language::Rssian == language)
		os << "23423435345";
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
