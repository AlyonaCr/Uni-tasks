#include "Header.h"
#include "pch.h"
#include <iostream>


void enter(BigInteger* pInt) { 

	printf("Enter the number. Press enter to complete the entry\n");
	
	pInt->n = 1;
	pInt->p = new unsigned char[pInt->n];
	
	unsigned int i = 0, k = 1;
	
	while (true) {
		char ch = getchar();
		
		if (ch == '\n') {
			break;
		}
		
		else if ((ch < '0') || (ch > 'f') || (ch > '9') && (ch < 'A') || (ch > 'F') && (ch < 'a')) {
			rewind(stdin);
			printf("\nWrong data type. Try again\n");
			
				pInt->n = 1;
				unsigned char * pTmp = new unsigned char[pInt->n];
				delete[]pInt->p;
				pInt->p = pTmp;
				i = 0;
				k = 1;
		
			continue;
		}
		else {
			
			if (i == pInt->n) {
				
				unsigned char * pTmp = new unsigned char[pInt->n += 1];
				memcpy(pTmp, pInt->p, (pInt->n - 1));
				delete[]pInt->p;
				pInt->p = pTmp;
				
			}
			
			
			if (ch >= 'a') {
				ch -= 87;

			} else if (ch <= '9') {
				ch -= 48;
			} else {
				ch -= 55;
			}

			
			if ((k & 1) == 0) {
				pInt->p[i] = pInt->p[i] | ch;
				k++;
				i++;
				
			}
			
			else {
				pInt->p[i] = ch << 4;
				k++;
			}
		}
	}

	print(pInt, (k - 1) * 4);
	
}


 void print(BigInteger* pInt, int bits) {
	
	for (int ind = 0; ind < pInt->n; ind++) {
		for (int i = 7; i >= 0 && (bits > 0); i--, bits--) {
			printf("%d",((pInt->p[ind] & (1 << i)) ? 1 : 0));
		}
	}
	printf("\nByte occupied: %zd\n", pInt->n);
	
}
