/*
2021年7月31日
快速排序的实现
*/

#include<iostream>
using namespace std;

//升序
void quickSort(int datum[], int left, int right) {
	int i, j, t, temp;
	if (left > right)
	{
		return;
	}

	temp = datum[left];
	i = left;
	j = right;

	while (i != j)
	{
		while (datum[j] >= temp && i < j) {
			j--;
		}

		while (datum[i] <= temp && i < j) {
			i++;
		}

		if (i < j)
		{
			t = datum[i];
			datum[i] = datum[j];
			datum[j] = t;
		}
	}
	datum[left] = datum[i];
	datum[i] = temp;

	quickSort(datum,left, i - 1);
	quickSort(datum,i + 1, right);
	return;
}

//int main() {
//
//	int datum[5]{5,3,2,4,1};
//
//
//	quickSort(datum,0, 4);
//
//	for (int i = 0; i < 5; i++) {
//		cout << datum[i] << ' ';
//	}
//}
