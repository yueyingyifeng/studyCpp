#include <iostream>
using namespace std;


void insertSort(int arr[], int length) {
	int p;
	/*ÉýÐò
	for (int i{}; i < length; i++) {
		for (int j{}; j < length - 1; j++) {
			p = arr[j];
			if (arr[j] > arr[j + 1]) {
				arr[j] = arr[j + 1];
				arr[j + 1] = p;
			}
		}
	}
	*/
	/*½µÐò*/
	for (int i{}; i < length; i++) {
		for (int j{ }; j < length - 1; j++) {
			p = arr[j];
			if (arr[j] < arr[j + 1]) {
				arr[j] = arr[j + 1] ;
				arr[j + 1] = p;
			}
		}
	}
}
//from visual Algo
void insertionSort(int a[], int N) {
	for (int i = 1; i < N; ++i) { // O(N)
		int X = a[i]; // X is the item to be inserted
		int j = i - 1;
		for (; j >= 0 && a[j] > X; --j) // can be fast or slow
			a[j + 1] = a[j]; // make a place for X
		a[j + 1] = X; // index j+1 is the insertion point
	}
}


//int main() {
//	int arr[5]{ 1,2,3,4,5 };
//	insertSort(arr, 5);
//	for (int n : arr) {
//		cout << n << " ";
//	}
//}