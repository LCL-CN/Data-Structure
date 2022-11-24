#include"实验三-无向网图.h"
#include<iostream>
using namespace std;
int main(){
	Graph g;
	cout << endl << endl;
	cout << "广度遍历序列：" << endl;
	g.bfTraverse(0);
	cout << endl << endl;
	cout << "深度遍历序列：" << endl;
	g.dfTraverse(0);
	cout << endl << endl;
	cout << "Prim最小生成树（以1号顶点为始）：" << endl;
	g.mst_Prim(1);
	cout << endl << endl;
	cout << "Kruskal最小生成树" << endl;
	g.mst_Kruskal();
	cout << endl << endl;
	cout << "Dijkstra最短路径（2号顶点为始）：" << endl;
	g.sp_Dijkstra(2);
}