# include <iostream>
# include <cstdio>
using namespace std;

char str[60][60];
int n, m;

void dfs_Y(int x, int y)
{
	if(x >= 0 && x < n && y < m && y >= 0 && (str[x][y] == 'Y' || str[x][y] == 'G'))
	{
		if(str[x][y] == 'G') str[x][y] = 'B';
		else str[x][y] = 'X';
		dfs_Y(x - 1, y - 1);
		dfs_Y(x + 1, y + 1);
	}
	return;
}

void dfs_B(int x, int y)
{
	if(x >= 0 && x < n && y < m && y >= 0 && (str[x][y] == 'B' || str[x][y] == 'G'))
	{
		if(str[x][y] == 'G') str[x][y] = 'Y';
		else str[x][y] = 'X';
		dfs_B(x + 1, y - 1);
		dfs_B(x - 1, y + 1);
	}
	return;
}

void display()
{
	cout << "-----------" << endl;
	for(int k = 0; k < n; ++k)
		cout << str[k] << endl;
}

int main()
{
	int cnt;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s", str[i]);
	}

	cnt = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(str[i][j] == 'Y')
			{
				dfs_Y(i, j);
				cnt++;
			}
			else if(str[i][j] == 'B')
			{
				dfs_B(i, j);
				cnt++;
			}
			else if(str[i][j] == 'G')
			{
				dfs_Y(i, j);
				str[i][j] = 'B';
				dfs_B(i, j);
				cnt += 2;
			}		
		}	
	}

	
	printf("%d\n", cnt);
	return 0;
}

// 4 4
// YXXB
// XYGX
// XBYY
// BXXY

// out: 3