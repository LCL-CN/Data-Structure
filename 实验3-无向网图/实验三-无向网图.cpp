#include "实验三-无向网图.h"
#include <iostream>
using namespace std;
Graph::Graph()
{
	cout << "输入顶点数：" << endl;
	int vn;
	cin >> vn;
	vertexNum = vn;
	cout << "输入顶点：" << endl;
	string vert;
	for (int i = 0; i < vertexNum; ++i) {
		cin >> vert;
		vertex[i] = vert;
	}
	cout << "输入邻接矩阵：" << endl;
	int ed;
	edgeNum = 0;
	for (int i = 0; i < vertexNum; ++i) {
		for (int j = 0; j < vertexNum; ++j) {
			cin >> ed;
			if (ed == 0) {
				edge[i][j] = 0xFFFFFF;
			}
			else {
				edge[i][j] = ed;
				edgeNum++;
			}
		}
	}
	edgeNum /= 2;
}

void Graph::dfTraverse(int v)
{
	clearVisited();//清空访问标记
	Stack s;
	s.top = -1;
	cout << vertex[v] << " ";
	visited[v] = true;
	s.data[++s.top] = v;
	bool flag=0;
	while (s.top != -1) {
		flag = 0;
		v = s.data[s.top];//取栈顶元素
		//将其所有未访问邻接元素访问并入栈
		for (int w = 0; w < vertexNum; ++w) {
			if (edge[v][w] != 0xffffff && !visited[w]) {
				cout << vertex[w] << " ";
				visited[w] = true;
				s.data[++s.top] = w;
				flag = 1;
				break;
			}
		}
		//栈顶元素所有邻接元素都已访问，栈顶元素出栈
		if (!flag) {
			s.top--;
		}
	}
}

void Graph::bfTraverse(int v)
{
	clearVisited();
	Quene q;
	q.front = q.rear = -1;
	cout << vertex[v] << " ";
	visited[v] = true;
	q.data[++q.rear] = v;
	while (q.front != q.rear) {
		v = q.data[++q.front];
		for (int w = 0; w < vertexNum; ++w) {
			if (edge[v][w] != 0xffffff && !visited[w]) {
				cout << vertex[w] << " ";
				visited[w] = true;
				q.data[++q.rear] = w;
			}
		}
	}
}

void Graph::mst_Prim(int v)
{
	MinEdge minEdge[MaxSize];
	//初始化
	for (int i = 0; i < MaxSize;++i) {
		minEdge[i].lowcost = edge[v][i];
		minEdge[i].adjex = v;
	}
	//顶点v加入U
	minEdge[v].lowcost = 0;
	for (int i = 1; i < vertexNum; ++i) {
		//寻找U-(V-U)最小花费
		v = shortEdge(minEdge, vertexNum);
		//输出边
		cout << vertex[minEdge[v].adjex] << " " << vertex[v] << " " << minEdge[v].lowcost << endl;
		//顶点v加入U
		minEdge[v].lowcost = 0;
		for (int i = 0; i < vertexNum; ++i) {
			if (edge[v][i] < minEdge[i].lowcost) {
				minEdge[i].lowcost = edge[v][i];
				minEdge[i].adjex = v;
			}
		}
	}
}

void Graph::mst_Kruskal()
{
	//初始化
	int parent[MaxSize];
	for (int i = 0; i < MaxSize; ++i) {
		parent[i] = -1;
	}
	LowEdge lowedge[MaxSize * (MaxSize - 1) / 2]{};
	int num = 0;
	for (int i = 0; i < vertexNum; ++i) {
		for (int j = i; j < vertexNum; ++j) {
			if (edge[i][j] < 0xFFFFF) {
				lowedge[num].i = i;
				lowedge[num].j = j;
				num++;
			}
		}
	}
	//选择排序
	LowEdge temp;
	int k=0;
	for (int i = 0; i < edgeNum; ++i) {
		k = i;
		for (int j = i+1; j < edgeNum ; ++j) {
			if (edge[lowedge[j].i][lowedge[j].j] < edge[lowedge[k].i][lowedge[k].j])
				k = j;
		}
		if (k != i) {
			temp = lowedge[i];
			lowedge[i] = lowedge[k];
			lowedge[k] = temp;
		}
	}
	//最小生成树
	int lnum = vertexNum;//连通分量数目
	int ednum = 0;//最小边序号
	int u, v;
	while (lnum > 1) {
		u = lowedge[ednum].i;
		v = lowedge[ednum].j;
		while (parent[u] != -1)u = parent[u];
		while (parent[v] != -1)v = parent[v];
		if (u != v) {
			parent[v] = u;
			cout << vertex[lowedge[ednum].i] << " " << vertex[lowedge[ednum].j] << " " << edge[lowedge[ednum].i][lowedge[ednum].j] << endl;
			lnum--;
		}
		ednum++;
	}	
}

void Graph::sp_Dijkstra(int v)
{
	int dis[MaxSize];
	string path[MaxSize];
	for (int i = 0; i < vertexNum; ++i) {
		dis[i] = edge[v][i];
		if (dis[i] != 0xffffff) {
			path[i] = vertex[v] + "-" + vertex[i];
		}
	}
	dis[v] = 0;
	int num = 1;
	int k = 0;
	while (num < vertexNum) {
		k = 0;
		while (dis[k] == 0)k++;
		for (int i = 0; i < vertexNum; ++i) {
			if (dis[i] != 0 && dis[i] < dis[k]) {
				k = i;
			}
		}
		num++;
		cout << path[k] << "\t" << dis[k] << endl;
		for (int i = 0; i < vertexNum; ++i) {
			if (dis[i] > dis[k] + edge[k][i]) {
				dis[i] = dis[k] + edge[k][i];
				path[i] = path[k] + "-" + vertex[i];
			}
		}
		dis[k] = 0;
	}
}

void Graph::clearVisited()
{
	for (int i = 0; i < vertexNum; ++i) {
		visited[i] = false;
	}
}

int shortEdge(MinEdge m[MaxSize], int vertexNum)
{
	double min =0xffff;
	int rev=0;
	for (int i = 0; i < vertexNum; ++i) {
		if (m[i].lowcost != 0 && m[i].lowcost < min) {
			min = m[i].lowcost;
			rev = i;
		}
	}
	return rev;
}
