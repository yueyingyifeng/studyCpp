/*
2021年7月22日
n个人围成一个圈
然后到第g个人就要被踢出
讨论在各种情况下
那个位置的人会存活到最后？

2021年7月31日成功解决
*/

#include<iostream>
#include<vector>
using namespace std;

int result(int* data, int size) {//找到最终结果
	for (int n{}; n < size; n++) {
		if (data[n] != -1) {
			return n;
		}
	}
}

bool cheack(int* data,int size) {		//显示最终结果
	int count{};
	for (int i{}; i < size; i++) {
		if (data[i] == -1) {
			count++;
		}
	}
	if (size - count == 1) {
		cout << "最后存活的是" << result(data, size) << endl;
		return true;
	}
	else {
		return false;
	}
}

void show(int* data, int size) {		//显示数据
	cout << " data: ";
	for (int i{ }; i < size; i++) {
		cout << data[i] << ",";
	}
	cout << endl;
}

void Maual_fun() {
	int g, n;

	cout << "请输入多少人围成一个圈:";
	cin >> n;
	int* data = new int[n];
	cout << "请输入到第几个人就踢走:";
	cin >> g;

	for (int i{ }; i < n; i++) {		//初始化数据
		data[i] = i;
	}

	for (int index{}, i{};; i++)
	{
		if (i == n) {					//当i碰到最后一个人时重置i 
			i = 0;
		}

		if (data[i] == -1) {			//如果遇到-1就跳过
			continue;
		}
		index++;
		if (index == g + 1) {			//当遇到目标数时标记这个数为-1
			data[i] = -1;
			show(data, n);
			index = 0;
		}

		if (cheack(data, n)) {
			break;
		}
	}
}

void Maual_fun(int n,int g) {
	int* data = new int[n];

	for (int i{ }; i < n; i++) {		//初始化数据
		data[i] = i;
	}

	for (int index{}, i{};; i++)
	{
		if (i == n) {					//当i碰到最后一个人时重置i 
			i = 0;
		}

		if (data[i] == -1) {			//如果遇到-1就跳过
			continue;
		}
		index++;
		if (index == g + 1) {			//当遇到目标数时标记这个数为-1
			data[i] = -1;
			index = 0;
		}

		if (cheack(data, n)) {
			break;
		}
	}
}

void auto_fun(int nMax,int gMax) {
	for (int n{1}; n < nMax; n++) {
		cout << "当n为" << n  << "----------------------" << endl;
		for (int g{1}; g < gMax; g++) {
			cout << "当g为" << g << ":";
			Maual_fun(n, g);
		}
	}
}

/*int main() {
	//Maual_fun();			//手动调整数值
	auto_fun(20, 10);			//自动
}*/