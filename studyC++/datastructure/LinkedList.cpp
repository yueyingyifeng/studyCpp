#include <iostream>
#include "ListNode.cpp"
#include <vector>
using namespace std;


template<typename T>
class LinkedList {
protected:
	Node<T>* head;
	int length;
public:
	//�޲ι��캯��
	LinkedList() {
		head = new Node<T>();
		length = 0;
	}
	//�вι��캯��
	LinkedList(T defaultData[], int length) {
		for (int n{}; n < length; n++) {
			if (n == 0) {
				head = new Node<T>(defaultData[n]);
			}
			else {
				addLastNode(defaultData[n]);
			}
		}
		this->length = length;
	}
	//����ͷ�ڵ�
	Node<T>* getHeadNode() {
		return head;
	}
	//�������һ���ڵ�
	Node<T>* getLastNode() {
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		return p;
	}
	//����ָ���ڵ�
	Node<T>* getNodeByIndex(int index) {
		if (index < length && index >= 0) {
			Node<T>* p = head;
			for (int n{}; p->next != nullptr && n < index; n++) {
				p = p->next;
			}
			return p;
		}
		cout << "����ָ����index:" << index << (index < 0 ? " С����" : (index >= length ? " ����������" + length : " ")) << endl;
		return new Node<T>();
	}
	//��ָ���ڵ�����һ���ڵ�
	void addNodeAfterIndex(int index, T data) {
		Node<T>* p = getNodeByIndex(index);
		p->next = new Node<T>(data);
		length++;
	}
	//���ͷ�ڵ�
	void addHeadNode(T data) {
		//����������޲εĹ��캯��
		if (length == 0) {
			head = new Node<T>(data);
		}
		else {
			Node<T>* temp = new Node<T>(data);
			temp->next = head;
			head = temp;
		}
		
		length++;
	}
	//��������һ���ڵ�
	void addLastNode(T data) {
		//����������޲εĹ��캯��
		if (length == 0) {
			head = new Node<T>(data);
		}
		else {
			Node<T>* temp = new Node<T>(data);
			getLastNode()->next = temp;
		}
		length++;
	}
	//ɾ��ͷ�ڵ�
	void delHeadNode() {
		Node<T>* d = head;
		head = head->next;
		delete d;
		length--;
	}
	//ɾ��β�ڵ�
	void delLastNode() {
		Node<T>* p = getNodeByIndex(length - 2);
		delete getLastNode();
		p->next = nullptr;

		length--;
	}
	//ɾ��ָ���ڵ�
	void delNodeByIndex(int index) {
		if (index <= 0) {
			delHeadNode();
		}
		else if (index > length) {
			delLastNode();
		}
		else {
			Node<T>* p = getNodeByIndex(index - 1);//��ȡ��һ��
			p->next = getNodeByIndex(index + 1);//����һ��������һ��
			length--;
		}
	}
	//�滻ָ���ڵ��ֵ
	void replaceNode(int index, T data) {
		if (index > length) {
			getLastNode()->data = data;
		}
		else {
			Node<T>* p = getNodeByIndex(index);
			p->data = data;
		}
	}
	//�����������淵��--�ݹ�д��
	vector<T> traversal() {
		

	}
	//��ȡָ��index������
	T& get(int index) {
		return getNodeByIndex(index)->data;
	}
	//��ȡͷ����
	T& getHead() {
		return head->data;
	}
	//��ȡβ����
	T& getLast() {
		return getLastNode()->data;
	}
	//��ȡ����
	int getLength() {
		return length;
	}
	//���������������ݣ��ͺ�����һ��
	T& operator[](int index) {
		return get(index);
	}
};

//int main() {
//	LinkedList<int> l(new int[] {0, 1, 2}, 3);
//	l.get(0);
//	l.delNodeByIndex(1);
//	cout << l.get(1) << endl;
//}