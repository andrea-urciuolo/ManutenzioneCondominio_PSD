#ifndef PQUEUE_H
#define PQUEUE_H

#include "../include/request.h"

// Pointer to the PQueue structure
typedef struct c_PQ *PQueue;

/*
 * Function: newPQ
 * ----------------------
 * Allocates and initializes a new empty Priority Queue
 *
 * Parameters:
 *   None (void)
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns a pointer to a newly allocated PQueue structure.
 *
 * Side-effect:
 *   Allocates the memory needed for the PQueue structure.
 *
 * Returns:
 *   The newly created PQueue, or NULL if memory allocation fails
 */
PQueue newPQ(void);

/*
 * Function: emptyPQ
 * ----------------------
 * Checks if the priority queue is empty or uninitialized
 *
 * Parameters:
 *   q: The priority queue to check
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns 1 if the queue pointer is NULL or if the number of
 *   elements is 0; returns 0 otherwise.
 *
 * Returns:
 *   An int (1 for true, 0 for false) indicating if the queue is empty
 */
int emptyPQ(PQueue q);

/*
 * Function: getMax
 * ----------------------
 * Returns the element with the highest urgency without removing it
 *
 * Parameters:
 *   q: The priority queue to inspect
 *
 * Pre-conditions:
 *   q != NULL
 *   q must not be empty
 *
 * Post-conditions:
 *   Returns the request with the maximum urgency value.
 *
 * Returns:
 *   The request structure with the highest priority, or NULL if the
 *   queue is empty.
 */
request getMax(PQueue q);

/*
 * Function: deleteMax
 * ----------------------
 * Removes the element with the highest urgency from the queue
 *
 * Parameters:
 *   q: The priority queue from which to remove the element
 *
 * Pre-conditions:
 *   q != NULL
 *   q must not be empty
 *
 * Post-conditions:
 *   The root element is removed. The last element in the heap is moved
 *   to the root position and then sunk down to restore the Max-Heap property.
 *   Returns 1 if successful, 0 if the queue was empty.
 *
 * Side-effect:
 *   Decrements the element count and modifies the internal array order.
 *
 * Returns:
 *   An int (1 for success, 0 for failure/empty queue)
 */
int deleteMax(PQueue q);

/*
 * Function: insert
 * ----------------------
 * Inserts a new request into the Priority Queue
 *
 * Parameters:
 *   q: The priority queue where the request will be added
 *   r: The request structure to be inserted
 *
 * Pre-conditions:
 *   q must not be NULL
 *
 * Post-conditions:
 *   Returns 1 if the insertion is successful, 0 otherwise.
 *
 * Side-effect:
 *   Increments the element count. The new element is placed at
 *   the end of the heap and floated up until the Max-Heap
 *   property is restored.
 *
 * Returns:
 *   An int (1 for success, 0 for memory allocation failure)
 */
int insert(PQueue q, request r);

/*
 * Function: deallocatePQ
 * ----------------------
 * Frees all dynamically allocated memory for the Priority Queue
 *
 * Parameters:
 *   q: The priority queue to be deallocated
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   The memory associated PQueue structure is released.
 *
 * Side-effect:
 *   Frees memory. Note that this function does not deallocate the
 *   individual 'request' structures.
 *
 * Returns:
 *   void
 */
void deallocatePQ(PQueue q);

#endif
