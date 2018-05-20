#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include "Dijkstra.h"
#include "PQ.h"

int main() {
	Graph g = newGraph(4);
	AdjList p;
	int size, i;
	insertEdge(g, 0, 1, 11);
	insertEdge(g, 0, 2, 22);
	insertEdge(g, 0, 3, 33);
	insertEdge(g, 2, 3, 10);

	ShortestPaths sp = dijkstra(g, 0);
	printf("scr: %d\n", sp.src);
	for (i = 0; i < sp.noNodes; i++) {
		if (i == sp.src) continue;
		printf("dst: %d, cost: %d\n", i, sp.dist[i]);
	}

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