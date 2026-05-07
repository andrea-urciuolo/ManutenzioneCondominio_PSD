#include <stdio.h>
#include <stdlib.h>
#include "../include/opRequest.h"
#include "../include/request.h"

void printAllRequests(PQueue pq) {
    // Check for the Preconditions to avoid operations on null pointers
    if (pq == NULL || emptyPQ(pq)) {
        printf("La coda è vuota o non inizializzata.\n");
        return;
    }

    // Temporary Priority Queue to hold elements while inspecting the original one
    PQueue tempQ = newPQ();
    if (tempQ == NULL) return;

    // Extract every request from pq to print it, and store it in tempQ to prevent data loss
    while (!emptyPQ(pq)) {
        request r = getMax(pq);
        printRequest(r);
        insert(tempQ, r);
        deleteMax(pq);
    }

    // Restore the original Priority Queue by moving all elements back from tempQ
    while (!emptyPQ(tempQ)) {
        insert(pq, getMax(tempQ));
        deleteMax(tempQ);
    }

    // Free the temporary queue's memory envelope, but keep the actual requests intact
    deallocatePQ(tempQ);
}

void printRequestById(PQueue pq, int id) {
    // Check for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("La coda è vuota o non inizializzata.\n");
        return;
    }

    // Create a temporary queue to hold elements of the original PQueue during the search
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return;

    request currentReq;
    int found = 0;

    // Linearly search for the request by emptying the queue item by item
    while (!emptyPQ(pq)) {
        currentReq = getMax(pq);
        deleteMax(pq);

        if (getIdRequest(currentReq) == id) {
            printRequest(currentReq);
            found = 1;
        }

        insert(tempPq, currentReq);
    }

    // Restore the original PQueue structure to maintain its state for future operations
    while (!emptyPQ(tempPq)) {
        insert(pq, getMax(tempPq));
        deleteMax(tempPq);
    }

    // Free the temporary queue memory but not the dynamically allocated requests
    deallocatePQ(tempPq);

    // In case the target ID is not found in the entire queue, notify the user
    if (!found) {
        printf("Richiesta con ID %d non trovata.\n", id);
    }
}

void printRequestsByType(PQueue pq, char type) {
    // Checks for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("La coda è vuota o non inizializzata.\n");
        return;
    }

    // Input validation: ensure the type falls within the accepted range ('a' to 'f')
    if (type < 'a' || type > 'f') {
        printf("La tipologia selezionata non esiste.\n");
        return;
    }

    // Create a temporary queue to hold the elements of the original PQueue
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return;

    request currentReq;
    int count = 0;

    printf("Ricerca delle richieste di tipologia [%c]...\n", type);

    // Check the PQueue and print only the requests that match the specified type
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
        printf("Nessuna richiesta trovata per la tipologia [%c].\n", type);
    } else {
        printf("Trovata/e %d richiesta/e di tipologia [%c].\n", count, type);
    }
}

void printRequestsByApartment(PQueue pq, int apartment) {
    // Checks for the Preconditions
    if (pq == NULL || emptyPQ(pq)) {
        printf("La coda è vuota o non inizializzata.\n");
        return;
    }
    
    // Input validation: apartment numbers cannot be negative
    if (apartment < 0) {
        printf("Il numero dell'appartamento è negativo.\n");
        return;
    }

    // Create a temporary PQueue to hold the elements of the original PQueue
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return;

    request currentReq;
    int count = 0;

    // Specific logic check: apartment 0 identifies requests for the whole building (e.g., elevators)
    if (apartment == 0) {
        printf("Ricerca delle richieste relative all'intero edificio...\n");
    } else {
        printf("Ricerca delle richieste per l'appartamento n.%d...\n", apartment);
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

    // Restores the original PQueue
    while (!emptyPQ(tempPq)) {
        insert(pq, getMax(tempPq));
        deleteMax(tempPq);
    }

    // Free the temporary PQueue memory but not the requests
    deallocatePQ(tempPq);

    // Print summary results based on whether it was a building-wide or specific apartment search
    if (count == 0) {
        if (apartment == 0) {
            printf("Nessuna richiesta trovata per l'intero edificio.\n");
        } else {
            printf("Nessuna richiesta trovata per l'appartamento specificato.\n");
        }
    } else {
        printf("Trovata/e %d richiesta/e per l'appartamento/edificio.\n", count);
    }
}

request getRequestById(PQueue pq, int id) {
    // Return NULL immediately if the queue is not valid or empty
    if (pq == NULL || emptyPQ(pq)) {
        return NULL;
    }
    
    // Allocate a temporary queue to safely extract items
    PQueue tempPq = newPQ();
    if (tempPq == NULL) return NULL;

    request currentReq;
    request foundReq = NULL;

    // Unload the queue to find the specific target ID
    while (!emptyPQ(pq)) {
        currentReq = getMax(pq);
        deleteMax(pq);

        // If the ID matches, save the pointer to return it later
        if (getIdRequest(currentReq) == id) {
            foundReq = currentReq;
        }

        // Keep pushing elements into the temporary queue to avoid data loss
        insert(tempPq, currentReq);
    }

    // Fully restore the original Priority Queue structure
    while (!emptyPQ(tempPq)) {
        insert(pq, getMax(tempPq));
        deleteMax(tempPq);
    }

    // Clean up temporary data structure
    deallocatePQ(tempPq);

    // Returns the pointer to the target request, or NULL if the loop didn't find any match
    return foundReq;
}