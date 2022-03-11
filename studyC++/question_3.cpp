/*
2022年3月4日
给链表1(l1)和链表2(l2)

比如
l1[1,2,3]
l2[1,2]
将每项相加，得出新链表
r[2,4,3]
就和加法竖式计算一样
*/
#include <iostream>
#include "LinkedList.cpp"
using namespace std;

using ListNode = Node<int>;

void showList(ListNode* list) {
    if (list) {
        cout << list->data << " ";
        list = list->next;
        showList(list);
    }
    return;
}

ListNode* fun(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode();
    ListNode* temp = result;

    while (l1 || l2) {
        int add1 = l1 ? l1->data : 0;
        int add2 = l2 ? l2->data : 0;
        

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
        temp->data = (add1 + add2) % 10;
        temp->next = new ListNode();
        temp = temp->next;
    }
    return result;
}



//int main() {
//    ListNode* l1;
//    l1 = new ListNode(1);
//    ListNode* t = new ListNode(2);
//    l1->next = t;
//    t->next = new ListNode(3);
//    
//
//   
//    ListNode* l2;
//    l2 = new ListNode(1);
//    l2->next = new ListNode(2);
//
//    showList(fun(l1, l2));
//}

