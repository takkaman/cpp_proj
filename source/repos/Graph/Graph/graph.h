#pragma once
#include "String"
#include "vector"
#include "cstdio"
#include "map"
#include "iostream"
using namespace std;

#define INF 99999999

class Edge {

};

class Vertex {
public:
	int value;
};

class Graph {
public:
	int **adjMatrix;

	Graph(int v, int e) {
		this->numV = v;
		numE = e;
		adjMatrix = new int*[v];
		// init adjacent matrix
		for (int i = 0; i < v; i++) {
			adjMatrix[i] = new int[v];
			for (int j = 0; j < v; j++) {
				adjMatrix[i][j] = INF;
			}
		}
		// init vecrot and index map
		iToV = new Vert[numV];
		for (int i = 0; i < numV; i++) {
			iToV[i] = new Vertex();
		}

	}

	int V() {
		return this->numV;
	}

	int E() {
		return numE;
	}

	bool adjacent(int x, int y) {
		if (adjMatrix[x][y] < INF) return true;
		return false;
	}

	vector<int> neighbors(int x) {
		vector<int> nb;
		for (int i = 0; i < numV; i++) {
			if (adjMatrix[x][i] < INF) {
				nb.push_back(i);
			}
		}
		return nb;
	}

	int remove(int x, int y) {
		if (x < numV && y < numV) {
			adjMatrix[x][y] = INF;
			return 1;
		}
		printf("Vertice %d or %d not in graph.", x, y);
		return 0;
	}

	int add(int x, int y) {
		if (x < numV && y < numV) {
			adjMatrix[x][y] = 1;
			return 1;
		}
		printf("Vertice %d or %d not in graph.", x, y);
		return 0;
	}

	int get_node_value(int x) {
		if (x >= numV) {
			printf("Vertice %d not in graph.", x);
			return 0;
		}
		return iToV[x]->value;
	}

	int set_node_value(int x, int a) {
		if (x >= numV) {
			printf("Vertice %d not in graph.", x);
			return 0;
		}
		iToV[x]->value = a;
		return 1;
	}

	int get_edge_value(int x, int y) {
		return adjMatrix[x][y];
	}

	void set_edge_value(int x, int y, int v) {
		adjMatrix[x][y] = v;
	}
	

private:
	int numV;
	int numE;
	typedef Vertex* Vert;
	Vert *iToV;
};

class ShortestPath {
public:
	int vertices() {
		return this->g->V();
	}

	void hello() {
		int i = 0;
	}

	ShortestPath(Graph &g1) {
		g = &g1;
	}

private:
	Graph *g;
};