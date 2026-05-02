#include <stdio.h>
#include <stdlib.h>
#include "../include/opRequest.h"
#include "../include/request.h"

/*

void printAllRequests(PQueue pq) {
    // temporary PQueue for support
    PQueue tempQ = newPQ();

    // Extract everything from pq to insert in TempQ
    while (!emptyPQ(pq)) {
        request* r = getMax(q);
        printRequest(*r);      // Funzione del modulo request
        insert(tempQ, r);     // Salva per non perdere il dato
        deleteMax(q);
    }

    // 3. Ripristina la coda originale
    while (!emptyPQ(tempQ)) {
        insert(q, getMax(tempQ));
        deleteMax(tempQ);
    }

    // 4. Libera la memoria della coda temporanea (ma non le request!)
    free(tempQ);

}

*/