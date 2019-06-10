#include <iostream>

using namespace std;

class LandAnimal {
public:
    int numLegs;
    virtual void run() {
        cout << "Land animal run" << endl;
    }
};

class Mammal {
public:
    int numBreasts;
    virtual void milk() {
        cout << "Mammal milk" << endl;
    }
};

class Human: public Mammal, public LandAnimal {
public:
    int race;
    void milk() {
        cout << "Human milk" << endl;;
    }
    void run() {
        cout << "Human run" << endl;
    }
    void eat() {
        cout << "Human eat" << endl;
    }
};

int main(void) {
    Human human;

    cout << "用LandAnimal指针调用human实例的方法" << endl;
    LandAnimal *laPtr = NULL;
    laPtr = &human;
    laPtr->run();

    cout << "用Mammal指针调用human实例的方法" << endl;
    Mammal *mPtr = NULL;
    mPtr = &human;
    mPtr->milk();

    return 0;
}

// 用LandAnimal指针调用human实例的方法
// Human run
// 用Mammal指针调用human实例的方法
// Human milk

// 1>  class LandAnimal    size(8):
// 1>      +---
// 1>   0  | {vfptr}
// 1>   4  | numLegs
// 1>      +---
// 1>
// 1>  LandAnimal::$vftable@:
// 1>      | &LandAnimal_meta
// 1>      |  0
// 1>   0  | &LandAnimal::run
// 1>
// 1>  class Mammal    size(8):
// 1>      +---
// 1>   0  | {vfptr}
// 1>   4  | numBreasts
// 1>      +---
// 1>
// 1>  Mammal::$vftable@:
// 1>      | &Mammal_meta
// 1>      |  0
// 1>   0  | &Mammal::milk
// 1>
// 1>  class Human size(20):
// 1>      +---
// 1>   0  | +--- (base class Mammal)
// 1>   0  | | {vfptr}
// 1>   4  | | numBreasts
// 1>      | +---
// 1>   8  | +--- (base class LandAnimal)
// 1>   8  | | {vfptr}
// 1>  12  | | numLegs
// 1>      | +---
// 1>  16  | race
// 1>      +---
// 1>
// 1>  Human::$vftable@Mammal@:
// 1>      | &Human_meta
// 1>      |  0
// 1>   0  | &Human::milk
// 1>
// 1>  Human::$vftable@LandAnimal@:
// 1>      | -8
// 1>   0  | &Human::run

// 有LandAnimal（陆生动物）类和Mammal（哺乳动物）类，它们都有breathe和eat方法，都被声明成虚函数。
// Human类继承了LandAnimal类和Mammal类，同时Human类重写了eat方法。
// 对于多继承的情况，子类会包含多个基类的内存结构，包括多个虚函数表，
// 若子类中重写了基类种被定义为虚函数的方法，则虚函数表中的函数指针指向子类的实现，
// 否则指向基类的实现。

