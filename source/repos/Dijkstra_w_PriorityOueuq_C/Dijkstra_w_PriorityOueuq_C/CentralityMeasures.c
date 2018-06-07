// Graph ADT interface for Ass2 (COMP2521)
#include "CentralityMeasures.h"
#include "Dijkstra.h"
#include "PQ.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX 99999999

// typedef struct GraphRep {
// 	AdjList adj;
// 	int vNum;
// 	int eNum;
// }GraphRep;

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
	NodeValues inoutD, inD, outD;
	int i;
	inD = inDegreeCentrality(g);
	outD = outDegreeCentrality(g);
	inoutD.noNodes = inD.noNodes;
	inoutD.values = malloc(sizeof(double)*inD.noNodes);
	for (i = 0; i < inoutD.noNodes; i++) {
		inoutD.values[i] = inD.values[i] + outD.values[i];
	}
	return inoutD;
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

int calcShortestPaths(NodeValues *betCent, ShortestPaths sp, int src, int dst, int vArr[]) {
	PredNode *p = sp.pred[dst];
	//printf("  1st pre node: %d\n", sp.pred[dst]->v);
	//printf("  1st pre node: %d\n", p->v);
	if (p == NULL) return 1;
	int ttl = 0;
	while (p != NULL) {
		// printf("  Scan pre node: %d\n", p->v);
		int subT = calcShortestPaths(betCent, sp, src, p->v, vArr);
		ttl += subT;
		if (p->v != src) {
			vArr[p->v] += subT;
		}
		p = p->next;
	}

	return ttl;
}

NodeValues betweennessCentrality(Graph g){
	NodeValues betCent;
	int i, j, k, ttl = 0;
	ShortestPaths sp;
	betCent.noNodes = g->vNum;
	betCent.values = malloc(sizeof(double)*betCent.noNodes);
	int *vArr = malloc(sizeof(int)*betCent.noNodes);
	for (i = 0; i < betCent.noNodes; i++) {
		betCent.values[i] = 0;
	}

	for (i = 0; i < betCent.noNodes; i++) {
		sp = dijkstra(g, i);
		// printf("Node %d\n", i);
		for (j = 0; j < betCent.noNodes; j++) {
			for (k = 0; k < betCent.noNodes; k++) {
				vArr[k] = 0;
			}
			if (j == i) continue;
			if (sp.dist[j] == 0) continue;
			// printf("Scan node %d\n", j);
			ttl = calcShortestPaths(&betCent, sp, i, j, vArr);
			// printf("Total %d paths between %d and %d\n", ttl, i, j);
			for (k = 0; k < betCent.noNodes; k++) {
				if (k == i || k == j) continue;
				// printf("Node %d contributes %d\n", k, vArr[k]);
				double b = (double)vArr[k] / (double)ttl;
				betCent.values[k] += b;
			}
		}
	}

	//for (i = 0; i < betCent.noNodes; i++) {
	//	betCent.values[i] = (double) betCent.values[i] / (double) ttl;
	//}

	return betCent;
}

NodeValues betweennessCentralityNormalised(Graph g){
	NodeValues betCentNorm = betweennessCentrality(g);
	double min = MAX, max = 0;
	int i = 0;
	for (i = 0; i < betCentNorm.noNodes; i++) {
		if (betCentNorm.values[i] > max) {
			max = betCentNorm.values[i];
		}
		if (betCentNorm.values[i] < min) {
			min = betCentNorm.values[i];
		}
	}
	for (i = 0; i < betCentNorm.noNodes; i++) {
		betCentNorm.values[i] = (betCentNorm.values[i] - min) / (max - min);
	}
	return betCentNorm;
}

void showNodeValues(NodeValues values) {
	int i = 0;
	for (i = 0; i < values.noNodes; i++) {
		printf("%d: %lf\n", i, values.values[i]);
	}
}

void freeNodeValues(NodeValues values){

}
