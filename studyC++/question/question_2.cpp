/*
2022��3��4��
��һ�����飬������������ary[1,2,3]
�ָ��һ����ά���飬��ʾΪ
result[][3]{
	{1},
	{2},
	{3},
	{1,2},
	{1,3},
	{2,1},
	{2,3},
	{3,1},
	{3,2},
	...
}
*/

#include <iostream>
using namespace std;

int* function(int ary[]) {
	return nullptr;
}
//ǰ�����⣺������һ��������Ķ�ά���飿
void p() {
	int ary[][3]{
		{1,2,3},
		{1},
		{3,2}
	};

	for (int y{}; y < 3; y++) {
		for (int x{}; x < 3; x++) {
			if (ary[y][x] != 0) {
				cout << ary[y][x] << " ";
			}
		}
		cout << endl;
	}
	
	

}