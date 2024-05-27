#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char buff[50];
    char str[50];
    int countWordITF = 0;
    int counterNumbers = 0;
    int counterNumbers_1 = 0;
    ofstream fout_1("t_3var1.txt");
    cin.getline(str, 50);
    fout_1 << str << '.' << '\n';
    fout_1.close();
    ifstream fin("t_3var1.txt");
    fin.getline(buff, 50);
    cout << buff << endl;
    for (int i = 0; i < strlen(buff); i++)
    {
        if (buff[i] == ' ' || buff[i] == '.') {
            countWordITF++;
        }
    }
    fin.close();
    ofstream fout_2("t_3var2.txt");
    ifstream fin_1("t_3var1.txt");
    for (int i = 0; i < countWordITF; i++)
    {
        fin_1 >> buff;
        int buff_len = strlen(buff);
        for (int j = 0; j < buff_len; j++) {
            if (buff[j] == '1' || buff[j] == '2' || buff[j] == '3' || buff[j] == '4' || buff[j] == '5' || buff[j] == '6' || buff[j] == '7' || buff[j] == '8' || buff[j] == '9' || buff[j] == '0') {
                counterNumbers++;
            }
        }
        if (counterNumbers > 0) {
            counterNumbers_1++;
        }
        else {
            cout << buff << endl;
            fout_2 << buff << " ";
        }
        counterNumbers = 0;
    }
    cout << "Наборов символов :  " << counterNumbers_1 << endl;
    cout << "Количество слов :  " << countWordITF - counterNumbers_1 << endl;
    fout_2.close();
    fin_1.close();
}
