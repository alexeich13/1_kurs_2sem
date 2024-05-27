#include <iostream>
#include <tchar.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Queue
{
	int info;
	Queue* next;
};

void create(Queue** begin, Queue** end, int p);
void view(Queue* begin);
Queue* maxElem(Queue* begin);
void size(Queue* begin);
void delAll(Queue** begin);
void del3(Queue** begin);

int main(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	Queue* begin = NULL, *end, *t;
	t = new Queue;
	int p;
	int max_size, choice;
	int current_size = 0;
	cout << "\n������� ������������ ������ �������="; cin >> max_size;
	cout << "������� ������ ������� �������= "; cin >> p;
	t->info = p;
	t->next = NULL;
	begin = end = t;
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � �������" << endl;
		cout << "2 - ����� �������" << endl;
		cout << "3 - ����� ������������� �������� �������" << endl;
		cout << "4 -������ ������� " << endl;
		cout << "5 -�������� ���� ���������" << endl;
		cout << "6 - �������� ��������� ������� " << endl;
		cout << "7 - �����" << endl;

		cin >> choice;
		switch (choice)
		{

		case 1:
			if (current_size < max_size)
				cout << "������� ����� ";
			cin >> p;
			create(&begin, &end, p);
			current_size++;
			break;
		case 2:
			cout << "\n�������� �������: \n";
			if (begin == NULL)
				cout << "��� ���������" << endl;
			else
				view(begin);
			break;
		case 3:
			maxElem(begin);
			break;
		case 4:
			if (begin == NULL)
				cout << "��� ���������" << endl;
			else
				size(begin);
			break;
		case 5:
			del3(&begin);
			break;
		case 6:
			delAll(&begin);
			break;
		case 7:
			return 0;
			break;
		}
	}
	return 0;
}

void create(Queue** begin, Queue** end, int p)
{
	Queue* t = new Queue;
	t->next = NULL;
	if (*begin == NULL)
		*begin = *end = t;
	else
	{
		t->info = p;
		(*end)->next = t;
		*end = t;
	}
}
void view(Queue* begin)
{
	setlocale(LC_CTYPE, "RUSSIAN");
	Queue* t = begin;
	if (t == NULL)
	{
		cout << "������� �����\n";
		return;
	}
	else
		while (t != NULL)
		{
			cout << t->info << endl;
			t = t->next;
		}
}
Queue* maxElem(Queue* begin)
{
	Queue* t = begin;
	int max;
	if (t == NULL)
	{
		cout << "������� �����\n"; return 0;
	}
	else
	{
		max = t->info;
		while (t != NULL)
		{
			if (t->info >= max)
			{
				max = t->info;


			}
			t = t->next;
		}
	}
	cout << "������������ ������� - " << max << endl;
}
void size(Queue* begin)
{
	setlocale(LC_CTYPE, "RUSSIAN");
	Queue* t = begin;
	int sz = 0;
	if (t == NULL)
	{
		cout << "������� �����\n";
		return;
	}
	else
		while (t != NULL)
		{
			t->info;
			t = t->next;
			sz++;
		}
	cout << "������ �������=" << sz << endl;
}
void del3(Queue** begin)
{
	Queue* t;
	int i = 0;
	while (*begin != NULL && i != 3)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
		i++;
	}

}
void delAll(Queue** begin)
{
	Queue* t;
	while (*begin != NULL)
	{
		t = *begin;
		*begin = (*begin)->next;
		delete t;
	}
}