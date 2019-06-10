#include <iostream>

using namespace std;

class Animal {
public:
    int name;
    virtual void breathe() {
        cout << "Animal breathe" << endl;
    }
};

class LandAnimal: virtual public Animal {
public:
    int numLegs;
    virtual void run() {
        cout << "Land animal run" << endl;
    }
};

class Mammal: virtual public Animal {
public:
    int numBreasts;
    virtual void milk() {
        cout << "Mammal milk" << endl;
    }
};

class Human: public Mammal, public LandAnimal {
public:
    int race;
    void breathe() {
        cout << "Human breathe" << endl;
    }
    void milk() {
        cout << "Human milk" << endl;
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

    cout << "用LandAnimal指针调用Human实例的方法" << endl;
    LandAnimal *laPtr = NULL;
    laPtr = &human;
    laPtr->run();

    cout << "用Mammal指针调用Human实例的方法" << endl;
    Mammal *mPtr = NULL;
    mPtr = &human;
    mPtr->milk();

    cout << "用Animal指针调用Human实例的方法" << endl;
    Animal *aPtr = NULL;
    aPtr = &human;
    aPtr->breathe();

    return 0;
}

// virtual inheritance
// 用LandAnimal指针调用Human实例的方法
// Human run
// 用Mammal指针调用Human实例的方法
// Human milk
// 用Animal指针调用Human实例的方法
// Human breathe

// 1>  class Animal    size(8):
// 1>      +---
// 1>   0  | {vfptr}
// 1>   4  | name
// 1>      +---
// 1>
// 1>  Animal::$vftable@:
// 1>      | &Animal_meta
// 1>      |  0
// 1>   0  | &Animal::breathe
// 1>
// 1>  class LandAnimal    size(20):
// 1>      +---
// 1>   0  | {vfptr}
// 1>   4  | {vbptr}
// 1>   8  | numLegs
// 1>      +---
// 1>      +--- (virtual base Animal)
// 1>  12  | {vfptr}
// 1>  16  | name
// 1>      +---
// 1>
// 1>  LandAnimal::$vftable@LandAnimal@:
// 1>      | &LandAnimal_meta
// 1>      |  0
// 1>   0  | &LandAnimal::run
// 1>
// 1>  LandAnimal::$vbtable@:
// 1>   0  | -4
// 1>   1  | 8 (LandAnimald(LandAnimal+4)Animal)
// 1>
// 1>  LandAnimal::$vftable@Animal@:
// 1>      | -12
// 1>   0  | &Animal::breathe
// 1>
// 1>  class Mammal    size(20):
// 1>      +---
// 1>   0  | {vfptr}
// 1>   4  | {vbptr}
// 1>   8  | numBreasts
// 1>      +---
// 1>      +--- (virtual base Animal)
// 1>  12  | {vfptr}
// 1>  16  | name
// 1>      +---
// 1>
// 1>  Mammal::$vftable@Mammal@:
// 1>      | &Mammal_meta
// 1>      |  0
// 1>   0  | &Mammal::milk
// 1>
// 1>  Mammal::$vbtable@:
// 1>   0  | -4
// 1>   1  | 8 (Mammald(Mammal+4)Animal)
// 1>
// 1>  Mammal::$vftable@Animal@:
// 1>      | -12
// 1>   0  | &Animal::breathe
// 1>
// 1>  class Human size(36):
// 1>      +---
// 1>   0  | +--- (base class Mammal)
// 1>   0  | | {vfptr}
// 1>   4  | | {vbptr}
// 1>   8  | | numBreasts
// 1>      | +---
// 1>  12  | +--- (base class LandAnimal)
// 1>  12  | | {vfptr}
// 1>  16  | | {vbptr}
// 1>  20  | | numLegs
// 1>      | +---
// 1>  24  | race
// 1>      +---
// 1>      +--- (virtual base Animal)
// 1>  28  | {vfptr}
// 1>  32  | name
// 1>      +---
// 1>
// 1>  Human::$vftable@Mammal@:
// 1>      | &Human_meta
// 1>      |  0
// 1>   0  | &Human::milk
// 1>
// 1>  Human::$vftable@LandAnimal@:
// 1>      | -12
// 1>   0  | &Human::run
// 1>
// 1>  Human::$vbtable@Mammal@:
// 1>   0  | -4
// 1>   1  | 24 (Humand(Mammal+4)Animal)
// 1>
// 1>  Human::$vbtable@LandAnimal@:
// 1>   0  | -4
// 1>   1  | 12 (Humand(LandAnimal+4)Animal)
// 1>
// 1>  Human::$vftable@Animal@:
// 1>      | -28
// 1>   0  | &Human::breathe

// 我们可以观察到，一个子类虚继承自另一个基类
// ，它不再像普通继承那样直接拥有一份基类的内存结构，
// 而是加了一个虚表指针vbptr指向虚基类，这个虚基类在msvc中被放在的类的内存空间的最后。

// 这样，当出现类似这里的菱形继承时，基类Animal在子类Human中出现一次，
// 子类Human所包含的Mammal类和LandAnimal类各有一个虚基类指向虚基类。
// 从而避免了菱形继承时的冲突。