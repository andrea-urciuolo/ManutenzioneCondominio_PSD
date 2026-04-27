#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

struct node {
    item value;
    struct node* next;
};

struct c_queue {
    struct node* head;
    struct node* tail;
    int numEl;
};


queue newQueue() {
    struct c_queue *q = malloc(sizeof(struct c_queue));
    if (q == NULL) return NULL;

    q->numEl = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}


int emptyQueue(queue q) {
    if (q == NULL) return -1;
    return q->numEl == 0;
}


int enqueue(queue q, item val) {
    if (q == NULL) return -1;

    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL) return 0;
    newNode->value = val;
    newNode->next = NULL;

    if (q->head == NULL) q->head = newNode;
    else q->tail->next = newNode;

    q->tail = newNode;
    (q->numEl)++;

    return 1;
}


item dequeue(queue q) {
    if (q == NULL) return NULLITEM;
    if (q->numEl == 0) return NULLITEM;

    item result = q->head->value;
    struct node* tmp = q->head;
    q->head = q->head->next;
    free(tmp);

    if (q->head == NULL) q->tail = NULL;

    (q->numEl)--;

    return result;
}