// Graph ADT interface for Ass2 (COMP2521)
#include "CentralityMeasures.h"
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 99999999

//typedef struct GraphRep {
//	AdjList adj;
//	int vNum;
//	int eNum;
//}GraphRep;

NodeValues outDegreeCentrality(Graph g){
	NodeValues outD;
	AdjList p;
	outD.noNodes = g->vNum;
	outD.values = malloc(sizeof(double)*outD.noNodes);
	int i, j;
	for (i = 0; i < outD.noNodes; i++) {
		j = 0;
		p = &g->adj[i];
		while (p->next != NULL)
		{
			j++;
			p = p->next;
		}
		outD.values[i] = j / (double) (outD.noNodes - 1);
	}
	return outD;
}

NodeValues inDegreeCentrality(Graph g){
	NodeValues inD;
	AdjList p;
	inD.noNodes = g->vNum;
	inD.values = malloc(sizeof(double)*inD.noNodes);
	int i, j, k;
	for (i = 0; i < inD.noNodes; i++) {
		k = 0;
		//printf("Calc node: %d\n", i);
		for (j = 0; j < inD.noNodes; j++) {
			if (j == i) continue;
			// printf("Scan node: %d\n", j);
			p = &g->adj[j];
			while (p->next != NULL) {
				p = p->next;
				// printf("edge w: %d, weight: %d\n", p->w, p->weight);
				if (p->w == i) {
					// printf("Found node %d and in %lf\n", i, k);
					k++;
					continue;
				}
			}
		}
		inD.values[i] = k / (double) (inD.noNodes - 1);
		// printf("Node: %d, in: %lf\n", i, inD.values[i]);
	}
	return inD;
}
NodeValues degreeCentrality(Graph g) {
	NodeValues throwAway = {0};
	return throwAway;
}

NodeValues closenessCentrality(Graph g){
	NodeValues closeCent;
	ShortestPaths sp;
	int i, j, n;
	closeCent.noNodes = g->vNum;
	closeCent.values = malloc(sizeof(double)*closeCent.noNodes);
	for (i = 0; i < closeCent.noNodes; i++) {
		closeCent.values[i] = 0;
	}

	for (i = 0; i < closeCent.noNodes; i++) {
		sp = dijkstra(g, i);
		n = 0;
		for (j = 0; j < closeCent.noNodes; j++) {
			if (j == i) continue;
			if (sp.dist[j] != MAX) {
				closeCent.values[i] += sp.dist[j];
				n++;
			}
		}
		closeCent.values[i] = (double)(n*n) / (double)(closeCent.values[i] * (closeCent.noNodes - 1));
	}
	return closeCent;
}

NodeValues betweennessCentrality(Graph g){
	NodeValues throwAway = {0};
	return throwAway;
}

NodeValues betweennessCentralityNormalised(Graph g){
	NodeValues throwAway = {0};
	return throwAway;
}

void showNodeValues(NodeValues values){

}

void freeNodeValues(NodeValues values){

}
