#include <iostream>
using namespace std;

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
    //ɾ��ָ���ڵ�,������---------------------------δʵ��
    void delNode_Next(int index) {
        if (index > length && !isLoop) {
            cout << index << "����������,����ʧ��" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "С�ڴ�����,����ʧ��" << endl;
        }
        else if (index < 0) {
            if (index - 1 == 0) {
                delHeadNode();
            }
            cout << index << "С�ڴ�����,����ʧ��" << endl;
        }
        else if (index > length) {
            if (index + 1 == length) {
                delLastNode();
            }
            cout << index << "����������,����ʧ��" << endl;
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
    //ɾ��ָ���ڵ㣬��ǰ����---------------------------δʵ��
    void delNode_Prior(int index) {
        if (index > length && !isLoop) {
            cout << index << "����������,����ʧ��" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "С�ڴ�����,����ʧ��" << endl;
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
    //ɾ��ͷ�ڵ�---------------------------��bug
    void delHeadNode() {
        if (length > 0) {
            Node<T>* temp = head;
            head = head->next;
            length--;
            delete temp;
        }
        else {
            cout << "�������Ѿ����ˣ���ɾ��" << endl;
        }
    }
    //ɾ��β�ڵ�---------------------------��bug
    void delLastNode() {
        if (length > 0) {
            Node<T>* temp = getLastNode();
            temp->prior->next = nullptr;
            length--;
            delete temp;
        }
        else {
            cout << "�������Ѿ����ˣ���ɾ��" << endl;
        }
    }
    //���ͷ�ڵ�
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
    //���β�ڵ�
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
    //ָ��λ�ú����ڵ�--���Ǵ�ͷ��㿪ʼ, ���� 1 2 0 0 3
    void insertNode_Next(int index, T data) {
        if (index > length && !isLoop) {
            cout << index << "����������,����ʧ��" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "С�ڴ�����,����ʧ��" << endl;
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
    //ָ��λ��ǰ����ڵ� --���Ǵ�ͷ��㿪ʼ, ���� 1 0 0 2 3
    void insertNode_Prior(int index, T data) {
        if (index > length && !isLoop) {
            cout << index << "����������,����ʧ��" << endl;
        }
        else if (index < 0 && !isLoop) {
            cout << index << "С�ڴ�����,����ʧ��" << endl;
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
    //��ȡָ���ڵ㣨������ң�
    Node<T>* getNode_Next(int index) {
        if (index > length && !isLoop) {
            cout << index << "����������,���ص������һ���ڵ�" << endl;
            return getLastNode();
        }
        else if (index < 0 && !isLoop) {
            cout << index << "С�ڴ�����,���ص��ǵ�һ���ڵ�" << endl;
            return getHeadNode();
        }
        else {
            Node<T>* p = head;//��ͬ��
            for (int n{}; n < index; n++) {
                p = p->next;
            }
            return p;
        }
    }
    //��ȡָ���ڵ㣨ǰ����ң�
    Node<T>* getNode_Prior(int index) {
        if (index > length && !isLoop) {
            cout << index << "����������,���ص������һ���ڵ�" << endl;
            return getLastNode();
        }
        else if (index < 0 && !isLoop) {
            cout << index << "С�ڴ�����,���ص��ǵ�һ���ڵ�" << endl;
            return head;
        }
        else {
            Node<T>* p = getLastNode();//��ͬ��
            for (int n{}; n < index; n++) {
                p = p->prior;
            }
            return p;
        }
    }
    //��ȡͷ�ڵ�
    Node<T>* getHeadNode() {
        return head;
    }
    //��ȡβ�ڵ�
    Node<T>* getLastNode() {
        Node<T>* p = head;
        while (p->next != nullptr) {
            if (isLoop) {
                cout << "�������Ѿ�ͷβ������û��β�˰�.���ص���ͷ(����Ϊɶͷ���ڣ��ⲻ�ϻ���1X1��Ҳ����1��)" << endl;
                return head;
            }
            p = p->next;
        }
        return p;
    }
    //��ȡindex�ڵ��µ�ֵ,�������
    T& get_Next(int index) {
        return getNode_Next(index)->data;
    }
    //��ȡindex�ڵ��µ�ֵ,ǰ�����
    T& get_Prior(int index) {
        return getNode_Prior(index)->data;
    }
    //��ȡͷ�ڵ�ֵ
    T& getHead() {
        return getHeadNode()->data;
    }
    //��ȡβ�ڵ�ֵ
    T& getLast() {
        return getLastNode()->data;
    }
    //��ȡ������
    int getLength() {
        return length;
    }
    //�����Ƿ�Ϊ��
    bool isEmpty() {
        return length <= 0 ? true : false;
    }
};

//int main() {
//
//    return 0;
//}