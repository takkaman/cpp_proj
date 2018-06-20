#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include "Dijkstra.h"
#include "PQ.h"
#include "CentralityMeasures.h"

void displayShortestPathsStruct(ShortestPaths sps) {
	int i = 0;
	printf("Node %d\n", sps.src);
	printf("  Distance\n");
	for (i = 0; i < sps.noNodes; i++) {
		if (i == sps.src)
			printf("    %d : X\n", i);
		else
			printf("    %d : %d\n", i, sps.dist[i]);
	}
	printf("  Preds\n");
	for (i = 0; i < sps.noNodes; i++) {
		printf("    %d : ", i);
		PredNode* curr = sps.pred[i];
		while (curr != NULL) {
			printf("[%d]->", curr->v);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

int main() {
	Graph g = newGraph(5);
	AdjList p;
	int size, i;
	insertEdge(g, 1, 2, 1);
	insertEdge(g, 2, 1, 10);
	insertEdge(g, 4, 2, 60);
	insertEdge(g, 3, 2, 6);
	insertEdge(g, 1, 4, 2);
	insertEdge(g, 2, 3, 1);
	insertEdge(g, 1, 0, 1);
	insertEdge(g, 0, 4, 2);
	insertEdge(g, 3, 4, 1);
	insertEdge(g, 3, 1, 5);

	for (i = 0; i<numVerticies(g); i++) {
		ShortestPaths paths = dijkstra(g, i);
		displayShortestPathsStruct(paths);
		freeShortestPaths(paths);
	}

	NodeValues outD = outDegreeCentrality(g);
	NodeValues inD = inDegreeCentrality(g);
	NodeValues closeCent = closenessCentrality(g);
	NodeValues betCent = betweennessCentrality(g);
	NodeValues betCentNorm = betweennessCentralityNormalised(g);
	printf("Out: %d, in: %d\n", outD.noNodes, inD.noNodes);
	for (i = 0; i < numVerticies(g); i++) {
		printf("Node: %d, out: %lf, in %lf, close: %lf, between: %lf, between norm: %lf\n", i, outD.values[i], inD.values[i], closeCent.values[i], betCent.values[i], betCentNorm.values[i]);
	}

	//printf("scr: %d\n", sp.src);
	//for (i = 0; i < sp.noNodes; i++) {
	//	if (i == sp.src) {
	//		printf("dst: %d, cost: X\n", i);
	//	}
	//	else {
	//		printf("dst: %d, cost: %d\n", i, sp.dist[i]);
	//	}
	//}
	//PredNode *pn;
	//for (i = 0; i < g->vNum; i++) {
	//	printf("%d : ", i);
	//	if (i == src) {
	//		printf("NULL\n");
	//		continue;
	//	}

	//	pn = sp.pred[i];
	//	while (pn != NULL) {
	//		printf("[%d] -> ", pn->v);
	//		pn = pn->next;
	//	}
	//	printf("NULL\n");
	//}
	//PQ pq = newPQ(), temp;
	//ItemPQ itm, dq;
	//itm.key = 1;
	//itm.value = 8;
	//addPQ(pq, itm);
	//itm.key = 2;
	//itm.value = 6;
	//addPQ(pq, itm);
	//itm.key = 3;
	//itm.value = 7;
	//addPQ(pq, itm);
	//itm.value = 9;
	//updatePQ(pq, itm);
	////printf("key: %d, val: %d\n", itm.key, itm.value);
	//temp = pq;
	//while (temp->next != NULL) {
	//	printf("key: %d, val: %d\n", temp->next->itm.key, temp->next->itm.value);
	//	temp = temp->next;
	//}
	//while (!PQEmpty(pq)) {
	//	dq = dequeuePQ(pq);
	//	printf("Dequeue key: %d, val: %d\n", dq.key, dq.value);
	//	temp = pq;
	//	while (temp->next != NULL) {
	//		printf("key: %d, val: %d\n", temp->next->itm.key, temp->next->itm.value);
	//		temp = temp->next;
	//	}
	//}
	
	//printf("Init List\n");
	//for (i = 0; i < numVerticies(g); i++) {
	//	printf("Vertex: %d\n", g->adj[i].w);
	//}

	//printf("Scan List\n");
	//p = &g->adj[0];
	//while (p != NULL) {
	//	printf("node: %d, weight: %d\n", p->w, p->weight);
	//	p = p->next;
	//}
	//removeEdge(g, 0, 2);
	//p = &g->adj[0];
	//printf("Remove List\n");
	//while (p->next != NULL) {
	//	printf("Node: %d, weight: %d\n", p->next->w, p->next->weight);
	//	p = p->next;
	//}

	//printf("Out Inc\n");
	//p = outIncident(g, 0);
	//while (p != NULL) {
	//	printf("Node: %d, weight: %d\n", p->w, p->weight);
	//	p = p->next;
	//}

	//printf("In Inc\n");
	//p = inIncident(g, 1);
	//while (p != NULL) {
	//	printf("Node: %d, weight: %d\n", p->w, p->weight);
	//	p = p->next;
	//}
	system("pause");
	return 0;
}