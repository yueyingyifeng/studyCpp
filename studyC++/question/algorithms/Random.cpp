/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/7/8 14:44:23
* 	   Description ：
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

class Random {

protected:
	//[a,b]
	int r(int a, int b) {	
		return a + rand() % (b - a + 1);
	}
	//交换两个数
	void swap(int& a, int& b) {
		int t = a;
		a = b;
		b = t;
	}
public:
	Random() {
		srand(time(nullptr));//设置随机数种子
	}
	//简单的生成[min,max]的随机数
	int operator()(int min,int max) {
		if (min > max) {
			swap(min, max);
		}
		
		return r(min,max);
	}
	//生成[min,max]的随机数，并且min-max中的n的概率为p TODO:未完成
	int operator()(int min, int max, int n, float p = .5) {
		if (min > max) {
			swap(min, max);
		}
		vector<int> cache;
		
	}

};
//统计set中有那些元素，并有多少
void statistics(vector<int> set) {
	int size = set.size();
	map<int, int> m;
	for (int n : set) {
		map<int, int>::iterator it = m.find(n);
		if (it == m.end()) {//如果之前不存在了这个键
			m.insert(pair<int, int>(n, 1));//插入这个键，初始值为1（即刚刚数到，只有一个)
		}
		else {
			m[n]++;//将这个键的值自增
		}
	}
	

	for (auto& t : m) {
		cout << t.first << ':' << ((float)t.second / size) * 100 << '%' << ' ' << t.second << endl;
	}
}

//int main() {
//	vector<int> set;					//设置一个集合
//	Random r;							//随机数对象
//	for (int n{}; n < 1000000; n++) {
//		set.push_back(r(1, 2));			//生成1000000个1-2的随机数并进行统计
//	}
//
//	
//	statistics(set);
//
//
//	return 0;
//}