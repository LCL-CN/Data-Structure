#include"ʵ����-������ͼ.h"
#include<iostream>
using namespace std;
int main(){
	Graph g;
	cout << endl << endl;
	cout << "��ȱ������У�" << endl;
	g.bfTraverse(0);
	cout << endl << endl;
	cout << "��ȱ������У�" << endl;
	g.dfTraverse(0);
	cout << endl << endl;
	cout << "Prim��С����������1�Ŷ���Ϊʼ����" << endl;
	g.mst_Prim(1);
	cout << endl << endl;
	cout << "Kruskal��С������" << endl;
	g.mst_Kruskal();
	cout << endl << endl;
	cout << "Dijkstra���·����2�Ŷ���Ϊʼ����" << endl;
	g.sp_Dijkstra(2);
}