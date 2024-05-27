#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	FILE* f1;
	FILE* f2;
	char str[255];
	fopen_s(&f1, "matrix14_1.txt", "r");
	fopen_s(&f2, "matrix14_2.txt", "w");
	int column;
	cout << "¬ведите столбец матрицы:\n";
	cin >> column;
	while (fgets(str, sizeof(str), f1))
	{
		int counter = 0;
		char word[255];
		stringstream x;
		x << str;
		while (x >> word)
		{
			if (counter + 1 == column)
			{
				fputs (word, f2);
				fputs("\n", f2);
			}
			counter++;
		}
		cin.get();
	}
	fclose(f2);
}