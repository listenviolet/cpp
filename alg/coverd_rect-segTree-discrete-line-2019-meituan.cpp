# include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n;
set<int> x_set;
set<int>::iterator it;
int x[maxn * 2 + 10];

struct TreeNode
{
    int l, r;
    int real_l, real_r;
    int covered; // covered times
    double cnt; // total covered length in this zone
}segTree[maxn * 4];

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
    segTree[t].real_l = x[l];
    segTree[t].real_r = x[r];

    segTree[t].covered = 0;
    segTree[t].cnt = 0;

    if(l == r) return;
    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid + 1, r);
}

void calen(int t)
{
    if(segTree[t].covered > 0)
    {
        double tmp = 0;
        if(segTree[t].l == segTree[t].r) tmp = 0.5;
        segTree[t].cnt = segTree[t].real_r - segTree[t].real_l + tmp;
        return;
    }

    if(segTree[t].r - segTree[t].l == 0) segTree[t].cnt = 0 ;
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
    if(segTree[t].real_l > line.x2 || segTree[t].real_r < line.x1) return;

    // update the child node
    update(t << 1, line);
    update(t << 1 | 1, line);
    calen(t); // 每个节点的cnt的值为其孩子节点cnt的值的加和, 更新完孩子节点cnt后要更新t节点cnt
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
            lines[t].y = y1;
            lines[t].x1 = x1 - 1;
            lines[t].x2 = x2;
            lines[t].flag = -1;
            x_set.insert(x1 - 1);
            ++t;

            lines[t].y = y2 - 1;
            lines[t].x1 = x1 - 1;
            lines[t].x2 = x2;
            lines[t].flag = 1; 
            x_set.insert(x2);
            ++t;           
        }
        sort(lines + 1, lines + t, cmp);

        int x_index = 1;
        for(it = x_set.begin(); it != x_set.end(); ++it)
        {
            x[x_index++] = *it;
        }
        sort(x + 1, x + x_index);

        build(1, 1, x_index - 1);

        int res = 0;
        update(1, lines[1]);
        for(int i = 2; i < t; ++i)
        {
            int tmp = (lines[i].y - lines[i - 1].y) * segTree[1].cnt;
            res += tmp;
            update(1, lines[i]);
        }

        cout << res << endl;
    }
    return 0;
}