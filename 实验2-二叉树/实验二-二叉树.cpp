#include "实验二-二叉树.h"
#include<iostream>
using namespace std;
void BiTree::PreOrder(BiNode* bt)
{    

    Stack S;
    S.top = -1;
    while (bt != nullptr || S.top != -1) {
        while (bt != nullptr) {
            cout << bt->data;
            S.data[++S.top] = bt;
            bt = bt->lchild;
        }
        if (S.top != -1) {
            bt = S.data[S.top--];
            bt = bt->rchild;
        }
    }

}
void BiTree::InOrder(BiNode* bt)
{
    Stack S;
    S.top = -1;
    while (bt != nullptr || S.top != -1) {
        while (bt != nullptr) {
            S.data[++S.top] = bt;
            bt = bt->lchild;
        }
        if (S.top != -1) {
            bt = S.data[S.top--];
            cout << bt->data;
            bt = bt->rchild;
        }
    }
}
void BiTree::PostOrder(BiNode* bt)
{
    Stack2 S2;
    for (int i = 0; i < 20; ++i) {
        S2.flag[i] = 0;
    }
    S2.top = -1;
    while (bt != nullptr || S2.top != -1) {
        while (bt != nullptr) {  //左子树
            S2.top++;
            S2.data[S2.top] = bt;//bt结点入栈
            bt = bt->lchild;
        }
        while (S2.top != -1 && S2.flag[S2.top] == true) {
            S2.flag[S2.top] = false;
            bt = S2.data[S2.top--];//出栈
            cout << bt->data;
        }
        if (bt == root) { bt = NULL; };
        if (S2.top != -1) { //开始遍历右子树
            S2.flag[S2.top] = true;
            //栈顶元素不变，修改flag，再出栈即为第二次出栈            
            bt = S2.data[S2.top]->rchild;//取右孩子为bt，继续遍历              
        }
    }
}
void BiTree::LeverOrder()
{
    Quene Q;
    Q.front = Q.rear = -1;
    if (root == nullptr) return;
    Q.data[++Q.rear] = root;
    while (Q.front != Q.rear) {
        BiNode *q = Q.data[++Q.front];
        cout << q->data;
        if (q->lchild != nullptr)  Q.data[++Q.rear] = q->lchild;
        if (q->rchild != nullptr)  Q.data[++Q.rear] = q->rchild;
    }
}
int BiTree::getDeep()
{
    Quene Q;
    Q.front = Q.rear = -1;
    int num = 0;
    BiNode* levelFlag = NULL;
    bool flag = 0;
    if (root == nullptr) return 0;
    levelFlag = root;
    Q.data[++Q.rear] = root;
    while (Q.front != Q.rear) {
        BiNode* q = Q.data[++Q.front];
        if (q == levelFlag) {
            num++;
            flag = 1;
        }
        if (q->lchild != nullptr)  Q.data[++Q.rear] = q->lchild;
        if (q->rchild != nullptr)  Q.data[++Q.rear] = q->rchild;

        if (flag) {
            levelFlag = Q.data[Q.rear];
            flag = 0;
        }
    }
    return num;
}
leaves* BiTree::getLeaves()
{
    leaves* first=new leaves;
    first->next = NULL;
    Stack S;
    S.top = -1;
    Quene Q;
    Q.front = Q.rear = -1;
    if (root == nullptr) return NULL;
    Q.data[++Q.rear] = root;
    while (Q.front != Q.rear) {
        BiNode* q = Q.data[++Q.front];
        if (q->lchild != nullptr) {
            Q.data[++Q.rear] = q->lchild;
            if (q->rchild != nullptr) Q.data[++Q.rear] = q->rchild;
        }
        else {
            if (q->rchild != nullptr) Q.data[++Q.rear] = q->rchild;
            else {
                leaves* p = new leaves;
                p->leaf = q;
                p->next = first->next;
                first->next = p;
            }
        }
    }
    return first->next;
}
int BiTree::Location(char x)
{
    Stack S;
    S.top = -1;
    int num = 0;
    bool flag=0;
    BiNode* bt = root;
    while (bt != nullptr || S.top != -1) {
        while (bt != nullptr) {
            num++;
            if (bt->data == x) {
                flag = 1;
                break;
            }
            S.data[++S.top] = bt;
            bt = bt->lchild;
        }
        if (flag)return num;
        if (S.top != -1) {
            bt = S.data[S.top--];
            bt = bt->rchild;
        }
    }
    return -1;
}
BiNode* BiTree::Creat(BiNode* bt)
{
    char ch;
    cin >> ch;
    if (ch == '#')     bt = nullptr;
    else {
        bt = new BiNode;
        bt->data = ch;
        bt->lchild = Creat(bt->lchild);
        bt->rchild = Creat(bt->rchild);
    }
    return bt;

}

void BiTree::Release(BiNode* root)
{
    if (root != NULL) {
        Release(root->lchild);
        Release(root->rchild);
        delete root;
    }

}
