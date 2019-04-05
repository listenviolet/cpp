// # include <iostream>
// # include <cstdio>
// # include <algorithm>
// # include <cstring>
// using namespace std;
// # define LL long long

// const int maxn = 5e5 + 10;
// int arr[maxn];
// int tmp[maxn];
// int n;
// LL Sum, res, multi;

// int cmp(int a, int b)
// {
// 	return a > b;
// }

// int main()
// {
// 	while(scanf("%d", &n) != EOF)
// 	{
// 		res = 0;
// 		for(int i = 0; i < n; ++i)
// 		{
// 			scanf("%d", &arr[i]);
// 		}

// 		sort(arr, arr + n, cmp);

// 		for(int i = 1; i <= n; ++i)
// 		{
// 			Sum = 0;
// 			for(int j = 0; j < i; ++j)
// 			{
// 				tmp[j] = arr[j];
// 				Sum += tmp[j];
//  			}
//  			int Min = tmp[i - 1];
//  			multi = Sum * Min;
//  			if(multi > res)
//  			{
//  				res = multi;
//  			}
// 		}
// 		printf("%lld\n", res);
// 	}
// 	return 0;
// }

// 10
// 81 87 47 59 81 18 25 40 56 0 
// 对应输出应该为:

// 16685

// 你的输出为:

// 20384

// Error Analysis:
// The arr cannot be sorted. Just use the origin one.

#include <iostream>
using namespace std;

int main()
{
	int n; 
	while(cin >> n)
	{
		int x[n];
		for(int i = 0; i < n; ++i)
		{
			cin >> x[i];
		}

		int max = 0;
		for(int i = 0; i < n; ++i)
		{
			int j = i;
			int k = j - 1;
			int sum1 = 0;

			while(x[i] <= x[j] && j < n)
			{
				sum1 += x[j];
				j++;
			}

			while(x[i] <= x[k] && k >= 0)
			{
				sum1 += x[k];
				k--;
			}

			int tmp = sum1;
			if(x[i] * tmp > max)
			{
				max = x[i] * tmp;
			}
		}
		cout << max << endl;
	}
	return 0;
}