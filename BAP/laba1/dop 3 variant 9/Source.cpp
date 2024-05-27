#include <iostream>
using namespace std;

void StrSym()
{
	char* Size = new char[256];
	cout << "¬ведите предложение, заканчивающеес€ точкой:\n";
	cin.getline(Size, 256, '.');
	short i = 0, Probel = 0, LastP = 0, Length = strlen(Size), Max = 0;
	while (i != Length)
	{
		if (*(Size + i) == ' ')
		{
			Probel = i;
			short Word = Probel - LastP - 1;
			if (Word > Max)
			{
				Max = Word;
			}
			LastP = Probel;
		}
		if ((i + 1) == Length)
		{
			short Word = Length - LastP - 1;
			if (Word > Max)
			{
				Max = Word;
			}
		}
		i++;
	}
	cout << "ћаксимальное количество букв в слове: " << Max;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	StrSym();
}