#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/request.h"
#include "../include/intervention.h"
#include "../include/list.h"
#include "../include/item.h"
#include "../include/PQueue.h"

int main() {
    // TODO: Crea una lista di intervention completate e un'altra per le non completate
    // TODO: Crea un contatore di request e technician così da gestire l'id (Non più random o inserito dall'utente)

    PQueue q = newPQ();
    request r = newRequest();
    insert(q, r);
    request temp = getMax(q);
    printf("INIZIO TEST...\n");
    printf("Apartment: %d\n", getApartment(temp));
    printf("FINE TEST...\n");
    printRequest(r);
    deallocateRequest(r);
    return 0;
}