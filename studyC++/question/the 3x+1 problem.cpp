/*
2021��8��11�� - �ѽ������ָ�õݹ�ʵ�����㣡���ǽ�������nb�����⡣����
3x+1����
��һ��x
���xΪż�������2
���xΪ��������3*x+1
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