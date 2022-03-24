/*
* 乱序算法
* 给一串数字，然后打乱
* 1，2，5，3，4 -》 4，2，3，1，5
* solved !
*/
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int random(int m, int n) {
	srand(time(nullptr));
	return rand() % (n - m + 1) + m;
}

void swap(int* a, int* b) {
	int* t;
	t = a;
	a = b;
	b = t;
	delete t;
	t = nullptr;
}
						
vector<int> fun0(vector<int>& targets) {
	int tar_length = targets.size();
	for (int n{}; n < tar_length;n++) {
		int rand = random(n, tar_length - 1);
		swap(targets[n], targets[rand]);
	}

	return targets;
}

//int main() {
//	vector<int> target{ 1,2,3,4,5 };
//	vector<int> result;
//	result = fun0(target);
//
//	for (int n : result) {
//		cout << n << " ";
//	}
//
//	return 0;
//}
