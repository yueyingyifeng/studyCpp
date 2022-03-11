#include <iostream>
#include<cstring>
#include <iomanip>
using namespace std;

class User {
	string name;
	double cash;
public:
	User(string name, int cash)
		: name(name), cash(cash)
	{}
	User(int cash)
		: cash(cash)
	{
		name = "无名氏";
	}
	User() {}
	//减少 多少 钱
	void cost(double number)
	{
		cash -= number;
	}
	//增加 多少 钱
	void gotMoney(double number) {
		cash += number;
	}
	//获取还剩多少钱
	double getCash() { return cash; }
	string getName() { return name; }
};

class Userlist {
	User* data;
	int length;
	void arr_copy(User* From, User* to, int length) {
		for (int n{}; n < length; n++) {
			to[n] = From[n];
		}
	}
public:
	Userlist() {
		data = nullptr;
		length = 0;
	}
	Userlist(User* data, int length)
		: data(data), length(length)
	{}

	void add(User newOne) {
		User* temp = new User[length + 1];

		arr_copy(data, temp, length);
		temp[length++] = newOne;
		this->data = new User[length];
		arr_copy(temp, data, length);
	}

	User& getUser(int index) {
		return data[index];
	}

	int getLength() {
		return this->length;
	}
	void show() {
		for (int n{}; n < length; n++) {
			cout << "No." << n << " : " << data[n].getName() << endl;
		}
	}
};

class Bank {
	Userlist* list;
	User* u;
public:
	Bank(Userlist* list)
		: list(list)
	{}
	Bank(User* u)
		: u(u)
	{}

	void round(int costMoney,int makeMoney) {
		for (int n{}; n < list->getLength(); n++) {
			list->getUser(n).cost(costMoney);
			list->getUser(n).gotMoney(makeMoney);
		}
	}

	void addOneDay(double costMoney) {
		u->cost(costMoney);
		u->gotMoney(u->getCash() * .01f);
	}

	Userlist& getList() {
		return *list;
	}
};
/*
int main() {
	User* u = new User("1", 100000);
	//Userlist* list = new Userlist(u,3);
	Bank bank(u);

	for (int n{1}; n <= 53 * 365; n++) {
		bank.addOneDay(2000/7);
		//cout << "第" << fixed << setprecision(0) << n << "天" << u->getCash() << endl;
		if (n % (365) == 0) {
			cout << "第" <<  fixed << setprecision(0) << (n/(365)) << "年" << u->getCash() << endl;
		}
	}

	return 0;
}
*/