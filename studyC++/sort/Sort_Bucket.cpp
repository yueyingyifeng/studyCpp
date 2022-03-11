/*
* 2021年7月16日17点30分
* 桶排序 - 通用版
*/
#include<iostream>
using namespace std;

//-------计算数组内最大值-------//
int Max(int* array,int size) {
	int max{};
	for (int n{}; n < size; n++) {
		if (max < array[n]) {
			max = array[n];
		}
	}
	return max;
}
//------------桶排序-----------//
int* bucketSort(int* array, int size) {
	int max = Max(array, size) + 1;//计算最终数组的最大值，通常由数组内最大值决定（因为桶排序的特殊性）
	int* temp = new int[max];//存放桶排序的结果
	int* result = new int[size];//最终结果

	//初始化
	for (int n{}; n < max; n++) {
		temp[n] = 0;
	}
	//桶排序
	for (int n{}; n < max; n++) {
		for (int x{}; x < max; x++) {
			if (array[x] == n) {
				++temp[n];
			}
		}
	}
	//最终结果
	for (int n{}, sz{}; n < max; n++) {
		for (int x{}; x < temp[n]; x++) {
			result[sz++] = n;
		}
	}
	return result;
}

/*int main() {
	int* array = new int[] {2, 1,3,3,6};
	int* result = bucketSort(array, 5);

	for (int n{}; n < 5; n++) {
		cout << result[n] << " ";
	}
}*/