#include <iostream>
#include <string>
#include "windows.h"
using namespace std;

struct Node {
    char word[40];
    int count;
    Node* next; // ������ �� ��������� ����
};
typedef Node* PNode;

PNode CreateNode(char NewWord[])
{
    PNode NewNode = new Node; // ��������� �� ����� ����
    strcpy_s(NewNode->word, NewWord); // �������� �����
    NewNode->count = 1; // ������� ���� = 1
    NewNode->next = NULL; // ���������� ���� ���
    return NewNode; // ��������� ������� � ����� ����
}

PNode Find(PNode Head, char NewWord[])
{
    PNode q = Head;
    while (q && strcmp(q->word, NewWord))
        q = q->next;
    return q;
}

void AddFirst(PNode& Head, PNode NewNode)
{
    NewNode->next = Head;
    Head = NewNode;
}

void AddAfter(PNode p, PNode NewNode)
{
    NewNode->next = p->next;
    p->next = NewNode;
}

void AddBefore(PNode& Head, PNode p, PNode NewNode)
{
    PNode q = Head;
    if (Head == p) {
        AddFirst(Head, NewNode); // ������� ����� ������ �����
        return;
    }
    while (q && q->next != p) // ���� ����, �� ������� ������� p
        q = q->next;
    if (q) // ���� ����� ����� ����,
        AddAfter(q, NewNode); // �������� ����� ����� ����
}

void AddLast(PNode& Head, PNode NewNode)
{
    PNode q = Head;
    if (Head == NULL) { // ���� ������ ����,
        AddFirst(Head, NewNode); // ��������� ������ �������
        return;
    }
    while (q->next) q = q->next; // ���� ��������� �������
    AddAfter(q, NewNode);
}

void PrintNode(Node* b) {
    Node* print = b;
    while (print != NULL) {
        cout << print->word << endl;
        print = print->next;
    }
}

void PrintNodeKey(Node* b) {
    Node* print = b;
    while (print != NULL) {
        cout << print->word << " " << print->count << endl;
        print = print->next;
    }
}

void DeleteNode(PNode& Head, PNode OldNode)
{
    PNode q = Head;
    if (Head == OldNode)
        Head = OldNode->next; // ������� ������ �������
    else {
        while (q && q->next != OldNode) // ���� �������
            q = q->next;
        if (q == NULL) return; // ���� �� �����, �����
        q->next = OldNode->next;
    }
    delete OldNode; // ����������� ������
}

void ClearNode(PNode& Head) {
    while (Head)
    {
        Node* next = Head->next;
        delete Head;
        Head = next;
    }
}

struct Birthday {
    int day;
    int mounth;
    int year;
};

struct PeopleJobInfo {
    char LastName[50];
    char JobTitle[50];
    int salary = 0;
    Birthday birthday;
    PeopleJobInfo* next;
};

void AddFirst(PeopleJobInfo*& Head, PeopleJobInfo* NewNode)
{
    NewNode->next = Head;
    Head = NewNode;
}

void AddAfter(PeopleJobInfo* p, PeopleJobInfo* NewNode)
{
    NewNode->next = p->next;
    p->next = NewNode;
}

PeopleJobInfo* CreateJobNode(char NewLastName[], char NewJobTitle[], int NewSalary, int Day, int Mounth, int Year)
{
    PeopleJobInfo* NewNode = new PeopleJobInfo; // ��������� �� ����� ����
    strcpy_s(NewNode->LastName, NewLastName);
    strcpy_s(NewNode->JobTitle, NewJobTitle);
    NewNode->salary = NewSalary;
    NewNode->birthday.day = Day;
    NewNode->birthday.mounth = Mounth;
    NewNode->birthday.year = Year;
    NewNode->next = NULL; // ���������� ���� ���
    return NewNode; // ��������� ������� � ����� ����
}

void AddFirstJOB(PeopleJobInfo*& Head, PeopleJobInfo* NewNode)
{
    PeopleJobInfo* q = Head;
    if (Head == NULL) { // ���� ������ ����,
        AddFirst(Head, NewNode); // ��������� ������ �������
        return;
    }
    while (q->next) q = q->next; // ���� ��������� �������
    AddAfter(q, NewNode);
}

