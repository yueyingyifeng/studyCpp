#include<iostream>
using namespace std;

int Paritition(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			--high;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			++low;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high) {
	if (low < high) {
		int pivot = Paritition(A, low, high);
		QuickSort(A, low, pivot - 1);
		QuickSort(A, pivot + 1, high);
	}
}

//int main() {
//	int arr[]{3, 2, 1, 4, 5};
//	QuickSort(arr, 0, 4);
//	for (int n : arr) {
//		cout << n << endl;
//	}
//
//}