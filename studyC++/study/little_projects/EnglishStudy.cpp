/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/4/9 20:07:17
* 	   Description ：背单词的设计
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>s
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

using spair = pair<string, string>;

class msg {
public:
	void operator()() {
		cout << endl;
	}
	void operator()(string s,bool br = true) {
		if (br) {
			cout << s << endl;
		}
		else {
			cout << s;
		}
	}
	void operator()(const char* s, bool br = true) {
		if (br) {
			cout << s << endl;
		}
		else {
			cout << s;
		}
	}
	void operator()(char s, bool br = true) {
		if (br) {
			cout << s << endl;
		}
		else {
			cout << s;
		}
	}
	void operator()(int s, bool br = true) {
		if (br) {
			cout << s << endl;
		}
		else {
			cout << s;
		}
	}


};

class WordsLoader {
	unordered_map<string,string> map;
public:
	enum class type {
		EN, CN
	};
private:
	type mode;
public:
	
	WordsLoader(type t) {
		string input_buffer_word{"null"};
		string input_buffer_para{ "null" };
		mode = t;


		

		while (input_buffer_word != "!") {
			switch (t)
			{
			case WordsLoader::type::EN:
				//---------------------------------------------------EN

				msg()("请输入一个单词,输入!结束");
				if (!( (int)input_buffer_word[0] > 65 && (int)input_buffer_word[0] < 123 ) ) {
					cin >> input_buffer_word;
				}
				else {
					msg()("我感觉你输入的不是英语，可能是符号或者中文，反正不是正常的字母");

				}
				msg()("请输入此单词的释义");
				cin >> input_buffer_para;
				//---------------------------------------------------EN
				break;
				/*
				* 我忽然想到，中文对应英语的意思有很多，比如走，你可以说go，也可以说walk，就是多义性
				* 所以这是一个一对多的形式，似乎map似乎不能满足要求了。。。但我们还是先求简单，把基础的实现
				* 这也算是挖个坑
				*/
			case WordsLoader::type::CN:
				//---------------------------------------------------EN
				msg()("请输入一个词,输入!结束");
				if (((int)input_buffer_word[0] > 65 && (int)input_buffer_word[0] < 123)) {
					cin >> input_buffer_word;
				}
				else {
					msg()("我感觉你输入的不是汉字，可能是...，反正不是正常的汉字");

				}
				msg()("请输入此汉字对应的单词");
				cin >> input_buffer_para;
				//---------------------------------------------------EN
				break;
			}
			msg()();
			map.insert(spair(input_buffer_word, input_buffer_para));
		}//while end
		
	}

	type getMode() {
		return mode;
	}
};


//主程序
class App {

};

int main() {
	WordsLoader wl(WordsLoader::type::EN);

	return 0;
}