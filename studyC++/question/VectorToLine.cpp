#include<iostream>
#include <string>

using namespace std;

enum class Dir { up, down, left, right };//方向

int replace(char c) {//字符0-9转整型
	return c >= 48 && c <= 58 ? c - 48 : -1;
}

int* readLine(int length) {//获取一行的数据，输入类似1 2 3中间用空格分开
	int x{};
	int* arr = new int[length];
	string str;
	getline(cin, str);

	cout << str.c_str() << endl;
	for (int n{}; n < str.length(); n++) {
		if (str.at(n) != ' ') {
			arr[x++] = replace(str.at(n));
		}
	}

	return arr;
}

void line(int** arr, int x_max, int y_max) {//线性输出
	int y{}, x{};
	int x_min{}, y_min{};
	Dir d = Dir::right;			//默认朝右
	int max = x_max * y_max;	//最大步数
	for (int step{}; step < max; step++) {
		cout << endl << x << ":" << y << endl;
		switch (d) {
		case Dir::up://------------------上
			cout << arr[x--][y];
			break;
		case Dir::down://----------------下
			cout << arr[x++][y];
			break;
		case Dir::left://----------------右
			cout << arr[x][y--];
			break;
		case Dir::right://---------------左
			cout << arr[x][y++];
			break;
		}
		//---------碰到边界就改变方向--------//
		if ((x <= x_max && y <= y_max) /*&& (x >= x_min && y >= y_min)*/) {	//右
			d = Dir::right;
		}
		if ((x >= x_max && y <= y_max) /*&& (x <= x_min && y >= y_min)*/) {	//下
			d = Dir::down;
		}
		if ((x <= x_max && y >= y_max) /*&& (x >= x_min && y <= y_min)*/) {	//左
			d = Dir::left;
		}
		if ((x >= x_max && y >= y_max) /*&& (x <= x_min && y <= y_min)*/) {	//上
			d = Dir::up;
		}
	}
}
/*
int main() {
	int length{}, height{};

	cin >> length >> height; cin.ignore();//输入长度和高度

	//-----堆空间开辟二维数组-----//
	int** arr = new int* [height];
	for (int n{}; n < height; n++) {
		arr[n] = new int[length];
	}
	//-----二维数组每读取一行-----//
	for (int y{}; y < height; y++) {
		arr[y] = readLine(length);
	}
	//-----矩形输出这个二维数组-------//
	cout << "------------------" << endl;
	for (int y{}; y < height; y++) {
		for (int x{}; x < length; x++) {
			cout << arr[y][x];
		}
		cout << endl;
	}
	//-----线性输出这个二维数组-------//
	cout << "------------------" << endl;
	line(arr, length, height);

	return 0;
}
*/