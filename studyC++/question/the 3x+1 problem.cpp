/*
2021年8月11日 - 已解决——指用递归实现运算！不是解决了这个nb的问题。。。
3x+1问题
给一个x
如果x为偶数，则除2
如果x为奇数，则3*x+1
*/
#include<iostream>
using namespace std;

int fun(int x) {
	if (x == 1) {
		return 1;
	}
	if (x % 2 == 0) {
		cout << x << endl;
		return fun(x /= 2);
	}
	else {
		cout << x << endl;
		return fun(x = 3 * x + 1);
	}
}

/*
int main() {
	for (int n{ 1 }; n <= 10;n++) {
		cout << "n: " << n << "----------------" << endl;
		cout << fun(n) << " " << endl;
	}

}*/