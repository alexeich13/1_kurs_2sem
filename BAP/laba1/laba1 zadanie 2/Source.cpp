#include <iostream>
using namespace std;

int fmax(int a, ...)
{
	int* p = &a;
	int min=100;
	for (int i = 0; i < a; i++)
	{
		if (*(++p) < min)
			min = *p;
	}
	cout << min;
	return min;
}

    int main()
	{
	fmax(8, 5, 12, 89, -42, 45, -13, 98);
}