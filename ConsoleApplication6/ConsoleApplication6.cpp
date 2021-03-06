
/*************************************************************
	Практическое занятие №6. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/

#include "pch.h"
#include <iostream>
#include "Book.h"


#define	  stop __asm nop	


void main()
{
	size_t capacity = 1;
	Book ** bb = new Book*[capacity];
	CARD_INDEX cI = { bb, 0, 1 };

	

	unsigned int option = 0;
	while (option != EXIT) {

		printf("Select menu item : \n(1) to print card-index\n(2) to add new book\n(3) to delete book(s)\n(4) to save to file\
			\n(5) to read from file\n(6) to sort card-index\n(7) to exit the program\n");
		

		scanf("%d", &option);

		if (option == PRINT) {
			printBook(&cI);
		}
		else if (option == ADD) {
			
			addBook(&cI);

		}
		else if (option == DELETE) {
			deleteBook(&cI);
			
		}
		else if (option == WRITE) {
			saveCardInd(&cI);
		}
		else if (option == READ) {
			readCardInd(&cI);
		}
		else if (option == EXIT) {
			break;
		}
		else if (option == SORT) {
			std::cout << "Choose field for sort" << '\n' << std::endl;
			std::cout << "1 to sort by author" << '\n' << std::endl;
			std::cout << "2 to sort by titel" << '\n' << std::endl;
			std::cout << "3 to sort by category" << '\n' << std::endl;
			std::cout << "4 to sort by year of realise" << '\n' << std::endl;
			std::cout << "5 to sort by price" << '\n' << std::endl;
			int option0 = 0;
			scanf("%d", &option0);
			if (cI.count>9){
				QuickSort(&cI, static_cast<Sort>(option0), (cI.count - 1), 0);
			}
			else {
				SelectionSort(&cI, static_cast<Sort>(option0));
			}
		}

	
	}


}