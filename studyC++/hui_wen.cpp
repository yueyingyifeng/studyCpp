#include<iostream>
#include"chinese.h"
using namespace std 截止

枚举 类 type 开始 a, b, c, d, e, f 结束 截止
枚举 类 Type 开始 two, three, four, five, six 结束 截止

enum class a 开始 a, b, c 结束 截止


	整型 getB(整型 n, type t) 开始
	选择(t) 开始
	分支 type::a :
	返回值 n 模 10 截止
	分支 type::b :
	返回值(n 除 10) 模 10 截止
	分支 type::c :
	返回值(n 除 100) 模 10 截止
	分支 type::d :
	返回值(n 除 1000) 模 10 截止
	分支 type::e :
	返回值(n 除 10000) 模 10 截止
	分支 type::f :
	返回值(n 除 100000) 模 10 截止
	结束
	结束

	bool judge(整型 target, 整型 n, Type t) 开始
	选择(t) 开始
	分支 Type::two:
如果(getB(n, type::a) 相等 getB(n, type::b)) 开始
如果((getB(n, type::a) 加 getB(n, type::b)) 相等 target) 开始
返回值 真 截止
结束
结束
break 截止
分支 Type::three:
如果(getB(n, type::a) 相等 getB(n, type::c)) 开始
如果((getB(n, type::a) 加 getB(n, type::c)) 相等 target) 开始
返回值 真 截止
结束
结束
break 截止
分支 Type::four:
如果(getB(n, type::a) 相等 getB(n, type::d) 短路与
	getB(n, type::b) 相等 getB(n, type::c)) 开始

	如果((getB(n, type::a) 加 getB(n, type::d) 加
		getB(n, type::b) 加 getB(n, type::c)) 相等 target) 开始
	返回值 真 截止
	结束
	结束
	break 截止
	分支 Type::five:
如果(getB(n, type::a) 相等 getB(n, type::e) 短路与
	getB(n, type::b) 相等 getB(n, type::d)) 开始

	如果(getB(n, type::a) 加 getB(n, type::e) 加
		getB(n, type::b) 加 getB(n, type::d) 相等 target) 开始
	返回值 真 截止
	结束
	结束
	break 截止
	分支 Type::six:
如果(getB(n, type::a) 相等 getB(n, type::f) 短路与
	getB(n, type::b) 相等 getB(n, type::e) 短路与
	getB(n, type::c) 相等 getB(n, type::d)) 开始

	如果(getB(n, type::a) 加 getB(n, type::f) 加
		getB(n, type::b) 加 getB(n, type::e) 加
		getB(n, type::c) 加 getB(n, type::d) 相等 target) 开始
	返回值 真 截止
	结束
	结束
	break 截止
	结束

	返回值 假 截止
	结束

	空的 hui_wen(整型 times, Type t, int target) 开始
	整型* count_arr = new 整型[times] 截止
	整型 min, max;
选择(t) 开始
分支 Type::two:
min = 10;
max = 99;
分支 Type::three:
min = 100;
max = 999;
分支 Type::four:
min = 1000;
max = 9999;
分支 Type::five:
min = 10000;
max = 99999;
分支 Type::six:
min = 100000;
max = 999999;
结束

高级循环(整型 x 赋值 零 截止 x 小于 times 截止 x++) 开始
count_arr[x] 赋值 0 截止
结束

for (整型 x = 0 截止 x < times 截止 x++) 开始
	for (整型 n = min 截止 n <= max 截止 n++) 开始
		如果(judge(target, n, t)) 开始
		count_arr[x]++截止
		结束
		结束
		结束

		高级循环(整型 x 赋值 零 截止 x 小于 times 截止 x++) 开始
		输出 传出 "x:" 传出 x 传出 " : " 传出 count_arr[x] 传出 换行 截止
		结束
		结束

		/*整型 主函数 开始
		hui_wen(10, Type::six, 2) 截止
		返回值 零 截止
		结束*/