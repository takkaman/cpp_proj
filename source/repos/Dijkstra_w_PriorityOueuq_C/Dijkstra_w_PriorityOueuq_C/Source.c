#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include "Graph.h"
#include "PQ.h"

int main() {
	Graph g = newGraph(3);
	printf("%d", g->adj[0].w);
	system("pause");
	return 0;
}