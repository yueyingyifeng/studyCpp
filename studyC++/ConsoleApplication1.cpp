//             ＿＿
//          ／＞　　フ
//          |   -  - l
//         ／`  = x =ノ
//        /　　　 　  |
//       /　   ヽ　　 ﾉ
//       │　   |　|　|
//    ／￣|　　 |　|　|
//    | (￣ヽ＿_ヽ_)__)
//    ＼二つ​
//       猫猫护体，永无BUG
//此项目保存着在猫猫注视下我写过的代码，测试，学习，数据结构等。
#include <iostream>
using namespace std;

class A {
	int a_;
public:
	void printA() {
		cout << a_ << endl;
	}
	void setA(int a_) {
		this->a_ = a_;
	}
	A* operator()() {
		return this;
	}
};

void PrintA(A (*a)()) {
	a().printA();
}

int main() {
	PrintA([]()->A {
		A a;
		a.setA(2);
		return a;
	});
}