#include "实验二-二叉树.h"
#include<iostream>
using namespace std;
int main() {
	cout << "输入字符元素，以前序创建二叉树，无孩子输入“#”" << endl;
	BiTree tree;
	BiNode* bt = tree.GetRoot();
	cout << "前序遍历输出：" << endl;
	tree.PreOrder(bt);
	cout << endl;
	cout << "中序遍历输出：" << endl;
	tree.InOrder(bt);
	cout << endl;
	cout << "后序遍历输出：" << endl;
	tree.PostOrder(bt);
	cout << endl;
	cout << "层序遍历输出：" << endl;
	tree.LeverOrder();
	cout << endl;
	cout << "输入元素值查找" << endl;
	char a;
	cin >> a;
	int n = tree.Location(a);
	if (n != -1) {
		cout << "找到元素值为“" << a << "”的元素，在前序遍历第 " << n << " 位" << endl;
	}
	else {
		cout << "未找到值为“" << a << "”的元素" << endl;
	}
	cout << "深度为：" << endl;
	cout<<tree.getDeep();
	cout << endl;
	cout << "叶子节点为：" << endl;
	leaves* p = tree.getLeaves();
	while (p != NULL) {
		cout << p->leaf->data;
		p = p->next;
	}

}