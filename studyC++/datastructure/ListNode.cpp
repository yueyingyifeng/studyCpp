//����Ľڵ�
template<typename T>
class Node {
public:
	T data;
	Node<T>* next;
	Node() {
		data = {};
		next = nullptr;
	}
	Node(T data) {
		this->data = data;
		next = nullptr;
	}
};

using ListNode = Node<int>;