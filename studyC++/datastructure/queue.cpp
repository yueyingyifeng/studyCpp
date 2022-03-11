#include<iostream>
using namespace std;

template<typename T>
class queue {
	T* data;
	int front{}, rear{ 1 };
public:
	queue(int* data, int size)
		:data(data), rear(size)
	{

	}

	void push(T content) {
		T* t_data = new T[rear + 1];
		t_data = data;
		t_data[rear++] = content;
		data = new int[rear];
		data = t_data;
	}
	T pop() {
		T pop = data[front];
		T* t_data = new T[--rear];
		for (int n{}; n < rear; n++) {
			t_data[n] = data[n + 1];
		}
		data = new T[rear];
		data = t_data;

		return pop;
	}

	void show() {
		for (int n{}; n < rear; n++) {
			cout << data[n] << endl;
		}
	}
};
//void Queue(){
//	int array[100]{ 1,2,3,4,5,6 };
//	int front{}, rear{ 6 };
//	while (front < 6) {
//		array[rear++] = array[front];
//		array[front++] = 0;
//	}
//
//	for (int n{}; n < 100; n++) {
//		cout << array[n] << endl;
//	}
//}

/*/int main() {
	int q[100]{ 0,1,2,3,4,5,6,7,8,9 };
	int front{ 0 }, rear{ 10 };
	while (front < rear) {
		cout << q[front];
		front++;
		q[rear] = q[front];
		rear++;
		++front;
	}
}*/