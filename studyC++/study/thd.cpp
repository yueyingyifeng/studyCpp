#include <iostream>
#include <thread>
#include<mutex>//���� �̻߳���
#include <Windows.h>

using namespace std;
mutex m;
int work{ 10 };
void thd1() {
	while(work>5){
		if (m.try_lock()) {
			cout << "���߳�1ִ�� " << work-- << endl;
			m.unlock();
		}
	}
}

void thd2() {
	while (work > 0) {
		if (m.try_lock()) {
			cout << "���߳�2ִ�� " << work-- << endl;
			m.unlock();
		}
	}
}

//int main() {
//	thread t1(thd1), t2(thd2);
//	thread t3([]() {
//
//		});
//	t1.detach(); 
//	t2.detach();
//	cout << "���߳���ͣ" << endl;
//	system("pause");//���û����ͣ�����߳�Ҳ���ᱻ��ֹ
//}