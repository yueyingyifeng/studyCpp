/*
һ����Ϸ��������ΪA��B
A��B�������5���ƣ����淶Χ��1-9
Ȼ��A����һ���Ʒ������ӵĶ���
����B����һ���Ʒ���A��������
���ѭ��

����Ϸ��
����A����3
B����4
A����2
B�ֳ���3
��B����3423������B�����Ƶ�β��

�����˭���µ��ƺ�֮�ϵ�����һ���ģ�˭�����߼��ŵĲ��ֵ������Ʋ������Լ�β��

˭����û��˭��Ӯ��

������
��Ҷ�Ӧ���У�����Ϊ���ӣ�����Ϊ���
���Ӷ�Ӧջ������������ֻ�ܴ�������

*/
#include<iostream>
using namespace std;
//���鸴�ƺ���
inline void arr_Copy(int* From, int* To, int sizeTo) {
	for (int n{}; n < sizeTo; n++) {
		To[n] = From[n];
	}
}
/*
����
*/
class queue {
	int* data;
	int front{}, rear{ 1 };
public:
	queue(int* data, int size)
		:data(data), rear(size)
	{
	}
	~queue() {}
	void push(int content) {
		int* t_data = new int[rear + 1];
		arr_Copy(data, t_data, rear + 1);
		t_data[rear++] = content;
		data = new int[rear];
		arr_Copy(t_data, data, rear);
	}
	int pop() {
		int pop = data[front];
		if (rear - 1 >= 0) {
			rear--;
		}
		int* t_data = new int[rear];
		for (int n{}; n < rear; n++) {
			t_data[n] = data[n + 1];
		}
		data = new int[rear];
		arr_Copy(t_data, data, rear);

		return pop;
	}
	int getRear() {
		return rear;
	}
	int* getData() {
		return data;
	}
};
/*
ջ
*/
class stack {
	int* data;
	int top{ 0 };
public:
	stack() { data = new int[top]; }//��ջ
	stack(int* data, int top) :data(data), top(top) {}//��ʼ��ջ
	~stack() {}
	void push(int content) {
		int* t_data = new int[top];
		arr_Copy(data, t_data, top + 1);
		t_data[top] = content;
		data = new int[top];
		arr_Copy(t_data, data, top + 1);

		++top;
	}

	int pop() {
		int pop = data[top - 1];
		if (top - 1 >= 0) {
			top--;
		}
		int* t_data = new int[top]; //------------------------------------------------------------------
		for (int n{}; n < top; n++) {
			t_data[n] = data[n];
		}
		data = new int[top];
		data = t_data;

		return pop;
	}

	int getTop() {
		return top;
	}

	int* getData() {
		return data;
	}
};
/*
����࣬���ö���ģ���Լ����ϵ���
*/
class Player {
	//������е���
	queue pokers;
public:
	//������ʱֻ���ǵ�����ĸ����
	char name;
	Player(char name, int* pokers, int count)
		: name(name), pokers(pokers, count) {}
	~Player() {}
	//��һ����
	int play() {
		return pokers.pop();
	}
	//��������һƪ���ƣ�����.û�Ǹ���Ҫ
	void take(int* poker, int count) {
		for (int n{}; n < count; n++) {
			pokers.push(poker[n]);
		}
	}
	//����һ����
	void take(int poker) {
		pokers.push(poker);
	}
	//��ʾ��ҵ���
	void show() {
		cout << name << "'s pokers: ";
		for (int n{}; n < pokers.getRear(); n++) {
			cout << pokers.getData()[n] << " ";
		}
		cout << endl;
	}
	//��һ�ʣ������
	int remain() {
		return pokers.getRear();
	}
};
/*
���ӣ�����ջ��ģ���Ƶİڷ�
*/
class Table {
	stack* table;
public:
	Table() { table = new stack; }
	Table(stack* s) :table(s) {}
	//��ҳ������Ϸ�һ���ƣ��������û�к�������һ����
	void put(Player* player) {

		table->push(player->play());
		/*
		* �����ɵ�д��
			pһ����x����Ϊp��ê�㣬x�Ƕ��㡪����ê��Ͷ������һһ�Ա�
			����ҵ��ˣ��򽫴�ê�㵽��������������ƣ������Ǹ����
			������������һ���µ����⡪��
			�Ǵ�ê�㿪ʼ������أ����ǴӶ��㿪ʼ���أ����ǴӶ���ɣ����ϳ�ʶ��
			��������n�Ǽ���������ê�㿿��
			�ȵȣ�ջֻ�ܴӺ�������ݡ������ʡ�����û�취�ˣ�ֻ��ê���򶯵㿿����
		
		for (int p{ table.getTop() }; p >= 0; p--) {
			for (int x{ table.getTop() }; x >= 0; x--) {
				if (table.getData()[p] == table.getData()[x]) {
					for (int n{ p }; n >= x; n--) {
						player->take(table.pop());
					}
				}
			}
		}
		*/
		/*
		���ո���ҷŵ�������������Ƿ���һ����
		*/
		int top = table->getTop();
		for (int x{ top - 1 }; x >= 0; x--) {
			if (table->getData()[x - 1] == table->getData()[top - 1]) {
				for (int n{ top }; n >= x; n--) {
					player->take(table->pop());
				}
				break;
			}
		}
	}


	void show() {
		cout << "    on Table: ";
		for (int n{}; n < table->getTop(); n++) {
			cout << table->getData()[n] << " ";
		}
		cout << endl;
	}
};
/*
int main() {
	const int countOfPoker{ 10 };

	Player* A = new Player('A', new int[] {1,2,3,4, 11,6,7,8,9,0}, countOfPoker);
	Player* B = new Player('B', new int[] {0,9,8,7,6,5,4,3,2,1}, countOfPoker);
	Table table;
	int time{};
	while (1) {
		if (A->remain() == 0) {
			cout << "���" << B->name << "��ʤ" << endl;
			break;
		}
		if (B->remain() == 0) {
			cout << "���" << A->name << "��ʤ" << endl;
			break;
		}
		cout << "----------------��" << ++time << "�غ�-----------------" << endl;
		

		table.put(A);
		table.put(B);

		A->show();
		B->show();
		table.show();
	}

	
}

��������
*/
/*
int main() {
	Player* A = new Player('A', new int[] {1, 4, 5}, 3);
	Table table(new stack(new int[] {1, 2, 3}, 3));
	table.show();

	table.put(A);
	table.show();
	A->show();


}
*/
/*
2021��10��21�� - �ܽ�
һ���ܴ�Ŀ�Ҫע�⣺���������Խ�����⡣�������鳤����7��������������һ��Ԫ�ظ���η��ʣ� ���ֶ�������
���������ʵ���׺���(�ԣ��Ҿ�����Ϊ��������������һֱ�ϵ����ڲŽ��)

��������漰���ˡ���
������ջ��ʵ��
������ջ�Ĳ���
��������н�ȡ

������������ˡ������´�Ҫ������
*/