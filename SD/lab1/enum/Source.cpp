#include <iostream>
using namespace std;

enum levelsName { parking, bank, insurance, market, fitnesroom, Restaurant };

int main()
{
	setlocale(LC_ALL, "rus");

	int floor = parking; // ����� ������ ����� ������������
	int exitOrNot = 9; // ����� ��� ���

	while (exitOrNot == 9)
	{
		cout << "����� ����� (0,1,2,3,4,5): ";
		cin >> floor;

		switch (floor)
		{
		case(parking):
			cout << "\a\a\a�� � ��������!\n\n";
			break;

		case(bank):
			cout << "\a\a\a������ ����!";
			cout << "\n ����� ��������� ��������� �����������.\n\n";
			break;

		case(insurance):
			cout << "\a\a\a������ ����!";
			cout << "\n ��������� �������� �����������.\n\n";
			break;

		case(market):
			cout << "\a\a\a������ ����!";
			cout << "\n ����������� �������-�������� �����.\n\n";
			break;

		case(fitnesroom):
			cout << "\a\a\a�������� ����!";
			cout << "\n ������ �����.\n\n";
			break;

		case(Restaurant):
			cout << "\a\a\a����� ����!";
			cout << "\n�������� �7-� ����.\n\n";
			break;

		default: cout << "\a\a\a������!\n\n";
		}

		cout << "����� �� ����� - ������� 0.\n";
		cout << "������� ������ ���� - ������� 9: ";
		do
		{
			cin >> exitOrNot;
		} while (exitOrNot != 0 && exitOrNot != 9);
		cout << endl;
	}
	return 0;
}
