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
	PQ node, temp = pq;
	while (temp->next != NULL && temp->next->itm.key != itm.key && temp->next->itm.value <= itm.value) {
		temp = temp->next;
	}
	if (temp->next == NULL) {
		node = malloc(sizeof(PQRep) * 1);
		node->itm = itm;
		node->next = NULL;
		temp->next = node;
	}
	else if (temp->next->itm.key == itm.key) {
		temp->next->itm.value = itm.value;
	}
	else {
		node = malloc(sizeof(PQRep) * 1);
		node->itm = itm;
		node->next = temp->next;
		temp->next = node;
	}
}

/* Removes and returns the item (ItemPQ) with smallest 'value'.
For items with equal 'value', observes FIFO.
Returns null if this queue is empty.
*/
ItemPQ dequeuePQ(PQ pq) {
	ItemPQ itm = pq->next->itm;
	pq->next = pq->next->next;
	return itm;
}

/* Updates item with a given 'key' value, by updating that item's value to the given 'value'.
If item with 'key' does not exist in the queue, no action is taken
*/
void updatePQ(PQ pq, ItemPQ itm) {
	PQ temp = pq, q;
	while (temp->next != NULL && temp->next->itm.key != itm.key) {
		temp = temp->next;
	}
	if (temp->next != NULL) { // found vertex to update
		q = temp->next;
		temp->next = temp->next->next;
		addPQ(pq, itm);
	}
}

int PQEmpty(PQ pq) {
	if (pq->next == NULL) {
		return 1;
	}
	return 0;
}

void  showPQ(PQ pq) {

}
void  freePQ(PQ pq) {

}