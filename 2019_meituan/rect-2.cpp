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

const int maxn = 1e3;
int n;
int x[maxn * 2 + 10];

struct TreeNode
{
    int l, r;
    int real_l, real_r;
    int covered; // whether been covered
    int cnt; // covered length
}segTree[maxn * 2 + 10];

struct Line
{
    int y;
    int x1, x2;
    int flag;
}lines[maxn * 2 + 10];

bool cmp(Line a, Line b)
{
    return a.y < b.y;
}

void build(int t, int l, int r)
{
    segTree[t].l = l;
    segTree[t].r = r;
    segTree[t].real_r = x[l];
    segTree[t].real_l = x[r];

    segTree[t].covered = 0;
    segTree[t].cnt = 0;

    if(l + 1 == r) return;
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid, r);
}

void calen(int t)
{
    if(segTree[t].covered > 0)
    {
        segTree[t].cnt = segTree[t].real_r - segTree[t].real_l + 1;
        return;
    }

    if(segTree[t].r - segTree[t].l == 1) segTree[t].cnt = 1;
    else segTree[t].cnt = segTree[t << 1].cnt + segTree[t << 1 | 1].cnt;
}

void update(int t, Line line)
{
    // line.x1 ~ line.x2 covered segTree[t].real_l ~ real_r => add 1
    if(segTree[t].real_l >= line.x1 && segTree[t].real_r <= line.x2)
    {
        segTree[t].covered += line.flag;
        calen(t);
        return;
    }

    // line not in the segTree[t] covered line
    if(segTree[t].real_l > line.x1 || segTree[t].real_r < line.x2) return;

    // uodate the child node
    update(t << 1, line);
    update(t << 1 | 1, line);

    // update cnt from leaf to parent
    calen(t);
}


int main()
{   
    int x1, x2, y1, y2;
    while(cin >> n)
    {
        int t = 1;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            lines[t].y = y2;
            lines[t].x1 = x1;
            lines[t].x2 = x2;
            lines[t].flag = 1;
            x[t] = x1;
            ++t;

            lines[t].y = y1;
            lines[t].x1 = x1;
            lines[t].x2 = x2;
            lines[t].flag = -1; 
            x[t] = x2;
            ++t;           
        }
        cout << "t = " << t << endl;
        sort(lines + 1, lines + t, cmp);
        sort(x + 1, x + t);
        for(int i = 1; i < t; ++i)
        {
            cout << "x" << i << " = " << x[i] << endl;
        }
        
        build(1, 1, t);

        int res = 0;
        update(1, lines[1]);
        for(int i = 2; i < t; ++i)
        {
            res += (lines[i].y - lines[i - 1].y + 1) * segTree[1].cnt;
            update(1, lines[i]);
        }

        printf("Covered area = %d\n", res);
    }
    return 0;
}