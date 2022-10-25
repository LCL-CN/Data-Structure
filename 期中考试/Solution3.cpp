//#include<iostream>
//using namespace std;
//
////单链表节点
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
//	//记录最小值指针（新表尾指针）
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
//	//比较l1旧表首元素（min->next）与l2首元素，将最大的移动到l1新表首位
//	while (min->next != NULL || l2.first->next != NULL) {
//		//判断短链
//		//旧l1链已空
//		if (min->next == NULL) {
//			temp = l2.first->next;
//			l2.first->next = temp->next;
//			temp->next = l1.first->next;
//			l1.first->next = temp;
//		}
//		//l2链已空
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
//	cout << "输入表一元素数目：" << endl;
//	int len1;
//	cin >> len1;
//	cout << "从小到大输入" << len1 << "个数(表一)：" << endl;
//	int num1 = 0;
//	for (int i = 0; i < len1; ++i) {
//		cin >> num1;
//		link1.insert(i + 1, num1);
//	}
//	cout << "输入表二元素数目：" << endl;
//	int len2;
//	cin >> len2;
//	cout << "从小到大输入" << len2 << "个数（表二）：" << endl;
//	int num2 = 0;
//	for (int i = 0; i < len2; ++i) {
//		cin >> num2;
//		link2.insert(i + 1, num2);
//	}
//	cout << endl;
//	cout << "创建的单链表(表一)为：" << endl;
//	cout << endl;
//	link1.show();
//	cout << endl;
//	cout << "创建的单链表(表二)为：" << endl;
//	cout << endl;
//	link2.show();
//
//	problem3(link1, link2);
//	cout << endl;
//	cout << "调整后的单链表为：" << endl;
//	cout << endl;
//	link1.show();
//}