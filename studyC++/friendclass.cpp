#include <iostream>

using namespace std;

class A {
private:
   
    int a_ = 0;
    friend class B;
public:
    void fun(A a) {
        cout << a.a_;
    }
};

class B {
public:
    void Print() {
        A ca;
        cout << ca.a_ << endl;
    }
};



//int main() {
//    B b;
//    b.Print();
//
//    A a;
//    return 0;
//}