/*
* 2021��7��16��17��30��
* Ͱ���� - ͨ�ð�
*/
#include<iostream>
using namespace std;

//-------�������������ֵ-------//
int Max(int* array,int size) {
	int max{};
	for (int n{}; n < size; n++) {
		if (max < array[n]) {
			max = array[n];
		}
	}
	return max;
}
//------------Ͱ����-----------//
int* bucketSort(int* array, int size) {
	int max = Max(array, size) + 1;//����������������ֵ��ͨ�������������ֵ��������ΪͰ����������ԣ�
	int* temp = new int[max];//���Ͱ����Ľ��
	int* result = new int[size];//���ս��

	//��ʼ��
	for (int n{}; n < max; n++) {
		temp[n] = 0;
	}
	//Ͱ����
	for (int n{}; n < max; n++) {
		for (int x{}; x < max; x++) {
			if (array[x] == n) {
				++temp[n];
			}
		}
	}
	//���ս��
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