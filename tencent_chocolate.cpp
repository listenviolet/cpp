# include <bits/stdc++.h>
using namespace std;

int n, m;
int Sum(int begin, int n)
{
    long total  = 0;
    int number = begin;
    while(n--)
    {
        total += number;
        number = (number + 1) / 2;
    }
    return total;
}

bool isOK(int a, int n, int m)
{
    long total = 0;
    total = Sum(a, n);
    if(total <= m) return true;
    else return false;
}



int binary_search(int left, int right, int n, int m)
{
    int mid = (left + right) / 2;
    if(left == mid && isOK(mid, n, m)) return mid;
    else if(isOK(mid, n, m)) return binary_search(mid, right, n, m);
    else if(isOK(mid, n, m) == false) return binary_search(left, mid, n, m);
    else return -1;
}

int main()
{
    while(cin >> n >> m)
    {
        int begin = 0;
        begin = binary_search(1, m + 1, n, m);
        cout << begin << endl;
    }
    return 0;
}

// 小Q的父母要出差N天，走之前给小Q留下了M块巧克力。
// 小Q决定每天吃的巧克力数量不少于前一天吃的一半，
// 但是他又不想在父母回来之前的某一天没有巧克力吃，
// 请问他第一天最多能吃多少块巧克力

// 输入描述:
// 每个输入包含一个测试用例。
// 每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。

// 输出描述:
// 输出一个数表示小Q第一天最多能吃多少块巧克力。

// 输入例子1:
// 3 7

// 输出例子1:
// 4