//#include<iostream>
//using namespace std;
//
//
////顺序表
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
//		int first = 0;
//		int end = length - 1;
//		int temp;
//		while (first < end) {
//			while (first < end && data[first] < 0) ++first;
//			while (first < end && data[end] > 0) --end;
//			temp = data[first];
//			data[first] = data[end];
//			data[end] = temp;
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
////单链表节点
//struct Node {
//	int data;
//	Node* next;
//};
//
////双链表节点
//struct DNode {
//	int data;
//	DNode* prior;
//	DNode* next;
//	int frequency;
//};
//
////单链表
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
//	void problem2() {
//
//		Node* slow, * fast;
//		slow = first;
//		fast = first;
//
//		//找到中点
//		while (fast->next != NULL) {
//			slow = slow->next;
//			fast = fast->next;
//			if (fast->next != NULL)fast = fast->next;
//		}
//		Node* mid, * back;
//		mid = slow;
//		back = mid->next;
//
//		//逆置后半部分
//		while (back->next != NULL) {
//			Node* s = new Node;
//			s = back->next;
//			back->next = s->next;
//			s->next = mid->next;
//			mid->next = s;
//		}
//
//		//后半部分依次插入
//		Node* p = new Node;
//		back = mid->next;//后半部分首元素
//		p = first->next;
//		Node* temp;
//		while (back != NULL) {
//			temp = back;
//			back = back->next;
//			mid->next = back;
//			temp->next = p->next;
//			p->next = temp;
//			p = temp->next;
//		}
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
//void problem3(LinkList& l1, LinkList& l2) {
//
//	//记录最小值指针（新表尾指针）
//	Node* min = NULL;
//	if (l2.first->next->data < l1.first->next->data) {
//		min = l2.first->next;
//	}
//	else {
//		min = l1.first->next;
//	}
//
//	//比较l1旧表首元素（min->next）与l2首元素，将最大的移动到l1新表首位
//	Node* temp = NULL;
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
//
////双链表
//class DLinkList {
//public:
//	DLinkList() {
//		head = new DNode;
//		head->prior = NULL;
//		head->next = NULL;
//		head->frequency = -1;
//	}
//	void insert(int n, int a) {
//		DNode* p = head;
//		for (int i = 0; (i < n - 1) && p; ++i) {
//			p = p->next;
//		}
//		DNode* s = new DNode;
//		s->data = a;
//		s->next = p->next;
//		s->prior = p;
//		p->next = s;
//		s->frequency = 0;
//	}
//	void show() {
//		DNode* p = head->next;
//		while (p != NULL) {
//			cout << "数据值： " << p->data << "\t" << "频次： " << p->frequency << endl;
//			p = p->next;
//		}
//	}
//	DNode* Locate(int x) {
//		DNode* p = head->next;
//		DNode* max = NULL;//保存待插入位置
//		DNode* temp = NULL;
//
//		//遍历寻找元素
//		while (p != NULL) {
//			if (p->data == x) {
//				p->frequency++;
//
//				//比较频次，进行移动
//				max = p->prior;
//				while (max->frequency < p->frequency && max != head) {
//					max = max->prior;
//				}
//				p->prior->next = p->next;
//				if (p->next != NULL)
//					p->next->prior = p->prior;
//				p->next = max->next;
//				p->prior = max;
//				max->next->prior = p;
//				max->next = p;
//				return p;
//			}
//			p = p->next;
//		}
//		return nullptr;
//	}
//private:
//	DNode* head;
//};
//
////Solution
//void solution1() {
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
//}
//void solution2() {
//	LinkList link;
//	cout << "输入元素数目：" << endl;
//	int len;
//	cin >> len;
//	cout << "输入" << len << "个数：" << endl;
//	int num = 0;
//	for (int i = 0; i < len; ++i) {
//		cin >> num;
//		link.insert(i + 1, num);
//	}
//	cout << endl;
//	cout << "创建的单链表为：" << endl;
//	cout << endl;
//	link.show();
//	cout << endl;
//	cout << "调整后单链表：" << endl;
//	cout << endl;
//	link.problem2();
//	link.show();
//}
//void solution3() {
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
//void solution4() {
//	DLinkList Dlink;
//	cout << "输入元素数目：" << endl;
//	int len;
//	cin >> len;
//	cout << "输入" << len << "个数：" << endl;
//	int num = 0;
//	for (int i = 0; i < len; ++i) {
//		cin >> num;
//		Dlink.insert(i + 1, num);
//	}
//	cout << endl;
//	cout << "创建的双链表为：" << endl;
//	cout << endl;
//	Dlink.show();
//	cout << endl;
//	int data;
//	cout << "输入元素值查询：" << endl;
//	while (cin >> data) {
//		DNode* p = Dlink.Locate(data);
//		if (p != NULL) {
//			cout << "找到值为" << data << "的元素，频次为：" << p->frequency << endl;
//		}
//		else {
//			cout << "没有值为" << data << "的元素" << endl;
//		}
//	}
//	cout << "查询结束，现双链表数据为：" << endl;
//	Dlink.show();
//}
//
//
//int main() {
//
//	//solution1();
//
//	//solution2();
//
//	//solution3();
//
//	solution4();
//
//}