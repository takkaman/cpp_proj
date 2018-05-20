#include "PQ.h"
#include <stdio.h>
#include <stdlib.h>

/* Creates new priority queue, that can store items of type ItemPQ.
*/
PQ newPQ() {
	PQ pq = malloc(sizeof(PQRep)*1);
	pq->next = NULL;
	return pq;
}

/* Adds item (ItemPQ) to the priority queue.
If an item with 'key' exists, it's 'value' is updated.
*/
void addPQ(PQ pq, ItemPQ itm) {
	PQ node;
	while (pq->next != NULL) {
		pq = pq->next;
	}

	node = malloc(sizeof(PQRep) * 1);
	node->itm = itm;
	node->next = NULL;
	pq->next = node;
}

/* Removes and returns the item (ItemPQ) with smallest 'value'.
For items with equal 'value', observes FIFO.
Returns null if this queue is empty.
*/
ItemPQ dequeuePQ(PQ pq) {
	ItemPQ p;
	p.key = 3;
	return p;
}

/* Updates item with a given 'key' value, by updating that item's value to the given 'value'.
If item with 'key' does not exist in the queue, no action is taken
*/
void updatePQ(PQ pq, ItemPQ itm) {

}

int PQEmpty(PQ pq) {
	int i = 0;
	return i;
}

void  showPQ(PQ pq) {

}
void  freePQ(PQ pq) {

}