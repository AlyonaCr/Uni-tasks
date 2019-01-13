#include "Book.h"
#include <iostream>

const char* categorys[] = {"Classic_literature", "Philosophy", "Computer_science"};

void printBook(CARD_INDEX *pCard) {
	for (int i = 0; i < pCard->count; i++) {
		printf("%d author: %s\ntitel: %s\ncategory: %s\nyear of release: %d\nprice: %g\n", (i+1), pCard->pB[i]->author, \
			pCard->pB[i]->titel, categorys[pCard->pB[i]->category - 1], pCard->pB[i]->year, pCard->pB[i]->price);
		printf("\n");
	}
}

void addBook(CARD_INDEX *pCard) {

	if (pCard->count == pCard->cap) //емкость исчерпана
	{
		Book** tmp = new Book*[(pCard->cap + 1)];
		for (int i = 0; i < pCard->cap; i++) {
			tmp[i] = pCard->pB[i];
		}
		delete[] pCard->pB;
		pCard->pB = tmp;
		pCard->cap += 1;
	}

	pCard->pB[pCard->count] = new Book();
	

		printf("Enter the author\n");
		scanf("%s", pCard->pB[pCard->count]->author);

		printf("Enter the titel\n");
		scanf("%s", pCard->pB[pCard->count]->titel);

		printf("Choose the category: CLASSICS_LITERATURE (1), PHILOSIPHY (2), COMPUTER_SCIENCE (3)");
		while (true) {
			int tmp1 = 0;
			scanf("%d", &tmp1);
			if ((tmp1 == 1)||(tmp1 == 2)||(tmp1 == 3)) {
				pCard->pB[pCard->count]->category = static_cast<Category>(tmp1);
				break;
			}else{
				printf("Wrong category");
				continue;

			}
		}


		printf("Enter the year of book release");
		while (true) {
			int tmp2;
			scanf("%d", &tmp2);
			if ((tmp2 < 1564) || (tmp2 > 2018)) {
				printf("You have entered wrong year. Enter another one");
				continue;
			}
			else {
				pCard->pB[pCard->count]->year = tmp2;
				break;
			}
		}



		printf("Enter the price");
		while (true) {
			float tmpD;
			scanf("%f", &tmpD);
			if (tmpD < 0) {
				printf("Price cant be less than 0. Enter another one");
				continue;
			}
			else {
				pCard->pB[pCard->count]->price = tmpD;
				break;
			}

		}
		pCard->count += 1;
		
}
void saveCardInd(CARD_INDEX *pCard) {

	FILE* f = fopen("cardind1.txt", "w");
	
		if (f) {

			for (int i = 0; i < pCard->count; i++) {

				fprintf(f, " %s %s %s %u %lf", (pCard->pB[i])->author, (pCard->pB[i])->titel, categorys[(pCard->pB[i]->category)-1], (pCard->pB[i])->year, (pCard->pB[i])->price);
			}

		}
		else {
			std::cout << "File error " << std::endl;

		}

	
	fclose(f);


}

void readCardInd(CARD_INDEX *pCard) {


	FILE* f = fopen("cardind1.txt", "r");
	if (f) {
	while (!feof(f)){
			
				
			if (pCard->count == pCard->cap) //емкость исчерпана
			{
				Book** tmp = new Book*[(pCard->cap + 1)];
				for (int i = 0; i < pCard->cap; i++) {
					tmp[i] = pCard->pB[i];
				}
				delete[] pCard->pB;
				pCard->pB = tmp;
				pCard->cap += 1;
			}
		
			pCard->pB[pCard->count] = new Book();

			char p[20] = {'0'};
			fscanf(f, "%s %s %s %d %fl", pCard->pB[pCard->count]->author, pCard->pB[pCard->count]->titel, &p, &pCard->pB[pCard->count]->year, &pCard->pB[pCard->count]->price);
			
			for (int i = 0; i < 3; i++) {
				int r = strcmp(p, categorys[i]);
				if (r == 0) {
					pCard->pB[pCard->count]->category = static_cast<Category>(i+1);
				}

			}
			pCard->count += 1;
			
		}
			
	}
	else {
		std::cout << "File error " << std::endl;
		
	}
	fclose(f);
}

