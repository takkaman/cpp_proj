#include "Dijkstra.h"
#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 99999999
#define MAX_PATH 200

//typedef struct GraphRep {
//	AdjList adj;
//	int vNum;
//	int eNum;
//}GraphRep;

ShortestPaths dijkstra(Graph g, Vertex v) {
	ShortestPaths sp;
	ItemPQ itm, dst;
	AdjList p;
	PredNode *pd;
	int i, newDist;
	sp.src = v;
	sp.noNodes = g->vNum;
	sp.dist = malloc(sizeof(int)*sp.noNodes);
	sp.pred = malloc(sizeof(PredNode*)*sp.noNodes);
	for (i = 0; i < sp.noNodes; i++) {
		sp.dist[i] = MAX;
		sp.pred[i] = NULL;
	}
	// printf("test pre: %d\n", sp.pred[1][0].v);
	sp.dist[sp.src] = 0;
	PQ pq = newPQ();
	itm.key = sp.src;
	itm.value = sp.dist[sp.src];
	addPQ(pq, itm);
	while (!PQEmpty(pq)) {
		// printf("here");
		itm = dequeuePQ(pq);
		// printf("pop out vertex: %d\n", itm.key);
		p = &g->adj[itm.key]; // get all neighbor edge of vertex itm.key
		while (p->next != NULL) {
			dst.key = p->next->w; // dst
			dst.value = p->next->weight;
			// printf("scan dst: %d, weight: %d\n", dst.key, dst.value);
			newDist = sp.dist[itm.key] + dst.value;
			if (sp.dist[dst.key] > newDist) {
				updatePQ(pq, dst);
				sp.dist[dst.key] = newDist;
				addPQ(pq, dst);
				// printf("test: %d\n", sp.pred[itm.key][0].v);
				//if (sp.pred[itm.key] == NULL) {
				sp.pred[dst.key] = malloc(sizeof(PredNode));
				sp.pred[dst.key]->v = itm.key;
				sp.pred[dst.key]->next = NULL;
				//}
				//else {
				//	for (i = 0; i < MAX_PATH; i++) {
				//		sp.pred[dst.key][i].v = -1;
				//		sp.pred[dst.key][i].next = NULL;
				//	}
				//	i = 0;
				//	while (sp.pred[itm.key][i].v != -1) {
				//		sp.pred[dst.key][i].v = itm.key;
				//		sp.pred[dst.key][i].next = &sp.pred[itm.key][i];
				//		i++;
				//	}
				//}
			}
			else if (sp.dist[dst.key] == newDist) {
				pd = sp.pred[dst.key];
				while (pd->next != NULL) {
					pd = pd->next;
				}
				pd->next = malloc(sizeof(PredNode));
				pd->next->v = itm.key;
				pd->next->next = NULL;
			}
			p = p->next;
		}
	}
	for (i = 0; i < sp.noNodes; i++) {
		if (sp.dist[i] == MAX) {
			sp.dist[i] = 0;
		}
	}
	return sp;
}

void  showShortestPaths(ShortestPaths sp) {

}

void  freeShortestPaths(ShortestPaths sp) {

}