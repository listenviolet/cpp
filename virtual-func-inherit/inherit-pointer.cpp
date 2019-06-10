#include <iostream>

using namespace std;

class Animal {
public:
    char *name;
    void breathe() {
        cout << "Animal breathe" << endl;
    }
    virtual void eat() {
        cout << "Animal eat" << endl;
    }
};

class Human: public Animal {
public:
    int race;
    void breathe() {
        cout << "Human breathe" << endl;
    }
    void eat() {
        cout << "Human eat" << endl;
    }
};

int main(void) {
    // 用实例调用
    Animal a;
    Human h;
    a.breathe();
    a.eat();
    h.breathe();
    h.eat();

    cout << endl;

    // 用基类指针调用
    Animal *aPtr = NULL;
    aPtr = &a;
    aPtr->breathe();
    aPtr->eat();
    aPtr = &h;
    aPtr->breathe();
    aPtr->eat();
    return 0;
}

// https://www.jianshu.com/p/02183498a2c2
// Animal breathe
// Animal eat
// Human breathe
// Human eat

// Animal breathe
// Animal eat
// Animal breathe
// Human eat

// 1. 对于没有声明被声明成虚函数的方法，
// 比如这里的breathe，代码中对于breathe方法的调用在编译时就已经被绑定了实现，
// 绑定的是基类的实现，此为早绑定。

// 2. 对于被声明成虚函数的方法，比如这里的eat，
// 代码中对于eat方法的调用是在程序运行时才去绑定的，
// 而这里的基类指针指向了一个Human类的实例，它会调用Human类的eat方法实现。

// 如何做到调用具体类的实现而非基类的实现呢？
// 对于有虚函数的类，它在类内存的开始有一个指针指向虚函数表，
// 虚函数表中包含了基类中以virtual修饰的所有虚函数。
// 在基类Animal中，虚函数表中的eat指向的是Animal::eat，
// 而在子类Human中，虚函数表中的eat指向的是Human::eat，
// 因而在使用基类指针调用实例方法时，会调用虚函数表中的函数，也就是具体实例所属类的实现。

// 1>  class Animal    size(8):
// 1>      +---
// 1>   0  | {vfptr}
// 1>   4  | name
// 1>      +---
// 1>
// 1>  Animal::$vftable@:
// 1>      | &Animal_meta
// 1>      |  0
// 1>   0  | &Animal::eat
// 1>
// 1>  class Human size(12):
// 1>      +---
// 1>   0  | +--- (base class Animal)
// 1>   0  | | {vfptr}
// 1>   4  | | name
// 1>      | +---
// 1>   8  | race
// 1>      +---
// 1>
// 1>  Human::$vftable@:
// 1>      | &Human_meta
// 1>      |  0
// 1>   0  | &Human::eat