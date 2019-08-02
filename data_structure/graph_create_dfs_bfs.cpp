#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int visit[maxn];

struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
};

struct VNode
{
	char data;
	ArcNode *firstarc;
};

struct Graph
{
	VNode adjlist[maxn];
	int n, e;
};

void createGraph(Graph *G)
{
	int n, e;
	cout << "number of nodes and edges:" << endl;
	cin >> n >> e;

	cout << "data of nodes:" << endl;
	for(int i = 0; i < n; ++i)
	{
		// getchar();
		cin >> G -> adjlist[i].data;
		G -> adjlist[i].firstarc = NULL;
	}

	cout << "input (v1, v2): " << endl;
	int v1, v2;
	for(int i = 0; i < e; ++i)
	{
		cin >> v1 >> v2;
		ArcNode *node = new ArcNode();
		node -> adjvex = v2;
		node -> nextarc = G -> adjlist[v1].firstarc;
		G -> adjlist[v1].firstarc = node;

		// undirected graph
		ArcNode *node2 = new ArcNode();
		node2 -> adjvex = v1;
		node2 -> nextarc = G -> adjlist[v2].firstarc;
		G -> adjlist[v2].firstarc = node2;
	}

	cout << "adjacency list:" << endl;
	for(int i = 0; i < n; ++i)
	{
		ArcNode *arcnode = nullptr;
		arcnode = G -> adjlist[i].firstarc;
		while(arcnode)
		{
			cout << "(" << G -> adjlist[i].data << ", " << G -> adjlist[arcnode -> adjvex].data << ")" << " ";
			arcnode = arcnode -> nextarc;
		}
		cout << endl;
	}
}

void dfs(Graph *G, int v)
{
	ArcNode *arcnode = nullptr;
	visit[v] = 1;
	cout << G -> adjlist[v].data << "->";

	arcnode = G -> adjlist[v].firstarc;
	while(arcnode)
	{
		if(visit[arcnode -> adjvex] == 0)
		{
			dfs(G, arcnode -> adjvex);
		}
		arcnode = arcnode -> nextarc;
	}
}

void bfs(Graph *G, int v)
{
	memset(visit, 0, sizeof(visit));
	ArcNode *p;
	queue<int> que;
	cout << G -> adjlist[v].data << "->";
	visit[v] = 1;
	int cur;
	que.push(v);
	while(!que.empty())
	{
		cur = que.front();
		// cout << "cur = " << cur << endl;
		que.pop();
		p = G -> adjlist[cur].firstarc;
		while(p != NULL)
		{
			// cout << "p -> adjvex = " << p -> adjvex << " ";
			// cout << "visit[" << p -> adjvex << "] = " << visit[p -> adjvex] << endl;
			if(visit[p -> adjvex] == 0)
			{
				cout << G -> adjlist[p -> adjvex].data << "->";
				visit[p -> adjvex] = 1;
				// cout << "in que = " << p -> adjvex << " ";
				que.push(p -> adjvex);
			}
			p = p -> nextarc;
		}
	}
}

int main()
{
	Graph G;
	createGraph(&G);
	// dfs(&G, 0);
	bfs(&G, 0);
	return 0;
}

// 4 5
// A B C D 
// 0 1
// 0 2
// 0 3
// 1 2
// 2 3
