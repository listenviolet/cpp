# include <iostream>
# include <cstdio>
# include <cstring>
#include <algorithm>
using namespace std;

# define LL long long 
const int maxn = 1e5 + 10;

struct node{
	int x, y;
}machines[maxn], tasks[maxn];

int cnt[105]; // cnt[i] = num: there are num machines whose level are i

int cmp(node a, node b)
{
	if(a.x == b.x) return a.y > b.y;
	return a.x > b.x;
}

int main()
{
	int n, m; //n:#machines; m: #tasks
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d%d", &machines[i].x, &machines[i].y);
	for(int i = 0; i < m; ++i) scanf("%d%d", &tasks[i].x, &tasks[i].y);
	sort(machines, machines + n, cmp);
	sort(tasks, tasks + m, cmp);

	int num = 0;
	LL benifit = 0;
	memset(cnt, 0, sizeof(cnt));

	int i, j, k;
	for(i = 0, j = 0; i < m; ++i)
	{
		while(j < n && machines[j].x >= tasks[i].x)
		{
			cnt[machines[j].y]++;
			j++;
		}

		for(k = tasks[i].y; k <= 100; ++k)
		{
			if(cnt[k])
			{
				cnt[k]--;
				num++;
				benifit = benifit + 200 * tasks[i].x + 3 * tasks[i].y;
				break;
			}
		}
	}

	printf("%d %lld\n", num, benifit);
	return 0;
}