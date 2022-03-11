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
	//无参构造函数
	LinkedList() {
		head = new Node<T>();
		length = 0;
	}
	//有参构造函数
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
	//返回头节点
	Node<T>* getHeadNode() {
		return head;
	}
	//返回最后一个节点
	Node<T>* getLastNode() {
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		return p;
	}
	//返回指定节点
	Node<T>* getNodeByIndex(int index) {
		if (index < length && index >= 0) {
			Node<T>* p = head;
			for (int n{}; p->next != nullptr && n < index; n++) {
				p = p->next;
			}
			return p;
		}
		cout << "错误，指定的index:" << index << (index < 0 ? " 小于零" : (index >= length ? " 大于链表长度" + length : " ")) << endl;
		return new Node<T>();
	}
	//在指定节点后添加一个节点
	void addNodeAfterIndex(int index, T data) {
		Node<T>* p = getNodeByIndex(index);
		p->next = new Node<T>(data);
		length++;
	}
	//添加头节点
	void addHeadNode(T data) {
		//如果调用了无参的构造函数
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
	//在最后添加一个节点
	void addLastNode(T data) {
		//如果调用了无参的构造函数
		if (length == 0) {
			head = new Node<T>(data);
		}
		else {
			Node<T>* temp = new Node<T>(data);
			getLastNode()->next = temp;
		}
		length++;
	}
	//删除头节点
	void delHeadNode() {
		Node<T>* d = head;
		head = head->next;
		delete d;
		length--;
	}
	//删除尾节点
	void delLastNode() {
		Node<T>* p = getNodeByIndex(length - 2);
		delete getLastNode();
		p->next = nullptr;

		length--;
	}
	//删除指定节点
	void delNodeByIndex(int index) {
		if (index <= 0) {
			delHeadNode();
		}
		else if (index > length) {
			delLastNode();
		}
		else {
			Node<T>* p = getNodeByIndex(index - 1);//获取上一个
			p->next = getNodeByIndex(index + 1);//将上一个链接下一个
			length--;
		}
	}
	//替换指定节点的值
	void replaceNode(int index, T data) {
		if (index > length) {
			getLastNode()->data = data;
		}
		else {
			Node<T>* p = getNodeByIndex(index);
			p->data = data;
		}
	}
	//遍历链表并保存返回--递归写法
	vector<T> traversal() {
		

	}
	//获取指定index的数据
	T& get(int index) {
		return getNodeByIndex(index)->data;
	}
	//获取头数据
	T& getHead() {
		return head->data;
	}
	//获取尾数据
	T& getLast() {
		return getLastNode()->data;
	}
	//获取长度
	int getLength() {
		return length;
	}
	//中括号来访问数据，就和数组一样
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