# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cstring>
using namespace std;

int n, cnt;
const int maxn = 5e5 + 10;
int high = -1;

struct Node
{
	int x;
	int y;
}node[maxn], res[maxn];

int cmp(Node a, Node b)
{
	if (a.x == b.x) return a.y > b.y;
	return a.x > b.x;
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		cnt = 0;
		memset(res, 0, sizeof(res));
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &node[i].x, &node[i].y);
		}

		sort(node, node+n, cmp);
		for(int i = 0; i < n; ++i)
		{
			if(node[i].y > high)
			{
				high = node[i].y;
				res[cnt].x = node[i].x;
				res[cnt++].y = node[i].y;
			}
		}

		for(int i = cnt - 1; i >= 0; --i)
		{
			printf("%d %d\n", res[i].x, res[i].y);
		}

	}
	return 0;
}

// 5
// 1 2
// 5 3
// 4 6
// 7 5
// 9 0