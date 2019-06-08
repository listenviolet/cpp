# include <bits/stdc++.h>
using namespace std;

string swap(string str, int index)
{
    char tmp = str[0];
    str[0] = str[index];
    str[index] = tmp;
    return str;
}

int main()
{
	string str = "computer";
	string str2;
	str2 = swap(str, 3);
	cout << str << endl;
	cout << str2 << endl;
	str2 = str2 + str2[0];
	cout << str2 << endl;
	cout << str2 + 1 << endl;
	return 0;
}

