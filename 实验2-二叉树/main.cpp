#include "ʵ���-������.h"
#include<iostream>
using namespace std;
int main() {
	cout << "�����ַ�Ԫ�أ���ǰ�򴴽����������޺������롰#��" << endl;
	BiTree tree;
	BiNode* bt = tree.GetRoot();
	cout << "ǰ����������" << endl;
	tree.PreOrder(bt);
	cout << endl;
	cout << "������������" << endl;
	tree.InOrder(bt);
	cout << endl;
	cout << "������������" << endl;
	tree.PostOrder(bt);
	cout << endl;
	cout << "������������" << endl;
	tree.LeverOrder();
	cout << endl;
	cout << "����Ԫ��ֵ����" << endl;
	char a;
	cin >> a;
	int n = tree.Location(a);
	if (n != -1) {
		cout << "�ҵ�Ԫ��ֵΪ��" << a << "����Ԫ�أ���ǰ������� " << n << " λ" << endl;
	}
	else {
		cout << "δ�ҵ�ֵΪ��" << a << "����Ԫ��" << endl;
	}
	cout << "���Ϊ��" << endl;
	cout<<tree.getDeep();
	cout << endl;
	cout << "Ҷ�ӽڵ�Ϊ��" << endl;
	leaves* p = tree.getLeaves();
	while (p != NULL) {
		cout << p->leaf->data;
		p = p->next;
	}

}