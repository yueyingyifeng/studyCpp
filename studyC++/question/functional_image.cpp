/*
* 一个可以在控制台画函数图像的小程序
* 嗯，没错，就是将数学函数的结果的函数样子输出的控制台,比如直线函数，曲线函数，甚至。。。三角函数
*/
#include <iostream>
#include <vector>
using namespace std;
/*
* 坐标类，保存x和y还有其代表的字符样式
*/
class Coord {
public:
	int x, y;
	char point{ ' ' };		//点的样式

	Coord() {
		x = 0;
		y = 0;
	}
	Coord(int x, int y)
		:x(x), y(y) {}
};
/*
* 图像模板，提供一套函数图像显示的类。
* 就是负责显示最基础的转换
* 原始数据是
* 0,0 0,1 0,2
* 1,0 1,1...
* 而数学坐标系则是
* 1,-1 0,1 1,1
* 0,-1 0,0...
* 本类就是负责转换的，refer是转换好的，但保存数据，而real则是参考refer来存放 点(point) 的
*/
class Fun_img {
	vector<Coord> refer_img;//只保存坐标系的图
	vector<Coord> real_img;	//保存最终图像
	int maxValue;			//x、y轴的最大值
	int area;				//共保存多少个点
	char point{ '*' };		//点的样式
protected:
	//从坐标系的图中获取对应的点
	int getPbyCoord(Coord& c) {
		for (int n{}; n < refer_img.size(); n++) {
			if (refer_img[n].x == c.x && refer_img[n].y == c.y) {
				return n;
			}
		}
	}
	int getPbyCoord(int x, int y) {
		for (int n{}; n < refer_img.size(); n++) {
			if (refer_img[n].x == x && refer_img[n].y == y) {
				return n;
			}
		}
	}
public:
	Fun_img() {
		maxValue = 0;
		area = 0;
	}
	Fun_img(int maxValue) {
		if (maxValue == 0) {
			cout << "错误，函数图像必须大于0" << endl;
			return;
		}
		else {
			this->maxValue = maxValue * 2 + 1;
			area = (int)pow(this->maxValue, 2);
		}
		for (int y = 0; y < this->maxValue; y++) {
			for (int x = 0; x < this->maxValue; x++) {
				/*cout << "[" <<//输出图像,调试用
					(maxOfHorizon - x >= 0 ? -(maxOfHorizon - x) : x - maxOfHorizon) <<
					"," <<
					(maxOfVertical - y >= 0 ? maxOfVertical - y : -(y - maxOfVertical)) << "]" << " ";*/
				refer_img.push_back(Coord((maxValue - x >= 0 ? -(maxValue - x) : x - maxValue),
					(maxValue - y >= 0 ? maxValue - y : -(y - maxValue))
				));
			}
		}
		real_img.resize(refer_img.size(), Coord());
	}
	//设置点的样式
	void setPointStyle(char p) {
		this->point = p;
	}
	//在函数图像上画一个点
	void setPoint(Coord& c) {
		real_img[getPbyCoord(c)].point = this->point;
	}
	void setPoint(int x, int y) {
		real_img[getPbyCoord(x, y)].point = this->point;
	}
	//在函数图像上画一个自定义样式的点
	void setPoint(Coord& c, char p) {
		real_img[getPbyCoord(c)].point = p;
	}
	void setPoint(int x, int y, char p) {
		real_img[getPbyCoord(x, y)].point = p;
	}
	//显示坐标系实体,此方法仅显示函数图像的所有坐标，没有具体点
	void showReferImg() {
		cout << endl;
		for (int p{ 1 }; p <= area; p++) {
			if (p % maxValue != 0) {
				cout << "[" << refer_img[p - 1].x << "," << refer_img[p - 1].y << "]" << " ";
			}
			else {
				cout << "[" << refer_img[p - 1].x << "," << refer_img[p - 1].y << "]" << " ";
				cout << endl;
			}
		}
	}
	//显示坐标系内容,此方法显示函数图像的结果
	void show() {
		cout << endl;
		for (int p{ 1 }; p <= area; p++) {
			if (p % maxValue != 0) {
				cout << real_img[p - 1].point;
			}
			else {
				cout << real_img[p - 1].point;
				cout << endl;
			}
		}
	}
};
/*
* 数学类,封装(使用)了图像模板
* 包含四个基础的数学函数（精度问题还有几个无法运用）
* 并显示操作数学函数
*/
class Function {
	Fun_img fun_img;//封装
	int maxValue;	//轴的最大值[-maxValue,maxValue]
	char p = '*';	//默认显示样式
public:
	Function(int maxValue)
		:maxValue(maxValue)
	{
		fun_img = Fun_img(maxValue);
		for (int n{ -maxValue }; n < maxValue; n++) {
			fun_img.setPoint(n, 0, '-');
		}
		for (int n{ -maxValue }; n < maxValue; n++) {
			fun_img.setPoint(0, n, '|');
		}
		fun_img.setPoint(maxValue, 0, '>');
		fun_img.setPoint(0, maxValue, '^');
		fun_img.setPoint(0, 0, '+');
	}

	//直线函数:y = ax + b
	void LinearFunction(int a, int b = 0) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (y == a * x + b) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//二次函数:y = ax^2 + bx + c
	void QuadraticFunction(int a = 1, int b = 0, int c = 0) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (y == (a * pow(x, 2) + b * x + c)) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//指数函数:y = a^x + b,a>=1
	void ExponentialFunction(int a, int b = 0) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (!(a >= 1)) {
					cout << "指数函数a必须大于0!" << endl;
					return;
				}
				if (y == ((int)pow(a, x) + b)) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//对数函数:y = logax, a >= 0.(a为底数)
	void LogarithmicFunction(int a) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (!(a >= 1)) {
					cout << "指数函数a必须大于0!" << endl;
					return;
				}
				if (y == (log(x) / log(a))) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//设置笔刷
	void setPoint(char p) {
		this->p = p;
	}

	//显示函数图像
	void show() {
		fun_img.show();
	}
	//显示函数坐标系
	void showReferImg() {
		fun_img.showReferImg();
	}
};

//int main() {
//	Function f(10);
//	f.LinearFunction(3);//一次函数
//	f.setPoint('1');
//	f.QuadraticFunction(-2, 3, 2);//二次函数
//	f.setPoint('2');
//	f.ExponentialFunction(3,2);//指数函数
//	f.setPoint('3');
//	f.LogarithmicFunction(2);//对数函数
//
//	f.show();
//	
//}


//int main()
//{
//	double a = 2, x = 2;//以2为底的对数函数 
//	for (x = 2; x <= 16; x += 2)
//	{
//		cout << "x=" << x << "时，以2为底的对数函数=" << log(x) / log(a) << endl;
//	}
//	return 0;
//}