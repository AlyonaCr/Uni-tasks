#pragma once

struct BigInteger
{
	unsigned char* p;//указатель на динамический массив содержащий двоичное представление «длинного целого», заданного строкой 
	size_t n; //количество байтов в двоичном представлении 

};

void enter(BigInteger* pInt);

void print(BigInteger* pInt, int bits);




