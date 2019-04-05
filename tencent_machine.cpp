# include <bits/stdc++.h>
using namespace std;
# define LL long long
const int maxn = 1e6 + 10;

struct Node{
	int time;
	int level;
}tasks[maxn], machines[maxn];

int n_machine, m_task;

int cmp(Node a, Node b)
{
	if(a.time == b.time) return a.level > b.level;
	return a.time > b.time;
}

bool isOK(Node machine, Node task)
{
	if(machine.time >= task.time && machine.level >= task.level) return true;
	else return false;
}

int main()
{
	while(cin >> n_machine >> m_task)
	{
		int finished[m_task];
		memset(finished, 0, sizeof(finished));

		for(int i = 0; i < n_machine; ++i)
		{
			cin >> machines[i].time >> machines[i].level;
		}
		for(int i = 0; i < m_task; ++i)
		{
			cin >> tasks[i].time >> tasks[i].level;
		}

		sort(machines, machines + n_machine, cmp);
		sort(tasks, tasks + m_task, cmp);

		int cnt_task = 0;
		LL benefit = 0;

		// int new_task_index = 0;
		for(int i = 0; i < n_machine; ++i)
		{
			for(int j = 0; j < m_task; ++j)
			{
				if(isOK(machines[i], tasks[j]) && finished[j] == 0)
				{
					cnt_task++;
					benefit += 200 * tasks[j].time + 3 * tasks[j].level;
					// new_task_index = j + 1;
					finished[j] = 1;
					break;
				}
			}
		}

		printf("%d %lld\n", cnt_task, benefit);
	}
	return 0;
}

// Wrong analysis:

// Sample:
// Machine:
// (10 5)
// (10 4)

// Task:
// (10 4)
// (9 5)

// correct output: 2
// mine:			1

// This alg:
// sort machine and task 
// for a machine, choose a hardest task 
// However, this cannot ensure the max of finished tasks,
// since when a machine are choosing task, 
// it doesn't know other machines' condition

// So it should be: for a task, find the min cost machine
// see alg and code in tencent_machine-correct