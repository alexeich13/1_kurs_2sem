#include <iostream>
#include<tchar.h>
#include <iomanip>
#include<fstream>
using namespace std;

struct AAA
{
	int x;
	void print();
	int getPriority() const;
};
namespace heap
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap
	{
		int size;
		int maxSize;
		void** storage;              // 
		CMP(*compare)(void*, void*);
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			size = 0;
			storage = new void* [maxSize = maxsize];
			compare = f;
		};
		int left(int ix);
		int right(int ix);
		int parent(int ix);
		bool isFull() const
		{
			return (size >= maxSize);
		};
		bool isEmpty() const
		{
			return (size <= 0);
		};
		bool isLess(void* x1, void* x2) const
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL;
		};
		void swap(int i, int j);
		void heapify(int ix);
		void insert(void* x);
		void* extractMax();
		void extractMin();
		void extractI();
		void unionHeap(void* x);
		void scan(int i) const;
		void readFile();
		void leaves();
		void level();
	};
	Heap create(int maxsize, CMP(*f)(void*, void*));
};

heap::CMP cmpAAA(void* a1, void* a2) 
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1
}
//-------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	heap::Heap h3 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод 1 кучи на экран" << endl;
		cout << "2 - добавить элемент в 1 кучу" << endl;
		cout << "3 - вывод 2 кучи на экран" << endl;
		cout << "4 - добавить элемент в 2 кучу" << endl;
		cout << "5 - объединение 2 куч" << endl;
		cout << "6 - удалить минимальный элемент 1 кучи" << endl;
		cout << "7 - удалить i-й элемент 1 кучи" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: h1.scan(0);
			break;
		case 2:
		{AAA* a = new AAA;
		cout << "введите ключ" << endl; cin >> k;
		a->x = k;
		h1.insert(a);
		}
		break;
		case 3: h2.scan(0);
			break;
		case 4:
		{AAA* a = new AAA;
		cout << "введите ключ" << endl; cin >> k;
		a->x = k;
		h2.insert(a);
		h1.insert(a);
		}
		break;
		case 5:
			h1.scan(0);
			break;
		case 6: h1.extractMin();
			break;
		case 7: h1.extractI();
			break;
		default: cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
void AAA::print()

{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}

	void Heap::scan(int i) const 
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Êó÷à ïóñòà";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}
	void Heap::extractMin()
	{
		int min = 100, a;
		int** A = (int**)storage;
		void* rc = nullptr;
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (*A[i] < min)
				{
					min = *A[i];
					a = i;
				}
			}
			int i = parent(a);
			for (int i = a; i < size - 1; i++)
			{
				storage[i] = storage[i + 1];
			}
			size--;
			heapify(0);
		}

	}
	void Heap::extractI()
	{
		int i;
		cout << "Ââåäèòå i:";
		cin >> i;
		cout << endl;
		if (!isEmpty())
		{
			for (int j = i; j < size - 1; j++)
			{
				storage[j] = storage[j + 1];
			}
			size--;
			heapify(0);
		}
	}
	void Heap::unionHeap(void* x)
	{
		int i;
		for (i = 0; i < size - 1; i++)
		{
			storage[i] = storage[i + 1];
		}
		heapify(0);

		storage[i = ++size - 1] = x;
		while (i > 0 && isLess(storage[parent(i)], storage[i]))
		{
			swap(parent(i), i);
			i = parent(i);
		}
	}


}