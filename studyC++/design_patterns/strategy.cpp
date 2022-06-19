/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/6/19 20:13:17
* 	   Description ：策略模式，定义一个接口，定义一个容器，定义若干个接口实现类
*					 当容器装载的实现类不同时，容器的功能也就不同
*						就好比一个只能装5.56（接口）的弹夹（容器），但你也可以装5.56的曳光弹等同等型号不同效果的子弹（实现类）
*/
#include <iostream>

using namespace std;
//算法接口类
class Operator {
public:
	virtual int calc(int n1, int n2) = 0;
};
//算法容器类
class Context {
protected:
	Operator* op;
public:
	Context(Operator* op) {
		this->op = op;
	};
};
//算法实现类
class AddOp
	: public Operator{
public:
	virtual int calc(int n1, int n2) override {
		return n1 + n2;
	}
};
//算法实现类
class SubStractOp
	: public Operator{
public:
	virtual int calc(int n1, int n2) override {
		return n1 - n2;
	}
};
//算法容器的拓展类（就是特殊化)
class CalcContext
	: public Context {
public:
	CalcContext(Operator* op)
		: Context(op){}

	void excute(int n1, int n2) {
		cout << op->calc(n1, n2) << endl;
	}
};



//int main() {
//	CalcContext c(new AddOp);
//	c.excute(1, 1);
//	c = CalcContext(new SubStractOp);
//	c.excute(1, 1);
//
//	return 0;
//}