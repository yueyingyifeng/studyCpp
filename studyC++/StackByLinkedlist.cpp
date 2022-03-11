#include "LinkedList.cpp"


template<typename T>
class Stack
	: protected LinkedList<T> {
public:
	Stack() {
		this->head = new Node<T>();
		this->length = 1;
	}
	Stack(T defaultData[], int length) {
		for (int n{}; n < length; n++) {
			if (n == 0) {
				this->head = new Node<T>(defaultData[n]);
			}
			else {
				this->addLastNode(defaultData[n]);
			}
		}
		this->length = length;
	}
	//压栈
	void push(T data) {
		this->addLastNode(data);
		this->length++;
	}
	//出栈
	T pop() {
		T data = this->getLast();
		this->delLastNode();
		return data;
	}
	//获取指定index的数据
	T get(int index) {
		return this->get(index);
	}
	//获取长度
	int getLength() {
		return this->length;
	}
};