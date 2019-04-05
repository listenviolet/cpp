# include <bits/stdc++.h>
using namespace std;
# define LL long long
double total = 0;
LL c[105][105];
const int mod = 1000000007;

int k;
int a, x;
int b, y;

// LL C(double m, double n) // C_m ^ n
// {
// 	double total = 1.0;
// 	while(n && m)
// 	{	
// 		total = (total * (1.0 * m / n)) ;
// 		n--;
// 		m--;
// 	}
// 	return (LL)total % 1000000007;
// }

void init()
{
	c[0][0] = 1;
	for(int i = 1; i <= 100; ++i)
	{
		c[i][0] = 1;
		for(int j = 1; j <= 100; ++j)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
}

int main()
{
	init();
	while(cin >> k)
	{
		LL total = 0;
		cin >> a >> x >> b >> y;
		for(int n = x; n >= 0; --n)
		{
			for(int m = 0; m <= y; ++m)
			{
				if(a * n + b * m > k)
					break;
				else if(a * n + b * m == k)
				{
					// cout << "A = " << n << " B = " << m << endl;
					// cout << "C(" << x << ", " << n << ") = " << C(x, n) << endl;
					// cout << "C(" << y << ", " << m << ") = " << C(y, m) << endl;
					// cout << "-----------" << endl;
					// total += (C(x, n) * C(y, m));
					total += c[x][n] * c[y][m] % mod;
					break;
				}
				
			}
		}
		// printf("%lf\n", total % 1000000007);
		total = total % mod;
		printf("%lld\n", total);
	}
	return 0;
}

// 小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，
// 现在小Q想用这些歌组成一个总长度正好为K的歌单，
// 每首歌最多只能在歌单中出现一次，
// 在不考虑歌单内歌曲的先后顺序的情况下，请问有多少种组成歌单的方法。

// 输入描述:
// 每个输入包含一个测试用例。
// 每个测试用例的第一行包含一个整数，表示歌单的总长度K(1<=K<=1000)。
// 接下来的一行包含四个正整数，分别表示歌的第一种长度A(A<=10)和数量X(X<=100)以及歌的第二种长度B(B<=10)和数量Y(Y<=100)。保证A不等于B。

// 输出描述:
// 输出一个整数,表示组成歌单的方法取模。因为答案可能会很大,输出对1000000007取模的结果。

// 输入例子1:
// 5
// 2 3 3 3

// 输出例子1:
// 9

// Alg:
// the key point is to calculate c(m,n)
// use yanghui triangle
// A * N + b * M = K
// C(X, N) * C(Y, M) is the composition number for one case(n,m) 
// as there are different song, 
// when choosing #N A sonds, there are C(X, N) cases;
// when choosing #M B sonds, there are C(Y, M) cases;

// sum( C(X, N) * C(Y, M) ) is the total number for all possible (n,m) pairs