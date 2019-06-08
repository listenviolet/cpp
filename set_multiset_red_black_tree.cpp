# include <bits/stdc++.h>
using namespace std; 

int main()
{
	set<int> c;
	int n;
	cin >> n;
	int number;
	for(int i = 0; i < n; ++i)
	{
		cin >> number;
		c.insert(number);
	}

	set<int>::iterator it;
	for(it = c.begin(); it != c.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}