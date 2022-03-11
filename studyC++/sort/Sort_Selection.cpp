#include<iostream>
using namespace std;
/*
	选择排序，和冒泡差不多
*/
int* Selection(int* arr,int length) {
	int temp;
	for (int n{}; n < length; n++) {
		for (int i{}; i < length; i++) {
			if (arr[n] < arr[i]) {
				temp = arr[n];
				arr[n] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return arr;
}

//int main() {
//	const int length{ 5 };
//	int* a = new int[length] {2, 3, 1, 4, 5};
//	Selection(a, length);
//	for (int n{}; n < length; n++) {
//		cout << a[n] << " ";
//	}
//}