#include<iostream>
#include"queue.cpp"
using namespace std;

class Event {
public:
	Event() {
		cout << "�ҳ�����" << endl;
	}
	Event(std::string msg) {
		cout << msg << endl;
	}
	~Event() {
		cout << "���뿪��" << endl;
	}
};

class Listener {
	void (*callback(Event));
	std::string msg{ "���ǲ���Ĭ�Ϸ���,�Ǿ�����Listener�ӹ�����" };

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
