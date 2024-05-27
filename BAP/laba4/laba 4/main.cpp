#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;


	struct BankClients
	{
		string name;
		string accType;
		string accNumber;
		string sum;
		string date;
	};

	const short N = 20;

	void input(BankClients clients[])
	{
		int num;
		do {
			cout << "¬ведите количество клиентов банка (не более " << N << "): ";
			cin >> num;
		} while (num < 1 || num > N);
		fflush(stdin);
		for (int i = 0; i < num; i++)
		{
			cout << "\t лиент є" << i + 1 << endl;
			cout << "¬ведите ‘»ќ клиента:\n";
			cin >> clients[i].name;
			cout << "¬ведите тип счЄта:\n";
			cin >> clients[i].accType;
			cout << "¬ведите номер счЄта:\n";
			cin >> clients[i].accNumber;
			cout << "¬ведите сумму на счЄте:\n";
			cin >> clients[i].sum;
			cout << "¬ведите дату последнего изменени€:\n";
			cin >> clients[i].date;
			cout << "\n\n";
		}
	}

	void output(BankClients clients[])
	{
		int ClientNum;
		cout << "¬ведите номер клиента, которого вы хотите вывести:\n";
		cin >> ClientNum;
		int i = ClientNum - 1;
		cout << "\t лиент є" << ClientNum << '\n';
		cout << "‘»ќ клиента: " << clients[i].name << '\n';
		cout << "“ип счЄта: " << clients[i].accType << '\n';
		cout << "Ќомер счЄта: " << clients[i].accNumber << '\n';
		cout << "—умма на счЄте: " << clients[i].sum << '\n';
		cout << "ƒата последнего изменени€: " << clients[i].date << "\n\n\n";
	}

	void deleteClient(BankClients clients[])
	{
		int numCin;
		cout << "¬ведите пор€дковый номер клиента, информацию о котором ¬ы хотите удалить:\n";
		cin >> numCin;
		cout << '\n';
		int i = numCin - 1;
		clients[i].name = ' ';
		clients[i].accType = ' ';
		clients[i].accNumber = ' ';
		clients[i].sum = ' ';
		clients[i].date = ' ';
		cout << '\n';
	}

	void search(BankClients clients[])
	{
		string numSearch;
		cout << "¬ведите номер счЄта искомого клиента:\n";
		cin >> numSearch;
		for (int i = 0; i < N; i++)
		{
			if (numSearch == clients[i].accNumber)
			{
				cout << " лиент є" << i + 1 << ": счЄт є" << clients[i].accNumber << '\n';
			}
		}
		cout << "\n\n";
	}

	void ofile(BankClients clients[])
	{
		string buf;
		int num;
		do {
			cout << "¬ведите количество клиентов банка (не более " << N << "): ";
			cin >> num;
		} while (num < 1 || num > N);
		fflush(stdin);
		ofstream file1("information.txt");
		for (int i = 0; i < num; i++)
		{
			cout << "\t лиент є" << i + 1 << '\n';
			file1 << "\t лиент є" << i + 1 << '\n';
			cout << "¬ведите ‘»ќ клиента:\n";
			file1 << "‘»ќ клиента: ";
			cin >> clients[i].name;
			file1 << clients[i].name;
			cout << "¬ведите тип счЄта:\n";
			file1 << "\n“ип счЄта: ";
			cin >> clients[i].accType;
			file1 << clients[i].accType;
			cout << "¬ведите номер счЄта:\n";
			file1 << "\nЌомер счЄта: ";
			cin >> clients[i].accNumber;
			file1 << clients[i].accNumber;
			cout << "¬ведите сумму на счЄте:\n";
			file1 << "\n—умма на счЄте: ";
			cin >> clients[i].sum;
			file1 << clients[i].sum;
			cout << "¬ведите дату последнего изменени€:\n";
			file1 << "\nƒата последнего изменени€: ";
			cin >> clients[i].date;
			file1 << clients[i].date << "\n\n";
		}
		cout << "\n\n";
	}

	void ifile(BankClients clients[])
	{
		string strInf;
		ifstream file1("information.txt");
		while (file1)
		{
			getline(file1, strInf);
			cout << strInf << '\n';
		}
	}

	int main()
	{
		setlocale(LC_ALL, "ru");
		short choose;
		BankClients clients[N];
		do {
			cout << "¬ыберите, что сделать:\n1 Ч ввод элементов структуры с клавиатуры;\n2 Ч вывод элементов стуктуры в консольное окно;"
				"\n3 Ч удаление заданной структурированной переменной; \n4 Ч поиск информации; \n5 Ч запись информации в файл; \n6 Ч чтение данных из файла; \n7 Ч выход из программы.\n";
			cin >> choose;
			switch (choose)
			{
			case 1: input(clients); break;
			case 2: output(clients); break;
			case 3: deleteClient(clients); break;
			case 4: search(clients); break;
			case 5: ofile(clients); break;
			case 6: ifile(clients); break;
			case 7: main(); break;
			}
		} while (choose != 7);
	}
