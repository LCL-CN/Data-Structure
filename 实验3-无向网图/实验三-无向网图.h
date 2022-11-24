#pragma once
#include <string>
using namespace std;
const int MaxSize = 10;

struct Stack {
	int data[MaxSize];
	int top;
};
struct Quene {
	int data[MaxSize];
	int front, rear;
};

struct MinEdge {
	int adjex;
	double lowcost;
};
struct LowEdge {
	int i;
	int j;
};
class Graph {
public:
	Graph();
	~Graph() {};
	void bfTraverse(int v);
	void dfTraverse(int v);
	void mst_Prim(int v);
	void mst_Kruskal();
	void sp_Dijkstra(int v);
private:
	void clearVisited();
	int vertexNum;
	int edgeNum;
	bool visited[MaxSize];
	int edge[MaxSize][MaxSize];
	string vertex[MaxSize];
};

int shortEdge(MinEdge m[MaxSize], int vertexNum);