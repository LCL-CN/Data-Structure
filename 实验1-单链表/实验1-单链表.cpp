#include"ʵ��1-������.h"
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>
#include<cstdlib>
#include<conio.h>
using namespace std;

Star all[51];//�����ܱ�
LinkList allLink;
LinkList link;

Star::Star() {
    name = "δ֪";
    constellation = "δ֪";
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
    cout << "�������ƣ�" << "\t\t" << name << "\n" << endl;
    cout << "����������" << "\t\t" << constellation << "\n" << endl;
    cout << "���ǵ�  ��" << "\t\t" << apparent_magnitude << "\n" << endl;
    cout << "�����ǵȣ�" << "\t\t" << absolute_magnitude << "\n" << endl;
    cout << "��Ծ��룺" << "\t\t" << distance << endl;
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
    out << setiosflags(ios::left) << setw(10) << a.name << "\t\t"
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


//����ƶ�
void gotoXY(int x, int y)
{
    //Initialize the coordinates
    COORD coord = { x, y };
    //Set the position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//������ͣ
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


LinkList::LinkList()
{
    first = new Node;
    first->next = NULL;
}

LinkList::LinkList(Star a[], int n)
{
    first = new Node;
    first->next = NULL;
    Node* s ;
    for (int i = n - 1; i >= 0; --i) {
        s = new Node;
        s->data = a[i];
        s->next = first->next;
        first->next = s;
    }

}

LinkList::~LinkList()
{
    Node* p = first;
    Node* q = new Node;
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }

}

int LinkList::getLength()
{
    Node* p = first->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;

}

Star LinkList::getItem(int n)
{
    Node* p = first;
    for (int i = 0; (i < n) && p; ++i) {
        p = p->next;
    }
    if (!p)
        throw "wrong Location";
    else
        return p->data;


}

int LinkList::locate(Star a)
{
    Node* p = first;
    int len = this->getLength();
    for (int i = 1; i < len; ++i) {
        p = p->next;
        if ((p->data) == a) {
            return i;
        }
    }

    return 0;
}

int LinkList::locateName(string a)
{
    Node* p = first;
    int len = this->getLength();
    for (int i = 1; i < len; ++i) {
        p = p->next;
        if ((p->data).getName() == a) {
            return i;
        }
    }

    return 0;
}

void LinkList::insert(int n, Star a)
{
    Node* p = first;
    for (int i = 0; (i < n-1) && p; ++i) {
        p = p->next;
    }
    if (!p)
        throw "wrong Location";
    else
    {
        Node* s = new Node;
        s->data = a;
        s->next = p->next;
        p->next = s;
    }

}

void LinkList::remove(int n)
{

    Node* p = first;
    for (int i = 0; (i < n - 1) && p; ++i) {
        p = p->next;
    }
    if (!p || !p->next)
        throw "wrong Location";
    else {
        Node* s = p ->next;
        p->next = s->next;
        delete s;
    }

}

void LinkList::printList()
{
    int len = this->getLength();
    Node* p = first;
    cout << "�����������" << endl;
    cout << endl;
    for (int i = 0; i < 80; ++i) {
        cout << ' ';
    }
    cout << "���Ǳ�" << endl;
    cout << "\t\t" << "   ";
    for (int i = 0; i < 130; ++i) {
        cout << '-';
    }
    cout << endl << endl;

    cout << "\t\t\t";
    cout << setiosflags(ios::left) << "���" << "\t\t" << "��������" << "\t\t" << "��������" << "\t\t"
        << setw(10) << "���ǵ�" << "\t\t" << setw(10) << "�����ǵ�" << "\t\t" << "��Ծ���" << endl << endl;
    cout << "\t\t" << "   ";
    for (int i = 0; i < 130; ++i) {
        cout << '-';
    }
    cout << endl << endl;

    for (int i = 0; i < len; i++) {
        p = p->next;
        cout << "\t\t\t";
        cout << i+1 << "\t\t" << p->data << endl;
        cout << "\t\t" << "   ";
        for (int i = 0; i < 130; ++i) {
            cout << '-';
        }
        cout << endl << endl;
    }

    gotoXY(12, 0);
    pause();

}

bool LinkList::empty()
{
    if (first->next == NULL)
        return true;
    else
        return false;
}

void LinkList::clear()
{
    Node* p = first->next;
    Node* q = new Node;
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }
    first->next=NULL;
}


