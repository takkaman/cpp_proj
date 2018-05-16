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

void insertEdge(Graph g, Vertex src, Vertex dest, int weight) {
	// wrong method
	//adjListNode d, *p;
	//p = &g->adj[src];
	//d.w= dest;
	//d.weight = weight;
	//d.next = NULL;
	//while (p->next != NULL) {
	//	p = p->next;
	//}
	//p->next = &d;

	// correct method
	AdjList d, p;
	d = malloc(sizeof(adjListNode));
	p = &g->adj[src];
	d->w = dest;
	d->weight = weight;
	d->next = NULL;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = d;
}

void removeEdge(Graph g, Vertex src, Vertex dest) {
	AdjList p, tmp;
	p = &g->adj[src];
	while (p->next->w != dest) {
		p = p->next;
	}
	tmp = p->next;
	p->next = p->next->next;
	free(tmp);
}
bool adjacent(Graph g, Vertex src, Vertex dest) {
	AdjList p = &g->adj[src];
	while (p != NULL) {
		if (p->w == dest) {
			return true;
		}
	}
	return false;
}

int numVerticies(Graph g) {
	return g->vNum;
}

/* Returns a list of adjacent vertices
on outgoing edges from a given vertex.
*/
AdjList outIncident(Graph g, Vertex v) {
	return g->adj[v].next;
}

/* Returns a list of adjacent vertices
on incoming edges from a given vertex.
*/
AdjList inIncident(Graph g, Vertex v) {
	AdjList p, q, result = NULL;
	int i;
	for (i = 0; i < numVerticies(g); i++) {
		if (i == v) continue;
		p = &g->adj[i];
		while (p->next != NULL) {
			if (p->next->w == v) {
				q = malloc(sizeof(adjListNode));
				q->w = i;
				q->weight = p->next->weight;
				q->next = result;
				result = q;
				break;
			}
			p = p->next;
		}
	}
	return result;
}

//void  showGraph(Graph g);
//void  freeGraph(Graph g);