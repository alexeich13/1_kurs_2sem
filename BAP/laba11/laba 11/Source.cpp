#include <iostream>
using namespace std;

struct node
{
	int info;
	node* l, * r;
};

node* tree1 = NULL;

void push(int a, node** t) {
	if ((*t) == NULL) {
		(*t) = new node;
		(*t)->info = a;
		(*t)->l = (*t)->r = NULL;
		return;
	}

	if (a > (*t)->info)
		push(a, &(*t)->r);
	else
		push(a, &(*t)->l);
}

void print(node* t, int u) {
	if (t == NULL) return;
	else
	{
		print(t->r, ++u);
		for (int i = 0; i < u; ++i)
			cout << "|";
		cout << t->info << endl;
		u--;
	}
	print(t->l, ++u);


}

void printLevel(node* t, int level) {
	if (t == NULL) return;
	else {
		printLevel(t->l, level - 1);
		if (level == 0) {
			cout << t->info << endl;
		}
		printLevel(t->r, level - 1);
	}
}
void del(node** t)
{
	if (t != nullptr)
	{
		if ((*t)->l)del(&(*t)->l);
		if ((*t)->r)del(&(*t)->r);
		delete* t;
		*t = nullptr;
	}
}
void check(node* t)
{
	if (t == NULL)
	{
		cout << "������ ���" << endl;
	}
	else
	{
		return;
	}
}

int main() {
	setlocale(0, "");
	int Amount, newNumber;
	cout << "������� ���������� ���������:\t";
	cin >> Amount;
	cout << "\n������� �����:\n";
	for (int i = 0; i < Amount; ++i) {
		cin >> newNumber;
		push(newNumber, &tree1);
	}
	cout << "\n������:\n";
	print(tree1, 0);
	cout << "\n������:\n";
	printLevel(tree1, 0);
	cout << "\n1 �������:\n";
	printLevel(tree1, 1);
	cout << "\n2 �������:\n";
	printLevel(tree1, 2);
	cout << "\n3 �������:\n";
	printLevel(tree1, 3);
	cout << endl;
	del(&tree1);
	check(tree1);
}