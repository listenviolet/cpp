#include <iostream>

using namespace std;

class Animal {
public:
    int name;
    virtual void breathe() {
        cout << "Animal breathe" << endl;
    }
};

class LandAnimal: public Animal {
public:
    int numLegs;
    virtual void run() {
        cout << "Land animal run" << endl;
    }
};

class Mammal: public Animal {
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
    aPtr = &human; // error: base class "Animal" is ambiguous

    return 0;
}

// IDE会报错。因为Human类同时继承了LandAnimal类和Mammal类。
// 1>  Animal::$vftable@:
// 1>      | &Animal_meta
// 1>      |  0
// 1>   0  | &Animal::breathe
// 1>
// 1>  class LandAnimal    size(12):
// 1>      +---
// 1>   0  | +--- (base class Animal)
// 1>   0  | | {vfptr}
// 1>   4  | | name
// 1>      | +---
// 1>   8  | numLegs
// 1>      +---
// 1>
// 1>  LandAnimal::$vftable@:
// 1>      | &LandAnimal_meta
// 1>      |  0
// 1>   0  | &Animal::breathe
// 1>   1  | &LandAnimal::run
// 1>
// 1>  class Mammal    size(12):
// 1>      +---
// 1>   0  | +--- (base class Animal)
// 1>   0  | | {vfptr}
// 1>   4  | | name
// 1>      | +---
// 1>   8  | numBreasts
// 1>      +---
// 1>
// 1>  Mammal::$vftable@:
// 1>      | &Mammal_meta
// 1>      |  0
// 1>   0  | &Animal::breathe
// 1>   1  | &Mammal::milk
// 1>
// 1>  class Human size(28):
// 1>      +---
// 1>   0  | +--- (base class Mammal)
// 1>   0  | | +--- (base class Animal)
// 1>   0  | | | {vfptr}
// 1>   4  | | | name
// 1>      | | +---
// 1>   8  | | numBreasts
// 1>      | +---
// 1>  12  | +--- (base class LandAnimal)
// 1>  12  | | +--- (base class Animal)
// 1>  12  | | | {vfptr}
// 1>  16  | | | name
// 1>      | | +---
// 1>  20  | | numLegs
// 1>      | +---
// 1>  24  | race
// 1>      +---
// 1>
// 1>  Human::$vftable@Mammal@:
// 1>      | &Human_meta
// 1>      |  0
// 1>   0  | &Animal::breathe
// 1>   1  | &Human::milk
// 1>
// 1>  Human::$vftable@LandAnimal@:
// 1>      | -12
// 1>   0  | &Animal::breathe
// 1>   1  | &Human::run

// Human类包含了Mammal类和LandAnimal类的内存结构，
// 而Mammal类和LandAnimal类都继承自Animal类，
// 它们的一些成员变量和方法是相同的。

// 如果用Animal指针指向Human类的实例，则对于共同的成员变量和方法，
// 编译器无法判断是要使用Mammal类中的还是使用LandAnimal类中的。于是报上面的错误。

// 这时，我们需要用到虚继承。我们在继承的时候，加上virutal关键字，使LandAnimal类和Mammal类虚继承Animal类.