#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

const int N = 10; // ������������ ���-�� ��������

struct Department {
	string FIO;
	string education;
	string spec;
	string podrazdel;
	string position;
	int salary;
} depo[N]; // ������ (Department depo[]). ��� �������

void filter(Department depo[], int* counter)
{
	char v[256];
	printf("������� ������� �����: ");
	cin >> v;

	for (int j = 0; j < *counter; j++)
	{
		string s = depo[j].FIO;
		int i = 0;
		for (i = s.find(v, i++); i != string::npos; i = s.find(v, i + 1))
		{
			cout << "����� ������: " << j << endl;
			cout << "������� ���������� �����: " << i << endl;
		}
	}
}
void BubbleSort(Department depo[], int* counter)
{
	for (int i = 0; i < *counter; i++) {
		for (int j = i + 1; j < *counter; j++) {
			if (depo[i].salary > depo[j].salary) {
				//������ ������� ��������
				swap(depo[i].salary, depo[j].salary);
			}
		}
	}
}

///////////////////////////////

void search_int(Department depo[], int N) {

	int x = 0;
	int a = 0;
	int b = N - 1;

	int WhatFind;
	cout << "������� ����� ��� ������:\n";
	cin >> WhatFind;
	bool found;

	for (found = false; (depo[a].salary < WhatFind) && (depo[b].salary > WhatFind) && !found; )
	{

		x = a + ((WhatFind - depo[a].salary) * (b - a)) / (depo[b].salary - depo[a].salary);

		if (depo[x].salary < WhatFind)
			a = x + 1;
		else if (depo[x].salary > WhatFind)
			b = x - 1;
		else
			found = true;
	}

	if (depo[a].salary == WhatFind)
		cout << WhatFind << " ������� ������ � ������� " << a + 1 << endl;
	else if (depo[b].salary == WhatFind)
		cout << WhatFind << " ������� ������ � ������� " << b + 1 << endl;
	else
		cout << "Sorry. Not found" << endl;
}

int binary(Department depo[], int N)
{
	int key;
	cout << endl << "������� ����:\n";
	cin >> key;

	bool flag = false;
	int l = 0;
	int r = N - 1;
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = (l + r) / 2;

		if (depo[mid].salary == key) flag = true;
		if (depo[mid].salary > key) r = mid - 1;
		else l = mid + 1;
	}

	if (flag) cout << "������ �������� " << key << " � ������� �����: " << mid << "\n";
	else cout << "��������, �� ������ �������� � ������� ���\n";
	return 0;
}


void newNode(Department depo[], int* counter) {
	cout << "������� ��� ";
	cin >> depo[*counter].FIO;
	cout << "������� ����������� ";
	cin >> depo[*counter].education;
	cout << "������� ������������� ";
	cin >> depo[*counter].spec;
	cout << "������� ������������� ";
	cin >> depo[*counter].podrazdel;
	cout << "������� ��������� ";
	cin >> depo[*counter].position;
	cout << "������� �������� ";
	cin >> depo[*counter].salary;
	*counter = *counter + 1;
	cout << endl;
}

void outNode(Department depo[], int count) {
	int i;
	for (i = 1; i < count + 1; i++) {
		cout << "��������� ����� " << i << endl;
		cout << "���: " << depo[i - 1].FIO << endl;
		cout << "�����������: " << depo[i - 1].education << endl;
		cout << "������������: " << depo[i - 1].spec << endl;
		cout << "�������������: " << depo[i - 1].podrazdel << endl;
		cout << "���������: " << depo[i - 1].position << endl;
		cout << "��������: " << depo[i - 1].salary << endl << endl;
	}
}

