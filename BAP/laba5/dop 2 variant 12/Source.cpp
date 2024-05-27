#include <iostream>
#include<fstream>
#include <iomanip>
using namespace std;
# define str_len 256
# define size 100
using namespace std;
void enter_new();
void out();
void search();
union fornotebook
{
	char str[40];
	int limb;
};
struct notebook
{
	fornotebook name;
	fornotebook surname;
	fornotebook middleName;
	fornotebook date;
	fornotebook addres;
	fornotebook phone;
	fornotebook place_of_work;
	fornotebook position;
};
notebook people_in_notebook[size];
int current_size = 0; int choice;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1: enter_new(); break;
		case 2: out(); break;
		case 3: search(); break;
		}
	} while (choice != 4);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Фамилия" << endl;
		cin >> people_in_notebook[current_size].surname.str;
		cout << "Имя" << endl;
		cin >> people_in_notebook[current_size].name.str;
		cout << "Отчество" << endl;
		cin >> people_in_notebook[current_size].middleName.str;
		cout << "Дата рождения: " << endl;
		cin >> people_in_notebook[current_size].date.str;
		cout << "Адрес:" << endl;
		cin >> people_in_notebook[current_size].addres.str;
		cout << "Номер телефона:" << endl;
		cin >> people_in_notebook[current_size].phone.limb;
		cout << "Место работы:" << endl;
		cin >> people_in_notebook[current_size].place_of_work.str;
		cout << "Должность:" << endl;
		cin >> people_in_notebook[current_size].position.str;
		current_size++;


	}
	else
		cout << "Введено максимальное кол-во строк";
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void out()
{
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		cout << "Фамилия" << endl;
		cout << people_in_notebook[n - 1].surname.str;
		cout << endl;
		cout << "Имя" << endl;
		cout << people_in_notebook[n - 1].name.str;
		cout << endl;
		cout << "Отчество" << endl;
		cout << people_in_notebook[n - 1].middleName.str;
		cout << endl;
		cout << "Дата рождения: " << endl;
		cout << people_in_notebook[n - 1].date.str;
		cout << "Адрес:" << endl;
		cout << people_in_notebook[n - 1].addres.str;
		cout << endl;
		cout << "Номер телефона:" << endl;
		cout << people_in_notebook[n - 1].phone.limb;
		cout << endl;
		cout << "Место работы:" << endl;
		cout << people_in_notebook[n - 1].place_of_work.str;
		cout << endl;
		cout << "Должность:" << endl;
		cout << people_in_notebook[n - 1].position.str;
		cout << endl;

	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Фамилия" << endl;
			cout << people_in_notebook[i].surname.str;
			cout << endl;
			cout << "Имя" << endl;
			cout << people_in_notebook[i].name.str;
			cout << endl;
			cout << "Отчество" << endl;
			cout << people_in_notebook[i].middleName.str;
			cout << endl;
			cout << "Дата рождения: " << endl;
			cout << people_in_notebook[i].date.str;
			cout << "Адрес:" << endl;
			cout << people_in_notebook[i].addres.str;
			cout << endl;
			cout << "Номер телефона:" << endl;
			cout << people_in_notebook[i].phone.limb;
			cout << endl;
			cout << "Место работы:" << endl;
			cout << people_in_notebook[i].place_of_work.str;
			cout << endl;
			cout << "Должность:" << endl;
			cout << people_in_notebook[i].position.str;
			cout << endl;
		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}
void search()
{
	char name[16];
	cout << "Введите фамилию:" << "\n";
	cin >> name;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(name, people_in_notebook[z].surname.str) == 0)
		{
			cout << "Фамилия" << endl;
			cout << people_in_notebook[z].surname.str;
			cout << endl;
			cout << "Имя" << endl;
			cout << people_in_notebook[z].name.str;
			cout << endl;
			cout << "Отчество" << endl;
			cout << people_in_notebook[z].middleName.str;
			cout << endl;
			cout << "Дата рождения: " << endl;
			cout << people_in_notebook[z].date.str;
			cout << "Адрес:" << endl;
			cout << people_in_notebook[z].addres.str;
			cout << endl;
			cout << "Номер телефона:" << endl;
			cout << people_in_notebook[z].phone.limb;
			cout << endl;
			cout << "Место работы:" << endl;
			cout << people_in_notebook[z].place_of_work.str;
			cout << endl;
			cout << "Должность:" << endl;
			cout << people_in_notebook[z].position.str;
			cout << endl;

		}
	}
	cout << "Что дальше?" << endl;
	cin >> choice;
}