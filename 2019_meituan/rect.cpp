// 时间限制：C/C++语言 1000MS；其他语言 3000MS
// 内存限制：C/C++语言 65536KB；其他语言 589824KB
// 题目描述：
// 在二维平面上有一个无限的网格图形，初始状态下，所有的格子都是空白的。现在有n个操作，每个操作是选择一行或一列，并在这行或这列上选择两个端点网格，把以这两个网格为端点的区间内的所有网格染黑（包含这两个端点）。问经过n次操作之后，共有多少个格子被染黑，显然在众多操作中，很容易重复染色同一个格子，这个时候只计数一次。

// 输入
// 输入第一行包含一个正整数n（1<=n<=10000）.

// 接下来n行，每行四个整数，x1，y1，x2，y2，分别表示一个操作的两端格子坐标。（-10^9<=x1,y1,x2,y2<=10^9）,若x1=x2则是在一列上染色，若y1=y2，则是在一行上染色，保证每次操作是在一行或一列上染色。 

// 输出
// 输出仅包含一个正整数，表示被染色的格子的数量。


// 样例输入
// 3
// 1 2 3 2
// 2 5 2 3
// 1 4 3 4
// 样例输出
// 8

# include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int n;

struct TreeNode
{
	int l;
	int r;

	int real_l, real_r;

	int cnt;
}segTree[maxn * 2 + 10];

// line parallel to x axis
// y: y
// x1: left 
// x2: right
// flag: top = 1; bottom = 1
struct Line
{
	int y;
	int x1, x2;
	int flag;
}line[maxn * 2 + 10];

void build(int t, int l, int r)
{
	segTree[t].l = l;
	segTree[t].r = r;

	segTree[t].real_l = y[l];
	segTree[t].real_r = y[r];

	segTree[t].cnt = 0;

	if(l + 1 == r) return;
	int mid = (l + r) >> 1;
	build(t << 1, l, mid);     // t * 2
	build(t << 1 | 1, mid, r); // t * 2 + 1
}

bool cmp(Line a, Line b)
{
	return a.x < b.x;
}

int main()
{
	int x1, y1, x2, y2;
	while(cin >> n)
	{
		t = 1;
		memset(segTree, 0, sizeof(segTree));
		memset(line, 0, sizeof(line));

		for(int i = 1; i <= n; ++i)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			line[t].y = y2;
			line[t].x1 = x1;
			line[t].x2 = x2;
			line[t].flag = -1;
			
			++t;

			line[t].y = y1;
			line[t].x1 = x1;
			line[t].x2 = x1;
			line[t].flag = 1;
			++t;
		}

		sort(line + 1, line + t, cmp);
		sort(y + 1, y + t);

		build(1, 1, t - 1);


	}
	return 0;
}