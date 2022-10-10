#pragma once

#include <string>
using namespace std;


class Star {
public:
    Star();
    Star(string n, string c, double ap, double ab, double d);
    Star(const Star& a);
    ~Star() {};
    friend ostream& operator <<(ostream& out, Star& a);
    friend bool operator ==(Star b, Star c);
    void operator =(Star a);
    void show();
    string getName();
    void setName(string a);
    void setConstellation(string a);
    void setAPM(double a);
    double getAPM();
    void setABM(double a);
    double getABM();
    void setDistance(double a);
    double getDistance();

private:
    string name;//名称
    string constellation;//星座
    double apparent_magnitude;//视星等
    double absolute_magnitude;//绝对星等
    double distance;//距离
};

struct Node{
    Star data;
    Node* next;
};

class LinkList {
public:
    LinkList();
    LinkList(Star a[], int n);
    ~LinkList();
    int getLength();
    Star getItem(int n);
    int locate(Star a);
    int locateName(string a);
    void insert(int n, Star a);
    void remove(int n);
    void printList();
    bool empty();
    void clear();
private:
    Node* first;
};

//光标移动
void gotoXY(int x, int y);

void pause();

void search(LinkList& s);

void insert(LinkList& s);

void remove(LinkList& s);

void screen(LinkList& s);

void invert(LinkList& s);

void mainMenu();