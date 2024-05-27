#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n1, n2, num = 0, counter = 0;
	string str;
	cout << "Введите, с какой строки копировать:\n";
	cin >> n1;
	cout << "Введите, до какой строки копировать:\n";
	cin >> n2;
	ifstream file1("file9_1_1.txt");
	ofstream file2("file9_1_2.txt");
	n1--;
	n2--;
	while (getline(file1, str))
	{
		if (num >= n1 && num <= n2)
		{
			if (str[0] == 'C' || str[0] == 'c')
			{
				file2 << str << '\n';
				for (int i = 0; i < str.length(); i++)
				{
					if (str[i] == ' ')
					{
						counter++;
					}
				}
			}
		}
		num++;
	}
	cout << "В первой строке второго файла " << ++counter << " слова.\n";
}