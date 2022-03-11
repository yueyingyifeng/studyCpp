template <typename T>
class Node {
public:
    T data;
    Node<T>* prior;//ǰ��
    Node<T>* next;//���

    Node() {
        data = {};
        prior = nullptr;
        next = nullptr;
    }
    Node(T initialData) {
        data = initialData;
        prior = nullptr;
        next = nullptr;
    }
};

using DListNode = Node<int>;