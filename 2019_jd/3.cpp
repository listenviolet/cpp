# include <bits/stdc++.h>
using namespace std;

#define LL long long
int n;
const int maxn = 1e4 + 10;
int arr[maxn];
LL mod = 998244353;

void solve(int *arr, int n, int i, int low, int high, int &cnt)
{
    if(i == n + 1)
    {
        ++cnt;
        cnt %= mod;
        return;
    }

    if(i == 1)
    {
        if(arr[i] > 0)
        {
            if(3 <= n && arr[3] > 0) solve(arr, n, i + 1, arr[i], max(arr[3], arr[1]), cnt);
            else solve(arr, n, i + 1, arr[i], high, cnt);
        }
        else if(arr[i] == 0)
        {
            for(int j = low; j <= high; ++j)
            {
                arr[i] = j;
                solve(arr, n, i + 1, arr[i], high, cnt);
                arr[i] = 0;
            }
        }
    }

    else if(i == 2)
    {
        if(arr[i] > 0) solve(arr, n, i + 1, low, arr[2], cnt);
        else if(arr[i] == 0)
        {
            for(int j = low; j <= high; ++j)
            {
                arr[i] = j;
                solve(arr, n, i + 1, low, arr[2], cnt);
                arr[i] = 0;
            }
        }
    }

    else if(i > 2)
    {
        if(arr[i] > 0) solve(arr, n, i + 1, low, arr[i], cnt);
        else if(arr[i] == 0)
        {
            for(int j = low; j <= high; ++j)
            {
                arr[i] = j;
                solve(arr, n, i + 1, low, arr[i], cnt);
                arr[i] = 0;
            }
        }
    }
}



int main()
{
    while(cin >> n)
    {
        memset(arr, 0, sizeof(arr));
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        solve(arr, n, 1, 1, 200, cnt);
        printf("%ld\n", cnt);
    }
    return 0;
}