void search(LinkList& s) {

    char i;

    while (1) {

        system("cls");
        cout << "1.���������ƾ�ȷ����" << endl;
        cout << "2.�����кž�ȷ����" << endl;
        cout << "3.������һ��" << endl;
        cin >> i;
        if (i == '1') {
            system("cls");
            cout << "������������ƣ�" << endl;
            string a;
            cin >> a;
            int num = s.locateName(a);
            if (num) {
                system("cls");
                cout << "�ɹ����ҵ���Ϊ��" << a << "���ĺ��ǣ����Ϊ��" << num << endl;
                cout << endl;
                s.getItem(num).show();
                cout << endl;
            }
            else
                cout << "����û����Ϊ��" << a << "���ĺ���" << endl;
            cout << "�������������һ��" << endl;
            pause();
        }
        else if (i == '2') {
            system("cls");
            cout << "�����������ţ�" << endl;
            int n;
            cin >> n;
            if (1 <= n && n <= s.getLength()) {
                system("cls");
                cout << "�ɹ����ҵ����Ϊ��" << n << "���ĺ���" << endl;
                cout << endl;
                s.getItem(n).show();
                cout << endl;
            }
            cout << "�������������һ��" << endl;
            pause();
        }
        else if (i == '3') {
            break;
        }
        else {
            system("cls");
            cout << "����ȷ���룡" << endl;
        }
    }
}

void insert(LinkList& s)
{
    int n;
    while (1) {
        system("cls");
        cout << "����Ҫ���뵽��λ�ã�" << endl;

        cin >> n;
        if (1 <= n && n <= s.getLength()) {
            Star temp("������", "������", 0.0, 0.0, 0.0);
            Star temp2 = s.getItem(n - 1);
            Star temp3 = s.getItem(n);
            system("cls");
            cout << "����Ԥ����" << endl;
            if (n - 1 > 0) {
                cout << n - 1 << "\t\t" << temp2 << endl;
            }
            cout << n << "\t\t" << temp << endl;
            cout << n + 1 << "\t\t" << temp3 << endl;
            cout << "ȷ��Ҫ���뵽��λ�ã�" << endl;
            cout << "1.ȷ��" << endl << "2.����" << endl;
            char choose;
            cin >> choose;
            if (choose == '1') {
                string name; string con; double appm; double absm; double dis;
                cout << "����������ƣ�" << endl;
                cin >> name;
                if (s.locateName(name)) {
                    cout << "�����Ѵ���ͬ�����ǣ�" << endl;
                    cout << "�������������һ��" << endl;
                    pause();
                    return;
                }
                cout << "�����������������" << endl;
                cin >> con;
                cout << "�������ǵȣ�" << endl;
                cin >> appm;
                cout << "��������ǵȣ�" << endl;
                cin >> absm;
                cout << "������Ծ��룺" << endl;
                cin >> dis;
                Star in(name, con, appm, absm, dis);
                s.insert(n, in);
                system("cls");
                cout << "����ɹ���" << endl;
                cout << "�����������" << endl;
                break;
            }
            else if (choose == '2') {
                break;
            }
            system("cls");
            cout << "�������룬�������������һ��" << endl;
            pause();
            return;
        }
    }
}

void remove(LinkList& s)
{
    int n;
    while (1) {
        system("cls");
        cout << "����Ҫɾ��Ԫ�ص���ţ�" << endl;
        cin >> n;
        if (1 <= n && n <= s.getLength()) {
            cout << "���Ϊ��" << n << "����Ԫ��Ϊ��" << endl << endl;
            s.getItem(n).show();
            cout << endl;
            cout << "ȷ��Ҫɾ����Ԫ�أ�" << endl;

            cout << "1.ȷ��" << endl << "2.����" << endl;
            char choose;
            cin >> choose;
            if (choose == '1') {
                s.remove(n);
                system("cls");
                cout << "ɾ���ɹ���" << endl;
                cout << "�����������" << endl;
                break;
            }
            else if (choose == '2') {
                break;
            }
            system("cls");
            cout << "�������룬�������������һ��" << endl;
            pause();
            return;
        }
    }
}

