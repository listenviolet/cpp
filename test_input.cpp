# include <iostream>
# include <queue>
# include <vector>
# include <cstdio>
# include <cstring>
using namespace std;

int n_pm, m_programmer, p_idea;
const int maxn = 3000 + 10;

struct D
{
	int pm_id;
	int raise_time;
	int priority;
	int duration;
};



int main()
{
	freopen("test.txt","r",stdin);  

	D ideas[10000];
	cin >> n_pm >> m_programmer >> p_idea;
	{
		printf("%d %d %d\n", n_pm, m_programmer, p_idea);

		for(int i = 0; i < p_idea; ++i)
		{

			printf("--%d, ",i );
			cin >> ideas[i].pm_id;
			printf("%d, ",ideas[i].pm_id);
			cin >> ideas[i].raise_time;
			printf("%d, ",ideas[i].raise_time);
			cin >> ideas[i].priority;
			printf("%d, ",ideas[i].priority);
			cin >> ideas[i].duration;
			printf("%d\n",ideas[i].duration);
		}



	}
	return 0;
}