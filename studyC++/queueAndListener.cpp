#include<iostream>
#include"queue.cpp"
using namespace std;

class Event {
public:
	Event() {
		cout << "我出来啦" << endl;
	}
	Event(std::string msg) {
		cout << msg << endl;
	}
	~Event() {
		cout << "我离开了" << endl;
	}
};

class Listener {
	void (*callback(Event));
	std::string msg{ "这是不是默认方法,是经过本Listener加工过的" };

public:
	void run() {
		callback(Event(msg));
	}
	void run(void(*callback(Event))) {
		callback(Event());
	}
};

class Dispose {
	//queue<Listener> q;
public:
	void createListener(void(*doSomething)) {
		
	}
	
};

void Listening() {

}
