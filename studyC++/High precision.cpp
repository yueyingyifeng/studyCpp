/*
2021��7��31��
�߾�������
һ�����ǳ��ǳ���
ϣ���ܹ�����������ţ��������£�
���õ�ȡλ��������ĵ�һλ���Ǹ��������λ�����һλ���Ǹ�λ
��ȷ�Ŀ��ƣ�����Ӽ������������һ��λ��,�����λ���9�ȵ�

��100����ʾ�ľ���
number[0] = 1
number[1] = 0
number[2] = 0
*/
#include <iostream>
using namespace std;

class integer {
	int* numbers;//����
	int length{};//���ݵĳ���
	//------��ȡ����-------//
	int numLength(int num) {
		int count{0};
		while (num /= 10) {
			count++;
		}
		return count;
	}
	//------���鸴��-------//
	inline void arr_Copy(int* From, int* To, int sizeTo) {
		for (int n{}; n < sizeTo; n++) {
			To[n] = From[n];
		}
	}
	//-------��ȡλ-------//
	inline int getPossition(int number, int n) {
		return (int)(number / pow(10, n)) % 10;
	}
	//-------������-------//
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
	number.set(4, 9);//���õ���λΪ9
	number.show();

}
*/
