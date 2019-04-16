# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;

typedef struct ArcNode
{
    int adjvex;
    ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    int id;
    ArcNode *firstarc;
}VNode;

typedef struct Graph
{
    VNode adjlist[maxn];
    int n;
    int e;
}Graph;

int NumChildren(int index, Graph G, int &num)
{
    ArcNode *p = G.adjlist[index].firstarc;
    while(p)
    {
        NumChildren(p -> adjvex, G, ++num);
        p = p -> nextarc;
    }
    return num;
}

int main()
{
    while(cin >> n)
    {
        Graph G;
        G.n = n;
        G.e = n - 1;
        for(int i = 1; i <= n; ++i)
        {
            G.adjlist[i].id = i;
            G.adjlist[i].firstarc = nullptr;
        }

        for(int i = 1; i <= n - 1; ++i)
        {
            int child_id, parent_id;
            cin >> child_id >> parent_id;
            ArcNode *e = new ArcNode;
            e -> adjvex = child_id;
            e -> nextarc = G.adjlist[parent_id].firstarc;
            G.adjlist[parent_id].firstarc = e;
        }
        // cout << "input finished." << endl;
        vector<int> numOfChildren;
        ArcNode *p = G.adjlist[1].firstarc;
        while(p)
        {
            // cout << p -> adjvex << endl;
            int num = 1;
            num = NumChildren(p -> adjvex, G, num);
            numOfChildren.push_back(num);
            p = p -> nextarc;
        }

        int Max = *max_element(numOfChildren.begin(), numOfChildren.end());
        cout << Max << endl;

    }
    return 0;
}

// Description:
// 时间限制：C/C++语言 1000MS；其他语言 3000MS
// 内存限制：C/C++语言 65536KB；其他语言 589824KB
// 题目描述：
// 体育场突然着火了，现场需要紧急疏散，但是过道真的是太窄了，同时只能容许一个人通过。
// 现在知道了体育场的所有座位分布，座位分布图是一棵树，
// 已知每个座位上都坐了一个人，安全出口在树的根部，也就是1号结点的位置上。
// 其他节点上的人每秒都能向树根部前进一个结点，
// 但是除了安全出口以外，没有任何一个结点可以同时容纳两个及以上的人，
// 这就需要一种策略，来使得人群尽快疏散，问在采取最优策略的情况下，
// 体育场最快可以在多长时间内疏散完成。

// 输入
// 第一行包含一个正整数n，即树的结点数量（1<=n<=100000）。

// 接下来有n-1行，每行有两个正整数x，y，表示在x和y结点之间存在一条边。(1<=x<=y<=n)

// 输出
// 输出仅包含一个正整数，表示所需要的最短时间


// 样例输入
// 6
// 2 1
// 3 2
// 4 3
// 5 2
// 6 1
// 样例输出
// 4

// alg:
// for every leaf node: the step for its children to come to it is 0 
// and add one to leave this node;

// For example:
//     A
//    / \
//   B   C
// the step for A's children to come to A is: steps(B) + steps(C) + 1;
// step1: A and B move upper

//     B
//      \
//       C

// step2: B and C move upper

//     C 

// step3: C move upper

//     null

// As the root node can exists more than one people, 
// so there is no need to pass one by one to the node.

// the final num of min step is
// max(steps(root.child1), steps(root.child2), ..., steps(root.childn)) + 1


