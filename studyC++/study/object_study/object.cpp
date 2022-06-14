//2022年6月14日
//装包和拆包

#include <iostream>
using namespace std;

class Object{
public:
    virtual string toString(){
        return "";
    }
};

class A
    : public Object{
protected:
    int a;
    string str;
public:
    A(int a,string str){
        this->a = a;
        this->str = str;
    }
    int getA(){
        return a;
    }
    string getStr(){
        return str;
    }

    string toString() override{

        return to_string(a) + str;
    }
};


void fun(Object* o){
    A* a = (A*)o;

    cout << a->getA() << endl;
    cout << a->getStr() << endl;
    cout << a->toString();
}

// int main(){
//     A* a = new A(2,"hi");
    
//     fun(a);
// }