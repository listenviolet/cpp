# include <bits/stdc++.h>
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
	int n,e;
};

void createGraph(Graph *G)
{
	int n, e;
	cout << "number of nodes and edges:" << endl;
	cin >> n >> e;
	cout << "input node data:" << endl;
	for(int i = 0; i < n; ++i) 
	{
		cin >> G -> adjlist[i].data;
		G -> adjlist[i].firstarc = nullptr;
	}

	cout << "input edges (v1, v2):" <<endl;
	int v1, v2;
	for(int i = 0; i < e; ++i)
	{
		ArcNode *arcnode = new ArcNode();
		cin >> v1 >> v2;
		arcnode -> adjvex = v2;
		arcnode -> nextarc = G ->adjlist[v1].firstarc;
		G -> adjlist[v1].firstarc = arcnode;

		ArcNode *arcnode2 = new ArcNode();
		arcnode2 -> adjvex = v1;
		arcnode2 -> nextarc = G -> adjlist[v2].firstarc;
		G -> adjlist[v2].firstarc = arcnode2;
	}

	cout << "adjacency list:" << endl;
	for(int i = 0; i < n; ++i)
	{
		ArcNode *arcnode = nullptr;
		arcnode = G -> adjlist[i].firstarc;
		while(arcnode)
		{
			cout << "(" << G -> adjlist[i].data << ", " << G -> adjlist[arcnode -> adjvex].data << ")" << endl;
			arcnode = arcnode -> nextarc;
		}
		cout << endl;
	}
}

void dfs(Graph *G, int v)
{
	ArcNode *p;
	visit[v] = 1;
	cout << v << "->";
	p = G -> adjlist[v].firstarc;
	while(p)
	{
		if(visit[p -> adjvex] == 0)
		{
			dfs(G, p -> adjvex);
		}
		p = p -> nextarc;
	}
}

void bfs(Graph *G, int v)
{
	ArcNode *p;
	queue<int> que;
	que.push(v);
	visit[v] = 1;
	cout << v << "->";
	while(!que.empty())
	{
		int cur = que.front();
		que.pop();
		p = G -> adjlist[cur].firstarc;
		while(p != NULL)
		{
			if(visit[p -> adjvex] == 0)
			{
				cout << p -> adjvex << "->";
				que.push(p -> adjvex);
				visit[p -> adjvex] = 1;
			}
			p = p -> nextarc;
		}
	}
}

int main()
{
	Graph G;
	createGraph(&G);
	memset(visit, 0, sizeof(visit));
	cout << "dfs: " << endl;
	dfs(&G, 0);
	cout << endl;
	cout << "bfs: " << endl;
	memset(visit, 0, sizeof(visit));
	bfs(&G, 0);
	return 0;
}