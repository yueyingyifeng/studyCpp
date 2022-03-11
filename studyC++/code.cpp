#include<iostream>
//65 + 26 = 90 大写
//97 + 26 = 122 小写

using namespace std;
enum class dir { left, right };

class secretKey {
	dir d;
	int num;
public:
	secretKey(dir d, int num) :d(d), num(num) {}
	dir getDir() { return d; }
	int getNum() { return num; }
};

class solution {
	//const char letters[26]
	//{ 'a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', };

	bool isCap(char c) {//是否大写
		if (c >= 65 && c <= 91) {
			return true;
		}
		else {
			return false;
		}
	}
public:

	string encrypt(string str, secretKey sk) {
		char letter;

		string result;
		for (int n{}; n < str.length(); n++) {
			letter = str.at(n);
			switch (sk.getDir())
			{
			case dir::left:
				if (isCap(letter)) {//如果是大写
					if (letter - sk.getNum() <= 65) {//如果这个字母不幸低于A
						letter = 90 - sk.getNum();
						result.push_back(letter);
					}
					else {
						result.push_back(letter - sk.getNum());
					}
				}
				else {
					if (letter - sk.getNum() <= 97) {//如果这个字母不幸低于a
						letter = 122 - sk.getNum();
						result.push_back(letter);
					}
					else {
						result.push_back(letter - sk.getNum());
					}
				}
				break;
			case dir::right:
				if (isCap(letter)) {//如果是大写
					if (letter + sk.getNum() >= 90) {//如果这个字母不幸高于Z
						letter = 65 + sk.getNum();
						result.push_back(letter);
					}
					else {
						result.push_back(letter + sk.getNum());
					}
				}
				else {
					if (letter + sk.getNum() >= 122) {//如果这个字母不幸高于z
						letter = 97 + sk.getNum();
						result.push_back(letter);
					}
					else {
						result.push_back(letter + sk.getNum());
					}
				}
				break;
			default:
				break;
			}
		}
		return result;
	}
};

/*
int main() {
	solution* s = new solution();
	string str;
	while (1) {
		cin >> str;
		cout << s->encrypt(str, secretKey(dir::left, 3)) << endl;
		cout << s->encrypt(str, secretKey(dir::right, 3)) << endl;
	}

}
*/