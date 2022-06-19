/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/6/19 20:43:32
* 	   Description ：观察者模式
*/
#include <iostream>
#include <vector>

using namespace std;

class Observer {
protected:
	int status;

	friend class Subject;
	//此方法只有他的朋友可以使用  :D
	virtual void changeStatus() = 0;
public:
	

	int getStatus() {
		return status;
	}
	void setStatus(int status) {
		this->status = status;
	}
};



class ObserverA
	: public Observer {
	virtual void changeStatus() override {
		status = 0;
	}
public:

};

class ObserverB 
	: public Observer{
	virtual void changeStatus() override {
		status = 1;
	}
};

class Subject {
	vector<Observer*> observers;
public:
	Subject() {}
	Subject(Observer* ob) {
		observers.push_back(ob);
	}
	Subject(vector<Observer*> observers)
		: observers(observers) {}
	//增加一个观察者
	Subject* attach(Observer* ob) {
		observers.push_back(ob);
		return this;
	}

	void notifyAllObserver() {
		for (Observer* ob : observers) {
			ob->changeStatus();
		}
	}

	void A() {
		cout << "这个方法会影响到其他观察者" << endl;
		this->notifyAllObserver();
	}
};

int main() {
	Observer* a = new ObserverA();
	Observer* b = new ObserverB();

	Subject sub;

	sub.attach(a)->attach(b);

	a->setStatus(3);
	b->setStatus(4);

	cout << a->getStatus() << endl;
	cout << b->getStatus() << endl;
	cout << endl;

	sub.A();

	cout << a->getStatus() << endl;
	cout << b->getStatus() << endl;


	return 0;
}