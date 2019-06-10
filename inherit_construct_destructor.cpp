# include <bits/stdc++.h>
using namespace std; 

class A
{
public:
	static A *GetInstance()
	{
		return (new A());
	}

	static void DeleteInstance(A *pInstance)
	{
		delete pInstance;
	}

private:
	A(){cout << "in A" << endl;}
	~A(){}
};

class B : A
{
public:
	void print()
	{
		cout << "in B" << endl;
	}
};

int main()
{
	A *pA = A::GetInstance();
	A::DeleteInstance(pA);
	B b;
	b.print();
	return 0;
}