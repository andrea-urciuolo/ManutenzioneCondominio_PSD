#ifndef PQUEUE_H
#define PQUEUE_H

#include "../include/request.h"

typedef struct c_PQ *PQueue;

PQueue newPQ(void);
int emptyPQ(PQueue q);
request* getMax(PQueue q);
int deleteMax(PQueue q);
int insert(PQueue q, request* r);

#endif
