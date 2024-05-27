#include <iostream>
#include <iomanip>

using namespace std;

struct Node {
	float Number;
	Node* next;
};

struct Queue {
	int size = 0;
	Node* head;
	Node* tail;
};
void CreateQueue(Queue* Q) {
	Q->head = new Node();
	Q->head->next = NULL;
	Q->tail = Q->head;
	Q->size = 0;
}
void AddElem(Queue* Q) {
	float newElem;
	cout << "������� �������:" << endl;
	cin >> newElem;
	cout << endl;
	Q->tail->next = new Node();
	Q->tail = Q->tail->next;
	Q->tail->Number = newElem;
	Q->tail->next = NULL;
	Q->size++;
}
int OutQueue(Queue* Q) {
	if (Q->head == Q->tail) {
		cout << "������� �����" << endl;
		return 0;
	}
	else {
		Node* Temp = Q->head->next;
		cout << endl;
		while (Temp) {
			cout << Temp->Number << endl;
			Temp = Temp->next;
		}
	}
}
int Shift(Queue* Q) {
	if (Q->head == Q->tail) {
		cout << "������� �����" << endl;
		return 0;
	}
	else {
		float max = 0;
		Node* Temp = Q->head->next;
		while (Temp) {
			if (Temp->Number > max)
				max = Temp->Number;
			Temp = Temp->next;
		}
		cout << "���������� ��������:" << max << endl;
		cout << "������� �� �������:" << endl;
		Temp = Q->head;
		Temp->Number = max;
		cout << Temp->Number << endl;
		while (Temp) {
			if (Temp->Number != max) cout << Temp->Number << endl;
			Temp = Temp->next;
		}
		cout << endl << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Queue t;
	int choice;
	CreateQueue(&t);
	for (;;)
	{
		cout << "�������� �������:" << endl;
		cout << "1 - ���������� �������� � �������" << endl;
		cout << "2 - ����� �������" << endl;
		cout << "3 - ����������� �����" << endl;
		cout << "4 - �����" << endl;
		cin >> choice;
		switch (choice)
		{

		case 1:
			AddElem(&t);
			break;
		case 2:
			OutQueue(&t);
			break;
		case 3:
			Shift(&t);
			break;
		case 4:
			return 0;
			break;

		}
	}
}