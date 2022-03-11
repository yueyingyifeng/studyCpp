/*
2022年3月4日
给一个数组，比如整型数组ary[1,2,3]
分割成一个二维数组，表示为
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
//前置问题：如何输出一个不规则的二维数组？
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