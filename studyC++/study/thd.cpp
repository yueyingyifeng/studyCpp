#include <iostream>
#include <thread>
#include<mutex>//引入 线程互斥
#include <Windows.h>

using namespace std;
mutex m;
int work{ 10 };
void thd1() {
	while(work>5){
		if (m.try_lock()) {
			cout << "子线程1执行 " << work-- << endl;
			m.unlock();
		}
	}
}

void thd2() {
	while (work > 0) {
		if (m.try_lock()) {
			cout << "子线程2执行 " << work-- << endl;
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
//	cout << "主线程暂停" << endl;
//	system("pause");//如果没有暂停，子线程也将会被终止
//}