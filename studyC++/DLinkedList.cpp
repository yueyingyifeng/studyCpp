#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* prior;//前驱
    Node<T>* next;//后继

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

template<typename T>
class DoubleLinkedList {
    Node<T>* head;
    int length;
    bool isLoop;
public:
    DoubleLinkedList() {
        head = nullptr;
        length = 0;
        isLoop = false;
    }
    DoubleLinkedList(int initialData) {
        head = new Node(initialData);
        length = 1;
        isLoop = false;
    }
    //删除指定节点,向后查找---------------------------未实现
    void delNode_Next(int index) {
        if (index > length && !isLoop) {
            cout << index << "超过此链表,操作失败" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "小于此链表,操作失败" << endl;
        }
        else if (index < 0) {
            if (index - 1 == 0) {
                delHeadNode();
            }
            cout << index << "小于此链表,操作失败" << endl;
        }
        else if (index > length) {
            if (index + 1 == length) {
                delLastNode();
            }
            cout << index << "超过此链表,操作失败" << endl;
        }
        else {
            Node<T>* del = getNode_Next(index);
            Node<T>* p = getNode_Next(index - 1) != nullptr ? getNode_Next(index - 1) : NULL;;
            Node<T>* p2 = getNode_Next(index + 1) != nullptr ? getNode_Next(index + 1) : NULL;

            if (p != nullptr && p2 != nullptr) {
                p->next = p2;
                p2->prior = p;

            }
            delete del;
            length--;
        }
    }
    //删除指定节点，向前查找---------------------------未实现
    void delNode_Prior(int index) {
        if (index > length && !isLoop) {
            cout << index << "超过此链表,操作失败" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "小于此链表,操作失败" << endl;
        }
        else {
            Node<T>* del = getNode_Prior(index);
            Node<T>* p = getNode_Prior(index + 1);
            Node<T>* p2 = getNode_Prior(index - 1);

            p->next = p2;
            p2->prior = p;
            length--;
            delete del;
        }
    }
    //删除头节点---------------------------有bug
    void delHeadNode() {
        if (length > 0) {
            Node<T>* temp = head;
            head = head->next;
            length--;
            delete temp;
        }
        else {
            cout << "此链表已经空了，别删了" << endl;
        }
    }
    //删除尾节点---------------------------有bug
    void delLastNode() {
        if (length > 0) {
            Node<T>* temp = getLastNode();
            temp->prior->next = nullptr;
            length--;
            delete temp;
        }
        else {
            cout << "此链表已经空了，别删了" << endl;
        }
    }
    //添加头节点
    void addHeadNode(T data) {
        if (length == 0) {
            head = new Node<T>(data);
            length++;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            temp->next = head;
            head->prior = temp;
            head = temp;
            length++;
        }
    }
    //添加尾节点
    void addLastNode(T data) {
        if (length == 0) {
            addHeadNode(data);
        }
        else {
            Node<T>* p = getLastNode();
            Node<T>* temp = new Node<T>(data);
            p->next = temp;
            temp->prior = p;
            length++;
        }
    }
    //指定位置后插入节点--都是从头结点开始, 比如 1 2 0 0 3
    void insertNode_Next(int index, T data) {
        if (index > length && !isLoop) {
            cout << index << "超过此链表,操作失败" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "小于此链表,操作失败" << endl;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            Node<T>* p = getNode_Next(index);
            Node<T>* p2 = getNode_Next(index + 1);

            p->next = temp;
            temp->prior = p;
            temp->next = p2;
            p2 != nullptr ? p2->prior = temp : NULL;

            length++;
        }
    }
    //指定位置前插入节点 --都是从头结点开始, 比如 1 0 0 2 3
    void insertNode_Prior(int index, T data) {
        if (index > length && !isLoop) {
            cout << index << "超过此链表,操作失败" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "小于此链表,操作失败" << endl;
        }
        else {
            Node<T>* temp = new Node<T>(data);
            Node<T>* p = getNode_Next(index);
            Node<T>* p2 = getNode_Next(index - 1);

            p2->next = temp;
            temp->prior = p2;
            temp->next = p;
            p->prior = temp;

            length++;
        }
    }
    //获取指定节点（后向查找）
    Node<T>* getNode_Next(int index) {
        if (index > length && !isLoop) {
            cout << index << "超过此链表,返回的是最后一个节点" << endl;
            return getLastNode();
        }
        else if (index < 0 && !isLoop) {
            cout << index << "小于此链表,返回的是第一个节点" << endl;
            return getHeadNode();
        }
        else {
            Node<T>* p = head;//不同点
            for (int n{}; n < index; n++) {
                p = p->next;
            }
            return p;
        }
    }
    //获取指定节点（前向查找）
    Node<T>* getNode_Prior(int index) {
        if (index > length && !isLoop) {
            cout << index << "超过此链表,返回的是最后一个节点" << endl;
            return getLastNode();
        }
        else if (index < 0 && !isLoop) {
            cout << index << "小于此链表,返回的是第一个节点" << endl;
            return head;
        }
        else {
            Node<T>* p = getLastNode();//不同点
            for (int n{}; n < index; n++) {
                p = p->prior;
            }
            return p;
        }
    }
    //获取头节点
    Node<T>* getHeadNode() {
        return head;
    }
    //获取尾节点
    Node<T>* getLastNode() {
        Node<T>* p = head;
        while (p->next != nullptr) {
            if (isLoop) {
                cout << "此链表已经头尾相连，没有尾了啊.返回的是头(你问为啥头还在，这不废话吗，1X1不也等于1吗？)" << endl;
                return head;
            }
            p = p->next;
        }
        return p;
    }
    //获取index节点下的值,后向查找
    T& get_Next(int index) {
        return getNode_Next(index)->data;
    }
    //获取index节点下的值,前向查找
    T& get_Prior(int index) {
        return getNode_Prior(index)->data;
    }
    //获取头节点值
    T& getHead() {
        return getHeadNode()->data;
    }
    //获取尾节点值
    T& getLast() {
        return getLastNode()->data;
    }
    //获取链表长度
    int getLength() {
        return length;
    }
    //链表是否为空
    bool isEmpty() {
        return length <= 0 ? true : false;
    }
};

//int main() {
//
//    return 0;
//}