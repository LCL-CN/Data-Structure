#pragma once

#include <string>
using namespace std;

const int MaxSize = 100;




class Star {
public:
    Star();
    Star(string n, string c, double ap, double ab, double d);
    Star(const Star &a);
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

class SeqList
{
public:
    SeqList() { length = 0; }
    SeqList(Star a[], int n);
    ~SeqList() {}
    int getLength() { return length; }
    Star getItem(int i);
    int locate(Star x);
    int locateName(string a);
    void insert(int i, Star x);
    void printList();
    void printItem(int i);
    void remove(int i);
    bool empty();
    void clear();
private:
    Star data[MaxSize];
    int length;
};


//光标移动
void gotoXY(int x, int y);

void pause();

void search(SeqList s);

void insert(SeqList& s);

void remove(SeqList& s);

void screen(SeqList& s);

void mainMenu();





