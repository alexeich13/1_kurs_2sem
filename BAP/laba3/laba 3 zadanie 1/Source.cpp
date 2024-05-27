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
	int k, num = 0, counter = 0;
	cout << "¬ведите, с какой строки копировать:\n";
	cin >> k;
	int k1 = k + 3;
	string str;
	ifstream file1("fileMain1_1.txt");
	ofstream file2("fileMain1_2.txt");
	k--;
	k1--;
	while (getline(file1, str))
	{
		if (num >= k && num <= k1)
		{
			file2 << str << '\n';
			for (int j = 0; j < 8; j++)
			{
				if (str[j] == 'a' || str[j] == 'o' || str[j] == 'e' || str[j] == 'y' || str[j] == 'u' || str[j] == 'i')
					counter++;
			}
		}
		num++;
	}
	cout << counter << " гласных букв.\n";
}