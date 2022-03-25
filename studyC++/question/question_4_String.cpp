/*
* �ַ���ռλ���滻
* �����и��ַ����ǣ�this is %1
* ���%1��һ��ռλ�������Ա�����һ�������滻
* ������ԣ����ռλ���滻�أ�
*/
#include <iostream>
//#include <vector>
using namespace std;

class String {
	char* data;
public:
	explicit String() { data = nullptr; };
	explicit String(char* data)
		:data(data) {}
	explicit String(const char* data) {
		this->data = (char*)data;
	}

	const char* to_str() {
		return data;
	}
	//��ȡ����,�ӱ�����
	int length() {
		int n{};
		while (data[n] != '\0') {
				n++;
		}
		return n;
	}
	//��ȡ����,���ַ�����
	int length(const char* arg) {
		int n{};
		while (arg[n] != '\0') {
			n++;
		}
		return n;
	}
	//�ж��ַ��Ƿ�������
	bool isNumber(char n) {
		if (n >= 48 && n < 58) {
			return true;
		}
		return false;
	}
	//�滻ռλ��������
	String* args(const char* arg) {
		int length = this->length();
		int arg_length = this->length(arg);
		int total = length + arg_length;

		char* result = new char[total];
		int replace_p;//ռλ����ʼλ��

		bool havePlaceholder = false;

		for (int n{}; data[n] != '\0'; n++) {
			if (data[n] == '%' && isNumber(data[n + 1]) ) {				
				replace_p = n;//��¼Ҫ�ָ��λ��
				havePlaceholder = true;
				break;
			}
			havePlaceholder = false;
		}
		//�Ƿ����ռλ��
		if (!havePlaceholder) {
			return this;
		}

		String front(this->cut(0, replace_p-1));		//ռλ��֮ǰ���ַ���
		String replace(arg);						
		String rear(this->cut(replace_p + 2, length));	//ռλ��֮����ַ���

		//���պϲ�����,���� 1 2 3 -> (1+2)+3
		char* t = front + replace;
		result = merge(t,rear());
		//��������
		data = new char[total];
		data = result;


		return this;
	}
	//�ϲ������ַ���
	char* merge(const char* a, const char* b) {
		int lengthOfa = length(a);
		int lengthOfb = length(b);
		int total = lengthOfa + lengthOfb;
		char* result = new char[total] {};

		for (int n{}; n < total; n++) {
			if (n < lengthOfa) {
				result[n] = a[n];//��a���ַ���
			}
			else {
				result[n] = b[n - lengthOfa];//��b���ַ���
			}
		}
		result[total] = '\0';
		return result;
	}

	//��ȡ�ַ���,�������޸�ԭ����,ԭ���ݣ���ʼ������
	char* cut(const char* temp,int begin,int end) {
		int result_length = end - begin + 1;
		char* result = new char[result_length] {};

		for (int n{}; n < result_length; n++) {
			result[n] = temp[begin + n];
		}
		result[result_length] = '\0';
		/*
		* �����ԭ����{1��2��3}��ȡ1-2�����ݣ�Ҳ����2��3
		* result������������2��3�����룬����,...����,\0
		*/
		return result;
	}
	//�ӱ��ַ�����ȡһ�����ַ�������,�������޸�ԭ����:��ʼ������
	char* cut(int begin, int end) {
		int result_length = end - begin + 1;
		char* result = new char[result_length] {};

		for (int n{}; n < result_length; n++) {
			result[n] = this->data[begin + n];
		}
		result[result_length] = '\0';
		/*
		* �����ԭ����{1��2��3}��ȡ1-2�����ݣ�Ҳ����2��3
		* result������������2��3�����룬����,...����,\0
		*/
		return result;
	}
	//���ش�����ַ���
	char* operator()() {
		return this->data;
	}
	//��ȡ�ڼ����ַ�
	char& operator[](int index) {
		return data[index];
	}
	//ƴ���ַ���
	char* operator+(const char* b) {
		return merge(this->data, b);
	}
	char* operator+(String b) {
		return merge(this->data, b());
	}
};

int main() {
	String a{ "this is %1 and %2" };
	String b{ "[%1,%2]" };

	cout << a.args("a")->to_str() << endl;
	cout << a.args("b")->to_str() << endl;

	cout << b.args("12")->args("34")->to_str();
	
}