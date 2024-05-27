#include <iostream>
using namespace std;

float MinMatr(int aa, ...)
{
	int *a = &aa;
	int min = 100;
	for (int i = 0; i < 9; i++)
	{
		if (*(a++) < min)
			min = *a;
	}
	cout << min;
	return min;
}

int main()
{
	MinMatr(8, 12, 54, -12, -45, 0, 34, 23, 75);
}