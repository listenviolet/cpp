#include <bits/stdc++.h>
using namespace std;

class A
{
private:
	int n1;
	int n2;
	static int n3;
public:
	A():n2(0), n1(n2 + 2){}
	// A(){}
	void Print()
	{
		cout << "n1 = " << n1 << " n2 = " << n2 << " n3 = " << n3 << endl;
	}
};

int A::n3;

int main()
{
	A a;
	a.Print();

	int x;
	cout << x << endl;
	return 0;
}

// n1 = 32766 n2 = 0 n3 = 0
// 0

// in class:
// only the class type member will be default initialized; => n3
// others will be randomly initialized; => n1

// initialize order: 
// same as the var declaration order (n1 -> n2)
// not the initialized list order(n2 -> n1)

// n3: default init n3 = 0;
// n1: n1 = n2 + 2 : as n2 hasn't been init -> random => n1 => random
// n2: n2 = 0

// x: x = 0