#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int> newlist = { 6, 2, 8, 4, 5 };


void AddBack()
{
	cout << " Добавление элементов\n";
	int a;
	cout << "Введите число: "; cin >> a;
	newlist.push_back(a);
	cout << "\nДобавлено" << endl;
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void DopOne()
{
	cout << "Удаление элемента\n";
	int a;
	cout << "Выберите элемент: "; cin >> a;
	newlist.remove(a);
	cout << "\nУдалено" << endl;
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void DopTwo()
{
	cout << "Удаление элементов с начальной позиции\n";
	int f, g, h;
	list <int> ::iterator it, at;
	cout << "Выберите начальную позиции: "; cin >> f;
	it = newlist.begin();
	advance(it, f);
	cout << "Выберите последнию позицию: "; cin >> g;
	at = newlist.end();
	advance(at, -g);
	cout << "\nУдалено" << endl;
	newlist.erase(it, at);
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void DopThree()
{
	cout << "Добавлене элементов в \n";
	int a, b;
	list <int> ::iterator it;
	cout << "Выберите позицию: "; cin >> a;
	it = newlist.begin();
	advance(it, a);
	cout << "Введите значаение: "; cin >> b;
	newlist.insert(it, b);
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void Menu()
{
start:
	cout << "1. Задание " << endl;
	cout << "2. Доп 1" << endl;
	cout << "3. Доп 2" << endl;
	cout << "4. Доп 3" << endl;
	cout << "5. Выход" << endl;
	int count;
	cout << "Выберите задание: "; cin >> count;
	if (count > 5)
		goto start;
	else
		switch (count)
		{
		case 1: system("cls"), AddBack(), system("cls"), Menu(); break;
		case 2: system("cls"), DopOne(), system("cls"), Menu(); break;
		case 3: system("cls"), DopTwo(), system("cls"), Menu(); break;
		case 4: system("cls"), DopThree(), system("cls"), Menu(); break;
		case 5: break;
		}
}
int main()
{
	setlocale(LC_ALL, "ru");
	Menu();
}