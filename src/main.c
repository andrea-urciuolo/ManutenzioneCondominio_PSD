#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/request.h"
#include "../include/intervention.h"
#include "../include/list.h"
#include "../include/item.h"
#include "../include/PQueue.h"
#include "../tests/testing.h"

int main() {
    // TODO: Crea una lista di intervention completate e un'altra per le non completate
    // TODO: Crea un contatore di request e technician così da gestire l'id (Non più random o inserito dall'utente)

    // TODO: DA CANCELLARE DOPO, UN TEST PER IL TESTING
    
    // REQUEST
    run_test_suite_getIdRequest("tests/cases/request/getIdRequest/TS_input.txt", "tests/cases/request/getIdRequest/oracle.txt");
    run_test_suite_getType("tests/cases/request/getType/TS_input.txt", "tests/cases/request/getType/oracle.txt");
    run_test_suite_getUrgency("tests/cases/request/getUrgency/TS_input.txt", "tests/cases/request/getUrgency/oracle.txt");
    run_test_suite_getApartment("tests/cases/request/getApartment/TS_input.txt", "tests/cases/request/getApartment/oracle.txt");
    run_test_suite_getSubmissionDate("tests/cases/request/getSubmissionDate/TS_input.txt", "tests/cases/request/getSubmissionDate/oracle.txt");
    run_test_suite_getDescription("tests/cases/request/getDescription/TS_input.txt", "tests/cases/request/getDescription/oracle.txt");
    run_test_suite_printRequest("tests/cases/request/printRequest/TS_input.txt", "tests/cases/request/printRequest/oracle.txt");

    // TODO

/*
    PQueue q = newPQ();
    request r = newRequest();
    insert(q, r);
    request temp = getMax(q);
    printf("INIZIO TEST...\n");
    printf("Apartment: %d\n", getApartment(temp));
    printf("FINE TEST...\n");
    printRequest(r);
    deallocateRequest(r);

    */
    return 0;
}