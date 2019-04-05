# include <iostream>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstring>
using namespace std;

const int maxn = 3000 + 10;

struct Programmer
{
	int id;
	int finishtime;
}programmers[maxn];

struct cmp_programmer
{
	bool operator()(Programmer p1, Programmer p2)
	{
		if(p1.finishtime == p2.finishtime) return p1.id > p2.id;
		else return p1.finishtime > p2.finishtime;
	}
};

int main()
{
	int n; 
	cin >> n;
	priority_queue<Programmer, vector<Programmer>, cmp_programmer> pq_programmer;
	for(int i = 0; i < n; ++i)
	{
		programmers[i].id = i;
		cin >> programmers[i].finishtime;
		pq_programmer.push(programmers[i]);
	}

	for(int i = 0; i < n; ++i)
	{
		cout << pq_programmer.top().id << " " << pq_programmer.top().finishtime << endl;
		pq_programmer.pop();
	}
	return 0;
}