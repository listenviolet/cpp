# include <bits/stdc++.h>
using namespace std;

int main()
{
	int length = 10;
	char **strNumbers = (char**)(new int[length]);
	
	for(int i = 0; i < length; ++i)
	{
		cout << strNumbers[i] << " ";
	}
	cout << endl;
	return 0;
}