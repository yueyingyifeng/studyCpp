/*
2021年7月31日
高精度整数
一个数非常非常大
希望能够用数组来存放，理由如下：
更好的取位，如数组的第一位就是该数的最大位，最后一位就是个位
精确的控制，随意加减这个数的任意一个位置,比如百位变成9等等

如100所表示的就是
number[0] = 1
number[1] = 0
number[2] = 0
*/
#include <iostream>
using namespace std;

class integer {
	int* numbers;//数据
	int length{};//数据的长度
	//------获取长度-------//
	int numLength(int num) {
		int count{0};
		while (num /= 10) {
			count++;
		}
		return count;
	}
	//------数组复制-------//
	inline void arr_Copy(int* From, int* To, int sizeTo) {
		for (int n{}; n < sizeTo; n++) {
			To[n] = From[n];
		}
	}
	//-------获取位-------//
	inline int getPossition(int number, int n) {
		return (int)(number / pow(10, n)) % 10;
	}
	//-------计算幂-------//
	int power(int x, int n) {
		if (n > 1) {
			return x * power(x, --n);
		}
		else {
			return x;
		}
	}
public:
	integer() { numbers = nullptr; }
	integer(int number)
	{
		length = numLength(number);

	}


	void operator=(int num) {
		length = numLength(num) + 1;
		int* temp = new int[length];
		for (int n{}; n < length; n++) {
			temp[n] = getPossition(num, length- 1 -n);
		}
		numbers = new int[length];
		arr_Copy(temp, numbers, length);
	}

	void set(int position, int number) {
		numbers[length - position] = number;
	}

	void show() {
		cout << "numbers: ";
		for (int n{};n < length;n++)
		{
			cout << numbers[n];
		}
		cout << endl;
	}
};




/*
int main() {
	integer number;
	number = 123456;
	number.set(4, 9);//设置第四位为9
	number.show();

}
*/
