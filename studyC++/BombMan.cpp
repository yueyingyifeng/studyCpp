/*
2021��7��21��
��һ�ŵ�ͼ������ֲ���ǽ��#�� �� ���ˡ�G��
��������һ��ը������ը���Ƕ���ɱ�ˡ�
�ᳯ�ĸ�������������ɱ�ˣ����ᱻǽ�����

���ը������һ������λ�û�ɱ�����ܶ�ĵ��ˡ�
*/
#include <iostream>
using namespace std;
char map[][10]{
	{'#','#','#','#','#','#','#','#','#','#'},
	{'#','G','G',' ','#','G','G','G','#','#'},
	{'#','#',' ',' ','G','#','#','G','#','#'},
	{'#',' ','G',' ','#','#',' ','G','#','#'},
	{'#',' ','#',' ','G','G','G','G','G','#'},
	{'#','#','#','#','#','#','#','#','#','#',}
};

void show(char map[][10]) {
	cout << " ";
	for (int n{}; n < 10; n++) {
		cout << n;
	}
	cout << endl;
	for (int y{}; y < 6; y++) {
		cout << y;
		for (int x{}; x < 10; x++) {
			
			cout << map[y][x];
		}
		cout << endl;
	}
}

static void count(int up,int down, int left,int right,int y,int x) {
	 static int upMax{}, downMax{}, leftMax{}, rightMax{};
	 static int result{};
	 static int r_y{}, r_x{};
	 if (up > upMax) {
		 upMax = up;
	 }
	 if (down > downMax) {
		 downMax = down;
	 }
	 if (left > leftMax) {
		 leftMax = left;
	 }
	 if (right > rightMax) {
		 rightMax = right;
	 }
	 int t_result = upMax + downMax + rightMax + leftMax;
	 if (t_result > result) {
		 result = t_result;
		 r_y = y;
		 r_x = x;
	 }
	 cout << "��map" << '[' << r_y << ']' << '[' << r_x << ']' << " ���" << endl;
	 
}
/*
int main() {
	for (int y{}; y < 6; y++) {
		for (int x{}; x < 10; x++) {
			int ry{y}, rx{x};
			while (map[ry][rx] == ' ') {//��
				int up{}, down{}, left{}, right{};
				if (ry < 6) {
					ry++;
				}
				if (map[ry][rx] == 'G') {
					count(++up,down,left,right,y,x);
				}
			}

			while (map[ry][rx] == ' ') {//��
				int up{}, down{}, left{}, right{};
				if (ry >= 0) {
					ry--;
				}
				if (map[ry][rx] == 'G') {
					count(up, ++down, left, right, y, x);
				}
			}

			while (map[ry][rx] == ' ') {//��
				int up{}, down{}, left{}, right{};
				if (rx >= 0) {
					rx--;
				}
				if (map[ry][rx] == 'G') {
					count(up, down, ++left, right, y, x);
				}
			}

			while (map[ry][rx] == ' ') {//��
				int up{}, down{}, left{}, right{};
				if (rx < 10) {
					rx++;
				}
				if (map[ry][rx] == 'G') {
					count(up, down, left, ++right, y, x);
				}
			}
		}
	}
}

*/