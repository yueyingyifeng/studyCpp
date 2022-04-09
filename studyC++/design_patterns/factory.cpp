//2022��4��9��
//����ģʽ
#include <iostream>
using namespace std;

//ʳ��ӿڣ����������ķ���
class Food {
public:
	virtual void make() = 0;
};
//������,����ʳ�����Ҫʵ������������
class Cake
	:  public Food {
public:
	virtual void make() override {
		cout << "���������ĵ���" << endl;
	}
};
//������,����ʳ�����Ҫʵ������������
class Bread
	: public Food {
public:
	virtual void make() override {
		cout << "������������" << endl;
	}
};
//������,����ʳ�����Ҫʵ������������
class Chocolate
	: public Food{
public:
	virtual void make() override {
		cout << "���������ɿ���" << endl;

	}
};

//ʳ�﹤��,ר������ʳ��ĵط�
class FoodMaker {
public:
	//�����������ָ�����ͣ�������ֱ�Ӵ������󣨻�����
	static Food* Formula(string type) {
		if (type == "cake" || type == "Cake") {
			return new Cake();
		}
		else if (type == "bread" || type == "Bread") {
			return new Bread();
		}
	}
};


//int main() {
//	Food* food = FoodMaker::Formula("Cake");//����һ��ʳ�Ȼ�����ʳ������ʳ�﹤��ָ�ɵ����
//	food->make();//������
//	food = FoodMaker::Formula("Bread");
//	food->make();
//
//	return 0;
//}