/*
2021��7��22��
n����Χ��һ��Ȧ
Ȼ�󵽵�g���˾�Ҫ���߳�
�����ڸ��������
�Ǹ�λ�õ��˻�����

2021��7��31�ճɹ����
*/

#include<iostream>
#include<vector>
using namespace std;

int result(int* data, int size) {//�ҵ����ս��
	for (int n{}; n < size; n++) {
		if (data[n] != -1) {
			return n;
		}
	}
}

bool cheack(int* data,int size) {		//��ʾ���ս��
	int count{};
	for (int i{}; i < size; i++) {
		if (data[i] == -1) {
			count++;
		}
	}
	if (size - count == 1) {
		cout << "��������" << result(data, size) << endl;
		return true;
	}
	else {
		return false;
	}
}

void show(int* data, int size) {		//��ʾ����
	cout << " data: ";
	for (int i{ }; i < size; i++) {
		cout << data[i] << ",";
	}
	cout << endl;
}

void Maual_fun() {
	int g, n;

	cout << "�����������Χ��һ��Ȧ:";
	cin >> n;
	int* data = new int[n];
	cout << "�����뵽�ڼ����˾�����:";
	cin >> g;

	for (int i{ }; i < n; i++) {		//��ʼ������
		data[i] = i;
	}

	for (int index{}, i{};; i++)
	{
		if (i == n) {					//��i�������һ����ʱ����i 
			i = 0;
		}

		if (data[i] == -1) {			//�������-1������
			continue;
		}
		index++;
		if (index == g + 1) {			//������Ŀ����ʱ��������Ϊ-1
			data[i] = -1;
			show(data, n);
			index = 0;
		}

		if (cheack(data, n)) {
			break;
		}
	}
}

void Maual_fun(int n,int g) {
	int* data = new int[n];

	for (int i{ }; i < n; i++) {		//��ʼ������
		data[i] = i;
	}

	for (int index{}, i{};; i++)
	{
		if (i == n) {					//��i�������һ����ʱ����i 
			i = 0;
		}

		if (data[i] == -1) {			//�������-1������
			continue;
		}
		index++;
		if (index == g + 1) {			//������Ŀ����ʱ��������Ϊ-1
			data[i] = -1;
			index = 0;
		}

		if (cheack(data, n)) {
			break;
		}
	}
}

void auto_fun(int nMax,int gMax) {
	for (int n{1}; n < nMax; n++) {
		cout << "��nΪ" << n  << "----------------------" << endl;
		for (int g{1}; g < gMax; g++) {
			cout << "��gΪ" << g << ":";
			Maual_fun(n, g);
		}
	}
}

/*int main() {
	//Maual_fun();			//�ֶ�������ֵ
	auto_fun(20, 10);			//�Զ�
}*/