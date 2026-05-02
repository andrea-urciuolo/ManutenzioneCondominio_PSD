#ifndef OPREQUEST_H
#define OPREQUEST_H

#include "../include/PQueue.h"

// Prints all the request in the PQueue, from the least to the most prioritary
void printAllRequests(PQueue pq);

// Prints the request by id
void printRequestById(PQueue pq, int id);

// Prints requests by type
void printRequestsByType(PQueue pq, char type);

// Prints requests by apartment
void printRequestsByApartment(PQueue pq, int apartment);

#endif