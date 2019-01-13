#pragma once



enum Menu {
	PRINT = 1,
	ADD,
	DELETE,
	WRITE,
	READ,
	SORT,
	EXIT
};

enum Category {
	CLASSICS_LITERATURE = 1,
	PHILOSOPHY,
	COMPUTER_SCIENCE
};

enum Sort {
	AUTHOR = 1,
	TITEL,
	CATEGORY,
	YEAR,
	PRICE

};


struct Book {
	char author[30];
	char titel[80];
	Category category;
	unsigned short year;
	float price;
};

struct CARD_INDEX
{
	Book** pB;//указатель на картотеку
	size_t count; //количество книг в картотеке
	size_t cap; //емкость картотеки
};


void addBook(CARD_INDEX *pCard);

void printBook(CARD_INDEX *pCard);

void saveCardInd(CARD_INDEX *pCard);

void readCardInd(CARD_INDEX *pCard);

void deleteBook(CARD_INDEX *pCard);

void QuickSort(CARD_INDEX *pCard, Sort field, int r, int l);

void SelectionSort(CARD_INDEX *pCard, Sort field);