void deleteBook(CARD_INDEX *pCard) {
	while (true) {
		printf("Select menu item : \n(1) to delete all books\n(2) to delete one book\n(3) to exit\n");
		int option0 = 0;
		rewind(stdin);
		scanf("%d", &option0);
		if (option0 == 1) {
			if (remove("cardind1.txt") == 0) {
				printf("Deletion completed\n");
				for (int i = 0; i < pCard->cap; i++) {
					delete pCard->pB[i];
				}
				delete[]pCard->pB;
				pCard->pB = nullptr;
			}
			else {
				printf("File error\n");
			}

		}
		else if (option0 == 2) {
			printf("Enter the number of book for delete\n");
			printBook(pCard);
			rewind(stdin);
			int option1 = 0;
			scanf("%d", &option1);
			delete pCard->pB[option1 - 1];
			pCard->pB[option1 - 1] = nullptr;

			pCard->count -= 1;
			for (int i = option1 - 1; i < pCard->count; i++) {
				pCard->pB[i] = pCard->pB[i + 1];
			}

			saveCardInd(pCard);
		}
		else if (option0 == 3) {
			break;
		}
		else {
			printf("Wrong data. Try again");
			continue;

		}
	}

}



void QuickSort(CARD_INDEX *pCard, Sort field, int r, int l) {
	
		if ((r - l) < 2) return;
		int mid = ((l + r) / 2);
		int i = l;
		int j = r;
		do {
			if (field == AUTHOR) {
				while ((strcmp(pCard->pB[mid]->author, pCard->pB[i]->author)) > 0) i++;
				while ((strcmp(pCard->pB[j]->author, pCard->pB[mid]->author)) > 0) j--;
			}
			else if (field == TITEL) {
				while ((strcmp(pCard->pB[mid]->titel, pCard->pB[i]->titel)) > 0) i++;
				while ((strcmp(pCard->pB[j]->titel, pCard->pB[mid]->titel)) > 0) j--;
			}
			else if (field == CATEGORY) {
				while (pCard->pB[mid]->category > pCard->pB[i]->category) i++;
				while (pCard->pB[j]->category > pCard->pB[mid]->category) j--;
			}
			else if (field == YEAR) {
				while (pCard->pB[mid]->year > pCard->pB[i]->year) i++;
				while (pCard->pB[j]->year > pCard->pB[mid]->year) j--;
			}
			else {
				while (pCard->pB[mid]->price> pCard->pB[i]->price) i++;
				while (pCard->pB[j]->price > pCard->pB[mid]->price) j--;
			}

			if (i <= j) {
				
					Book* tmp = pCard->pB[i];
					pCard->pB[i++] = pCard->pB[j];
					pCard->pB[j--] = tmp;
			
			}
		} while (i < j);

		if (l < j){

			QuickSort(pCard, field, j, l);

		}
		if (i < r) {

			QuickSort(pCard, field, r, i);

		}
}


void SelectionSort(CARD_INDEX *pCard, Sort field) {

	for (int i = 0; i < pCard->count - 1; i++) {

		int min = i;

		for (int j = i + 1; j < pCard->count; j++) {
			if (field == AUTHOR) {
				if ((strcmp(pCard->pB[j]->author, pCard->pB[min]->author)) < 0) {

					min = j;
				}
			}
			else if (field == TITEL) {
				if ((strcmp(pCard->pB[j]->titel, pCard->pB[min]->titel)) < 0) {

					min = j;
				}
			}
			else if (field == CATEGORY) {
				if (pCard->pB[j]->category < pCard->pB[min]->category) {

					min = j;
				}
			}
			else if (field == YEAR) {
				if (pCard->pB[j]->year < pCard->pB[min]->year) {

					min = j;
				}
			}
			else {
				if (pCard->pB[j]->price < pCard->pB[min]->price) {

					min = j;
				}
			}

			Book* tmp = pCard->pB[min];
			pCard->pB[min] = pCard->pB[i];
			pCard->pB[i] = tmp;
		}

	}

}