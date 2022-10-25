//#include<iostream>
//using namespace std;
//
//
//const int maxSize = 100;
//class SeqList {
//public:
//	SeqList() {
//		for (int i = 0; i < maxSize; ++i) {
//			data[i] = 0;
//		}
//		length = 0;
//	}
//	void insert(int i, int x) {
//		for (int j = length; j >= i; j--)
//			data[j] = data[j - 1];
//		data[i - 1] = x;
//		length++;
//	}
//	void problem1() {
//		int positive = 0;
//		int negative = length - 1;
//		int temp;
//		while (positive < negative) {
//			while (positive < negative && data[positive] < 0) ++positive;
//			while (positive < negative && data[negative] > 0) --negative;
//			temp = data[positive];
//			data[positive] = data[negative];
//			data[negative] = temp;
//		}
//	}
//	void show() {
//		for (int i = 0; i < length; ++i) {
//			cout << data[i] << "  ";
//		}
//		cout << endl;
//	}
//private:
//	int data[maxSize];
//	int length;
//};
//
//int main() {
//
//	SeqList seq;
//	cout << "输入元素个数：" << endl;
//	int len;
//	cin >> len;
//	cout << "输入" << len << "个元素：" << endl;
//	int num = 0;
//	for (int i = 0; i < len; ++i) {
//		cin >> num;
//		seq.insert(i + 1, num);
//	}
//	cout << endl;
//	cout << "创建的顺序表为：" << endl;
//	cout << endl;
//	seq.show();
//	cout << endl;
//	cout << "调整后顺序表：" << endl;
//	cout << endl;
//	seq.problem1();
//	seq.show();
//
//} 