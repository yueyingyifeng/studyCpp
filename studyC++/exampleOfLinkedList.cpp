#include <iostream>
#include <windows.h>
#include <fstream>
#include "LinkedList.cpp"
using namespace std;
//个人信息
class Person {
	string name;
	int number;
public:
	Person() {
		name = "null";
		number = -1;
	}
	Person(string name,int number):name(name),number(number) {}

	string getName() {
		return name;
	}
	int getNum() {
		return number;
	}

	void setName(string n) {
		name = n;
	}
	void setNum(int n) {
		number = n;
	}
};
//判断是什么操作
enum class query {
	del, search, modify
};
//电话簿
class Tel_Dir{
	LinkedList<Person> list;
	//删除一位联系人的操作
	void delOnlyOnePreson(LinkedList<int> delList) {
		char confirm;
		cout << "**找到一位联系人，是否删除,输入d删除,任意键取消并返回" << endl << '>';
		cin >> confirm;
		if (confirm == 'd') {
			list.delNodeByIndex(delList.getHead());
			cout << "**成功删除" << endl;
			Sleep(1000);
		}
	}
	//删除多位联系人的操作
	void delMoreThenOnePerson(LinkedList<int> delList) {
		char target;
		char confirm;
		cout << "**找到多位联系人，请根据序号选择一位并删除" << endl << '>';
		cin >> target;
		for (int n{}; n < delList.getLength(); n++) {//遍历序号以进行最终匹配
			if (atoi(&target) == n) {
				//确认操作
				cout << "输入d确认删除,输入任意键退出" << endl << '>';
				cin >> confirm;
				if (confirm == 'd') {
					list.delNodeByIndex(delList[n]);
					cout << "**成功删除" << endl;
					Sleep(1000);
				}
			}
		}
	}
	//修改一位联系人的操作
	void modifyOnlyOnePerson(LinkedList<int> modList) {
		
		char confirm;
		cout << "**找到一位联系人,确认修改请按d" << endl << '>';
		cin >> confirm;
		if (confirm == 'd') {
			modifyNameAndNum(modList.getHead());//只有一个，故取头就行了
		}

	}
	//修改多位联系人的操作
	void modifyMoreThenOnePerson(LinkedList<int> modList) {
		char target;
		cout << "**找到多位联系人，请根据序号选择一位并修改" << endl << '>';
		cin >> target;
		for (int n{}; n < modList.getLength(); n++) {//遍历序号以进行最终匹配
			if (atoi(&target) == n) {
				modifyNameAndNum(n);//取选择上的
			}
		}
	}
	//修改内容
	void modifyNameAndNum(int target) {
		string newName{ "n" };
		int newNum{};
		cout << endl;
		cout << "*请输入新的姓名,输入n跳过" << endl << '>';
		cin >> newName;
		if (newName != "n") {
			list[target].setName(newName);
		}
		cout << "*请输入新的电话,输入0跳过" << endl << '>';
		cin >> newNum;
		if (newNum != 0) {
			list[target].setNum(newNum);
		}
		
		if (newName == "n" && newNum == 0) {
			cout << endl << "*修改失败,联系人信息没有变更,";
			system("pause");
		}
		else if (newName == "n") {
			cout << endl << "*没有修改姓名,联系人姓名没有变更,";
			system("pause");
		}
		else if (newNum == 0) {
			cout << endl << "*没有修改电话,联系人电话没有变更,";
			system("pause");
		}
		else {
			cout << endl << "*修改信息成功,";
			system("pause");
		}

	}
	//显示查找出的人
	void Opt(query q, LinkedList<int> List = {}) {
		if (List.getLength() == 0) {		//情况1，查无此人
				cout << "**查无此人,";
				system("pause");
		}
		else if (List.getLength() == 1) {						//情况2，只有一个
			switch (q)//根据选择的内容进行不同的操作
			{
			case query::del:				//删除一个操作
				delOnlyOnePreson(List);	
				break;
			case query::search:				//查找出一个操作
				cout << endl;
				system("pause");
				break;
			case query::modify:				//修改操作
				modifyOnlyOnePerson(List);
				break;
			default:
				break;
			}
		}
		else {													//情况3，有多个
			switch (q)
			{
			case query::del:
				delMoreThenOnePerson(List);
				break;
			case query::search:
				cout << endl;
				system("pause");
				break;
			case query::modify:
				modifyMoreThenOnePerson(List);
				break;
			default:
				break;
			}
		}
	}
public:
	Tel_Dir() {
		list = LinkedList<Person>();
	}
	Tel_Dir(const Person p[],const int length) {
		for (int n{}; n < length;n++) {
			list.addLastNode(p[n]);
		}
	}
	//添加联系人
	void addPerson(string name, int number) {
		list.addLastNode(Person(name, number));
	}
	//显示所有的联系人
	int showAllPerson() {
		int length = list.getLength();
		for (int n{}; n < length; n++) {
			cout << "**姓名:" << list.get(n).getName() << endl;
			cout << "**电话:" << list.get(n).getNum() << endl;
			if (n != list.getLength()-1) {
				cout << "*****" << endl;
			}
		}
		return length;
	}
	//删除名为name的联系人并归类处理
	void delPerson(string name) {
		int count{};
		LinkedList<int> delList;
		for (int n{}; n < list.getLength(); n++) {
			if (name == list[n].getName()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**姓名:" << list[n].getName() << endl;
				cout << "**电话:" << list[n].getNum() << endl;
				delList.addLastNode(n);//将目标位置记录下来
				count++;
			}
			
		}
		cout << endl;
		cout << "**共找到" << count << "个联系人,名字为:" << name << endl;
		Opt(query::del, delList);
		/*
			思路，遍历找出他们在链表的位置，然后用另外一个链表记录其位置，删除的时候根据链表次序就可以选择要删除的目标
			然后传给内部处理方法（showDelC...)，最终进行确认删除操作
			为什么有内部处理方法:
			由于需要根据名字或电话进行操作,只是遍历对象不一致,而删除确认一致，故独立出去，避免重复代码
		*/
	}
	//删除电话为num的联系人并归类处理
	void delPerson(int number) {
		int count{};
		LinkedList<int> delList;
		for (int n{}; n < list.getLength(); n++) {
			if (number == list[n].getNum()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**姓名:" << list[n].getName() << endl;
				cout << "**电话:" << list[n].getNum() << endl;
				delList.addLastNode(n);//将目标位置记录下来
				count++;
			}

		}
		cout << endl;
		cout << "**电话为" << number << "的共找到" << count << "个联系人" << endl;
		Opt(query::del, delList);
	}
	//显示名为name的联系人
	void showPerson(string name) {
		int count{};
		for (int n{}; n < list.getLength(); n++) {
			if (name == list[n].getName()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**姓名:" << list[n].getName() << endl;
				cout << "**电话:" << list[n].getNum() << endl;
				count++;
			}

		}
		cout << endl;
		cout << "**共找到" << count << "个联系人,名字为:" << name << endl;
		Opt(query::search);
	}
	//显示电话为num的联系人
	void showPerson(int num) {
		int count{};
		for (int n{}; n < list.getLength(); n++) {
			if (num == list[n].getNum()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**姓名:" << list[n].getName() << endl;
				cout << "**电话:" << list[n].getNum() << endl;
				count++;
			}

		}
		cout << endl;
		cout << "**共找到" << count << "个联系人,名字为:" << num << endl;
		Opt(query::search);
	}
	//修改名为name的联系人
	void modify(string name) {
		int count{};
		LinkedList<int> modList;
		for (int n{}; n < list.getLength(); n++) {
			if (name == list[n].getName()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**姓名:" << list[n].getName() << endl;
				cout << "**电话:" << list[n].getNum() << endl;
				modList.addLastNode(n);//将目标位置记录下来
				count++;
			}

		}
		cout << endl;
		cout << "**共找到" << count << "个联系人,名字为:" << name << endl;
		Opt(query::modify,modList);
	}
	//修改电话为num的联系人
	void modify(int num) {
		int count{};
		LinkedList<int> modList;
		for (int n{}; n < list.getLength(); n++) {
			if (num == list[n].getNum()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**姓名:" << list[n].getName() << endl;
				cout << "**电话:" << list[n].getNum() << endl;
				modList.addLastNode(n);//将目标位置记录下来
				count++;
			}

		}
		cout << endl;
		cout << "**共找到" << count << "个联系人,名字为:" << num << endl;
		Opt(query::modify);
	}
	//清空电话簿
	void clearList() {
		char confirm;
		cout << "**  确定清除此电话簿吗？信息将会消失并不可逆转!输入d确认" << endl << '>';
		cin >> confirm;
		if (confirm == 'd') {
			cout << "* 开始清除数据" << endl;
			int length = list.getLength();
			for (int n{}; n < length; n++) {
				list.delLastNode();
			}
			cout << "* 清除完毕,";
			system("pause");
		}
	}
};
//菜单,返回所选项
char menu() {
	system("cls");
	cout << "**************************" << endl;
	cout << "*****  1-添加联系人  *****" << endl;
	cout << "*****  2-显示联系人  *****" << endl;
	cout << "*****  3-删除联系人  *****" << endl;
	cout << "*****  4-查找联系人  *****" << endl;
	cout << "*****  5-修改联系人  *****" << endl;
	cout << "*****  6-清空联系人  *****" << endl;
	cout << "*****  0-退出通讯录  *****" << endl;
	cout << "**************************" << endl;
	char chose;
	while (1) {
		cout << ">";
		cin >> chose;
		switch (chose)
		{
		case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '0':
			return chose;
			break;
		default:
			cout << "你输入的有误，请重新输入";
			break;
		}
	}
}
//1填加联系人
void AddOpt(Tel_Dir* td) {
	system("cls");

	string name;
	int number;
	cout << "**********添加联系人********" << endl;
	cout << "**********请输入姓名********" << endl;
	cout << "**************************" << endl << ">";
	cin >> name;
	cout << "**********请输入电话********" << endl;
	cout << ">";
	cin >> number;

	td->addPerson(name, number);
	cout << "**************************" << endl;
	cout << "**********添加完毕*********" << endl;
	cout << "**************************" << endl;
	
	Sleep(1000);
}
//2显示联系人
void ShowAllPerson(Tel_Dir* td) {
	system("cls");
	cout << "***********电话簿**********" << endl;
	int count = td->showAllPerson();
	cout << endl << "*** 共有" << count << "位联系人" << endl;
	cout << "**************************" << endl;
	system("pause");
}
//3删除联系人
void DelPerson(Tel_Dir* td) {
	system("cls");
	char chose;
	string name{ "null" };
	int num{ -1 };
	cout << "*********删除联系人********" << endl;
	cout << "请选择方式，1为以名字删除**" << endl;
	cout << "*******2为号码以删除*******" << endl;
	cout << "**************************" << endl << ">";
	
	while (1) {
		cin >> chose;
		switch (chose) {
		case '1':
			cout << "**请输入名字:" << endl << '>';
			cin >> name;
			td->delPerson(name);
			return;

		case '2':
			cout << "**请输入电话:" << endl << '>';
			cin >> num;
			td->delPerson(num);
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	cout << "**************************" << endl;
}
//4查找联系人
void SearchPerson(Tel_Dir* td) {
	system("cls");
	char chose;
	string name{ "null" };
	int num{ -1 };
	cout << "*********查找联系人********" << endl;
	cout << "请选择方式，1为以名字查找**" << endl;
	cout << "*******2为号码以查找*******" << endl;
	cout << "**************************" << endl << ">";

	while (1) {
		cin >> chose;
		switch (chose) {
		case '1':
			cout << "**请输入名字:" << endl << '>';
			cin >> name;
			td->showPerson(name);
			return;

		case '2':
			cout << "**请输入电话:" << endl << '>';
			cin >> num;
			td->showPerson(num);
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	cout << "**************************" << endl;
	
}
//5修改联系人
void ModifyPerson(Tel_Dir* td) {
	system("cls");
	char chose;
	string name{ "null" };
	int num{ -1 };
	cout << "*********修改联系人********" << endl;
	cout << "请选择方式，1为以名字查找**" << endl;
	cout << "*******2为号码以查找*******" << endl;
	cout << "**************************" << endl << ">";

	while (1) {
		cin >> chose;
		switch (chose) {
		case '1':
			cout << "**请输入名字:" << endl << '>';
			cin >> name;
			td->modify(name);
			return;

		case '2':
			cout << "**请输入电话:" << endl << '>';
			cin >> num;
			td->modify(num);
			return;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	}
	cout << "**************************" << endl;
}
//主程序
void Program(Tel_Dir*td, char code) {
	switch (code)
	{
	case '1':
		AddOpt(td);
		break;
	case '2':
		ShowAllPerson(td);
		break;
	case '3':
		DelPerson(td);
		break;
	case '4':
		SearchPerson(td);
		break;
	case '5':
		ModifyPerson(td);
		break;
	case '6':
		td->clearList();
		break;
	case '7':
		//TODO
		break;
	}
}
//入口
//int main() {
//	Tel_Dir* td = new Tel_Dir;//电话簿
//	while (1) {
//		char code = menu();
//		if (code != '0') {
//			Program(td,code);
//		}
//		else {
//			char quit;
//			cout << "你确定要退出吗？再次输入0退出" << endl << ">";
//			cin >> quit;
//			if (quit == '0') {
//				delete td;
//				return 0;
//			}
//		}
//	}
//	delete td;
//	return -1;
//}
/*
int main() {
	char a = '2';
	int b = atoi(&a);
	cout << b+10 << endl;
}
*/