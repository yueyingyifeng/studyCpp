#include <iostream>
#include <windows.h>
#include <fstream>
#include "LinkedList.cpp"
using namespace std;
//������Ϣ
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
//�ж���ʲô����
enum class query {
	del, search, modify
};
//�绰��
class Tel_Dir{
	LinkedList<Person> list;
	//ɾ��һλ��ϵ�˵Ĳ���
	void delOnlyOnePreson(LinkedList<int> delList) {
		char confirm;
		cout << "**�ҵ�һλ��ϵ�ˣ��Ƿ�ɾ��,����dɾ��,�����ȡ��������" << endl << '>';
		cin >> confirm;
		if (confirm == 'd') {
			list.delNodeByIndex(delList.getHead());
			cout << "**�ɹ�ɾ��" << endl;
			Sleep(1000);
		}
	}
	//ɾ����λ��ϵ�˵Ĳ���
	void delMoreThenOnePerson(LinkedList<int> delList) {
		char target;
		char confirm;
		cout << "**�ҵ���λ��ϵ�ˣ���������ѡ��һλ��ɾ��" << endl << '>';
		cin >> target;
		for (int n{}; n < delList.getLength(); n++) {//��������Խ�������ƥ��
			if (atoi(&target) == n) {
				//ȷ�ϲ���
				cout << "����dȷ��ɾ��,����������˳�" << endl << '>';
				cin >> confirm;
				if (confirm == 'd') {
					list.delNodeByIndex(delList[n]);
					cout << "**�ɹ�ɾ��" << endl;
					Sleep(1000);
				}
			}
		}
	}
	//�޸�һλ��ϵ�˵Ĳ���
	void modifyOnlyOnePerson(LinkedList<int> modList) {
		
		char confirm;
		cout << "**�ҵ�һλ��ϵ��,ȷ���޸��밴d" << endl << '>';
		cin >> confirm;
		if (confirm == 'd') {
			modifyNameAndNum(modList.getHead());//ֻ��һ������ȡͷ������
		}

	}
	//�޸Ķ�λ��ϵ�˵Ĳ���
	void modifyMoreThenOnePerson(LinkedList<int> modList) {
		char target;
		cout << "**�ҵ���λ��ϵ�ˣ���������ѡ��һλ���޸�" << endl << '>';
		cin >> target;
		for (int n{}; n < modList.getLength(); n++) {//��������Խ�������ƥ��
			if (atoi(&target) == n) {
				modifyNameAndNum(n);//ȡѡ���ϵ�
			}
		}
	}
	//�޸�����
	void modifyNameAndNum(int target) {
		string newName{ "n" };
		int newNum{};
		cout << endl;
		cout << "*�������µ�����,����n����" << endl << '>';
		cin >> newName;
		if (newName != "n") {
			list[target].setName(newName);
		}
		cout << "*�������µĵ绰,����0����" << endl << '>';
		cin >> newNum;
		if (newNum != 0) {
			list[target].setNum(newNum);
		}
		
		if (newName == "n" && newNum == 0) {
			cout << endl << "*�޸�ʧ��,��ϵ����Ϣû�б��,";
			system("pause");
		}
		else if (newName == "n") {
			cout << endl << "*û���޸�����,��ϵ������û�б��,";
			system("pause");
		}
		else if (newNum == 0) {
			cout << endl << "*û���޸ĵ绰,��ϵ�˵绰û�б��,";
			system("pause");
		}
		else {
			cout << endl << "*�޸���Ϣ�ɹ�,";
			system("pause");
		}

	}
	//��ʾ���ҳ�����
	void Opt(query q, LinkedList<int> List = {}) {
		if (List.getLength() == 0) {		//���1�����޴���
				cout << "**���޴���,";
				system("pause");
		}
		else if (List.getLength() == 1) {						//���2��ֻ��һ��
			switch (q)//����ѡ������ݽ��в�ͬ�Ĳ���
			{
			case query::del:				//ɾ��һ������
				delOnlyOnePreson(List);	
				break;
			case query::search:				//���ҳ�һ������
				cout << endl;
				system("pause");
				break;
			case query::modify:				//�޸Ĳ���
				modifyOnlyOnePerson(List);
				break;
			default:
				break;
			}
		}
		else {													//���3���ж��
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
	//�����ϵ��
	void addPerson(string name, int number) {
		list.addLastNode(Person(name, number));
	}
	//��ʾ���е���ϵ��
	int showAllPerson() {
		int length = list.getLength();
		for (int n{}; n < length; n++) {
			cout << "**����:" << list.get(n).getName() << endl;
			cout << "**�绰:" << list.get(n).getNum() << endl;
			if (n != list.getLength()-1) {
				cout << "*****" << endl;
			}
		}
		return length;
	}
	//ɾ����Ϊname����ϵ�˲����ദ��
	void delPerson(string name) {
		int count{};
		LinkedList<int> delList;
		for (int n{}; n < list.getLength(); n++) {
			if (name == list[n].getName()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**����:" << list[n].getName() << endl;
				cout << "**�绰:" << list[n].getNum() << endl;
				delList.addLastNode(n);//��Ŀ��λ�ü�¼����
				count++;
			}
			
		}
		cout << endl;
		cout << "**���ҵ�" << count << "����ϵ��,����Ϊ:" << name << endl;
		Opt(query::del, delList);
		/*
			˼·�������ҳ������������λ�ã�Ȼ��������һ�������¼��λ�ã�ɾ����ʱ������������Ϳ���ѡ��Ҫɾ����Ŀ��
			Ȼ�󴫸��ڲ���������showDelC...)�����ս���ȷ��ɾ������
			Ϊʲô���ڲ�������:
			������Ҫ�������ֻ�绰���в���,ֻ�Ǳ�������һ��,��ɾ��ȷ��һ�£��ʶ�����ȥ�������ظ�����
		*/
	}
	//ɾ���绰Ϊnum����ϵ�˲����ദ��
	void delPerson(int number) {
		int count{};
		LinkedList<int> delList;
		for (int n{}; n < list.getLength(); n++) {
			if (number == list[n].getNum()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**����:" << list[n].getName() << endl;
				cout << "**�绰:" << list[n].getNum() << endl;
				delList.addLastNode(n);//��Ŀ��λ�ü�¼����
				count++;
			}

		}
		cout << endl;
		cout << "**�绰Ϊ" << number << "�Ĺ��ҵ�" << count << "����ϵ��" << endl;
		Opt(query::del, delList);
	}
	//��ʾ��Ϊname����ϵ��
	void showPerson(string name) {
		int count{};
		for (int n{}; n < list.getLength(); n++) {
			if (name == list[n].getName()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**����:" << list[n].getName() << endl;
				cout << "**�绰:" << list[n].getNum() << endl;
				count++;
			}

		}
		cout << endl;
		cout << "**���ҵ�" << count << "����ϵ��,����Ϊ:" << name << endl;
		Opt(query::search);
	}
	//��ʾ�绰Ϊnum����ϵ��
	void showPerson(int num) {
		int count{};
		for (int n{}; n < list.getLength(); n++) {
			if (num == list[n].getNum()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**����:" << list[n].getName() << endl;
				cout << "**�绰:" << list[n].getNum() << endl;
				count++;
			}

		}
		cout << endl;
		cout << "**���ҵ�" << count << "����ϵ��,����Ϊ:" << num << endl;
		Opt(query::search);
	}
	//�޸���Ϊname����ϵ��
	void modify(string name) {
		int count{};
		LinkedList<int> modList;
		for (int n{}; n < list.getLength(); n++) {
			if (name == list[n].getName()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**����:" << list[n].getName() << endl;
				cout << "**�绰:" << list[n].getNum() << endl;
				modList.addLastNode(n);//��Ŀ��λ�ü�¼����
				count++;
			}

		}
		cout << endl;
		cout << "**���ҵ�" << count << "����ϵ��,����Ϊ:" << name << endl;
		Opt(query::modify,modList);
	}
	//�޸ĵ绰Ϊnum����ϵ��
	void modify(int num) {
		int count{};
		LinkedList<int> modList;
		for (int n{}; n < list.getLength(); n++) {
			if (num == list[n].getNum()) {
				cout << "***** " << count << ". ******" << endl;
				cout << "**����:" << list[n].getName() << endl;
				cout << "**�绰:" << list[n].getNum() << endl;
				modList.addLastNode(n);//��Ŀ��λ�ü�¼����
				count++;
			}

		}
		cout << endl;
		cout << "**���ҵ�" << count << "����ϵ��,����Ϊ:" << num << endl;
		Opt(query::modify);
	}
	//��յ绰��
	void clearList() {
		char confirm;
		cout << "**  ȷ������˵绰������Ϣ������ʧ��������ת!����dȷ��" << endl << '>';
		cin >> confirm;
		if (confirm == 'd') {
			cout << "* ��ʼ�������" << endl;
			int length = list.getLength();
			for (int n{}; n < length; n++) {
				list.delLastNode();
			}
			cout << "* ������,";
			system("pause");
		}
	}
};
//�˵�,������ѡ��
char menu() {
	system("cls");
	cout << "**************************" << endl;
	cout << "*****  1-�����ϵ��  *****" << endl;
	cout << "*****  2-��ʾ��ϵ��  *****" << endl;
	cout << "*****  3-ɾ����ϵ��  *****" << endl;
	cout << "*****  4-������ϵ��  *****" << endl;
	cout << "*****  5-�޸���ϵ��  *****" << endl;
	cout << "*****  6-�����ϵ��  *****" << endl;
	cout << "*****  0-�˳�ͨѶ¼  *****" << endl;
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
			cout << "���������������������";
			break;
		}
	}
}
//1�����ϵ��
void AddOpt(Tel_Dir* td) {
	system("cls");

	string name;
	int number;
	cout << "**********�����ϵ��********" << endl;
	cout << "**********����������********" << endl;
	cout << "**************************" << endl << ">";
	cin >> name;
	cout << "**********������绰********" << endl;
	cout << ">";
	cin >> number;

	td->addPerson(name, number);
	cout << "**************************" << endl;
	cout << "**********������*********" << endl;
	cout << "**************************" << endl;
	
	Sleep(1000);
}
//2��ʾ��ϵ��
void ShowAllPerson(Tel_Dir* td) {
	system("cls");
	cout << "***********�绰��**********" << endl;
	int count = td->showAllPerson();
	cout << endl << "*** ����" << count << "λ��ϵ��" << endl;
	cout << "**************************" << endl;
	system("pause");
}
//3ɾ����ϵ��
void DelPerson(Tel_Dir* td) {
	system("cls");
	char chose;
	string name{ "null" };
	int num{ -1 };
	cout << "*********ɾ����ϵ��********" << endl;
	cout << "��ѡ��ʽ��1Ϊ������ɾ��**" << endl;
	cout << "*******2Ϊ������ɾ��*******" << endl;
	cout << "**************************" << endl << ">";
	
	while (1) {
		cin >> chose;
		switch (chose) {
		case '1':
			cout << "**����������:" << endl << '>';
			cin >> name;
			td->delPerson(name);
			return;

		case '2':
			cout << "**������绰:" << endl << '>';
			cin >> num;
			td->delPerson(num);
			return;
		default:
			cout << "������������������" << endl;
			break;
		}
	}
	cout << "**************************" << endl;
}
//4������ϵ��
void SearchPerson(Tel_Dir* td) {
	system("cls");
	char chose;
	string name{ "null" };
	int num{ -1 };
	cout << "*********������ϵ��********" << endl;
	cout << "��ѡ��ʽ��1Ϊ�����ֲ���**" << endl;
	cout << "*******2Ϊ�����Բ���*******" << endl;
	cout << "**************************" << endl << ">";

	while (1) {
		cin >> chose;
		switch (chose) {
		case '1':
			cout << "**����������:" << endl << '>';
			cin >> name;
			td->showPerson(name);
			return;

		case '2':
			cout << "**������绰:" << endl << '>';
			cin >> num;
			td->showPerson(num);
			return;
		default:
			cout << "������������������" << endl;
			break;
		}
	}
	cout << "**************************" << endl;
	
}
//5�޸���ϵ��
void ModifyPerson(Tel_Dir* td) {
	system("cls");
	char chose;
	string name{ "null" };
	int num{ -1 };
	cout << "*********�޸���ϵ��********" << endl;
	cout << "��ѡ��ʽ��1Ϊ�����ֲ���**" << endl;
	cout << "*******2Ϊ�����Բ���*******" << endl;
	cout << "**************************" << endl << ">";

	while (1) {
		cin >> chose;
		switch (chose) {
		case '1':
			cout << "**����������:" << endl << '>';
			cin >> name;
			td->modify(name);
			return;

		case '2':
			cout << "**������绰:" << endl << '>';
			cin >> num;
			td->modify(num);
			return;
		default:
			cout << "������������������" << endl;
			break;
		}
	}
	cout << "**************************" << endl;
}
//������
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
//���
//int main() {
//	Tel_Dir* td = new Tel_Dir;//�绰��
//	while (1) {
//		char code = menu();
//		if (code != '0') {
//			Program(td,code);
//		}
//		else {
//			char quit;
//			cout << "��ȷ��Ҫ�˳����ٴ�����0�˳�" << endl << ">";
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