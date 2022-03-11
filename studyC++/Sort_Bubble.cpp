#include <iostream>
using namespace std;

void BubbleSort(int arr[], int length) {
	int temp;
	for (int i{}; i < length; i++) {
		for (int j{}; j < i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp		= arr[j + 1];
				arr[j + 1]	= arr[j];
				arr[j]		= temp;
			}
		}
	}
}


//int main() {
//	int arr[] {4, 2, 5, 3, 1};
//	BubbleSort(arr, 5);
//	for (int n : arr) {
//		cout << n << " ";
//	}
//}