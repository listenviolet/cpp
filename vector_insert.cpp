#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;
  cout << "init:" << endl;
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  cout << "myvector.insert ( it , 200 )" << endl;
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  myvector.insert (it,2,300);
  cout << "  myvector.insert (it,2,300);" << endl;
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());
  cout << "myvector.insert (it+2,anothervector.begin(),anothervector.end());" << endl;
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);
  cout << "myvector.insert (myvector.begin(), myarray, myarray+3);" << endl;
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}