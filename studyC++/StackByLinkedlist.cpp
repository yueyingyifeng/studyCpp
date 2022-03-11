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
	//ѹջ
	void push(T data) {
		this->addLastNode(data);
		this->length++;
	}
	//��ջ
	T pop() {
		T data = this->getLast();
		this->delLastNode();
		return data;
	}
	//��ȡָ��index������
	T get(int index) {
		return this->get(index);
	}
	//��ȡ����
	int getLength() {
		return this->length;
	}
};