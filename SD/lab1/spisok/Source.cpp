#include "iostream" 
using namespace std;

struct list
{
	long val;
	list* next;
}*slist;

int main()
{
	setlocale(0, "");

	int n;

	cout << "Введите число элементов: ";
	cin >> n;

	cout << "Введите элементы: " << endl;
	for (int i = 0; i < n; i++)
	{
		slist = new list;
		cin >> slist->val;
		slist->next = new list;
		slist = slist->next;
	}
	cout << endl;

	return 0;
}