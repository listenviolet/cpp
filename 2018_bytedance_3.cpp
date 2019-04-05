# include <iostream>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstring>
using namespace std;

int n_pm, m_programmer, p_idea;
const int maxn = 3000 + 10;

struct Idea
{
	int id;
	int pm_id, raise_time, priority, duration;
	int end_time;
}ideas[maxn];



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

struct cmp_idea1
{
	bool operator()(Idea idea1, Idea idea2)
	{
		if(idea1.raise_time == idea2.raise_time) 
		{
			if(idea1.duration == idea2.duration)
				return idea1.pm_id > idea2.pm_id;
			else return idea1.duration > idea2.duration; 
		}
		else return idea1.raise_time > idea2.raise_time;
	}
};

struct cmp_idea2
{
	bool operator()(Idea idea1, Idea idea2)
	{
		if(idea1.priority == idea2.priority)
		{
			if(idea1.duration == idea2.duration) return idea1.pm_id > idea2.pm_id;
			else return idea1.duration > idea2.duration;
		} 
			
		else return idea1.priority > idea2.priority;
	}
};

int main()
{
	// freopen("test.txt","r",stdin);  

	// while(cin >> n_pm >> m_programmer >> p_idea)
	// while(scanf("%d %d %d", &n_pm, &m_programmer, &p_idea) != EOF)
	scanf("%d %d %d", &n_pm, &m_programmer, &p_idea);
	{
		memset(ideas, 0, sizeof(ideas));
		memset(programmers, 0, sizeof(programmers));

		priority_queue<Programmer, vector<Programmer>, cmp_programmer> pq_programmer;
		priority_queue<Idea, vector<Idea>, cmp_idea1> pq_idea1;
		priority_queue<Idea, vector<Idea>, cmp_idea2> pq_idea2;

		for(int i = 0; i < m_programmer; ++i)
		{
			programmers[i].id = i;
			programmers[i].finishtime = 0;
			pq_programmer.push(programmers[i]);
		}
		// printf("n_pm = %d, m_programmer = %d, p_idea = %d\n", n_pm, m_programmer, p_idea);
		for(int i = 0; i < p_idea; ++i)
		{
			ideas[i].id = i;
			scanf("%d%d%d%d", &ideas[i].pm_id, &ideas[i].raise_time, 
				&ideas[i].priority, &ideas[i].duration);
			// printf("--%d, ", i);
			// int a, b, c, d;
			// cin >> a >> b >> c >> d;
			// ideas[i].pm_id = a;
			// ideas[i].raise_time = b;
			// ideas[i].priority = c;
			// ideas[i].duration = d;

			// cin >> ideas[i].pm_id >> ideas[i].raise_time >> ideas[i].priority >> ideas[i].duration;
			// cin >> ideas[i].pm_id;
			// scanf("%d", &ideas[i].pm_id);
			// printf("pm_id = %d, ", ideas[i].pm_id);
			// scanf("%d", &ideas[i].raise_time);
			// cin >> ideas[i].raise_time;
			// printf("raise_time = %d, ", ideas[i].raise_time);
			// scanf("%d", &ideas[i].priority);
			// cin >> ideas[i].priority;
			// printf("priority = %d, ", ideas[i].priority);
			// scanf("%d", &ideas[i].duration);
			// cin >> ideas[i].duration;
			// printf("duration = %d\n", ideas[i].duration);

			pq_idea1.push(ideas[i]);
		}



		Programmer p;
		Idea tmp_idea;
		while(true)
		{

			if(pq_idea1.empty() && pq_idea2.empty()) break;
			// choose programmer
			p = pq_programmer.top();
			pq_programmer.pop();
			
			// choose idea
			while(!pq_idea1.empty() && pq_idea1.top().raise_time <= p.finishtime)
			{

				pq_idea2.push(pq_idea1.top());
				pq_idea1.pop();
			}
			// If exists an idea: raise < p.finishtime, do this
			if(!pq_idea2.empty())
			{
				tmp_idea = pq_idea2.top();
				pq_idea2.pop();
				tmp_idea.end_time = p.finishtime + tmp_idea.duration;
				ideas[tmp_idea.id].end_time = tmp_idea.end_time;
				// printf("case1 : id = %d, pm_id = %d, finishtime = %d, duration = %d, end_time = %d\n",
				// 	tmp_idea.id,  tmp_idea.pm_id,  p.finishtime, tmp_idea.duration, tmp_idea.end_time);
			}

			// raise > p.finishtime, do this until raise time
			else
			{
				tmp_idea = pq_idea1.top();
				pq_idea1.pop();
				tmp_idea.end_time = tmp_idea.raise_time + tmp_idea.duration;
				ideas[tmp_idea.id].end_time = tmp_idea.end_time;
				// printf("case2 :%d, %d, %d\n", tmp_idea.raise_time, tmp_idea.duration, tmp_idea.end_time);
			}
			p.finishtime = ideas[tmp_idea.id].end_time;
			pq_programmer.push(p);
			programmers[p.id].finishtime = p.finishtime;

		}

		for(int i = 0; i < p_idea; ++i)
		{
			// printf("%d, %d\n", i, ideas[i].end_time);
			printf("%d\n",ideas[i].end_time);
		}

	}
	return 0;
}