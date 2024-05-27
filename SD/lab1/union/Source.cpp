#include <iostream>
using namespace std;

union
{
	short int name1;
	int name2;
	long int name3;
} myUnion;

int main()
{
	myUnion.name1 = 22;
	cout << myUnion.name1 << endl;
	myUnion.name3 = 222222222;
	cout << myUnion.name3 << endl;
	myUnion.name1 = 12;
	cout << myUnion.name1 << endl; // снова обращаемся к name1
}
