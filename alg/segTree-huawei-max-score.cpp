#include <bits/stdc++.h>
using namespace std;
int N, M;
const int maxn = 30000;
const int maxm = 5000;
int scores[maxn];

struct Operation
{
	char c;
	int A;
	int B;
}operations[maxm + 5];

struct TreeNode
{
	int l, r;
	int max_score;
}segTree[maxn * 4 + 5];

void buildTree(int t, int l, int r)
{
	segTree[t].l = l;
	segTree[t].r = r;
	segTree[t].max_score = 0;
	if(l + 1 == r) return;
	int mid = (l + r) >> 1;
	buildTree(t << 1, l, mid);
	buildTree(t << 1 | 1, mid, r);
}

void update(int t, int *scores)
{
	if(segTree[t].l + 1 == segTree[t].r)
	{
		int id = segTree[t].r;
		segTree[t].max_score =scores[id];
		return; 
	}
	if(segTree[t].l == segTree[t].r)
	{
		segTree[t].max_score = 0;
		return;
	}
	update(t << 1, scores);
	update(t << 1 | 1, scores);
	segTree[t].max_score = max(segTree[t << 1].max_score, segTree[t << 1 | 1].max_score);
}

void query(int t, int A, int B, int &score)
{
	if(segTree[t].l + 1 >= A && segTree[t].r <= B) { score = max(score, segTree[t].max_score); return;}
	if(segTree[t].l >= B || segTree[t].r < A) return;
	query(t << 1, A, B, score);
	query(t << 1 | 1, A, B, score);
}

int loc(int t, int A)
{
	if(segTree[t].l + 1 == segTree[t].r && segTree[t].r == A) 
	{
		return t;
	}
	int mid = (segTree[t].l + segTree[t].r) >> 1;
	if(mid >= A) return loc(t << 1, A);
	else return loc(t << 1 | 1, A);
}

void changeSegTree(int A, int B)
{
	scores[A] = B;
	int t = loc(1, A);
	segTree[t].max_score = B;
	t /= 2;
	int origin;
	while(t >= 1)
	{
		origin = segTree[t].max_score;
		segTree[t].max_score = max(segTree[t << 1].max_score, segTree[t << 1 | 1].max_score);
		if(origin == segTree[t].max_score) break;
		t /= 2;
	}
}

int main()
{
	while(cin >> N >> M)
	{
		int score = 0;
		for(int i = 1; i <= N; ++i)
		{
			cin >> scores[i];
		}
		int first, second;
		for(int i = 1; i <= M; ++i)
		{
			cin >> operations[i].c;
			cin >> first >> second;
			if(operations[i].c == 'Q')
			{
				operations[i].A = min(first, second);
				operations[i].B = max(first, second);
			}
			else 
			{
				operations[i].A = first;
				operations[i].B = second;
			}
		}

		buildTree(1, 0, N);
		update(1, scores);

		for(int i = 1; i <= M; ++i)
		{
			if(operations[i].c == 'Q')
			{
				score = 0;
				query(1, operations[i].A, operations[i].B, score);
				cout << score << endl;
			}
			else if(operations[i].c == 'U')
			{
				changeSegTree(operations[i].A, operations[i].B);
			}
		}

	}
	return 0;
}

// segtree size: N * 4
// why have to be N * 4? pf: https://blog.csdn.net/gl486546/article/details/78243098
// Notice:
// A = B
// A > B when c == 'Q' : A < B; else keep the origin order

// 老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩.

// 输入描述:
// 输入包括多组测试数据。
// 每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
// 学生ID编号从1编到N。
// 第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
// 接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
// 当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

// 输出描述:
// 对于每一次询问操作，在一行里面输出最高成绩.

// input: 
// 12 27
// 1 15 16 15 6 19 24 39 26 26 14 7
// U 8 80
// Q 1 3	
// Q 5 3      
// Q 1 3	
// U 5 14	
// Q 12 10	
// Q 5 8	
// U 8 62
// U 3 8
// U 2 47
// U 7 42
// U 2 1
// Q 3 4	
// Q 1 10	
// Q 4 10	
// U 11 7
// Q 6 5	
// Q 2 2	
// Q 10 10	
// U 7 12
// U 2 45
// U 10 51
// U 4 82
// U 7 9
// U 2 64
// U 10 3
// Q 11 5	

// output:
// 16
// 16
// 16
// 26
// 80
// 15
// 62
// 62
// 19
// 1
// 26
// 62