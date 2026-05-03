#include <stdio.h>
#include <stdlib.h>
#include "../include/PQueue.h"
#include "../include/request.h"

#define INITIAL_CAPACITY_PQ 50

struct c_PQ {
    request* vet;                               // Dynamic array of requests
    int numel;                                  // Number of elements in the PQueue
    int capacity;                               // Max capacity at the moment
};

static void down(PQueue q);
static void up(PQueue q);

PQueue newPQ() {
    PQueue q = malloc(sizeof(struct c_PQ));
    if (q == NULL) return NULL;
    q->numel = 0;
    q->capacity = INITIAL_CAPACITY_PQ;

    // I allocate capacity +1 to allow the second element [i = 1] to be the root of the PQueue
    q->vet = malloc((q->capacity + 1) * sizeof(request));

    if (q->vet == NULL) {
        free(q);
        return NULL;
    }

    return q;
}

int emptyPQ(PQueue q) {
    if (q == NULL) return 1;
    return q->numel == 0;
}

request getMax(PQueue q) {
    if (emptyPQ(q)) return NULL;
    return q->vet[1];
}

static void down(PQueue q) {
    int i = 1;
    int n = q->numel;
    while (2 * i <= n) {
        int j = 2 * i;
        if (j < n && getUrgency(q->vet[j+1]) > getUrgency(q->vet[j])) {
            j++;
        }
        if (getUrgency(q->vet[i]) >= getUrgency(q->vet[j])) {
            break;
        }

        request temp = q->vet[i];
        q->vet[i] = q->vet[j];
        q->vet[j] = temp;
        i = j;
    }
}

static void up(PQueue q) {
    int pos = q->numel;
    while (pos > 1) {
        int root = pos / 2;
        if (getUrgency(q->vet[pos]) > getUrgency(q->vet[root])) {
            request temp = q->vet[root];
            q->vet[root] = q->vet[pos];
            q->vet[pos] = temp;
            pos = root;
        } else {
            break;
        }
    }
}

int deleteMax(PQueue q) {
    if (emptyPQ(q)) return 0;

    q->vet[1] = q->vet[q->numel];
    (q->numel)--;

    if (q->numel > 1) {
        down(q);
    }

    return 1;
}

int insert(PQueue q, request r) {
    if (q == NULL) return 0;

    // Check if the array is full
    if (q->numel == q->capacity) {
        int newCapacity = q->capacity * 2;
        request* newVet = realloc(q->vet, (newCapacity + 1) * sizeof(request));
        if (newVet == NULL) return 0;
        q->vet = newVet;
        q->capacity = newCapacity;
    }


    (q->numel)++;
    q->vet[q->numel] = r;
    up(q);

    return 1;
}

void deallocatePQ(PQueue q) {
    if (q == NULL) return;
    free(q->vet);
    free(q);
}