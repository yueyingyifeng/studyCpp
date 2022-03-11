#include<iostream>
#include <string>

using namespace std;

enum class Dir { up, down, left, right };//����

int replace(char c) {//�ַ�0-9ת����
	return c >= 48 && c <= 58 ? c - 48 : -1;
}

int* readLine(int length) {//��ȡһ�е����ݣ���������1 2 3�м��ÿո�ֿ�
	int x{};
	int* arr = new int[length];
	string str;
	getline(cin, str);

	cout << str.c_str() << endl;
	for (int n{}; n < str.length(); n++) {
		if (str.at(n) != ' ') {
			arr[x++] = replace(str.at(n));
		}
	}

	return arr;
}

void line(int** arr, int x_max, int y_max) {//�������
	int y{}, x{};
	int x_min{}, y_min{};
	Dir d = Dir::right;			//Ĭ�ϳ���
	int max = x_max * y_max;	//�����
	for (int step{}; step < max; step++) {
		cout << endl << x << ":" << y << endl;
		switch (d) {
		case Dir::up://------------------��
			cout << arr[x--][y];
			break;
		case Dir::down://----------------��
			cout << arr[x++][y];
			break;
		case Dir::left://----------------��
			cout << arr[x][y--];
			break;
		case Dir::right://---------------��
			cout << arr[x][y++];
			break;
		}
		//---------�����߽�͸ı䷽��--------//
		if ((x <= x_max && y <= y_max) /*&& (x >= x_min && y >= y_min)*/) {	//��
			d = Dir::right;
		}
		if ((x >= x_max && y <= y_max) /*&& (x <= x_min && y >= y_min)*/) {	//��
			d = Dir::down;
		}
		if ((x <= x_max && y >= y_max) /*&& (x >= x_min && y <= y_min)*/) {	//��
			d = Dir::left;
		}
		if ((x >= x_max && y >= y_max) /*&& (x <= x_min && y <= y_min)*/) {	//��
			d = Dir::up;
		}
	}
}
/*
int main() {
	int length{}, height{};

	cin >> length >> height; cin.ignore();//���볤�Ⱥ͸߶�

	//-----�ѿռ俪�ٶ�ά����-----//
	int** arr = new int* [height];
	for (int n{}; n < height; n++) {
		arr[n] = new int[length];
	}
	//-----��ά����ÿ��ȡһ��-----//
	for (int y{}; y < height; y++) {
		arr[y] = readLine(length);
	}
	//-----������������ά����-------//
	cout << "------------------" << endl;
	for (int y{}; y < height; y++) {
		for (int x{}; x < length; x++) {
			cout << arr[y][x];
		}
		cout << endl;
	}
	//-----������������ά����-------//
	cout << "------------------" << endl;
	line(arr, length, height);

	return 0;
}
*/