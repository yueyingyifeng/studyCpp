/*
2021年7月11日15点20分
实现阶乘(Factorial)
3! = 3*2*1
*/
#include<iostream>
using namespace std;

int fact(int n) {
	return n > 0 ? n * fact(n - 1) : 1;
}

int fact_(int n) {
	int result{1};
	for (; n > 0; n--) {
		result *= n;
	}
	return result;
}

/*int main() {
	cout << fact(3) << endl;
	cout << fact(4) << endl;

	cout << fact_(3) << endl;
	cout << fact_(4) << endl;
}*/