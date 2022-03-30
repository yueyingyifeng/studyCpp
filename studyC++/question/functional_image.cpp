/*
* һ�������ڿ���̨������ͼ���С����
* �ţ�û�����ǽ���ѧ�����Ľ���ĺ�����������Ŀ���̨,����ֱ�ߺ��������ߺ������������������Ǻ���
*/
#include <iostream>
#include <vector>
using namespace std;
/*
* �����࣬����x��y�����������ַ���ʽ
*/
class Coord {
public:
	int x, y;
	char point{ ' ' };		//�����ʽ

	Coord() {
		x = 0;
		y = 0;
	}
	Coord(int x, int y)
		:x(x), y(y) {}
};
/*
* ͼ��ģ�壬�ṩһ�׺���ͼ����ʾ���ࡣ
* ���Ǹ�����ʾ�������ת��
* ԭʼ������
* 0,0 0,1 0,2
* 1,0 1,1...
* ����ѧ����ϵ����
* 1,-1 0,1 1,1
* 0,-1 0,0...
* ������Ǹ���ת���ģ�refer��ת���õģ����������ݣ���real���ǲο�refer����� ��(point) ��
*/
class Fun_img {
	vector<Coord> refer_img;//ֻ��������ϵ��ͼ
	vector<Coord> real_img;	//��������ͼ��
	int maxValue;			//x��y������ֵ
	int area;				//��������ٸ���
	char point{ '*' };		//�����ʽ
protected:
	//������ϵ��ͼ�л�ȡ��Ӧ�ĵ�
	int getPbyCoord(Coord& c) {
		for (int n{}; n < refer_img.size(); n++) {
			if (refer_img[n].x == c.x && refer_img[n].y == c.y) {
				return n;
			}
		}
	}
	int getPbyCoord(int x, int y) {
		for (int n{}; n < refer_img.size(); n++) {
			if (refer_img[n].x == x && refer_img[n].y == y) {
				return n;
			}
		}
	}
public:
	Fun_img() {
		maxValue = 0;
		area = 0;
	}
	Fun_img(int maxValue) {
		if (maxValue == 0) {
			cout << "���󣬺���ͼ��������0" << endl;
			return;
		}
		else {
			this->maxValue = maxValue * 2 + 1;
			area = (int)pow(this->maxValue, 2);
		}
		for (int y = 0; y < this->maxValue; y++) {
			for (int x = 0; x < this->maxValue; x++) {
				/*cout << "[" <<//���ͼ��,������
					(maxOfHorizon - x >= 0 ? -(maxOfHorizon - x) : x - maxOfHorizon) <<
					"," <<
					(maxOfVertical - y >= 0 ? maxOfVertical - y : -(y - maxOfVertical)) << "]" << " ";*/
				refer_img.push_back(Coord((maxValue - x >= 0 ? -(maxValue - x) : x - maxValue),
					(maxValue - y >= 0 ? maxValue - y : -(y - maxValue))
				));
			}
		}
		real_img.resize(refer_img.size(), Coord());
	}
	//���õ����ʽ
	void setPointStyle(char p) {
		this->point = p;
	}
	//�ں���ͼ���ϻ�һ����
	void setPoint(Coord& c) {
		real_img[getPbyCoord(c)].point = this->point;
	}
	void setPoint(int x, int y) {
		real_img[getPbyCoord(x, y)].point = this->point;
	}
	//�ں���ͼ���ϻ�һ���Զ�����ʽ�ĵ�
	void setPoint(Coord& c, char p) {
		real_img[getPbyCoord(c)].point = p;
	}
	void setPoint(int x, int y, char p) {
		real_img[getPbyCoord(x, y)].point = p;
	}
	//��ʾ����ϵʵ��,�˷�������ʾ����ͼ����������꣬û�о����
	void showReferImg() {
		cout << endl;
		for (int p{ 1 }; p <= area; p++) {
			if (p % maxValue != 0) {
				cout << "[" << refer_img[p - 1].x << "," << refer_img[p - 1].y << "]" << " ";
			}
			else {
				cout << "[" << refer_img[p - 1].x << "," << refer_img[p - 1].y << "]" << " ";
				cout << endl;
			}
		}
	}
	//��ʾ����ϵ����,�˷�����ʾ����ͼ��Ľ��
	void show() {
		cout << endl;
		for (int p{ 1 }; p <= area; p++) {
			if (p % maxValue != 0) {
				cout << real_img[p - 1].point;
			}
			else {
				cout << real_img[p - 1].point;
				cout << endl;
			}
		}
	}
};
/*
* ��ѧ��,��װ(ʹ��)��ͼ��ģ��
* �����ĸ���������ѧ�������������⻹�м����޷����ã�
* ����ʾ������ѧ����
*/
class Function {
	Fun_img fun_img;//��װ
	int maxValue;	//������ֵ[-maxValue,maxValue]
	char p = '*';	//Ĭ����ʾ��ʽ
public:
	Function(int maxValue)
		:maxValue(maxValue)
	{
		fun_img = Fun_img(maxValue);
		for (int n{ -maxValue }; n < maxValue; n++) {
			fun_img.setPoint(n, 0, '-');
		}
		for (int n{ -maxValue }; n < maxValue; n++) {
			fun_img.setPoint(0, n, '|');
		}
		fun_img.setPoint(maxValue, 0, '>');
		fun_img.setPoint(0, maxValue, '^');
		fun_img.setPoint(0, 0, '+');
	}

	//ֱ�ߺ���:y = ax + b
	void LinearFunction(int a, int b = 0) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (y == a * x + b) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//���κ���:y = ax^2 + bx + c
	void QuadraticFunction(int a = 1, int b = 0, int c = 0) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (y == (a * pow(x, 2) + b * x + c)) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//ָ������:y = a^x + b,a>=1
	void ExponentialFunction(int a, int b = 0) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (!(a >= 1)) {
					cout << "ָ������a�������0!" << endl;
					return;
				}
				if (y == ((int)pow(a, x) + b)) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//��������:y = logax, a >= 0.(aΪ����)
	void LogarithmicFunction(int a) {
		for (int y{ -maxValue }; y <= maxValue; y++) {
			for (int x{ -maxValue }; x <= maxValue; x++) {
				if (!(a >= 1)) {
					cout << "ָ������a�������0!" << endl;
					return;
				}
				if (y == (log(x) / log(a))) {
					fun_img.setPoint(x, y, p);
				}
			}
		}
	}
	//���ñ�ˢ
	void setPoint(char p) {
		this->p = p;
	}

	//��ʾ����ͼ��
	void show() {
		fun_img.show();
	}
	//��ʾ��������ϵ
	void showReferImg() {
		fun_img.showReferImg();
	}
};

//int main() {
//	Function f(10);
//	f.LinearFunction(3);//һ�κ���
//	f.setPoint('1');
//	f.QuadraticFunction(-2, 3, 2);//���κ���
//	f.setPoint('2');
//	f.ExponentialFunction(3,2);//ָ������
//	f.setPoint('3');
//	f.LogarithmicFunction(2);//��������
//
//	f.show();
//	
//}


//int main()
//{
//	double a = 2, x = 2;//��2Ϊ�׵Ķ������� 
//	for (x = 2; x <= 16; x += 2)
//	{
//		cout << "x=" << x << "ʱ����2Ϊ�׵Ķ�������=" << log(x) / log(a) << endl;
//	}
//	return 0;
//}