# include <bits/stdc++.h>
using namespace std;
char arr[60][60];
int n, m;

void turn_B(int x, int y)
{
	while(x < n && y >= 0 && (arr[x][y] == 'B' || arr[x][y] == 'G'))
	{
		if(arr[x][y] == 'B') arr[x][y] = 'X';
		else if(arr[x][y] == 'G') arr[x][y] = 'Y';
		x++;
		y--;
	}
}

void turn_Y(int x, int y)
{
	while(x < n && y < m && (arr[x][y] == 'Y' || arr[x][y] == 'G'))
	{
		if(arr[x][y] == 'Y') arr[x][y] = 'X';
		else if(arr[x][y] == 'G') arr[x][y] = 'B';
		x++;
		y++;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(arr[i][j] == 'G')
			{
				turn_B(i, j);
				turn_Y(i, j);
				cnt += 2;
			}
			if(arr[i][j] == 'B')
			{
				turn_B(i, j);
				cnt++;
			}
			if(arr[i][j] == 'Y')
			{
				turn_Y(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	return 0;
}