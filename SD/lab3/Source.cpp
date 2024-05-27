#include <iostream>
#include <fstream>
using namespace std;

struct Birth {
    int day;
    int month;
    int year;
};
struct Employee
{
    string name;
    string surname;
    string role;
    Birth date;
};

void printInformation(Employee employee)
{
    cout << "Name: " << employee.name << "\n";
    cout << "Surname: " << employee.surname << "\n";
    cout << "Role: " << employee.role << "\n";
    cout << "Date of birth " << employee.date.day << "." << employee.date.month << "." << employee.date.year << "\n\n";
}

struct Node {
    Employee val;
    Node* next;

    Node(Employee _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(Employee _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void push_front(Employee _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first = p;
    }

    void print() {
        if (is_empty()) {
            cout << "list empty\n"; return;
        }
        Node* p = first;
        int a = 0;
        cout << "1.Вывод в консоль\n";
        cout << "2.Вывод в файл\n";
        cin >> a;
        ofstream os("file.txt");
        switch (a) {
        case 1:
            while (p) {
                printInformation(p->val);
                p = p->next;
            }
            cout << endl;
            break;
        case 2:
            while (p) {
                Employee employee = p->val;
                os << employee.name << "\n";
                os << employee.surname << "\n";
                os << employee.role << "\n";
                os << employee.date.day << " " << employee.date.month << " " << employee.date.year << endl;
                p = p->next;

            }
            cout << "Список записан в файл\n";
            os.close();
            cout << endl;
            break;
        default:
            cout << "input invalid" << endl;
            break;
        }
    }
    void printFILE() {
        if (is_empty()) {
            return;
        }
        Node* p = first;
        cout << "Записать в файл Y/N?\n";

        char a;
        cin >> a;
        if (a == 'n' || a == 'N')
        {
            cout << "Данные не сохранены\n"; return;
        }
        else if (a == 'y' || a == 'Y')
        {
            ofstream os("file.txt");
            while (p) {
                Employee employee = p->val;
                os << employee.name << "\n";
                os << employee.surname << "\n";
                os << employee.role << "\n";
                os << employee.date.day << " " << employee.date.month << " " << employee.date.year << endl;
                p = p->next;

            }
            cout << "Список записан в файл\n";
            os.close();
            cout << endl;
        }
        else cout << "Такого варианта нет\n";


    }
    void readFile() {
        Employee  s;
        string name;
        string surname;
        string role;
        int day;
        int month;
        int year;
        ifstream is("file.txt");
        while (is >> name >> surname >> role >> day >> month >> year)
        {
            s = { name,surname,role,{day,month,year} };
            push_front(s);
        }
        cout << "Файл прочтен\n";
        is.close();
    }
    void ff() {
        if (is_empty()) return;
        int sum = 0;
        int k = 0;
        Node* p = first;
        while (p) {
            if (2022 - (p->val.date.year) > 40)
                printInformation(p->val);
            p = p->next;
        }
        cout << "Людей старше 40: " << p << endl;
    }
    void countAVG() {
        if (is_empty()) return;
        int sum = 0;
        int k = 0;
        Node* p = first;
        while (p) {
            sum += 2022 - (p->val.date.year);
            k++;
            p = p->next;
        }
        cout << "Средний возраст: " << sum / k << endl;
    }
    void countVZ() {
        if (is_empty()) return;
        int sum = 0;
        Node* p = first;
        while (p) {
            sum += 2022 - (p->val.date.year);
            p = p->next;
        }
        cout << "Суммарный возраст: " << sum << endl;
    }
    void find(string _val) {
        Node* p = first;
        while (p) {
            if (p->val.surname == _val)
                printInformation(p->val);
            p = p->next;
        }
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(Employee _val) {
        if (is_empty()) return;
        if (first->val.surname == _val.surname) {
            remove_first();
            return;
        }
        else if (last->val.surname == _val.surname) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val.surname != _val.surname) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }


};
int main()
{
    setlocale(0, "");
    list l;
    int input = 1000;
    while (input != 0)
    {
        cout << "Выберите функцию " << endl;
        cout << "1. Добавить элемент в начало" << endl;
        cout << "2. Добавить элемент в конец" << endl;
        cout << "3. Вывести список/Сохранить в файл" << endl;
        cout << "4. Найти элемент" << endl;
        cout << "5. Удалить  заданный элемент" << endl;
        cout << "6. Очистить список" << endl;
        cout << "7. Сколько людей старше 40" << endl;
        cout << "8. Средний возраст" << endl;
        cout << "9. Подсчета суммарного возраста" << endl;
        cout << "10. Чтение файла" << endl;
        cout << "0. Выход" << endl;
        cin >> input;
        Employee  s;
        string name;
        string surname;
        string role;
        int day;
        int month;
        int year;
        switch (input) {
        case 1:
            cout << "Введите элемент" << endl;
            cout << "name\n";
            cin >> name;
            cout << "surname\n";
            cin >> surname;
            cout << "role\n";
            cin >> role;
            cout << "day\n";
            cin >> day;
            cout << "month\n";
            cin >> month;
            cout << "year\n";
            cin >> year;
            s = { name,surname,role,{day,month,year} };
            l.push_front(s);
            break;
        case 2:
            cout << "Введите элемент" << endl;
            cout << "name\n";
            cin >> name;
            cout << "surname\n";
            cin >> surname;
            cout << "role\n";
            cin >> role;
            cout << "day\n";
            cin >> day;
            cout << "month\n";
            cin >> month;
            cout << "year\n";
            cin >> year;
            s = { name,surname,role,{day,month,year} };
            l.push_back(s);
            break;
        case 3:
            l.print();
            break;

        case 4:
            cout << "Введите элемент" << endl;
            cout << "surname\n";
            cin >> surname;
            l.find(surname);
            break;
        case 5:
            cout << "Введите фамилию" << endl;
            cout << "name\n";
            cin >> name;
            cout << "surname\n";
            cin >> surname;
            cout << "role\n";
            cin >> role;
            cout << "day\n";
            cin >> day;
            cout << "month\n";
            cin >> month;
            cout << "year\n";
            cin >> year;
            s = { name,surname,role,{day,month,year} };
            l.remove(s);
            break;
        case 6:
            while (!l.is_empty())
            {
                l.remove_first();
            }
            cout << "Список очищен" << endl;
            break;
        case 7:
            l.ff();
            break;
        case 8:
            l.countAVG();
            break;
        case 9:
            l.countVZ();
            break;
        case 10:
            l.readFile();
            break;
        }
        l.printFILE();
    }
}