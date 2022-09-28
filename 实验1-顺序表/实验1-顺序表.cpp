﻿
#include"实验1-顺序表.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>
#include<cstdlib>
#include<conio.h>
using namespace std;

Star all[51];//恒星总表
SeqList allSeq;
SeqList seq;


SeqList::SeqList(Star a[], int n)
{
    if (n > MaxSize) throw "wrong parameter";
    for (int i = 0; i < n; i++)
        data[i] = a[i];
    length = n;
}


Star SeqList::getItem(int i)
{
    if (i<1 && i>length) throw "wrong Location";
    else return data[i - 1];
}


int SeqList::locate(Star x)
{
    for (int i = 0; i < length; i++)
        if (data[i] == x) return i + 1;
    return 0;
}

int SeqList::locateName(string a)
{
    for (int i = 0; i < length; i++) {
        if (data[i].getName() == a)
            return i + 1;
    }
    return 0;
}


void SeqList::insert(int i, Star x)
{
    if (length >= MaxSize) throw "Overflow";
    if (i<1 || i>length + 1) throw "Location";
    for (int j = length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    length++;
}


void SeqList::remove(int i)
{
    Star x=data[i];
    if (length == 0) throw "Underflow";
    if (i<1 || i>length) throw "Location";
    x = data[i - 1];
    for (int j = i; j < length; j++)
        data[j - 1] = data[j];
    length--;

}

bool SeqList::empty()
{
    if (length == 0) return true;
    else return false;
}

void SeqList::clear()
{
    int len = length;
    for (int i = 0; i < len; ++i) {
        remove(1);
    }
}


void SeqList::printList()
{

    cout << "按任意键返回" << endl;
    cout << endl;
    for (int i = 0; i < 80; ++i) {
        cout << ' ';
    }
    cout << "恒星表" << endl;
    cout << "\t\t" << "   ";
    for (int i = 0; i < 130; ++i) {
        cout << '-';
    }
    cout << endl << endl;

    cout << "\t\t\t";
    cout << setiosflags(ios::left) << "序号" << "\t\t" << "恒星名称" << "\t\t" << "所在星座" << "\t\t" 
         << setw(10) << "视星等" << "\t\t" << setw(10) << "绝对星等" << "\t\t" << "相对距离" << endl << endl;
    cout << "\t\t" << "   ";
    for (int i = 0; i < 130; ++i) {
        cout << '-';
    }
    cout << endl << endl;

    for (int i = 0; i < length; i++) {
        cout << "\t\t\t";
        cout << i + 1 << "\t\t" << data[i] << endl;
        cout << "\t\t" << "   ";
        for (int i = 0; i < 130; ++i) {
            cout << '-';
        }
        cout << endl << endl;
    }

    gotoXY(12, 0);
    pause();

}

void SeqList::printItem(int i)
{
    if (i<1 && i>length) throw "wrong Location";
    else data[i - 1].show();
}



Star::Star() {
    name = "未知";
    constellation = "未知";
    apparent_magnitude = 0.0;
    absolute_magnitude = 0.0;
    distance = 0;

}

Star::Star(string n, string c, double ap, double ab, double d) {
    name = n;
    constellation = c;
    apparent_magnitude = ap;
    absolute_magnitude = ab;
    distance = d;

}

Star::Star(const Star& a) {
    name = a.name;
    constellation = a.constellation;
    apparent_magnitude = a.apparent_magnitude;
    absolute_magnitude = a.absolute_magnitude;
    distance = a.distance;

}

void Star::operator=(Star a)
{
    this->name = a.name;
    this->constellation = a.constellation;
    this->apparent_magnitude = a.apparent_magnitude;
    this->absolute_magnitude = a.absolute_magnitude;
    this->distance = a.distance;
}

void Star::show() {
    cout << "恒星名称：" << "\t\t" << name << "\n" <<endl;
    cout << "所在星座：" << "\t\t" << constellation << "\n" <<endl;
    cout << "视星等  ：" << "\t\t" << apparent_magnitude << "\n" <<endl;
    cout << "绝对星等：" << "\t\t" << absolute_magnitude << "\n"<<endl;
    cout << "相对距离：" << "\t\t" << distance << endl;
}

string Star::getName()
{
    return name;
}

void Star::setName(string a)
{
    name = a;
}

void Star::setConstellation(string a)
{
    constellation = a;
}

void Star::setAPM(double a)
{

    apparent_magnitude = a;
}

double Star::getAPM()
{
    return apparent_magnitude;
}

void Star::setABM(double a)
{
    absolute_magnitude = a;
}

double Star::getABM()
{
    return absolute_magnitude;
}

void Star::setDistance(double a)
{
    distance = a;
}

double Star::getDistance()
{
    return distance;
}

ostream& operator <<(ostream& out, Star& a) {
    out << setiosflags(ios::left) <<  setw(10) <<a.name << "\t\t"
        << setw(12) << a.constellation << "\t\t"
        << setw(10) << a.apparent_magnitude << "\t\t"
        << setw(10) << a.absolute_magnitude << "\t\t"
        << a.distance << endl;
    return out;
}
bool operator ==(Star b, Star c) {
    if (b.getName() == c.getName())
        return true;
    else
        return false;
}


//光标移动
void gotoXY(int x, int y)
{
    //Initialize the coordinates
    COORD coord = { x, y };
    //Set the position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//阻塞暂停
void pause()
{
    while (1) {
        if (_kbhit()) {
            _getch();
            break;
        }
    }
    return;
}

void search(SeqList s) {
   
    char i;

    while (1) {

        system("cls");
        cout << "1.按恒星名称精确查找" << endl;
        cout << "2.按序列号精确查找" << endl;
        cout << "3.返回上一级" << endl;
        cin >> i;
        if (i == '1') {
            system("cls");
            cout << "请输入恒星名称：" << endl;
            string a;
            cin >> a;
            if (s.locateName(a)) {
                system("cls");
                cout << "成功查找到名为“" << a << "”的恒星，序号为：" << s.locateName(a) << endl;
                cout << endl;
                s.getItem(s.locateName(a)).show();
                cout << endl;
            }
            else
                cout << "表中没有名为“" << a << "”的恒星" << endl;
            cout << "按任意键返回上一级" << endl;
            pause();
        }
        else if (i == '2') {
            system("cls");
            cout << "请输入恒星序号：" << endl;
            int n;
            cin >> n;
            if (1 <= n && n <= s.getLength()) {
                system("cls");
                cout << "成功查找到序号为“" << n << "”的恒星" <<  endl;
                cout << endl;
                s.getItem(n).show();
                cout << endl;
            }
            cout << "按任意键返回上一级" << endl;
            pause();
        }
        else if (i == '3') {
            return;
        }
        else {
            system("cls");
            cout << "请正确输入！" << endl;
        }
    }
}

void insert(SeqList& s)
{
    int n;
    while (1) {
        system("cls");
        cout << "输入要插入到的位置：" << endl;

        cin >> n;
        if (1 <= n && n <= s.getLength()) {
            Star temp("待输入", "待输入", 0.0, 0.0, 0.0);
            Star temp2 = s.getItem(n - 1);
            Star temp3 = s.getItem(n);
            system("cls");
            cout << "插入预览：" << endl;
            if (n - 1 > 0) {
                cout << n - 1 << "\t\t" << temp2 << endl;
            }
            cout << n << "\t\t" << temp << endl;
            cout << n + 1 << "\t\t" << temp3 << endl;
            cout << "确定要插入到此位置？" << endl;
            cout << "1.确定" << endl << "2.返回" << endl;
            char choose;
            cin >> choose;
            if (choose == '1') {
                string name; string con; double appm; double absm; double dis;
                cout << "输入恒星名称：" << endl;
                cin >> name;
                if (s.locateName(name)) {
                    cout << "表中已存在同名恒星！" << endl;
                    cout << "按任意键返回上一级" << endl;
                    pause();
                    return;
                }
                cout << "输入恒星所在星座：" << endl;
                cin >> con;
                cout << "输入视星等：" << endl;
                cin >> appm;
                cout << "输入相对星等：" << endl;
                cin >> absm;
                cout << "输入相对距离：" << endl;
                cin >> dis;
                Star in(name, con, appm, absm, dis);
                s.insert(n, in);
                system("cls");
                cout << "插入成功！" << endl;
                cout << "按任意键返回" << endl;
                break;
            }
            else if (choose == '2') {
                break;
            }
           system("cls");
           cout << "错误输入，按任意键返回上一级" << endl;
           pause();
           return;        
        }
    }
}

void remove(SeqList& s)
{
    int n;
    while (1) {
        system("cls");
        cout << "输入要删除元素的序号：" << endl;
        cin >> n;
        if (1 <= n && n <= s.getLength()) {
            cout << "序号为“" << n << "”的元素为：" << endl << endl;
            s.getItem(n).show();
            cout << endl;
            cout << "确认要删除此元素？" << endl;

            cout << "1.确定" << endl << "2.返回" << endl;
            char choose;
            cin >> choose;
            if (choose == '1') {
                s.remove(n);
                system("cls");
                cout << "删除成功！" << endl;
                cout << "按任意键返回" << endl;
                break;
            }
            else if (choose == '2') {
                break;
            }
            system("cls");
            cout << "错误输入，按任意键返回上一级" << endl;
            pause();
            return;
        }
    }
}

void screen(SeqList& s)
{
    SeqList temp;
    char i;

    while (1) {
        temp.clear();
        system("cls");
        cout << "1.按视星等筛选" << endl;
        cout << "2.按绝对星等筛选" << endl;
        cout << "3.按相对距离筛选" << endl;
        cout << "4.返回上一级" << endl;
        cin >> i;
        if (i == '1') {
            system("cls");
            double min; double max;
            cout << "请输入最小值：" << endl;
            cin >> min;
            cout << "请输入最大值" << endl;
            cin >> max;
            for (int i = 0; i < s.getLength(); ++i) {
                if (min <= s.getItem(i + 1).getAPM() && max >= s.getItem(i + 1).getAPM()) {
                    temp.insert(1, s.getItem(i + 1));
                }
            }
            cout << "按任意键查看符合要求列表" << endl;
            pause();
            if (!temp.empty()) {
                system("cls");
                temp.printList();
            }
            else {
                system("cls");
                cout << "没有符合要求的元素！" << endl;
                cout << "按任意键返回" << endl;
                pause();
            }
        }
        else if (i == '2') {
            system("cls");
            double min; double max;
            cout << "请输入最小值：" << endl;
            cin >> min;
            cout << "请输入最大值" << endl;
            cin >> max;
            for (int i = 0; i < s.getLength(); ++i) {
                if (min <= s.getItem(i + 1).getABM() && max >= s.getItem(i + 1).getABM()) {
                    temp.insert(1, s.getItem(i + 1));
                }
            }
            cout << "按任意键查看符合要求列表" << endl;
            pause();
            if (!temp.empty()) {
                system("cls");
                temp.printList();
            }
            else {
                system("cls");
                cout << "没有符合要求的元素！" << endl;
                cout << "按任意键返回" << endl;
                pause();
            }
        }
        else if (i == '3') {
            system("cls");
            double min; double max;
            cout << "请输入最小值：" << endl;
            cin >> min;
            cout << "请输入最大值" << endl;
            cin >> max;
            for (int i = 0; i < s.getLength(); ++i) {
                if (min <= s.getItem(i + 1).getDistance() && max >= s.getItem(i + 1).getDistance()) {
                    temp.insert(1, s.getItem(i + 1));
                }
            }
            cout << "按任意键查看符合要求列表" << endl;
            pause();
            if (!temp.empty()) {
                system("cls");
                temp.printList();
            }
            else {
                system("cls");
                cout << "没有符合要求的元素！" << endl;
                cout << "按任意键返回" << endl;
                pause();
            }
        }
        else if (i == '4') {
            break;
        }
        else {
            system("cls");
            cout << "错误输入，按任意键返回上一级" << endl;
            pause();
            return; 
        }
    }
}

void mainMenu() {

    //导入数据
    ifstream file;
    file.open("恒星.txt");
    string str;
    int n = 0;
    int num = 0;
    while (file >> str) {
        switch (n) {
        case 0:
            break;
        case 1:
            all[num].setName(str);
            break;
        case 2:
            all[num].setConstellation(str);

            break;
        case 3:
            all[num].setAPM(stod(str));
            break;
        case 4:
            all[num].setABM(stod(str));
            break;
        case 5:
            all[num].setDistance(stod(str));
            num++;
            break;

        }
        n++;
        n %= 6;
        if (num == 51)
            break;
    }
    file.close();
    for (int i = 0; i < 51; ++i) {
        allSeq.insert(i + 1, all[i]);
    }

    int nnum;
    int nn;
    string strin;
reset:
    //构建
    cout << "按任意键后将跳转到已有数据总表，挑选编号构建顺序表" << endl;
    pause();
    nnum = 1;
    system("cls");
    allSeq.printList();

    system("cls");
    cout << "输入用于构建顺序表的元素序号（输入0或字母结束输入）：" << endl;

    while (cin >> strin) {
        nn = stoi('0' + strin);
        if (nn == 0)
            break;
        if (nn < 1 || nn>51) {
            cout << "此序号无效！" << endl;
            continue;
        }
        else if(seq.locate(allSeq.getItem(nn)))
            continue;
        seq.insert(nnum, allSeq.getItem(nn));
        nnum++;
        if (nnum > 100) {
            cout << "已达到表最大长度，按任意键结束创建" << endl;
            pause();
            break;
        }
    }
    if (seq.empty()) {
        system("cls");
        cout << "未添加任何元素！" << endl;
        cout << "按任意键重新添加：" << endl;
        pause();
        goto reset;
    }
    system("cls");
    cout << "顺序表创建完成，按任意键查看" << endl;
    pause();
    system("cls");
    seq.printList();


    //菜单
    char menu;
    int length = seq.getLength();
    while (1) {
        system("cls");
        cout << "1.查找" << endl;
        cout << "2.筛选" << endl;
        cout << "3.插入" << endl;
        cout << "4.删除" << endl;
        cout << "5.总览表" << endl;
        cout << "6.重置表" << endl;
        cout << endl << "输入序号选择功能：" << endl;
        cin >> menu;

        switch (menu) {
        case '1':
            search(seq);
            break;
        case '2':
            screen(seq);
            break;
        case '3':
            insert(seq);
            break;
        case '4':
            remove(seq);
            break;
        case '5':
            system("cls");
            seq.printList();
            break;
        case '6':
            seq.clear();
            if (seq.empty()) {
                system("cls");
                cout << "重置成功！" << endl;
                cout << "按任意键继续" << endl;
                pause();
                goto reset;
            }
            break;
        default:
            system("cls");
            cout << "输入错误！" << endl;
            cout << "按任意键返回" << endl;
            pause();
        }
    }
}

