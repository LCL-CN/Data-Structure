#pragma once
struct BiNode {
	BiNode* lchild;
	char data;
	BiNode* rchild;
};

struct leaves {
    BiNode* leaf;
    leaves* next;
};


class BiTree
{
public:
    BiTree() { root = Creat(root); }
    ~BiTree() { Release(root); };
    void PreOrder(BiNode* bt);
    void InOrder(BiNode* bt);
    void PostOrder(BiNode* bt);
    void LeverOrder();
    int getDeep();
    leaves* getLeaves();
    int Location(char x);
    BiNode* GetRoot() {return root;};
private:
    BiNode* root;
    BiNode* Creat(BiNode* bt);
    void Release(BiNode* bt);
};

struct Quene {
    BiNode* data[50];
    int front, rear;
};
struct Stack {
    BiNode* data[20];
    int top;
};
struct Stack2 {
    BiNode* data[20];
    bool flag[20];
    int top;
};
