#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int> newlist = { 6, 2, 8, 4, 5 };


void AddBack()
{
	cout << " ���������� ���������\n";
	int a;
	cout << "������� �����: "; cin >> a;
	newlist.push_back(a);
	cout << "\n���������" << endl;
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void DopOne()
{
	cout << "�������� ��������\n";
	int a;
	cout << "�������� �������: "; cin >> a;
	newlist.remove(a);
	cout << "\n�������" << endl;
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void DopTwo()
{
	cout << "�������� ��������� � ��������� �������\n";
	int f, g, h;
	list <int> ::iterator it, at;
	cout << "�������� ��������� �������: "; cin >> f;
	it = newlist.begin();
	advance(it, f);
	cout << "�������� ��������� �������: "; cin >> g;
	at = newlist.end();
	advance(at, -g);
	cout << "\n�������" << endl;
	newlist.erase(it, at);
	for (int n : newlist)
	{
		cout << n << "\t";
	}
	system("pause");
}

void DopThree()
{
	cout << "��������� ��������� � \n";
	int a, b;
	list <int> ::iterator it;
	cout << "�������� �������: "; cin >> a;
	it = newlist.begin();
	advance(it, a);
	cout << "������� ���������: "; cin >> b;
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
	cout << "1. ������� " << endl;
	cout << "2. ��� 1" << endl;
	cout << "3. ��� 2" << endl;
	cout << "4. ��� 3" << endl;
	cout << "5. �����" << endl;
	int count;
	cout << "�������� �������: "; cin >> count;
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