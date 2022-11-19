//#include<iostream>
//using namespace std;
//
//
////˳���
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
////������ڵ�
//struct Node {
//	int data;
//	Node* next;
//};
//
////˫����ڵ�
//struct DNode {
//	int data;
//	DNode* prior;
//	DNode* next;
//	int frequency;
//};
//
////������
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
//		//�ҵ��е�
//		while (fast->next != NULL) {
//			slow = slow->next;
//			fast = fast->next;
//			if (fast->next != NULL)fast = fast->next;
//		}
//		Node* mid, * back;
//		mid = slow;
//		back = mid->next;
//
//		//���ú�벿��
//		while (back->next != NULL) {
//			Node* s = new Node;
//			s = back->next;
//			back->next = s->next;
//			s->next = mid->next;
//			mid->next = s;
//		}
//
//		//��벿�����β���
//		Node* p = new Node;
//		back = mid->next;//��벿����Ԫ��
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
//	//��¼��Сֵָ�루�±�βָ�룩
//	Node* min = NULL;
//	if (l2.first->next->data < l1.first->next->data) {
//		min = l2.first->next;
//	}
//	else {
//		min = l1.first->next;
//	}
//
//	//�Ƚ�l1�ɱ���Ԫ�أ�min->next����l2��Ԫ�أ��������ƶ���l1�±���λ
//	Node* temp = NULL;
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
//
////˫����
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
//			cout << "����ֵ�� " << p->data << "\t" << "Ƶ�Σ� " << p->frequency << endl;
//			p = p->next;
//		}
//	}
//	DNode* Locate(int x) {
//		DNode* p = head->next;
//		DNode* max = NULL;//���������λ��
//		DNode* temp = NULL;
//
//		//����Ѱ��Ԫ��
//		while (p != NULL) {
//			if (p->data == x) {
//				p->frequency++;
//
//				//�Ƚ�Ƶ�Σ������ƶ�
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
//	cout << "����Ԫ�ظ�����" << endl;
//	int len;
//	cin >> len;
//	cout << "����" << len << "��Ԫ�أ�" << endl;
//	int num = 0;
//	for (int i = 0; i < len; ++i) {
//		cin >> num;
//		seq.insert(i + 1, num);
//	}
//	cout << endl;
//	cout << "������˳���Ϊ��" << endl;
//	cout << endl;
//	seq.show();
//	cout << endl;
//	cout << "������˳���" << endl;
//	cout << endl;
//	seq.problem1();
//	seq.show();
//}
//void solution2() {
//	LinkList link;
//	cout << "����Ԫ����Ŀ��" << endl;
//	int len;
//	cin >> len;
//	cout << "����" << len << "������" << endl;
//	int num = 0;
//	for (int i = 0; i < len; ++i) {
//		cin >> num;
//		link.insert(i + 1, num);
//	}
//	cout << endl;
//	cout << "�����ĵ�����Ϊ��" << endl;
//	cout << endl;
//	link.show();
//	cout << endl;
//	cout << "����������" << endl;
//	cout << endl;
//	link.problem2();
//	link.show();
//}
//void solution3() {
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
//void solution4() {
//	DLinkList Dlink;
//	cout << "����Ԫ����Ŀ��" << endl;
//	int len;
//	cin >> len;
//	cout << "����" << len << "������" << endl;
//	int num = 0;
//	for (int i = 0; i < len; ++i) {
//		cin >> num;
//		Dlink.insert(i + 1, num);
//	}
//	cout << endl;
//	cout << "������˫����Ϊ��" << endl;
//	cout << endl;
//	Dlink.show();
//	cout << endl;
//	int data;
//	cout << "����Ԫ��ֵ��ѯ��" << endl;
//	while (cin >> data) {
//		DNode* p = Dlink.Locate(data);
//		if (p != NULL) {
//			cout << "�ҵ�ֵΪ" << data << "��Ԫ�أ�Ƶ��Ϊ��" << p->frequency << endl;
//		}
//		else {
//			cout << "û��ֵΪ" << data << "��Ԫ��" << endl;
//		}
//	}
//	cout << "��ѯ��������˫��������Ϊ��" << endl;
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