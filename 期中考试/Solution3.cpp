//#include<iostream>
//using namespace std;
//
////������ڵ�
//struct Node {
//	int data;
//	Node* next;
//};
//
//class LinkList {
//public:
//	LinkList() {
//		first = new Node;
//		first->next = NULL;
//	}
//	void insert(int n, int a) {
//		Node* p = first;
//		for (int i = 0; (i < n - 1) && p; ++i) {
//			p = p->next;
//		}
//		Node* s = new Node;
//		s->data = a;
//		s->next = p->next;
//		p->next = s;
//	}
//	void show() {
//		Node* p = first;
//		while (p->next != NULL) {
//			cout << p->next->data << "  ";
//			p = p->next;
//		}
//		cout << endl;
//	}
//	void friend problem3(LinkList& l1, LinkList& l2);
//private:
//	Node* first;
//
//};
//
//void problem3(LinkList& l1, LinkList& l2) {
//
//	Node* temp = NULL;
//	//��¼��Сֵָ�루�±�βָ�룩
//	Node* min = NULL;
//	if (l2.first->next->data < l1.first->next->data) {
//		temp = l2.first->next;
//		l2.first->next = temp->next;
//		temp->next = l1.first->next;
//		l1.first->next = temp;
//		min = l2.first->next;
//	}
//	else {
//		min = l1.first->next;
//	}
//
//	//�Ƚ�l1�ɱ���Ԫ�أ�min->next����l2��Ԫ�أ��������ƶ���l1�±���λ
//	while (min->next != NULL || l2.first->next != NULL) {
//		//�ж϶���
//		//��l1���ѿ�
//		if (min->next == NULL) {
//			temp = l2.first->next;
//			l2.first->next = temp->next;
//			temp->next = l1.first->next;
//			l1.first->next = temp;
//		}
//		//l2���ѿ�
//		else if (l2.first->next == NULL) {
//			temp = min->next;
//			min->next = temp->next;
//			temp->next = l1.first->next;
//			l1.first->next = temp;
//		}
//		else if (min->next->data <= l2.first->next->data) {
//			temp = min->next;
//			min->next = temp->next;
//			temp->next = l1.first->next;
//			l1.first->next = temp;
//		}
//		else {
//			temp = l2.first->next;
//			l2.first->next = temp->next;
//			temp->next = l1.first->next;
//			l1.first->next = temp;
//		}
//	}
//}
//int main() {
//	LinkList link1, link2;
//	cout << "�����һԪ����Ŀ��" << endl;
//	int len1;
//	cin >> len1;
//	cout << "��С��������" << len1 << "����(��һ)��" << endl;
//	int num1 = 0;
//	for (int i = 0; i < len1; ++i) {
//		cin >> num1;
//		link1.insert(i + 1, num1);
//	}
//	cout << "������Ԫ����Ŀ��" << endl;
//	int len2;
//	cin >> len2;
//	cout << "��С��������" << len2 << "�������������" << endl;
//	int num2 = 0;
//	for (int i = 0; i < len2; ++i) {
//		cin >> num2;
//		link2.insert(i + 1, num2);
//	}
//	cout << endl;
//	cout << "�����ĵ�����(��һ)Ϊ��" << endl;
//	cout << endl;
//	link1.show();
//	cout << endl;
//	cout << "�����ĵ�����(���)Ϊ��" << endl;
//	cout << endl;
//	link2.show();
//
//	problem3(link1, link2);
//	cout << endl;
//	cout << "������ĵ�����Ϊ��" << endl;
//	cout << endl;
//	link1.show();
//}