void deleteNode(Department depo[], int* count) {
	int number;
	cout << "������� ����� ���������� �������� "; cin >> number;
	for (int i = number - 1; i < *count; i++) {
		depo[i] = depo[i + 1];
	}
	*count = *count - 1;
}
void deleteAll(Department depo[], int* count) {
	*count = 0;
}
void inFile(Department depo[], int count) {
	string str;
	cout << "������� �������� �����, ���� ������ ��� ������� ���� ������� n "; cin >> str;
	if (str == "n") {
		ofstream f;
		f.open("file.txt", ios::app);
		for (int i = 0; i < count; i++) {
			f << depo[i].FIO << "\n";
			f << depo[i].education << "\n";
			f << depo[i].spec << "\n";
			f << depo[i].podrazdel << "\n";
			f << depo[i].position << "\n";
			f << depo[i].salary << "\n";
		}
	}
	else {
		ofstream f(str, ios::app);
		for (int i = 0; i < count; i++) {
			f << depo[i].FIO << "\n";
			f << depo[i].education << "\n";
			f << depo[i].spec << "\n";
			f << depo[i].podrazdel << "\n";
			f << depo[i].position << "\n";
			f << depo[i].salary << "\n";
		}
	}
}

void fromFile(Department depo[], int* count) {
	string str;
	cout << "������� �������� �����, ���� ������ ��� ������� ���� ������� n "; cin >> str;
	if (str == "n") {
		ifstream f;
		f.open("file.txt");
		while (f >> str) {
			depo[*count].FIO = str;
			f >> str;
			depo[*count].education = str;
			f >> str;
			depo[*count].spec = str;
			f >> str;
			depo[*count].podrazdel = str;
			f >> str;
			depo[*count].position = str;
			f >> str;
			depo[*count].salary = atoi(str.c_str());
			*count = *count + 1;
		}

	}
	else {
		ifstream f(str);
		while (f >> str) {
			depo[*count].FIO = str;
			f >> str;
			depo[*count].education = str;
			f >> str;
			depo[*count].spec = str;
			f >> str;
			depo[*count].podrazdel = str;
			f >> str;
			depo[*count].position = str;
			f >> str;
			depo[*count].salary = atoi(str.c_str());
			*count = *count + 1;
		}
	}
}
void editNode(Department depo[], int counter) {
	int i;
	cout << "������� ����� ����������� �������� "; cin >> i; i -= 1;
	if (i <= counter) {
		cout << "������� ��� ";
		cin >> depo[i].FIO;
		cout << "������� ����������� ";
		cin >> depo[i].education;
		cout << "������� ������������� ";
		cin >> depo[i].spec;
		cout << "������� ������������� ";
		cin >> depo[i].podrazdel;
		cout << "������� ��������� ";
		cin >> depo[i].position;
		cout << "������� �������� ";
		cin >> depo[i].salary;
	}
	else {
		cout << "������ �������� ��� " << endl;
	}
	cout << endl;

}

void fun3() {
	int size = 0;
	Department depo[10];
	int choise;
	do {
		cout << "���� �������� � ���������� 1" << endl;
		cout << "����� ��������� ��������� � ���������� ���� 2" << endl;
		cout << "�������� �������� ����������������� ���������� 3" << endl;
		cout << "������ ���������� � ���� 4" << endl;
		cout << "����� ���������� �� ����� � ������ �������� 5" << endl;
		cout << "��������� �������� ����������������� ���������� 6" << endl;
		cout << "���������� �������� 7" << endl;
		cout << "����� ����� 8" << endl;
		cout << "����� �� �������� 9" << endl;
		cout << "����� �������� �� ������� 10" << endl;
		cout << "�������� ����� ������� 11" << endl << endl;
		cin >> choise;
		switch (choise)
		{
		case 1: {
			newNode(depo, &size); break;
		}
		case 2: {
			outNode(depo, size); break;
		}
		case 3: {
			deleteNode(depo, &size); break;
		}
		case 4: {
			inFile(depo, size); break;
		}
		case 5: {
			fromFile(depo, &size); break;
		}
		case 6: {
			editNode(depo, size); break;
		}
		case 7: {
			BubbleSort(depo, &size); break;
		}
		case 8: {
			filter(depo, &size); break;
		}
		case 9: {
			search_int(depo, size); break;
		}
		case 10: {
			binary(depo, size); break;
		}
		case 11: {
			deleteAll(depo, &size); break;
		}
		default:
			break;
		}
	} while (choise != 0);
}

void main() {
	setlocale(LC_ALL, "rus");
	fun3();
}
