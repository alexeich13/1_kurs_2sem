#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int stack[20];
	int i = -1;
	int counter = 0;
	for (int j = 0; j < 6; j++) {
		int a;
		cin >> a;
		i++;
		stack[i] = a;
	}
	cout << "Стек: " << endl;
	for (int j = 5; j >= 0; j--)
	{
		cout << stack[j] << endl;
	}
	cout << endl;
	for (int j = 5; j >= 0; j--)
	{
		for (int k = 5; k >= 0; k--)
		{
			if (stack[j] == stack[j + 1])
			{
				counter++;
				break;
			}
		}

	}
	cout << "Кол-во последовательных пар элементов  " << counter << endl;
	return 0;
}