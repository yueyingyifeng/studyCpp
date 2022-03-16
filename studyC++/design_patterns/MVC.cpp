/**
* 2022年3月16日
* 模拟MVC设计模式
*/
#include <iostream>
using namespace std;

class Module {
	int data;
public:
	Module(int data)
		:data(data) {}
	void setData(int data) {
		this->data = data;
	}
	int getData() {
		return data;
	}
};

class View {
public:
	void PrintData(int data) {
		cout << endl
			<< "-------------" << endl
			<< "data: " << data << endl
			<< "-------------" << endl;
	}
};

class Controler {
	Module module;
	View view;
public:
	Controler(Module& m, View& v)
		:module(m), view(v) {}
	void setData(int data) {
		this->module.setData(data);
	}
	int getData() {
		return module.getData();
	}
	void upDataView() {
		view.PrintData(module.getData());
	}
};

int main() {
	Module m(3);
	View v;

	Controler c(m, v);

	c.upDataView();


	return 0;
}