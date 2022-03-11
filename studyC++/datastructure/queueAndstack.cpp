/*
一个游戏，参与者为A和B
A、B各随机抽5张牌，牌面范围是1-9
然后A出第一张牌放在桌子的顶端
接着B出第一张牌放在A出的下面
如此循环

在游戏中
假如A出了3
B出了4
A出了2
B又出了3
则B拿走3423并接着B余下牌的尾部

即如果谁放下的牌和之上的牌有一样的，谁就拿走夹着的部分的所有牌并接着自己尾部

谁的牌没了谁就赢了

分析：
玩家对应队列，出牌为出队，拿牌为入队
桌子对应栈，符合条件的只能从上拿牌

*/
#include<iostream>
using namespace std;
//数组复制函数
inline void arr_Copy(int* From, int* To, int sizeTo) {
	for (int n{}; n < sizeTo; n++) {
		To[n] = From[n];
	}
}
/*
队列
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
栈
*/
class stack {
	int* data;
	int top{ 0 };
public:
	stack() { data = new int[top]; }//空栈
	stack(int* data, int top) :data(data), top(top) {}//初始化栈
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
玩家类，利用队列模拟自己手上的牌
*/
class Player {
	//玩家手中的牌
	queue pokers;
public:
	//我们暂时只考虑单个字母名字
	char name;
	Player(char name, int* pokers, int count)
		: name(name), pokers(pokers, count) {}
	~Player() {}
	//放一张牌
	int play() {
		return pokers.pop();
	}
	//拿走连成一篇的牌，废弃.没那个必要
	void take(int* poker, int count) {
		for (int n{}; n < count; n++) {
			pokers.push(poker[n]);
		}
	}
	//拿走一张牌
	void take(int poker) {
		pokers.push(poker);
	}
	//显示玩家的牌
	void show() {
		cout << name << "'s pokers: ";
		for (int n{}; n < pokers.getRear(); n++) {
			cout << pokers.getData()[n] << " ";
		}
		cout << endl;
	}
	//玩家还剩多少牌
	int remain() {
		return pokers.getRear();
	}
};
/*
桌子，利用栈来模拟牌的摆放
*/
class Table {
	stack* table;
public:
	Table() { table = new stack; }
	Table(stack* s) :table(s) {}
	//玩家朝桌子上放一张牌，并检查有没有和这张牌一样的
	void put(Player* player) {

		table->push(player->play());
		/*
		* 更自由的写法
			p一定比x大，因为p是锚点，x是动点——将锚点和动点进行一一对比
			如果找到了，则将从锚点到动点的所有数（牌）都给那个玩家
			不过这引发了一个新的问题——
			是从锚点开始给玩家呢，还是从动点开始给呢？还是从动点吧，符合常识。
			故在这里n是减减——朝锚点靠近
			等等，栈只能从后面出数据。。。故。。。没办法了，只能锚点向动点靠近了
		
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
		检查刚刚玩家放的牌与上面的牌是否有一样的
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
			cout << "玩家" << B->name << "获胜" << endl;
			break;
		}
		if (B->remain() == 0) {
			cout << "玩家" << A->name << "获胜" << endl;
			break;
		}
		cout << "----------------第" << ++time << "回合-----------------" << endl;
		

		table.put(A);
		table.put(B);

		A->show();
		B->show();
		table.show();
	}

	
}

测试样例
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
2021年10月21日 - 总结
一个很大的坑要注意：就是数组的越界问题。比如数组长度是7，那这个数组最后一个元素该如何访问？ （手动滑稽）
这个问题属实容易忽略(对，我就是因为忽略了这个问题才一直拖到现在才解决)

这个问题涉及到了——
队列与栈的实现
队列与栈的操作
对数组进行截取

好像就这三个了。。。下次要谨慎啊
*/