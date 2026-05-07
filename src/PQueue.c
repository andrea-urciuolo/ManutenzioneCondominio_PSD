#include <stdio.h>
#include <stdlib.h>
#include "../include/PQueue.h"
#include "../include/request.h"

// Default starting capacity for the dynamic array
#define INITIAL_CAPACITY_PQ 50

// Concrete structure representing the Priority Queue (implemented as a Max-Heap)
struct c_PQ {
    request* vet;                               // Dynamic array of requests
    int numel;                                  // Current number of elements in the PQueue
    int capacity;                               // Max capacity at the moment before reallocation is needed
};

/* Internal utility functions for heap maintenance (Hidden from the outside) */
static void down(PQueue q);
static void up(PQueue q);

// Allocates and initializes a new empty Priority Queue
PQueue newPQ() {
    PQueue q = malloc(sizeof(struct c_PQ));
    if (q == NULL) return NULL;
    
    q->numel = 0;
    q->capacity = INITIAL_CAPACITY_PQ;

    // I allocate capacity +1 to allow the second element [i = 1] to be the root of the PQueue.
    // Index 0 is intentionally left unused to simplify parent-child index calculations.
    q->vet = malloc((q->capacity + 1) * sizeof(request));

    if (q->vet == NULL) {
        free(q);
        return NULL;
    }

    return q;
}

// Checks if the Priority Queue is empty or uninitialized
int emptyPQ(PQueue q) {
    if (q == NULL) return 1;
    return q->numel == 0;
}

// Returns the element with the highest urgency (the root of the Max-Heap) without removing it
request getMax(PQueue q) {
    if (emptyPQ(q)) return NULL;
    return q->vet[1];
}

// Heapify-down procedure: restores the Max-Heap property from top to bottom
static void down(PQueue q) {
    int i = 1;
    int n = q->numel;
    
    // While the current node has at least a left child
    while (2 * i <= n) {
        int j = 2 * i; // Left child index
        
        // If the right child exists and has a higher urgency than the left child, select the right child
        if (j < n && getUrgency(q->vet[j+1]) > getUrgency(q->vet[j])) {
            j++;
        }
        
        // If the current node's urgency is greater than or equal to the largest child, the heap is valid
        if (getUrgency(q->vet[i]) >= getUrgency(q->vet[j])) {
            break;
        }

        // Otherwise, swap the current node with the largest child and continue sinking down
        request temp = q->vet[i];
        q->vet[i] = q->vet[j];
        q->vet[j] = temp;
        i = j;
    }
}

// Heapify-up procedure: restores the Max-Heap property from bottom to top
static void up(PQueue q) {
    int pos = q->numel;
    
    // While the current node is not the root
    while (pos > 1) {
        int root = pos / 2; // Parent index
        
        // If the current node has a higher urgency than its parent, swap them
        if (getUrgency(q->vet[pos]) > getUrgency(q->vet[root])) {
            request temp = q->vet[root];
            q->vet[root] = q->vet[pos];
            q->vet[pos] = temp;
            pos = root; // Move up to the parent's position
        } else {
            // If the parent is greater, the heap property is satisfied
            break;
        }
    }
}

// Removes the element with the highest urgency (the root) from the queue
int deleteMax(PQueue q) {
    if (emptyPQ(q)) return 0;

    // Replace the root with the last element in the heap
    q->vet[1] = q->vet[q->numel];
    (q->numel)--;

    // If there are still elements left, sink the new root down to its correct position
    if (q->numel > 1) {
        down(q);
    }

    return 1;
}

// Inserts a new request into the Priority Queue
int insert(PQueue q, request r) {
    if (q == NULL) return 0;

    // Check if the array is full. If so, double its capacity dynamically
    if (q->numel == q->capacity) {
        int newCapacity = q->capacity * 2;
        request* newVet = realloc(q->vet, (newCapacity + 1) * sizeof(request));
        if (newVet == NULL) return 0; // Reallocation failed
        q->vet = newVet;
        q->capacity = newCapacity;
    }

    // Insert the new element at the very end of the heap
    (q->numel)++;
    q->vet[q->numel] = r;
    
    // Float the new element up to its correct position to restore the Max-Heap property
    up(q);

    return 1;
}

// Frees all dynamically allocated memory for the Priority Queue
void deallocatePQ(PQueue q) {
    if (q == NULL) return;
    free(q->vet); // Free the underlying array
    free(q);      // Free the queue structure itself
}