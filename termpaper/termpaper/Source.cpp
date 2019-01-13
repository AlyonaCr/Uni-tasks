#include "Header.h"
#include "pch.h"
#include <iostream>

/*Функция приема значений и перевода их в двоичное представление*/
void enter(BigInteger* pInt) { 

	printf("Enter the number. Press enter to complete the entry\n");
	/*Динамически выделяем память под массив начальной размерностью 1*/
	pInt->n = 1;
	pInt->p = new unsigned char[pInt->n];
	/*i - счетчик "длинных целых", k - счетчик "значащих тетрад"*/
	unsigned int i = 0, k = 1;
	
	while (true) {
		char ch = getchar();
		/*Если пользователь нажал клавишу Enter, ввод закончен, выход из функции*/
		if (ch == '\n') {
			break;
		}
		/*Проверка на допустимость введенных значений*/
		else if ((ch < '0') || (ch > 'f') || (ch > '9') && (ch < 'A') || (ch > 'F') && (ch < 'a')) {
			rewind(stdin);
			printf("\nWrong data type. Try again\n");
			/*Удаляем сохраненные значения*/
				pInt->n = 1;
				unsigned char * pTmp = new unsigned char[pInt->n];
				delete[]pInt->p;
				pInt->p = pTmp;
				i = 0;
				k = 1;
		
			continue;
		}
		else {
			/*Если "длинных целых" больше, чем места в массиве, то динамически выделяется память на единицу*/
			if (i == pInt->n) {
				
				unsigned char * pTmp = new unsigned char[pInt->n += 1];
				memcpy(pTmp, pInt->p, (pInt->n - 1));
				delete[]pInt->p;
				pInt->p = pTmp;
				
			}
			
			/*В зависимости от кода символа производится его конвертация для получения нужного значения в двоичном представлении*/
			if (ch >= 'a') {
				ch -= 87;

			} else if (ch <= '9') {
				ch -= '0';
			} else {
				ch -= 55;
			}

			/*Если значение счетчика "значащих тетрад" четное, биты с 7-4 заняты прерыдущим числом. Для изменения значения битов 3-0 необходимо 
			применить операцию побитового или*/
			if ((k & 1) == 0) {
				pInt->p[i] = pInt->p[i] | ch;
				k++;
				i++;
				
			}
			/* Если значение счетчика "значащих тетрад" нечетное, необходимо переместить полученное значение на 7-4 биты*/
			else {
				pInt->p[i] = ch << 4;
				k++;
			}
		}
	}

	print(pInt, (k - 1) * 4);
	
}

/*Функция вывода полученных значений на экран*/
 void print(BigInteger* pInt, int bits) {
	/*Для вывода значений в цикле используется две переменных: i - индекс массива и bits - количество значащих битов*/
	for (int ind = 0; ind < pInt->n; ind++) {
		for (int i = 7; i >= 0 && (bits > 0); i--, bits--) {
			printf("%d",((pInt->p[ind] & (1 << i)) ? 1 : 0));
		}
	}
	printf("\nByte occupied: %zd\n", pInt->n);
	
}