/*
* Author : yueyingyifeng
* CreateTime : 2022年4月11日
* Description : 设计一个排队系统。程序开始时，创建几个窗口，然后给队伍长度，最后观察效果
*      总人数:n  总窗口：4
*		   第一轮  第二轮   第三轮
* 窗口1 [] 第n-1位 第n-5位 .......直至人数减完
* 窗口2 [] 第n-2位 第n-6位
* 窗口3 [] 第n-3位 第n-7位
* 窗口4 [] 第n-4位 第n-8位
*/

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <Windows.h>
using namespace std;

class Session {
public:
	//接纳一个人
	Session(int& takeone, int time) {
	
		time *= 400;
		Sleep(time);
		takeone--;//完毕
	}
};


class LineApp {
	vector<thread> Sessions;
public:
	//总人数，每个窗口需要工作多少时间才能解决一个客户(同时也指明了总窗口数量)
	LineApp(int numofpeople,vector<int> eachSessionWorkTime) {
		int numofsession = static_cast<int>(eachSessionWorkTime.size());
		mutex* m = new mutex;

		for (int n{}; n < numofsession; n++) {
			Sessions.push_back(thread([=](int& numofpeople, int time, mutex& m)mutable {
						int id = n;
						cout << "this is " << n << endl << endl; 
						m.lock(); //保护数据不被一直占用,大家不可能那么傻总去排一个队伍,如果发生了窗口也应该提醒：还有其他队伍呢
							cout << "窗口" << n << "开始工作---" << endl;
							Session* s = new Session(numofpeople, time);
							cout << "窗口" << n << "---结束工作" << endl;
						m.unlock();
						cout << "---剩余总人数:" << numofpeople << endl;

					}, ref(numofpeople), eachSessionWorkTime[n], ref(*m))
				);
		}

		

	}

	void start() {
		for (thread& t : Sessions) {
			t.detach();
		}
	}

};

void f(mutex& m,int& total) {
	m.lock();
	total--;
	cout << total << endl;
	m.unlock();
}

// int main() {
// 	LineApp l(10,vector<int>{1,1,2,3});
// 	l.start();
	
// 	测试
// 	mutex m;
// 	int tt = 3;
// 	thread t(f, ref(m), ref(tt));
// 	thread t1(f, ref(m), ref(tt));

// 	t.detach();
// 	t1.detach();
	
// 	system("pause");
// 	return 0;
// }