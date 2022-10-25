#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkList {
public:
	LinkList() {
		first = new Node;
		first->next = NULL;
	}
	void insert(int n, int a) {
		Node* p = first;
		for (int i = 0; (i < n - 1) && p; ++i) {
			p = p->next;
		}
		Node* s = new Node;
		s->data = a;
		s->next = p->next;
		p->next = s;
	}
	void show() {
		Node* p = first;
		while (p->next != NULL) {
			cout << p->next->data << "  ";
			p = p->next;
		}
		cout << endl;
	}
	void problem2() {

		Node* slow, * fast;
		slow = first;
		fast = first;

		//�ҵ��е�
		while (fast->next != NULL) {
			slow = slow->next;
			fast = fast->next;
			if (fast->next != NULL)fast = fast->next;
		}
		Node* mid, * back;
		mid = slow;
		back = mid->next;

		//���ú�벿��
		while (back->next != NULL) {
			Node* s = new Node;
			s = back->next;
			back->next = s->next;
			s->next = mid->next;
			mid->next = s;
		}

		//��벿�����β���
		Node* p = new Node;
		back = mid->next;//��벿����Ԫ��
		p = first->next;
		Node* temp;
		while (back != NULL) {
			temp = back;
			back = back->next;
			mid->next = back;
			temp->next = p->next;
			p->next = temp;
			p = temp->next;
		}
	}
private:
	Node* first;

};
int main() {
	LinkList link;
	cout << "����Ԫ����Ŀ��" << endl;
	int len;
	cin >> len;
	cout << "����" << len << "������" << endl;
	int num = 0;
	for (int i = 0; i < len; ++i) {
		cin >> num;
		link.insert(i + 1, num);
	}
	cout << endl;
	cout << "�����ĵ�����Ϊ��" << endl;
	cout << endl;
	link.show();
	cout << endl;
	cout << "����������" << endl;
	cout << endl;
	link.problem2();
	link.show();
}