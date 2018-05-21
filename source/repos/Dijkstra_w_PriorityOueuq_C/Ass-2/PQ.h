// PQ ADT interface for Ass2 (COMP2521)
#include <stdbool.h>

typedef struct ItemPQ {
	int key;
	int value;
} ItemPQ;

typedef struct PQRep {
	ItemPQ itm;
	struct PQRep *next;
} PQRep;

typedef struct PQRep *PQ;

/* Creates new priority queue, that can store items of type ItemPQ.
*/
PQ newPQ();

/* Adds item (ItemPQ) to the priority queue.
If an item with 'key' exists, it's 'value' is updated.
*/
void addPQ(PQ pq, ItemPQ itm);

/* Removes and returns the item (ItemPQ) with smallest 'value'.
For items with equal 'value', observes FIFO.
Returns null if this queue is empty.
*/
ItemPQ dequeuePQ(PQ pq);

/* Updates item with a given 'key' value, by updating that item's value to the given 'value'.
If item with 'key' does not exist in the queue, no action is taken
*/
void updatePQ(PQ pq, ItemPQ itm);

int PQEmpty(PQ pq);

void  showPQ(PQ pq);
void  freePQ(PQ pq);