#include <iostream>
using namespace std;

int DecToBin(int a, ...)
{
	char tA[33];
	int* pA = &a;
	for (int i = 0; i < 7; i++)
	{
		_itoa_s(*(pA++), tA, 2);
		cout << tA << endl;
	}
	return a;
}

void main()
{
	DecToBin(1, 4, 13, 15, 245, 256, 853);
}