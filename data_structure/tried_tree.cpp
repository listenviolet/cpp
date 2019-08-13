# include <bits/stdc++.h>
using namespace std;


char ch[100];

struct Node
{
	bool k; //bool型的K则表示该位置是否有终止标记
	Node *next[26];
	Node()
	{
		int i;
		for(int i = 0; i < 26; ++i)
		{
			next[i] = NULL;
			k = false;
		}
	}

	~Node()
	{
		int i = 0; 
		for(i = 0; i < 26; ++i)
		{
			if(next[i] != NULL)
			{
				delete next[i];
			}
		}
	}
};

Node *head;

void insert_ch(char *ch)
{
	int i;
	Node *p = head;
	for(int i = 0; ch[i]; ++i)
	{
		if(p -> next[ch[i] - 'a'] == NULL) p -> next[ch[i] - 'a'] = new Node;
		p = p -> next[ch[i] - 'a'];
	}
	p -> k = true;
}

bool find_ch(char *ch)
{
	int i;
	Node *p = head;
	for(i = 0; ch[i]; ++i)
	{
		if(p -> next[ch[i] - 'a'] == NULL) return false;
		p = p -> next[ch[i] - 'a'];
	}
	return p -> k;
}

int main()
{
	head = new Node;
	while(~scanf("%s", ch)) insert_ch(ch);
	while(~scanf("%s", ch)) printf("%s\n", find_ch(ch) ? "YES" : "No");
	delete head;
	return 0;
}