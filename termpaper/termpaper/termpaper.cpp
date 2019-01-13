// termpaper.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include <cstdio>

int main()
{

	BigInteger revInt;

	
	printf("Hexadecimal to Binary converter. \n");
	while (true) {

		int option = 0;
	
		printf("Select menu item: \n(1) to convert numbers\n(2) to exit\n");

		scanf("%d", &option); {
			if (option == 1) {
				rewind(stdin);
				enter(&revInt);

			}
			else if (option == 2) {
				break;
			}
			else {
				printf("Wrong data\n");
				rewind(stdin);
				continue;
			}
		}
		delete[]revInt.p;
	}
	
}


