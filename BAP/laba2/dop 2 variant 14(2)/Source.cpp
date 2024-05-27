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
	using namespace std;
	setlocale(LC_ALL, "Russian");
	FILE* F1;
	FILE* F2;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "f1_14.txt", "w");
	for (int i = 0; i < 6; i++)
	{
		fflush(stdin);
		printf("Строка  %d: \n", i + 1);
		gets_s(str);
		fputs(str, F1);
		fputs("\n", F1);
	}
	fclose(F1);
	err = fopen_s(&F1, "f1_14.txt", "r");
	err = fopen_s(&F2, "f2_14.txt", "w");

	while (fgets(str, 255, F1) != 0)
	{
		if (str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5'
			|| str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0')
		{
			fputs(str, F2);
		}
	}
	fclose(F1);
	fclose(F2);
}