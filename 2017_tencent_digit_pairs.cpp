#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int arr[maxn];


int main()
{
    // init();
    while(cin >> n)
    {
        map<int, int> map_count;
        int Max = INT_MIN, Min = INT_MAX;
        int max_cnt = 0, min_cnt = 0;
        
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            if(map_count.end() != map_count.find(arr[i])) map_count[arr[i]]++;
            else map_count.insert(pair<int, int>(arr[i], 1));
        }

        sort(arr, arr + n);
        Min = arr[0];
        Max = arr[n - 1];
        while(arr[min_cnt] == Min)
        {
            min_cnt++;
        }
        while(arr[n - max_cnt - 1] == Max)
        {
            max_cnt++;
        }
        int max_diff_cnt;
        max_diff_cnt = min_cnt * max_cnt;

        int Min_diff = INT_MAX, min_diff_cnt = 0;
        for(int i = 0; i < n - 1; ++i)
        {
            if(arr[i + 1] - arr[i] < Min_diff)
            {
                Min_diff = arr[i + 1] - arr[i];
                if(Min_diff == 0) break;
                min_diff_cnt = 1;
            }
            else if(arr[i + 1] - arr[i] == Min_diff)
            {
                min_diff_cnt += 1;
            }
        }

        if(Min_diff == 0)
        {
            min_diff_cnt = 0;
            for(auto it : map_count)
            {

                if(it.second > 1) min_diff_cnt += it.second * (it.second - 1) / 2;
            }
        }
        printf("%d %d\n", min_diff_cnt, max_diff_cnt);
    }
    return 0;
}

// sample
// 7
// 1 1 1 3 3 3 3
// C(3,2) + C(4, 2)

// 5
// 1 2 3 4 5
// pairs: 4

// Notice:
// put the map<int, int> map_count; in while
// otherwise, the former result may influence the current

// Description:
// 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，相差最小的有多少对呢？相差最大呢？


// 输入描述:

//  输入包含多组测试数据。

//  对于每组测试数据：

//  N - 本组测试数据有n个数

//  a1,a2...an - 需要计算的数据

//  保证:

//  1<=N<=100000,0<=ai<=INT_MAX.
  


// 输出描述:

// 对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。


// 输入例子1:
// 6
// 45 12 45 32 5 6

// 输出例子1:
// 1 2