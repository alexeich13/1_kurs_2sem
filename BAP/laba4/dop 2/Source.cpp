#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

struct Train {
	string Place;// место назначения
	int NumTrain; // номер поезда
	string time; // время отбытия 
};


bool compTrain(Train lhs, Train rhs)
{
	return lhs.Place < rhs.Place;
}

void displayTrain(Train* trains, int SIZE) {
	sort(trains, trains + SIZE, compTrain);

	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Номер поезда: " << trains[i].NumTrain << "\t";
		cout << "Место прибытия: " << trains[i].Place << "\t\t";
		cout << "Время прибытия на вокзал: " << trains[i].time << "\t";
		cout << "\n///////////////////////////////////////////////////////////////////////////////////" << endl;
	}
};

void displayTrainMode(Train* trains, int SIZE, string user_time)
{
	sort(trains, trains + SIZE, compTrain);

	if (user_time.size() > 5 || user_time.size() < 2)
	{
		cout << "Некорретная дата " << endl;
		exit(1);
	}

	istringstream x(user_time, istringstream::in);
	int time_user1;
	x >> time_user1;
	x.clear();

	int hours_user = time_user1 / 100; // часы 
	int minuts_user = time_user1 % 100;// минуты 

	if (hours_user < -1 || hours_user>60 || minuts_user < -1 || minuts_user >60)
	{
		cout << "Некорретная дата " << endl;
		exit(1);
	}


	cout << "Ваше время : " << hours_user << " часов, " << minuts_user << " минут " << endl;
	int all_user_time = hours_user * 60 * 60 + minuts_user * 60; //секунды с начатого дня

	vector <int> time_train;

	for (int i = 0; i < SIZE; i++)
	{
		istringstream x(trains[i].time, istringstream::in);
		int train_rail;
		x >> train_rail;
		int train_hours = train_rail / 100;
		int train_minuts = train_rail % 100;
		time_train.push_back((train_hours * 60 * 60) + (train_minuts * 60));
	}
	bool ones = false;

	for (int i = 0; i < SIZE; i++)
	{
		if (all_user_time < time_train[i])
		{
			cout << "Номер поезда: " << trains[i].NumTrain << "\t";
			cout << "Место прибытия: " << trains[i].Place << "\t\t";
			cout << "Время прибытия на вокзал: " << trains[i].time << "\t";
			cout << "\n////////////////////////////////////////////////////////////////////////////////////////" << endl;
			ones = true;
		}
	}
	if (ones == false)
	{
		cout << "Нет поездов." << endl;
	}
}
;

void ifileTrain(Train* trains, int SIZE)
{
	ifstream fin("trainsInfo.txt");

	if (!fin.is_open()) {
		cout << "Не удаётся открыть файл для чтения " << endl;
		exit(EXIT_FAILURE);
	}

	vector<string> fileinfo;
	string line, word;
	stringstream x;
	for (int i = 0; i < SIZE; ++i) {

		fin >> trains[i].NumTrain;//номер поезда 

		getline(fin, line);

		x << line; // деление строки
		while (x >> word)
		{
			fileinfo.push_back(word);
		}

		for (int k = 0; k < fileinfo.size(); ++k)
		{
			if (k == 0) { trains[i].Place = fileinfo[k]; }
			if (k == 1) { trains[i].time = fileinfo[k]; }
		}

		x.clear();
		line.clear();
		word.clear(); //очистка
		fileinfo.clear();
	}

}
int main()
{
	setlocale(LC_CTYPE, "rus");
	const int SIZE = 5;
	Train trains[SIZE];
	ifileTrain(trains, SIZE);
	displayTrain(trains, SIZE);
	cout << "\nВведите дату (формат ЧЧММ): ";
	string user_time;
	cin >> user_time;
	cout << endl;
	displayTrainMode(trains, SIZE, user_time);

}
