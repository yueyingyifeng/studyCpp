template <typename T>
class Node {
public:
    T data;
    Node<T>* prior;//Ç°Çý
    Node<T>* next;//ºó¼Ì

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