/*
* 			Author : yueyingyifeng
* 		CreateDate : 2022/4/9 20:07:17
* 	   Description ：背单词的设计
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

using spair = pair<string, string>;
//输入信息
class input {
	string data;
public:
	input() {
		cin >> data;
	}
	string getData() {
		return data;
	}
	string operator()() {
		return data;
	}
};
//输出信息
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
//建立并录入词汇与释义的映射关系
class WordsLoader {
	unordered_map<string,string> map;
public:
	enum class type {
		EN, CN
	};
private:
	type mode;
	//判断此字符是否为汉字或单词
	//写参数二是因为除了汉字单词还有符号，不可能翻译符号咯
	bool isCNChar(string word,type m) {
		switch (m)
		{
		case WordsLoader::type::EN:
			if (!((int)word[0] >= 65 && (int)word[0] < 123)) {
				return true;
			}
			break;
		case WordsLoader::type::CN:
			if (!((int)word[0] < 0)) {
				return true;
			}
			break;
		}
		return false;
	}
	//载入单词,界面模式
	void loadGui() {
		string input_buffer_word{ "null" };
		string input_buffer_para{ "null" };




		while (input_buffer_word != "!") {

			switch (mode)
			{
			case WordsLoader::type::EN:
				//---------------------------------------------------EN

				msg()("请输入一个单词, 输入!结束");
				cin >> input_buffer_word;
				if (input_buffer_word[0] == '!') {
					break;
				}
				if ( isCNChar(input_buffer_word,type::EN) ) {
					msg()("我感觉你输入的不是英语，可能是符号或者中文，反正不是正常的字母");
					continue;
				}
				msg()("请输入此单词的释义");
				//---------------------------------------------------EN
				break;
				/*
				* 我忽然想到，中文对应英语的意思有很多，比如走，你可以说go，也可以说walk，就是多义性
				* 所以这是一个一对多的形式，似乎map似乎不能满足要求了。。。但我们还是先求简单，把基础的实现
				* 这也算是挖个坑
				*/
			case WordsLoader::type::CN:
				//---------------------------------------------------CN

				msg()("请输入一个词, 输入!结束");
				cin >> input_buffer_word;
				if (input_buffer_word[0] == '!') {
					break;
				}
				if (isCNChar(input_buffer_word, type::CN)) {
					msg()("我感觉你输入的不是汉字，可能是...，反正不是正常的汉字");
					continue;
				}
				msg()("请输入此汉字对应的单词");

				//---------------------------------------------------CN
				break;
			}
			if (input_buffer_word[0] == '!') {
				break;
			}
			cin >> input_buffer_para;

			msg()();
			map.insert(spair(input_buffer_word, input_buffer_para));
		}//while end
	}
public:
	//默认构造函数，模式为英语
	WordsLoader() {
		mode = type::EN;
	}
	
	WordsLoader(type t) {
		mode = t;
		loadGui();
	}
	//载入单词，参数模式.目标，释义
	void loadParm(string word,string para) {
		if (mode == type::CN) {
			if (!isCNChar(word, mode)) {
				map.insert(spair(word, para));
				msg()("success");

			}
			else {
				msg()("load failure，this's not a Chinese char");
				msg()(__LINE__);
			}
		}
		else {
			if (!isCNChar(word, mode)) {
				map.insert(spair(word, para));
				msg()("success en");
			}
			else {
				msg()("load failure，this's not a English char");
				msg()(__LINE__);
			}
		}
	}
	//获取已载入的词组
	unordered_map<string,string> getMap() {
		return map;
	}
	//获取词对应的释义
	string operator[](const string& s) {
		if (map[s] != "") {
			return map[s];
		}
		string t ="this word's para is not exist at:";
		t += to_string(__LINE__);
		return t;
	}

	//获取模式
	type getMode() {
		return mode;
	}
};
//"学习" 算法,用于判断正确与否
class Learning {
	//保存每一组词汇的记忆程度
	/*
	* 比如有两组词汇				a,  b, c
	* 对应的释义					啊，是，的
	* 然后record就记录答对次数		0  n+1  1
	* 如果record中某个元素高于指定数n，则判定此组完成记忆，（PS：之后便不在出现)
	*/
	vector<int> record;
	const int n{ 2 };
public:
	Learning() {
		record = vector<int>();
	}
	//共有几组
	Learning(int count) {
		record = vector<int>(count);
	}
	//所给出释义是否与之正确
	bool isRigth(input i,string para) {
		if (i() == para) {
			return true;
		}
		return false;
	}
	//在position位置中是否达到n次
	bool operator()(string para, int position) {
		if (isRigth(input(), para)) {
			if (record[position]++ == 2) {
				return true;
			}
			else {
				record[position]++;
			}
		}
		else {
			record[position] = 0;
		}
		return false;
	}
};


//主程序
class App {
public:
	App() {

	}
};

int main() {
	input i;
	msg()(i());
	return 0;
}