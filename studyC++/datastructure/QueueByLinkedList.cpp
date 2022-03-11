#include"LinkedList.cpp"
template<typename T>
class Queue 
	: protected LinkedList<T>{
	Node<T>* head;
	int length;
public:
	Queue(int length,T defaultData[])
	: LinkedList() {
		for (int n{}; n < length; n++) {
			if (n == 0) {
				head.value = defaultData[n];
			}
			else {
				addNode(defaultData[n]);
			}
		}
		this->length = length;
	}

	void push(T data) {
		//addNode(data);
	}

	Node<T>* pop() {
		//Node<T> temp = getLastNode();
		//delLastNode();
		//return temp;
	}


};

class A {
public:
	void a() { cout << "我是a" << endl; }
	void fun() { cout << "我是fun of a" << endl; }
};

class B : public A {
public:
	void b() { cout << "我是b" << endl; }
	void fun() { cout << "我是fun of b" << endl; }
};
//
//int main() {
//	A* a = new A();
//	a->a();
//
//	A* b = new B();
//	b->a();
//
//	a->fun();
//	b->fun();
//}