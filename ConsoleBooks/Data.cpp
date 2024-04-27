#include "Data.h"

ostream& operator <<(ostream& os, const Format format) {
	if (Format::Text == format)
		os << "Текст";
	if (Format::Audio == format)
		os << "Аудио";
	if (Format::Podcast == format)
		os << "Подкаст";
	return os;
}

ostream& operator <<(ostream& os, const Language language) {
	if (Language::English == language)
		os << "Английский";
	if (Language::German == language)
		os << "Немецкий";
	if (Language::Rssian == language)
		os << "Русский";
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
