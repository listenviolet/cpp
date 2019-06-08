#include <iostream>
using namespace std;

class A
{
private:
  char *m_cBuffer;
  int m_nLen;
public:
  A(){ m_cBuffer = new char[m_nLen]; }
  ~A() { delete [] m_cBuffer; }
};


/////////class Babe
class Babe
{
public:
    Babe()
    {
        cout << "Create a Babe to talk with me" << endl;
    }
    ~Babe()
    {
        cout << "Babe don\'t go away,listen to me" << endl;
    }
};
//////////main function
int main()
{
    /* (1) */
    // Babe* pbabe1 = new Babe[3];
    // delete pbabe1;

    /* (2) */
    // Babe* pbabe2 = new Babe[3];
    // delete [] pbabe2;
    // return 0;

    int *a = new int[10];
    // delete a;        //方式1
    delete [] a;     //方式2

    // A *a = new A[10];
    // delete []a;
    return 0;
}

/* (1) Output: */
// Create a Babe to talk with me
// Create a Babe to talk with me
// Create a Babe to talk with me
// Babe don't go away,listen to me
// *** Error in `./delete_test': munmap_chunk(): invalid pointer: 0x00000000018a6c28 ***

/* (2) Output: */
// Create a Babe to talk with me
// Create a Babe to talk with me
// Create a Babe to talk with me
// Babe don't go away,listen to me
// Babe don't go away,listen to me
// Babe don't go away,listen to me
