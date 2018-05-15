#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph newGraph(int noNodes) {
	Graph g = malloc(sizeof(Graph)*1);
	int i;
	g->adj = malloc(sizeof(adjListNode)*noNodes);
	g->vNum = noNodes;
	for (i = 0; i < noNodes; i++) {
		g->adj[i].w = i;
		g->adj[i].weight = 0;
		g->adj[i].next = NULL;
	}
	return g;
}
//
//void insertEdge(Graph g, Vertex src, Vertex dest, int weight) {
//	adjListNode d, *p;
//	p = &g->adj[src];
//	d.w = dest;
//	d.weight = weight;
//	while (p->next != NULL) {
//		p = p->next;
//	}
//	p->next = &d;
//}
//void removeEdge(Graph g, Vertex src, Vertex dest);
//bool adjacent(Graph g, Vertex src, Vertex dest);
//int numVerticies(Graph g);
//
//
///*
//* Returns a list of adjacent vertices
//* on outgoing edges from a given vertex.
//**/
//AdjList outIncident(Graph g, Vertex v);
///*
//
//* Returns a list of adjacent vertices
//* on incoming edges from a given vertex.
//**/
//AdjList inIncident(Graph g, Vertex v);
//
//void  showGraph(Graph g);
//void  freeGraph(Graph g);