#ifndef MANUTENZIONECONDOMINIO_PSD_QUEUE_H
#define MANUTENZIONECONDOMINIO_PSD_QUEUE_H

#include "../include/item.h"

typedef struct c_queue *queue;

queue newQueue(void);
int emptyQueue(queue q);
item dequeue(queue q);
int enqueue(queue q, item val);

#endif