# include <iostream>
# include <cmath>
# include <cstring>
# include <cstdio>
using namespace std;

int dp[201][1001];

int main()
{
	int k;
	int a, x, b, y;

	while(scanf("%d\n%d %d %d %d", &k, &a, &x, &b, &y) != EOF)
	{
		cout << k << " " << a << " " << x << " " << b << " " << y << endl;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		
		for(int i = 1; i <= x + y; ++i)
		{
			for(int j = 0; j <= k; ++j)
			{
				int tmp_cost;
				if(i <= x) tmp_cost = a;
				else tmp_cost = b;

				if(j < tmp_cost)
					dp[i][j] = dp[i - 1][j] % 1000000007;
				else
				{
					dp[i][j] = dp[i - 1][j] % 1000000007 + dp[i - 1][j - tmp_cost] % 1000000007;
				}
			}
		}
		// for(int i = 0; i <= x + y; ++i)
		// {
		// 	for(int j = 0; j <= k; ++j)
		// 		cout << dp[i][j] << " ";
		// 	cout << endl;
		// }
		cout << dp[x + y][k] % 1000000007;
	}
	return 0;
}