/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/6/20 23:10:47
* 	   Description ：
*/
#include <iostream>
#include <vector>

#include <ctime>
using namespace std;
using vec = vector<int>;
//二分查找
void BS(vec arr, int t) {
	int l = 0;
	int r = arr.size() - 1;

	while (l < r) {
		//核心部分:
		//取中间的下标,就是最开始和最末端的中间（比如最开始是0，最末端是10，那中间就是(2+10) / 2 )
		int mid = l + (r - l) / 2;
		if (arr[mid] == t) {
			cout << "BS found it,index: " << mid << endl;
			return;
		}
		if (arr[mid] > t) {//如果mid在目标值的右边，则将此mid设为最末端，然后重新计算mid
			r = mid;
		}
		if(arr[mid] < t) {
			l = mid;
		}
	}
	cout << "not found" << endl;
}
//顺序查找
void nBS(vec arr, int t) {
	//如果获取size在for循环里 也就是for(int n{};n < arr.size();n++)时间还要多耗20个clock
	int size = arr.size();
	for (int n{}; n < size; n++) {
		if (arr[n] == t) {
			cout << "nBS found it,index: " << n << endl;
			return;
		}
	}
	cout << "not found" << endl;
}
//顺序生成0 - max的数组
vec generate(int max) {
	vec result;
	for (int n{}; n < max; n++) {
		result.push_back(n);
	}
	return result;
}
//测试函数，计算时间
int test(vec arr, int t, void(*callback)(vec, int)) {
	clock_t et, st;
	st = clock();
	callback(arr, t);
	et = clock();

	int result = et - st;
	cout << et - st << endl;
	return result;
}
//计算数组平均值
int average(vec v) {
	int size = v.size();
	int total = 0;
	for (int n : v) {
		total += n;
	}
	return total / size;
}

int main() {
	vec r1, r2;
	//测试5遍
	for (int n{}; n < 5; n++) {
		vec arr = generate(10000000);
		int t = 5255525;

		r1.push_back(test(arr, t, BS));
		r2.push_back(test(arr, t, nBS));
		cout << endl << endl << "===========" << endl;
	}
	cout << "\n\n\n\n";
	cout << "the BS's average of time: " << average(r1) << endl;
	cout << "the nBS's average of time: " << average(r2) << endl;

	return 0;
}