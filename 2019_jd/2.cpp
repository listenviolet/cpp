# include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;

struct Node
{
    int id;
    vector<Node> children;
}nodes[maxn];

int main()
{
    while(cin >> n)
    {
        for(int i = 1; i <= n; ++i)
        {
            nodes[i].id = i;
        }

        for(int i = 1; i < n; ++i)
        {
            int child_id, parent_id;
            cin >> child_id >> parent_id;
            nodes[parent_id].children.push_back(nodes[child_id]);
        }
        
    }
    return 0;
}