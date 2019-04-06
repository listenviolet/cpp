# include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
string str;	
string str2;
#define size_type decltype(str.size())	
int maxlen[maxn][maxn];

void init()
{
	for(size_type i = 0; i < str.size(); ++i)
	{
		maxlen[i][0] = 0;
		maxlen[0][i] = 0;
	}
}



int main()
{
	while(cin >> str)
	{
		init();
		str2 = str;
		reverse(str2.begin(), str2.end());
		size_type length = str.size();
		for(size_type i = 1; i <= length; ++i)
		{
			for(size_type j = 1; j <= length; ++j)
			{
				if(str[i - 1] == str2[j - 1])
				{
					maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
				}

				else
				{
					maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
				}
			}
		}

		cout << length - maxlen[length][length] << endl;
	}
	return 0;
}