// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "graph.h"
#include "stdio.h"
#include "iostream"
using namespace std;

int main()
{
	Graph g(6,6);
	cout << g.V();
	ShortestPath sp(g);
	cout << sp.vertices();
	
	system("pause");
    return 0;
}

