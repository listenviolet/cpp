# include <bits/stdc++.h>
using namespace std;

void change_arr(char arr[][3])
{
	arr[0][0] = 'A';
}

int main()
{
	char arr[2][3];
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}
	}
	change_arr(arr);
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}