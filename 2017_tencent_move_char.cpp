#include <bits/stdc++.h>
using namespace std;
string str;
int main()
{

    while(cin >> str)
    {
        int start, last = str.size() - 1, i;
        for(start = str.size() - 1; start >= 0; start--)
        {
            // cout << "start = " << start << endl;
            if(str[start] >='A' && str[start] <= 'Z')
            {
                // cout << str[start] << endl;
                char tmp = str[start];
                for(i = start; i < last; ++i)
                {
                    str[i] = str[i + 1];
                }
                str[last] = tmp;
                last--;
            }
        }

        cout << str << endl;
    }
    return 0;
}