void screen(LinkList& s)
{
    LinkList temp;
    char i;

    while (1) {
        temp.clear();
        system("cls");
        cout << "1.�����ǵ�ɸѡ" << endl;
        cout << "2.�������ǵ�ɸѡ" << endl;
        cout << "3.����Ծ���ɸѡ" << endl;
        cout << "4.������һ��" << endl;
        cin >> i;
        if (i == '1') {
            system("cls");
            double min; double max;
            cout << "��������Сֵ��" << endl;
            cin >> min;
            cout << "���������ֵ" << endl;
            cin >> max;
            for (int i = 0; i < s.getLength(); ++i) {
                if (min <= s.getItem(i + 1).getAPM() && max >= s.getItem(i + 1).getAPM()) {
                    temp.insert(1, s.getItem(i + 1));
                }
            }
            cout << "��������鿴����Ҫ���б�" << endl;
            pause();
            if (!temp.empty()) {
                system("cls");
                temp.printList();
            }
            else {
                system("cls");
                cout << "û�з���Ҫ���Ԫ�أ�" << endl;
                cout << "�����������" << endl;
                pause();
            }
        }
        else if (i == '2') {
            system("cls");
            double min; double max;
            cout << "��������Сֵ��" << endl;
            cin >> min;
            cout << "���������ֵ" << endl;
            cin >> max;
            for (int i = 0; i < s.getLength(); ++i) {
                if (min <= s.getItem(i + 1).getABM() && max >= s.getItem(i + 1).getABM()) {
                    temp.insert(1, s.getItem(i + 1));
                }
            }
            cout << "��������鿴����Ҫ���б�" << endl;
            pause();
            if (!temp.empty()) {
                system("cls");
                temp.printList();
            }
            else {
                system("cls");
                cout << "û�з���Ҫ���Ԫ�أ�" << endl;
                cout << "�����������" << endl;
                pause();
            }
        }
        else if (i == '3') {
            system("cls");
            double min; double max;
            cout << "��������Сֵ��" << endl;
            cin >> min;
            cout << "���������ֵ" << endl;
            cin >> max;
            for (int i = 0; i < s.getLength(); ++i) {
                if (min <= s.getItem(i + 1).getDistance() && max >= s.getItem(i + 1).getDistance()) {
                    temp.insert(1, s.getItem(i + 1));
                }
            }
            cout << "��������鿴����Ҫ���б�" << endl;
            pause();
            if (!temp.empty()) {
                system("cls");
                temp.printList();
            }
            else {
                system("cls");
                cout << "û�з���Ҫ���Ԫ�أ�" << endl;
                cout << "�����������" << endl;
                pause();
            }
        }
        else if (i == '4') {
            break;
        }
        else {
            system("cls");
            cout << "�������룬�������������һ��" << endl;
            pause();
            return;
        }
    }
}

void mainMenu() {

    //��������
    ifstream file;
    file.open("����.txt");
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
        allLink.insert(i + 1, all[i]);
    }
    int nnum;
    int nn;
    string strin;
reset:

    //����
    cout << "�����������ת�����������ܱ���ѡ��Ź���˳���" << endl;
    pause();


    nnum = 1;
    system("cls");
    allLink.printList();

    system("cls");
    cout << "�������ڹ���˳����Ԫ����ţ�����0����ĸ�������룩��" << endl;

    while (cin >> strin) {
        nn = stoi('0'+strin);
        if (nn == 0)
            break;
        if (nn < 1 || nn>51) {
            cout << "�������Ч��" << endl;
            continue;
        }
        if (link.locate(allLink.getItem(nn)))
            continue;
        link.insert(nnum, allLink.getItem(nn));
        nnum++;
        if (nnum > 100) {
            cout << "�Ѵﵽ����󳤶ȣ����������������" << endl;
            pause();
            break;
        }
    }
    if (link.empty()) {
        system("cls");
        cout << "δ����κ�Ԫ�أ�" << endl;
        cout << "�������������ӣ�" << endl;
        pause();
        goto reset;
    }
    system("cls");
    cout << "˳�������ɣ���������鿴" << endl;
    pause();
    system("cls");
    link.printList();


    //�˵�
    char menu;
    int length = link.getLength();
    while (1) {
        system("cls");
        cout << "1.����" << endl;
        cout << "2.ɸѡ" << endl;
        cout << "3.����" << endl;
        cout << "4.ɾ��" << endl;
        cout << "5.������" << endl;
        cout << "6.���ñ�" << endl;
        cout << endl << "�������ѡ���ܣ�" << endl;
        cin >> menu;

        switch (menu) {
        case '1':
            search(link);
            break;
        case '2':
            screen(link);
            break;
        case '3':
            insert(link);
            break;
        case '4':
            remove(link);
            break;
        case '5':
            system("cls");
            link.printList();
            break;
        case '6':
            link.clear();
            if (link.empty()) {
                system("cls");
                cout << "���óɹ���" << endl;
                pause();
                goto reset;
            }
            break;
        default:
            system("cls");
            cout << "�������" << endl;
            cout << "�����������" << endl;
            pause();
        }
    }
}