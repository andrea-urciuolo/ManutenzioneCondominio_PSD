#ifndef OPREQUEST_H
#define OPREQUEST_H

#include "../include/PQueue.h"

/*
 * Function: printAllRequests
 * ----------------------
 * Prints all the requests contained in the priority queue
 *
 * Parameters:
 *   pq: The priority queue containing the requests to be printed
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Cyclically extracts the maximum element from the queue, prints it,
 *   and inserts it into a temporary queue to later restore the
 *   original state of pq.
 *
 * Returns:
 *   void
 */
void printAllRequests(PQueue pq);

/*
 * Function: printRequestById
 * ----------------------
 * Searches for a specific request by its ID and prints its details
 *
 * Parameters:
 *   pq: The priority queue to search
 *   id: The ID of the request to find
 *
 * Pre-conditions:
 *   pq != NULL
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Iterates through the entire queue by extracting and re-inserting
 *   elements to find the request with the specified ID. Prints the
 *   details if found, or an error message otherwise.
 *
 * Returns:
 *   void
 */
void printRequestById(PQueue pq, int id);

/*
 * Function: printRequestsByType
 * ----------------------
 * Prints all requests of a specific type
 *
 * Parameters:
 *   pq: The priority queue to be scanned
 *   type: The character representing the request type ('a' - 'f')
 *
 * Pre-conditions:
 *   type € {'a', 'b', 'c', 'd', 'e', 'f'}
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Prints all requests whose type matches the 'type' parameter.
 *   Prints an error message if the type is invalid or if no matches
 *   are found. Restores the original state of pq after the search.
 *
 * Returns:
 *   void
 */
void printRequestsByType(PQueue pq, char type);

/*
 * Function: printRequestsByApartment
 * ----------------------
 *   Filters and prints all requests associated with a specific apartment
 *
 * Parameters:
 *   pq: The priority queue to be scanned
 *   apartment: The int identifying the apartment (n >= 0)
 *
 * Pre-conditions:
 *   pq != NULL
 *   apartment >= 0
 *
 * Post-conditions:
 *   None (void)
 *
 * Side-effect:
 *   Scans the queue to find and print requests for the specified apartment.
 *   The priority queue is fully restored to its original state after the operation.
 *
 * Returns:
 *   void
 */
void printRequestsByApartment(PQueue pq, int apartment);

/*
 * Function: getRequestById
 * ----------------------
 * Searches for and returns a pointer to a request with a specific ID
 *
 * Parameters:
 *   pq: The priority queue to search
 *   id: The ID of the request to find
 *
 * Pre-conditions:
 *   pq != NULL
 *   id >= 0
 *
 * Post-conditions:
 *   Returns the pointer to the request with the matching ID if present
 *   in the queue; otherwise, returns NULL
 *
 * Side-effect:
 *   Temporarily extracts elements from the original priority queue and
 *   stores them in a temporary queue to perform the scan. Restores the
 *   original structure of pq and deallocates the temporary structure
 *   before returning.
 *
 * Returns:
 *   The pointer to the request if found, or NULL otherwise
 */
request getRequestById(PQueue pq, int id);

#endif