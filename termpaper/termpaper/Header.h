#pragma once

struct BigInteger
{
	unsigned char* p;//��������� �� ������������ ������ ���������� �������� ������������� ��������� ������, ��������� ������� 
	size_t n; //���������� ������ � �������� ������������� 

};

void enter(BigInteger* pInt);

void print(BigInteger* pInt, int bits);




