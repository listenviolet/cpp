# include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int Next[maxn];
// s: the main string
// t: the templete string
int KMP(string s, string t)
{
	int i = 0, j = 0;
	while(i < s.size() && j < t.size())
	{
		if(s[i] == t[j])
		{
			++i;
			++j;
		}
		else
		{
			j = Next[j];
			if(j == -1)
			{
				j = 0;
				++i;
			}
		}
	}
	if(j == t.size())
		return i - t.size();
	else return -1;
}

void getNext(string t, int Next[])
{
	int i = 0, j = -1;
	Next[0] = -1;
	while(i < t.size())
	{
		if(j == -1 || t[i] == t[j])
		{
			++i;
			++j;
			Next[i] = j;
		}
		else
			j = Next[j];
	}
}

int main()
{
	string s, t;
	while(cin >> s >> t)
	{
		memset(Next, 0, sizeof(Next));
		getNext(t, Next);
		int index = KMP(s, t);
		cout << index << endl;
	}
	return 0;
}