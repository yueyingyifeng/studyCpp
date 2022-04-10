/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/4/10 15:12:00
* 	   Description ：
*/
#include <iostream>

using namespace std;

class A {
public:
	virtual void say() {
		cout << "I am class A" << endl;
	}
	void Aa() {
		cout << "this is A" << endl;
	}
};

class B
	: public A {
public:
	virtual void say() override{
		cout << "I am class B" << endl;
	}
	void Bb() {
		cout << "this is B" << endl;
	}
};

int main() {
	double d{ 1.33 };
	int i = static_cast<int>(d);
	cout << i << endl;
	cout << d << endl;

	A* a = new A();
	B* b = new B();

	a = static_cast<A*>(b);
	//b = dynamic_cast<B*>(a);

	a->say();
	a->Aa();
	b->say();
	b->Bb();


	return 0;
}