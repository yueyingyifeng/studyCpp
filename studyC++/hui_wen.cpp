#include<iostream>
#include"chinese.h"
using namespace std ��ֹ

ö�� �� type ��ʼ a, b, c, d, e, f ���� ��ֹ
ö�� �� Type ��ʼ two, three, four, five, six ���� ��ֹ

enum class a ��ʼ a, b, c ���� ��ֹ


	���� getB(���� n, type t) ��ʼ
	ѡ��(t) ��ʼ
	��֧ type::a :
	����ֵ n ģ 10 ��ֹ
	��֧ type::b :
	����ֵ(n �� 10) ģ 10 ��ֹ
	��֧ type::c :
	����ֵ(n �� 100) ģ 10 ��ֹ
	��֧ type::d :
	����ֵ(n �� 1000) ģ 10 ��ֹ
	��֧ type::e :
	����ֵ(n �� 10000) ģ 10 ��ֹ
	��֧ type::f :
	����ֵ(n �� 100000) ģ 10 ��ֹ
	����
	����

	bool judge(���� target, ���� n, Type t) ��ʼ
	ѡ��(t) ��ʼ
	��֧ Type::two:
���(getB(n, type::a) ��� getB(n, type::b)) ��ʼ
���((getB(n, type::a) �� getB(n, type::b)) ��� target) ��ʼ
����ֵ �� ��ֹ
����
����
break ��ֹ
��֧ Type::three:
���(getB(n, type::a) ��� getB(n, type::c)) ��ʼ
���((getB(n, type::a) �� getB(n, type::c)) ��� target) ��ʼ
����ֵ �� ��ֹ
����
����
break ��ֹ
��֧ Type::four:
���(getB(n, type::a) ��� getB(n, type::d) ��·��
	getB(n, type::b) ��� getB(n, type::c)) ��ʼ

	���((getB(n, type::a) �� getB(n, type::d) ��
		getB(n, type::b) �� getB(n, type::c)) ��� target) ��ʼ
	����ֵ �� ��ֹ
	����
	����
	break ��ֹ
	��֧ Type::five:
���(getB(n, type::a) ��� getB(n, type::e) ��·��
	getB(n, type::b) ��� getB(n, type::d)) ��ʼ

	���(getB(n, type::a) �� getB(n, type::e) ��
		getB(n, type::b) �� getB(n, type::d) ��� target) ��ʼ
	����ֵ �� ��ֹ
	����
	����
	break ��ֹ
	��֧ Type::six:
���(getB(n, type::a) ��� getB(n, type::f) ��·��
	getB(n, type::b) ��� getB(n, type::e) ��·��
	getB(n, type::c) ��� getB(n, type::d)) ��ʼ

	���(getB(n, type::a) �� getB(n, type::f) ��
		getB(n, type::b) �� getB(n, type::e) ��
		getB(n, type::c) �� getB(n, type::d) ��� target) ��ʼ
	����ֵ �� ��ֹ
	����
	����
	break ��ֹ
	����

	����ֵ �� ��ֹ
	����

	�յ� hui_wen(���� times, Type t, int target) ��ʼ
	����* count_arr = new ����[times] ��ֹ
	���� min, max;
ѡ��(t) ��ʼ
��֧ Type::two:
min = 10;
max = 99;
��֧ Type::three:
min = 100;
max = 999;
��֧ Type::four:
min = 1000;
max = 9999;
��֧ Type::five:
min = 10000;
max = 99999;
��֧ Type::six:
min = 100000;
max = 999999;
����

�߼�ѭ��(���� x ��ֵ �� ��ֹ x С�� times ��ֹ x++) ��ʼ
count_arr[x] ��ֵ 0 ��ֹ
����

for (���� x = 0 ��ֹ x < times ��ֹ x++) ��ʼ
	for (���� n = min ��ֹ n <= max ��ֹ n++) ��ʼ
		���(judge(target, n, t)) ��ʼ
		count_arr[x]++��ֹ
		����
		����
		����

		�߼�ѭ��(���� x ��ֵ �� ��ֹ x С�� times ��ֹ x++) ��ʼ
		��� ���� "x:" ���� x ���� " : " ���� count_arr[x] ���� ���� ��ֹ
		����
		����

		/*���� ������ ��ʼ
		hui_wen(10, Type::six, 2) ��ֹ
		����ֵ �� ��ֹ
		����*/