/*
* 字符串占位符替换
* 比如有个字符串是：this is %1
* 这个%1是一个占位符，可以被另外一个数据替换
* 如果可以，多个占位符替换呢？
*/
#include <iostream>
//#include <vector>
using namespace std;

class String {
	char* data;
public:
	explicit String() { data = nullptr; };
	explicit String(char* data)
		:data(data) {}
	explicit String(const char* data) {
		this->data = (char*)data;
	}

	const char* to_str() {
		return data;
	}
	//获取长度,从本数据
	int length() {
		int n{};
		while (data[n] != '\0') {
				n++;
		}
		return n;
	}
	//获取长度,从字符串中
	int length(const char* arg) {
		int n{};
		while (arg[n] != '\0') {
			n++;
		}
		return n;
	}
	//判断字符是否是数字
	bool isNumber(char n) {
		if (n >= 48 && n < 58) {
			return true;
		}
		return false;
	}
	//替换占位符的数据
	String* args(const char* arg) {
		int length = this->length();
		int arg_length = this->length(arg);
		int total = length + arg_length;

		char* result = new char[total];
		int replace_p;//占位符起始位置

		bool havePlaceholder = false;

		for (int n{}; data[n] != '\0'; n++) {
			if (data[n] == '%' && isNumber(data[n + 1]) ) {				
				replace_p = n;//记录要分割的位置
				havePlaceholder = true;
				break;
			}
			havePlaceholder = false;
		}
		//是否存在占位符
		if (!havePlaceholder) {
			return this;
		}

		String front(this->cut(0, replace_p-1));		//占位符之前的字符串
		String replace(arg);						
		String rear(this->cut(replace_p + 2, length));	//占位符之后的字符串

		//最终合并操作,例如 1 2 3 -> (1+2)+3
		char* t = front + replace;
		result = merge(t,rear());
		//覆盖数据
		data = new char[total];
		data = result;


		return this;
	}
	//合并两个字符串
	char* merge(const char* a, const char* b) {
		int lengthOfa = length(a);
		int lengthOfb = length(b);
		int total = lengthOfa + lengthOfb;
		char* result = new char[total] {};

		for (int n{}; n < total; n++) {
			if (n < lengthOfa) {
				result[n] = a[n];//将a部分放入
			}
			else {
				result[n] = b[n - lengthOfa];//将b部分放入
			}
		}
		result[total] = '\0';
		return result;
	}

	//截取字符串,并不会修改原数据,原数据，开始，结束
	char* cut(const char* temp,int begin,int end) {
		int result_length = end - begin + 1;
		char* result = new char[result_length] {};

		for (int n{}; n < result_length; n++) {
			result[n] = temp[begin + n];
		}
		result[result_length] = '\0';
		/*
		* 比如从原数组{1，2，3}截取1-2的内容，也就是2，3
		* result数组是这样：2，3，乱码，乱码,...乱码,\0
		*/
		return result;
	}
	//从本字符串截取一个新字符串出来,并不会修改原数据:开始，结束
	char* cut(int begin, int end) {
		int result_length = end - begin + 1;
		char* result = new char[result_length] {};

		for (int n{}; n < result_length; n++) {
			result[n] = this->data[begin + n];
		}
		result[result_length] = '\0';
		/*
		* 比如从原数组{1，2，3}截取1-2的内容，也就是2，3
		* result数组是这样：2，3，乱码，乱码,...乱码,\0
		*/
		return result;
	}
	//返回此类的字符串
	char* operator()() {
		return this->data;
	}
	//获取第几个字符
	char& operator[](int index) {
		return data[index];
	}
	//拼接字符串
	char* operator+(const char* b) {
		return merge(this->data, b);
	}
	char* operator+(String b) {
		return merge(this->data, b());
	}
};

int main() {
	String a{ "this is %1 and %2" };
	String b{ "[%1,%2]" };

	cout << a.args("a")->to_str() << endl;
	cout << a.args("b")->to_str() << endl;

	cout << b.args("12")->args("34")->to_str();
	
}