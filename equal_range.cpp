# include <bits/stdc++.h>
using namespace std;

int main()
{
    multimap<int ,int> m;
    m.insert({1,11});
    m.insert({1,12});
    m.insert({1,13});
    m.insert({1,14});
    m.insert({2,21});
    m.insert({3,31});
    for(auto pos=m.equal_range(1);pos.first!=pos.second;pos.first++)
    {
        // cout << pos.first << endl;
        cout << pos.second -> first << endl;
        cout << pos.second -> second << endl;
        cout<<pos.first->second<<endl;
        cout << endl;
    }

    return 0;
}


// pos.first  -> : (1, 11) -> (1, 12) -> (1, 13) -> (1,14) => pos.first++
// pos.second -> : (2, 21)
//                 (3, 31)