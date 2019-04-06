# include <bits/stdc++.h>
using namespace std;
string str;

bool isPalindrome(string substr)
{
	decltype(substr.size()) i;
	for(i = 0; i < substr.size() / 2; ++i)
	{
		if(substr[i] != substr[substr.size() - 1 - i]) return false;
	}
	return true;
}

decltype(str.size()) subPalindrome(string substr)
{
	if(isPalindrome(substr)) return substr.size();
	string delete_start;
	string delete_end;
	string delete_start_end;
	delete_start.assign(substr, 1, substr.size() - 1);
	delete_end.assign(substr, 0, substr.size() - 1);
	delete_start_end.assign(substr, 1, substr.size() - 2);

	if(substr[0] != substr[substr.size() - 1]) 
	{
		return max(subPalindrome(delete_start), subPalindrome(delete_end));
	}

	else
	{
		return max( max(subPalindrome(delete_start), subPalindrome(delete_end)), subPalindrome(delete_start_end) + 2);
	}
}	

int main()
{
	while(cin >> str)
	{
		decltype(str.size()) length = 0;
		length = subPalindrome(str);
		cout << str.size() - length << endl;
	}
	
	return 0;
}

// time complexity is toot high


