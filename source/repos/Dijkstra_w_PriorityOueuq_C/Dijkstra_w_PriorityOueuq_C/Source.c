#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include "Graph.h"
#include "PQ.h"

int main() {
	Graph g = newGraph(3);
	AdjList p;
	int size, i;
	insertEdge(g, 0, 1, 11);
	insertEdge(g, 0, 2, 22);
	insertEdge(g, 0, 3, 33);
	
	printf("Init List\n");
	for (i = 0; i < numVerticies(g); i++) {
		printf("Vertex: %d\n", g->adj[i].w);
	}

	printf("Scan List\n");
	p = &g->adj[0];
	while (p != NULL) {
		printf("node: %d, weight: %d\n", p->w, p->weight);
		p = p->next;
	}
	removeEdge(g, 0, 2);
	p = &g->adj[0];
	printf("Remove List\n");
	while (p->next != NULL) {
		printf("Node: %d, weight: %d\n", p->next->w, p->next->weight);
		p = p->next;
	}

	printf("Out Inc\n");
	p = outIncident(g, 0);
	while (p != NULL) {
		printf("Node: %d, weight: %d\n", p->w, p->weight);
		p = p->next;
	}

	printf("In Inc\n");
	p = inIncident(g, 1);
	while (p != NULL) {
		printf("Node: %d, weight: %d\n", p->w, p->weight);
		p = p->next;
	}
	system("pause");
	return 0;
}