//2022年4月9日
//工厂模式
#include <iostream>
using namespace std;

//食物接口，内有制作的方法
class Food {
public:
	virtual void make() = 0;
};
//蛋糕类,属于食物，所以要实现了制作方法
class Cake
	:  public Food {
public:
	virtual void make() override {
		cout << "制作精美的蛋糕" << endl;
	}
};
//蛋糕类,属于食物，所以要实现了制作方法
class Bread
	: public Food {
public:
	virtual void make() override {
		cout << "制作松软的面包" << endl;
	}
};
//蛋糕类,属于食物，所以要实现了制作方法
class Chocolate
	: public Food{
public:
	virtual void make() override {
		cout << "制作苦苦的巧克力" << endl;

	}
};

//食物工厂,专门制作食物的地方
class FoodMaker {
public:
	//抽象类必须是指针类型，否则不能直接创建对象（或函数）
	static Food* Formula(string type) {
		if (type == "cake" || type == "Cake") {
			return new Cake();
		}
		else if (type == "bread" || type == "Bread") {
			return new Bread();
		}
	}
};


//int main() {
//	Food* food = FoodMaker::Formula("Cake");//创建一个食物，然后这个食物是由食物工厂指派的佩服
//	food->make();//制作！
//	food = FoodMaker::Formula("Bread");
//	food->make();
//
//	return 0;
//}