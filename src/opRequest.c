#include <stdio.h>
#include <stdlib.h>
#include "../include/opRequest.h"
#include "../include/request.h"

void printAllRequests(PQueue pq) {
    // Check for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("The queue is empty or uninitialized.\n");
        return;
    }

    // Temporary PQueue for support
    PQueue tempQ = newPQ();
    if (tempQ == NULL) return;

    // Extract everything from pq to insert in TempQ
    while (!emptyPQ(pq)) {
        request r = getMax(pq);
        printRequest(r);
        insert(tempQ, r);
        deleteMax(pq);
    }

    // Restore the original PQueue
    while (!emptyPQ(tempQ)) {
        insert(pq, getMax(tempQ));
        deleteMax(tempQ);
    }

    // Free tempQ but not the request
    deallocatePQ(tempQ);
}

void printRequestById(PQueue pq, int id) {
    // Check for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("The queue is empty or uninitialized.\n");
        return;
    }

    // Create a temporary queue to hold elements of the original PQueue
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return;

    request currentReq;
    int found = 0;

    // Search for the request and move items to the temporary queue
    while (!emptyPQ(pq)) {
        currentReq = getMax(pq);
        deleteMax(pq);

        if (getIdRequest(currentReq) == id) {
            printRequest(currentReq);
            found = 1;
        }

        insert(tempPq, currentReq);
    }

    // Restore the original PQueue
    while (!emptyPQ(tempPq)) {
        insert(pq, getMax(tempPq));
        deleteMax(tempPq);
    }

    // Free the temporary queue memory but not the requests
    deallocatePQ(tempPq);

    // In case the id is not found gives error
    if (!found) {
        printf("Request with ID %d not found.\n", id);
    }
}

void printRequestsByType(PQueue pq, char type) {
    // Checks for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("The queue is empty or uninitialized.\n");
        return;
    }

    if (type < 'a' || type > 'f') {
        printf("The type selected does not exist.\n");
        return;
    }

    // Create a temporary queue to hold the elements of the original PQueue
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return;

    request currentReq;
    int count = 0;

    printf("Searching for requests of type [%c]...\n", type);

    // Checks the PQueue and print matching requests
    while (!emptyPQ(pq)) {
        currentReq = getMax(pq);
        deleteMax(pq);

        if (getType(currentReq) == type) {
            printRequest(currentReq);
            count++;
        }

        insert(tempPq, currentReq);
    }

    // Restore the original PQueue
    while (!emptyPQ(tempPq)) {
        insert(pq, getMax(tempPq));
        deleteMax(tempPq);
    }

    // Free the temporary queue memory but not the requests
    deallocatePQ(tempPq);

    if (count == 0) {
        printf("No requests found for type [%c].\n", type);
    } else {
        printf("Found %d request(s) of type [%c].\n", count, type);
    }
}

void printRequestsByApartment(PQueue pq, int apartment) {
    // Checks for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("The queue is empty or uninitialized.\n");
        return;
    }
    if (apartment < 0) {
        printf("Apartment is negative.\n");
        return;
    }

    // Create a temporary PQueue to hold the elements of the original PQueue
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return;

    request currentReq;
    int count = 0;

    if (apartment == 0) {
        printf("Searching for requests involving the entire building...\n");
    } else {
        printf("Searching for requests from apartment n.%d...\n", apartment);
    }

    // Checks the PQueue and prints matching requests
    while (!emptyPQ(pq)) {
        currentReq = getMax(pq);
        deleteMax(pq);

        if (getApartment(currentReq) == apartment) {
            printRequest(currentReq);
            count++;
        }

        insert(tempPq, currentReq);
    }

    //  Restores the original PQueue
    while (!emptyPQ(tempPq)) {
        insert(pq, getMax(tempPq));
        deleteMax(tempPq);
    }

    // Free the temporary PQueue memory but not the requests
    deallocatePQ(tempPq);

    if (count == 0) {
        if (apartment == 0) {
            printf("No requests found for the whole building\n");
        } else {
            printf("No requests found for the specified apartment.\n");
        }
    } else {
        printf("Found %d request(s) for apartment/building area.\n", count);
    }
}
