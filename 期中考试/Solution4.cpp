//#include<iostream>
//using namespace std;
//
////˫����ڵ�
//struct DNode {
//	int data;
//	DNode* prior;
//	DNode* next;
//	int frequency;
//};
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
//int main() {
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