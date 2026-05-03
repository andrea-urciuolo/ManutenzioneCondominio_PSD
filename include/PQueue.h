#ifndef PQUEUE_H
#define PQUEUE_H

#include "../include/request.h"

typedef struct c_PQ *PQueue;

// Initializes and returns a new empty PQueue
PQueue newPQ(void);

// Returns 1 if the PQueue is empty, 0 otherwise
int emptyPQ(PQueue q);

// Returns a pointer to the request with the highest urgency
request getMax(PQueue q);

// Removes the highest urgency request from the PQueue. Returns 1 if successful, 0 otherwise
int deleteMax(PQueue q);

// Inserts a new request pointer into the PQueue. Returns 1 if successful, 0 otherwise
int insert(PQueue q, request r);

// Deallocates the PQueue (does not free the requests)
void deallocatePQ(PQueue q);

#endif
