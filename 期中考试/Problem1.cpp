#include<iostream>
using namespace std;

const int maxSize = 10;
int seqList[maxSize];

int main() {

	cout << "����ʮ������" << endl;
	for (int i = 0; i < maxSize; ++i) {
		cin >> seqList[i];
	}
	int head = 0;
	int end = maxSize - 1;
	int temp;
	while (head < end) {
		while (head < end && seqList[head] < 0) ++head;
		while (head < end && seqList[end] > 0) --end;
		temp = seqList[head];
		seqList[head] = seqList[end];
		seqList[end] = temp;
	}
	cout << "������˳���" << endl;
	for (int i = 0; i < maxSize; ++i) {
		cout << seqList[i];
	}

}