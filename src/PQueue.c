#include <stdio.h>
#include <stdlib.h>
#include "Pqueue.h"

#define MAXPQ 50

struct c_PQ {
    int vet[MAXPQ];
    int numel;
};

static void scendi(PQueue q);
static void sali(PQueue q);

PQueue newPQ() {
    PQueue q = malloc(sizeof(struct c_PQ));
    if (q == NULL) return NULL;
    q->numel = 0;

    return q;
}

int emptyPQ(PQueue q) {
    if (q == NULL) return 1;
    return q->numel == 0;
}

int getMax(PQueue q) {
    return q->vet[1];
}

static void scendi(PQueue q) {
    int temp;
    int n = q->numel;
    int i = 1;
    int pos;

    while (1) {
        if (2*i+1 <= n) {
            pos = (q->vet[i*2] > q->vet[i*2+1]) ? i*2 : i*2+1;
        } else if (2*i <= n) {
            pos = 2*i;
        } else {
            break;
        }

        if (q->vet[pos] > q->vet[i]) {
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            i = pos;
        } else {
            break;
        }
    }
}

static void sali(PQueue q) {
    int temp;
    int pos = q->numel;
    int i =  pos/2;

    while (pos > 1) {
        if (q->vet[pos] > q->vet[i]) {
            temp = q->vet[i];
            q->vet[i] = q->vet[pos];
            q->vet[pos] = temp;
            pos = i;
            i = pos/2;
        } else {
            break;
        }
    }
}

int deleteMax(PQueue q) {
    if (q == NULL) return 0;
    if (q->numel == 0) return 0;

    q->vet[1] = q->vet[q->numel];
    (q->numel)--;
    scendi(q);

    return 1;
}

int insert(PQueue q, int key) {
    if (q == NULL) return 0;
    if (q->numel == MAXPQ) return 0;

    (q->numel)++;
    q->vet[q->numel] = key;
    sali(q);

    return 1;
}