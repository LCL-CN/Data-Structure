//#include<iostream>
//using namespace std;
//
////双链表节点
//struct DNode {
//	int data;
//	DNode* prior;
//	DNode* next;
//	int frequency;
//};
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
//int main() {
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