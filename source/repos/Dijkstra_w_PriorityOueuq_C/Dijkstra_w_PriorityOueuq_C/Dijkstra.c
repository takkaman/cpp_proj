#include "Dijkstra.h"
#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 99999999

ShortestPaths dijkstra(Graph g, Vertex v) {
	ShortestPaths sp;
	ItemPQ itm, dst;
	AdjList p;
	int i, newDist;
	sp.src = v;
	sp.noNodes = g->vNum;
	sp.dist = malloc(sizeof(int)*sp.noNodes);
	for (i = 0; i < sp.noNodes; i++) {
		if (i == sp.src) continue;
		sp.dist[i] = MAX;
	}
	sp.pred = malloc(sizeof(PredNode)*sp.noNodes);
	sp.dist[sp.src] = 0;
	PQ pq = newPQ();
	itm.key = sp.src;
	itm.value = sp.dist[sp.src];
	addPQ(pq, itm);
	while (!PQEmpty(pq)) {
		printf("here");
		itm = dequeuePQ(pq);
		p = &g->adj[itm.key]; // get all neighbor edge of vertex itm.key
		while (p->next != NULL) {
			dst.key = p->next->w; // dst
			dst.value = p->next->weight;
			printf("scan dst: %d, weight: %d\n", dst.key, dst.value);
			newDist = sp.dist[itm.key] + dst.value;
			if (sp.dist[dst.key] > newDist) {
				updatePQ(pq, dst);
				sp.dist[dst.key] = newDist;
				addPQ(pq, dst);
			}
			p = p->next;
		}
	}
	return sp;
}

void  showShortestPaths(ShortestPaths sp) {

}

void  freeShortestPaths(ShortestPaths sp) {

}