PNode Head = NULL, p, where;
PeopleJobInfo* HeadJ = NULL, * pJ, * whereJ;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    //cout << "������� ���������� ����������\n";
    int select, key = 1, len = 0, len1 = 0;
    //cin >> select;
    system("cls");


    while (true)
    {
        int sum = 0;
        char x[50], LastName[50];
        char JobTitle[50];
        int salary = 0, day, mounth, year;
        bool flag = false;
        cout << "********************************************\n"
            << "********************************************\n"
            << "** 1) �������� ������� � ������           **\n"
            << "** 2) �������� ������� � �����            **\n"
            << "** 3) ������� �������� ������ � �������   **\n"
            << "** 4) ����� ������� �� ��������� �������� **\n"
            << "** 5) ������� �������� �������            **\n"
            << "** 6) ������� n ���������                 **\n"
            << "** 7) �������� ������                     **\n"
            << "** 8) ������ ����� ������ 40 ���          **\n"
            << "** 9) �������� �������� ��������          **\n"
            << "** 10) �������� ��������� ��������        **\n"
            << "** 11) �����                              **\n"
            << "** 12) �������� ���� � ��������� JOB      **\n"
            << "********************************************\n"
            << "********************************************\n";
        cin >> select;
        system("cls");

        switch (select)
        {
        case 1:
            cin >> x;
            p = CreateNode(x);
            p->count = key;
            key++;
            len++;
            AddFirst(Head, p);
            system("cls");
            break;

        case 2:
            cin >> x;
            p = CreateNode(x);
            p->count = key;
            key++;
            len++;
            AddLast(Head, p);
            system("cls");
            break;
        case 3:
            PrintNode(Head);
            system("PAUSE");
            system("cls");
            break;

        case 4:
            cin >> x;
            p = Find(Head, x);
            if (p == NULL)
                cout << "���� � ����� �������� ���\n";
            else
                cout << "���� � �������� " << x << " ������� � ������, ��� ���� " << p->count << "\n";
            system("PAUSE");
            system("cls");
            break;

        case 5:
            PrintNodeKey(Head);
            cin >> x;
            p = Find(Head, x);
            if (p == NULL)
                cout << "���� � ����� �������� ���\n";
            else {
                DeleteNode(Head, p);
                len--;
            }
            system("cls");
            break;

        case 6:
            int n;
            PrintNodeKey(Head);
            cout << "���������� ��������� ������� ���� ������� � �������� �������� � �������� ������ �������\n";
            cin >> n >> x;
            p = Find(Head, x);

            for (int i = 0; i < n; i++) {
                //Node* p1;
                where = p->next;
                DeleteNode(Head, p);
                p = where;
                len--;
            }

            system("cls");
            break;

        case 7:
            ClearNode(Head);
            break;

        case 8:
            for (int i = 0; i < len1; i++) {
                whereJ = pJ->next;
                if (2022 - whereJ->birthday.year > 40) {
                    cout << whereJ->LastName << "������ 40 ���\n";
                }
                pJ = whereJ;
            }
            system("PAUSE");
            system("cls");
            break;

        case 9:
            sum = 0;
            for (int i = 0; i < len1; i++) {
                whereJ = pJ->next;
                sum += 2022 - pJ->birthday.year;
                pJ = whereJ;
            }
            cout << "������� ������� " << sum / len1 << "\n";
            system("PAUSE");
            system("cls");
            break;

        case 10:
            sum = 0;
            for (int i = 0; i < len1; i++) {
                whereJ = pJ->next;
                sum += pJ->salary;
                pJ = whereJ;
            }
            cout << "������� �������� " << sum << "\n";
            system("PAUSE");
            system("cls");
            break;


        case 11:
            cout << "����������";
            for (int i = 0; i < 15; i++) {
                cout << '.';
                Sleep(500);
            }
            cout << "\n";
            flag = true;
            break;
        case 12:
            cout << "�������, �������� ������, ��������, ����, �����, ��� ��������\n";
            cin >> LastName >> JobTitle >> salary >> day >> mounth >> year;
            pJ = CreateJobNode(LastName, JobTitle, salary, day, mounth, year);
            AddFirstJOB(HeadJ, pJ);
            len1++;
            system("cls");
            break;
        default:
            system("cls");
            break;
        }

        if (flag)
            break;
    }
}