# include <bits/stdc++.h>
using namespace std;

int NumberOf1(int n)
{
	int count = 0;
	unsigned int value = 1;
	while(value != 0)
	{
		if(value & n)
		{
			count++;
		}
		value = value << 1;
	}
	return count;
}

int main()
{
	int test_0x80000000 = 0x80000000;
	int test_0xFFFFFFFF = 0xFFFFFFFF;
	cout << test_0x80000000 << endl;  //-2147483648
	cout << INT_MIN << endl;          // -2147483648
	cout << test_0xFFFFFFFF << endl;  // -1
	cout << INT_MAX << endl;          //2147483647
	cout << NumberOf1(-8) << endl;    //29
	return 0;
}

