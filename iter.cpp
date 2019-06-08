#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> leastNumbers;
	set<int>::iterator set_iter;
	int n, number;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> number;
		leastNumbers.insert(number);
	}

	for(set_iter = leastNumbers.begin(); set_iter != leastNumbers.end(); ++set_iter)
	{
		cout << *set_iter << " ";
	}
	cout << endl;

	set_iter = leastNumbers.end();
	set_iter--;
	cout << *set_iter << endl;
	return 0;
}