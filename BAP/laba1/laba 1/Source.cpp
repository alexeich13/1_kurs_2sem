#include <iostream>
using namespace std;

float koren(float a, float b, float (*f)(float))
{
	float x, e = 0.001;
	do
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0)
			b = x;
		else a = x;
	} while (abs(a - b) > 2 * e);
	cout << x << endl;
	return x;
}

float f1(float x)
{
	float z = cos(x) + x - 7;
	return z;
}

float f2(float x)
{
	float z = exp(x) - (1 / x);
	return z;
}

    void main(){
	float aa, bb;
	cout << "Enter a: " << endl;
	cin >> aa;
	cout << "Enter b: " << endl;
	cin >> bb;
	float* a = &aa;
	float* b = &bb;
    koren(*a, *b, f1);
	koren(*a, *b, f2);
}