# include <iostream>
# include <vector>
using namespace std;

int main()
{
	vector<string> svec;
	svec.reserve(5);
	string word;
	while(cin >> word) 
	{
		svec.push_back(word);
		cout << "size: " << svec.size() << "capacity:" << svec.capacity() << endl;
	} 
	svec.resize(svec.size() + svec.size() / 2);
	cout << "size: " << svec.size() << "capacity:" << svec.capacity() << endl;
	vector<string>::iterator it;
	for(it = svec.begin(); it != svec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "end" << endl;
	return 0;
}