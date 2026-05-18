#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/request.h"
#include "../include/intervention.h"
#include "../include/list.h"
#include "../include/Btree.h"
#include "../include/item.h"
#include "../include/PQueue.h"
#include "../include/opRequest.h"
#include "../include/opTechnician.h"
#include "../include/opIntervention.h"
#include "../tests/testing_include/testingRequest.h"
#include "../tests/testing_include/testingTechnician.h"
#include "../tests/testing_include/testingIntervention.h"
#include "../tests/testing_include/testingUtils.h"
#include "../tests/testing_include/testingList.h"
#include "../tests/testing_include/pqueueTesting.h"
#include "../tests/testing_include/testingBtree.h"
#include "../tests/testing_include/testingOpRequest.h"
#include "../tests/testing_include/testingOpIntervention.h"
#include "../tests/testing_include/testingOpTechnician.h"
#include "../include/utils.h"

#define MAX_TECH 350
#define MAX_REQ 350


int main(int argc, char* argv[]) {
    
    // --- Command Line Argument Parsing ---
    
    if (argc != 2) {
        printf("\nERRORE: Numero di argomenti errato.\n");
        printf("Uso: .\\manutenzione --exe | .\\manutenzione --dev | .\\manutenzione --test\n\n");
        return 1;
    }

    // Testing Mode execution
    if (strcmp(argv[1], "--test") == 0) {
        printf("\n==================================================\n");
        printf("        SOFTWARE APERTO IN MODALITA' TESTING        \n");
        printf("==================================================\n\n");

        // REQUEST MODULE TESTS
        run_test_suite_getIdRequest("tests/cases/request/getIdRequest/TS_input.txt", "tests/cases/request/getIdRequest/oracle.txt");
        run_test_suite_getType("tests/cases/request/getType/TS_input.txt", "tests/cases/request/getType/oracle.txt");
        run_test_suite_getUrgency("tests/cases/request/getUrgency/TS_input.txt", "tests/cases/request/getUrgency/oracle.txt");
        run_test_suite_getApartment("tests/cases/request/getApartment/TS_input.txt", "tests/cases/request/getApartment/oracle.txt");
        run_test_suite_getSubmissionDate("tests/cases/request/getSubmissionDate/TS_input.txt", "tests/cases/request/getSubmissionDate/oracle.txt");
        run_test_suite_getDescription("tests/cases/request/getDescription/TS_input.txt", "tests/cases/request/getDescription/oracle.txt");
        run_test_suite_deallocateRequest("tests/cases/request/deallocateRequest/TS_input.txt");

        // TECHNICIAN MODULE TESTS
        run_test_suite_deleteTechnician("tests/cases/technician/deleteTechnician/TS_input.txt");
        run_test_suite_addIntervention("tests/cases/technician/addIntervention/TS_input.txt", "tests/cases/technician/addIntervention/oracle.txt");
        run_test_suite_getIdCode("tests/cases/technician/getIdCode/TS_input.txt", "tests/cases/technician/getIdCode/oracle.txt");
        run_test_suite_getInterventionCount("tests/cases/technician/getInterventionCount/TS_input.txt", "tests/cases/technician/getInterventionCount/oracle.txt");
        run_test_suite_getSpecialization("tests/cases/technician/getSpecialization/TS_suite.txt", "tests/cases/technician/getSpecialization/oracle.txt");
        run_test_suite_getName("tests/cases/technician/getName/TS_input.txt", "tests/cases/technician/getName/oracle.txt");

        // INTERVENTION MODULE TESTS
        run_test_suite_getRequestIntervention("tests/cases/intervention/getRequestIntervention/TS_input.txt", "tests/cases/intervention/getRequestIntervention/oracle.txt");
        run_test_suite_getTechnicianIntervention("tests/cases/intervention/getTechnicianIntervention/TS_input.txt", "tests/cases/intervention/getTechnicianIntervention/oracle.txt");
        run_test_suite_getDateAppointment("tests/cases/intervention/getDateTime/TS_input.txt", "tests/cases/intervention/getDateTime/oracle_date.txt");
        run_test_suite_getTimeAppointment("tests/cases/intervention/getDateTime/TS_input.txt", "tests/cases/intervention/getDateTime/oracle_time.txt");
        run_test_suite_deallocateIntervention();

        // UTILS MODULE TESTS
        run_test_suite_checkDateValidity("tests/cases/utils/checkDateValidity/TS_input.txt", "tests/cases/utils/checkDateValidity/oracle.txt");
        run_test_suite_checkTimeValidity("tests/cases/utils/checkTimeValidity/TS_input.txt", "tests/cases/utils/checkTimeValidity/oracle.txt");
        run_test_suite_StrToInt("tests/cases/utils/StrToInt/TS_input.txt", "tests/cases/utils/StrToInt/oracle.txt");

        // LIST MODULE TESTS
        run_test_suite_emptyList("tests/cases/list/emptyList/TS_input.txt", "tests/cases/list/emptyList/oracle.txt");
        run_test_suite_tailList("tests/cases/list/tailList/TS_input.txt", "tests/cases/list/tailList/oracle.txt");
        run_test_suite_getFirst("tests/cases/list/getFirst/TS_input.txt", "tests/cases/list/getFirst/oracle.txt");
        run_test_suite_consList("tests/cases/list/consList/TS_input.txt", "tests/cases/list/consList/oracle.txt");
        run_test_suite_sizeList("tests/cases/list/sizeList/TS_input.txt", "tests/cases/list/sizeList/oracle.txt");

        // PQUEUE MODULE TESTS
        run_test_suite_newPQ("tests/cases/Pqueue/newPQ/TS_input.txt", "tests/cases/Pqueue/newPQ/oracle.txt");
        run_test_suite_emptyPQ("tests/cases/Pqueue/emptyPQ/TS_input.txt", "tests/cases/Pqueue/emptyPQ/oracle.txt");
        run_test_suite_getMax("tests/cases/Pqueue/getMax/TS_input.txt", "tests/cases/Pqueue/getMax/oracle.txt");
        run_test_suite_deleteMax("tests/cases/Pqueue/deleteMax/TS_input.txt", "tests/cases/Pqueue/deleteMax/oracle.txt");
        run_test_suite_insert("tests/cases/Pqueue/insert/TS_input.txt", "tests/cases/Pqueue/insert/oracle.txt");
        run_test_suite_deallocatePQ("tests/cases/Pqueue/deallocatePQ/TS_input.txt", "tests/cases/Pqueue/deallocatePQ/oracle.txt");

        // BTREE MODULE TESTS
        run_test_suite_newBtree("tests/cases/Btree/newBtree/TS_input.txt", "tests/cases/Btree/newBtree/oracle.txt");
        run_test_suite_emptyBtree("tests/cases/Btree/emptyBtree/TS_input.txt", "tests/cases/Btree/emptyBtree/oracle.txt");
        run_test_suite_insertTechnician("tests/cases/Btree/insertTechnician/TS_input.txt", "tests/cases/Btree/insertTechnician/oracle.txt");
        run_test_suite_sizeBtree("tests/cases/Btree/sizeBtree/TS_input.txt", "tests/cases/Btree/sizeBtree/oracle.txt");
        run_test_suite_clearTreeNodes("tests/cases/Btree/clearTreeNodes/TS_input.txt", "tests/cases/Btree/clearTreeNodes/oracle.txt");

        // OPREQUEST MODULE TESTS
        run_test_suite_printAllRequests("tests/cases/opRequest/printAllRequests/TS_input.txt", "tests/cases/opRequest/printAllRequests/oracle.txt");
        run_test_suite_printRequestById("tests/cases/opRequest/printRequestById/TS_input.txt", "tests/cases/opRequest/printRequestById/oracle.txt");
        run_test_suite_printRequestsByType("tests/cases/opRequest/printRequestByType/TS_input.txt", "tests/cases/opRequest/printRequestByType/oracle.txt");
        run_test_suite_printRequestsByApartment("tests/cases/opRequest/printRequestByApartment/TS_input.txt", "tests/cases/opRequest/printRequestByApartment/oracle.txt");
        run_test_suite_getRequestById("tests/cases/opRequest/getRequestById/TS_input.txt", "tests/cases/opRequest/getRequestById/oracle.txt");

        // OPINTERVENTION MODULE TESTS
        run_test_suite_printInterventionById("tests/cases/opIntervention/printInterventionById/TS_input.txt", "tests/cases/opIntervention/printInterventionById/oracle.txt");
        run_test_suite_printInterventionsByDate("tests/cases/opIntervention/printInterventionByDate/TS_input.txt", "tests/cases/opIntervention/printInterventionByDate/oracle.txt");
        run_test_suite_printInterventionsByTech("tests/cases/opIntervention/printIntevrentionByTech/TS_input.txt", "tests/cases/opIntervention/printIntevrentionByTech/oracle.txt");
        run_test_suite_printInterventionsByType("tests/cases/opIntervention/printInterventionByType/TS_input.txt", "tests/cases/opIntervention/printInterventionByType/oracle.txt");
        run_test_suite_checkConflict("tests/cases/opIntervention/checkConflict/TS_input.txt", "tests/cases/opIntervention/checkConflict/oracle.txt");

        // OPTECHNICIAN MODULE TESTS
        run_test_suite_printAllTechnicians("tests/cases/opTechnician/printAllTechnicians/TS_input.txt", "tests/cases/opTechnician/printAllTechnicians/oracle.txt");
        run_test_suite_printTechniciansBySpecialization("tests/cases/opTechnician/printTechniciansBySpecialization/TS_input.txt", "tests/cases/opTechnician/printTechniciansBySpecialization/oracle.txt");
        run_test_suite_printTechniciansByWorkload("tests/cases/opTechnician/printTechniciansByWorkload/TS_input.txt", "tests/cases/opTechnician/printTechniciansByWorkload/oracle.txt");
        run_test_suite_printMostActiveTechnician("tests/cases/opTechnician/printMostActiveTechnician/TS_input.txt", "tests/cases/opTechnician/printMostActiveTechnician/oracle.txt");
        run_test_suite_findTechnicianByType("tests/cases/opTechnician/findTechnicianByType/TS_input.txt", "tests/cases/opTechnician/findTechnicianByType/oracle.txt");
        return 0;
    }

    // Execution Mode check
    if (strcmp(argv[1], "--exe") != 0 && strcmp(argv[1], "--dev") != 0) {
        printf("\nERRORE: Modalità di apertura errata.\n");
        return 1;
    }

    // --- Application Initialization ---

    Btree treeTechnician = newBtree();
    list completedIntervention = newList();
    list uncompletedIntervention = newList();
    PQueue pqueueRequest = newPQ();
    technician techID[MAX_TECH] = {NULL};
    request reqID[MAX_REQ] = {NULL};
    int countTechnician = 0;
    int countRequest = 0;
    char check = 'j';

    // Check --dev Mode
    if (strcmp(argv[1], "--dev") == 0) {
        printf("\n==================================================\n");
        printf("        SOFTWARE APERTO IN MODALITA' DEVELOPER      \n");
        printf("==================================================\n");

        // --- 1. AUTOMATIC GENERATION OF TECHNICIANS ---
        char specializations[] = {'a', 'b', 'c', 'd', 'e', 'f'};
        char tempName[30];

        printf("\n--- Avvio generazione automatica 100 tecnici ---\n");
        for (int i = 0; i < 100; i++) {
            if (countTechnician >= MAX_TECH) break;

            sprintf(tempName, "Tecnico_%d", countTechnician + 1);
            char spec = specializations[countTechnician % 6];

            technician t = buildTechnician(countTechnician, tempName, spec);

            if (t != NULL) {
                treeTechnician = insertTechnician(treeTechnician, t);
                techID[countTechnician] = t;
                countTechnician++;
            }
        }
        printf("Generati con successo %d tecnici.\n", countTechnician);

        // --- 2. AUTOMATIC GENERATION OF REQUESTS ---
        char tempDesc[100];
        char tempDate[12];

        printf("\n--- Avvio generazione automatica 100 richieste ---\n");
        for (int i = 0; i < 100; i++) {
            if (countRequest >= MAX_REQ) break;

            // Variables to randomize the parameters of the adt
            char typeReq = specializations[countRequest % 6];
            int urgencyReq = (countRequest % 5) + 1;
            int apartmentReq = (typeReq == 'e') ? 0 : (countRequest + 1);

            sprintf(tempDate, "2026/05/%02d", (countRequest % 28) + 1);
            sprintf(tempDesc, "Problema simulato di tipo %c di livello %d nell'appartamento %d", typeReq, urgencyReq, apartmentReq);

            // Generation of the request with random parameters
            request r = createRequest_TESTING(countRequest, typeReq, urgencyReq, apartmentReq, tempDate, tempDesc);

            if (r != NULL) {
                // Insert in pq if the allocation didn't fail
                if (insert(pqueueRequest, r) != 0) {
                    reqID[countRequest] = r;
                    countRequest++;
                } else {
                    // Error handling
                    deallocateRequest(r);
                }
            }
        }
        printf("Generate con successo %d richieste caricate in PQueue.\n", countRequest);

        // --- 3. AUTOMATIC GENERATION OF INTEFVENTIONS ---
        printf("\n--- Avvio generazione automatica 20 interventi ---\n");
        int countInterventionsGenerated = 0;
        char tempTime[6];

        for (int i = 0; i < 20; i++) {
            request currentReq = getMax(pqueueRequest);
            if (currentReq == NULL) break;

            int currentReqID = getIdRequest(currentReq);
            char typeReq = getType(currentReq);

            technician suitableTech = NULL;
            for (int j = 0; j < countTechnician; j++) {
                if (getSpecialization(techID[j]) == typeReq) {
                    suitableTech = techID[j];
                    break;
                }
            }

            if (suitableTech == NULL && countTechnician > 0) {
                suitableTech = techID[i % countTechnician];
            }

            if (suitableTech != NULL) {
                sprintf(tempDate, "2026/06/%02d", (countInterventionsGenerated % 28) + 1);
                sprintf(tempTime, "%02d:00", (9 + (countInterventionsGenerated % 8)));

                intervention newInter = buildIntervention(currentReq, suitableTech, tempDate, tempTime);

                if (newInter != NULL) {
                    // Insert the intervention to the list uncompletedIntervention
                    uncompletedIntervention = consList(uncompletedIntervention, newInter);

                    deleteMax(pqueueRequest);
                    reqID[currentReqID] = NULL;

                    countInterventionsGenerated++;
                }
            }
        }
        printf("Generati con successo %d interventi in corso (Stato: Non Completati).\n", countInterventionsGenerated);

        // 4. VISUALIZATION OF THE TREE STRUCTURE
        printf("\n--- Inizio Visualizzazione Albero ---\n");
        printf("(La radice e' all'estrema sinistra, i rami crescono a destra)\n");
        showTree(treeTechnician);
        printf("\n--- Fine Visualizzazione albero ---\n\n");
    }

    printf("\n==================================================\n");
    printf("               GESTIONALE MANUTENZIONI             \n");
    printf("==================================================\n");

    // --- Main Menu Loop ---
    while (check != 'z') {
        printf("\n------------------- MENU PRINCIPALE ------------------\n");
        printf(" Scegliere l'attività da svolgere:\n");
        printf("  [a] Crea una nuova richiesta\n");
        printf("  [b] Crea un nuovo tecnico\n");
        printf("  [c] Crea un nuovo intervento\n");
        printf("  [d] Visualizza le richieste attive\n");
        printf("  [e] Visualizza i tecnici inseriti\n");
        printf("  [f] Visualizza gli interventi\n");
        printf("  [g] Contrassegna un intervento come completato\n");
        printf("  [z] Terminare il programma\n");
        printf("------------------------------------------------------\n");
        printf("Scelta: ");
        check = getchar();
        clearBuffer();

        switch (check) {
            // --- Case A: Create a New Request ---
            case 'a':
                printf("\n--- CREAZIONE NUOVA RICHIESTA ---\n");
                request req = newRequest(countRequest);
                if (req == NULL) {
                    printf("ERRORE: Creazione della richiesta fallita.\n");
                    break;
                }
                if (insert(pqueueRequest, req) == 0) {
                    printf("ERRORE: Inserimento della richiesta nella coda fallito.\n");
                    deallocateRequest(req);
                    break;
                }
                printf("Richiesta creata con successo! (ID assegnato: %d)\n", countRequest);
                reqID[countRequest] = req;
                countRequest++;
                break;

            // --- Case B: Create a New Technician ---
            case 'b':
                printf("\n--- CREAZIONE NUOVO TECNICO ---\n");
                technician tech = createTechnician(countTechnician); // Passing the ID parameter
                if (tech == NULL) {
                    printf("ERRORE: Creazione del tecnico fallita.\n");
                    break;
                }
                treeTechnician = insertTechnician(treeTechnician, tech);
                if (treeTechnician == NULL) {
                    printf("ERRORE: Inserimento del tecnico nell'albero fallito.\n");
                    deleteTechnician(tech);
                    break;
                }
                printf("Tecnico inserito con successo! (ID assegnato: %d)\n", countTechnician);
                techID[countTechnician] = tech;
                countTechnician++;
                break;

            // --- Case C: Create a New Intervention ---
            case 'c':
                printf("\n--- CREAZIONE NUOVO INTERVENTO ---\n");
                char checkInter = 'c';
                printf(" Seleziona in che modo creare un nuovo intervento: \n");
                printf("  [a] Crea in base alla richiesta con più urgenza (Automatica)\n");
                printf("  [b] Crea su richiesta specifica (Manuale)\n");
                printf("Scelta: ");
                checkInter = getchar();
                clearBuffer();

                // Sub-case: Automatic creation based on highest urgency
                if (checkInter == 'a') {
                    request tmpR = getMax(pqueueRequest);
                    int tempReqID = getIdRequest(tmpR);
                    if (tmpR == NULL) {
                        printf("\nAvviso: Non ci sono richieste in coda da processare.\n");
                        break;
                    }
                    char typeReq = getType(tmpR);
                    technician foundTech = findTechnicianByType(treeTechnician, typeReq);


                    if (foundTech != NULL) {
                        int checkCon;
                        printf("\nTecnico idoneo trovato (ID: %d). Creazione intervento in corso...\n", getIdCode(foundTech));
                        // Loop to ensure the appointment does not conflict with existing ones
                        do {
                            intervention newInter = newIntervention(tmpR, foundTech);
                            checkCon = checkConflict(uncompletedIntervention, getIdCode(foundTech), getDateAppointment(newInter), getTimeAppointment(newInter));
                            if (checkCon == 1) {
                                printf("\nERRORE: Il tecnico inserito non è disponibile in questa data e orario. Riprovare.\n");
                            } else {
                                uncompletedIntervention = consList(uncompletedIntervention, newInter);
                                deleteMax(pqueueRequest); // Remove the request from the pending queue
                                reqID[tempReqID] = NULL;
                                printf("Intervento schedulato con successo!\n");
                            }
                        } while (checkCon != 0);
                    } else {
                        printf("\nERRORE: Nessun tecnico disponibile per questa tipologia di richiesta (%c).\n", typeReq);
                    }
                // Sub-case: Manual creation by specific IDs
                } else if (checkInter == 'b') {
                    int idReqInter;
                    int idTechInter;
                    printf("Inserisci l'ID della richiesta da associare all'intervento: ");
                    scanf("%d", &idReqInter);
                    clearBuffer();

                    request tempReqInter = reqID[idReqInter];
                    if (tempReqInter == NULL) {
                        printf("ERRORE: ID Richiesta non valido o non trovato.\n");
                        break;
                    }

                    printf("Inserisci l'ID del tecnico da assegnare all'intervento: ");
                    scanf("%d", &idTechInter);
                    clearBuffer();

                    technician tempTechInter = techID[idTechInter];
                    if (tempTechInter == NULL) {
                        printf("ERRORE: ID Tecnico non valido o non trovato.\n");
                        break;
                    }

                    intervention newInter = newIntervention(tempReqInter, tempTechInter);
                    if (newInter == NULL) {
                        printf("ERRORE: Creazione dell'intervento fallita.\n");
                        break;
                    }
                    reqID[idReqInter] = NULL;
                    uncompletedIntervention = consList(uncompletedIntervention, newInter);
                    printf("Intervento schedulato con successo!\n");
                } else {
                    printf("ERRORE: Selezione non valida. Per favore, scegli un'opzione dal menu.\n");
                }
                break;

            // --- Case D: View Active Requests ---
            case 'd':
                printf("\n--- VISUALIZZAZIONE RICHIESTE ATTIVE ---\n");
                char checkD = 'e';
                printf(" Seleziona come visualizzare le richieste: \n");
                printf("  [a] Stampa tutte le richieste in ordine di urgenza\n");
                printf("  [b] Stampa la richiesta con ID specifico\n");
                printf("  [c] Stampa tutte le richieste di una specifica tipologia\n");
                printf("  [d] Stampa tutte le richieste relative ad un appartamento\n");
                printf("Scelta: ");
                checkD = getchar();
                clearBuffer();

                switch (checkD) {
                    case 'a':
                        printAllRequests(pqueueRequest);
                        break;
                    case 'b':
                        int tmpID;
                        printf("\nInserisci l'ID della richiesta da cercare: ");
                        scanf("%d", &tmpID);
                        clearBuffer();
                        request tmpReqById = reqID[tmpID];
                        if (tmpReqById == NULL) {
                            printf("ERRORE: Non esiste una richiesta con questo ID\n");
                            break;
                        }
                        printRequest(tmpReqById);
                        break;
                    case 'c':
                        char checkD_C = 'l';
                        printf("\n Inserire la tipologia per filtrare le richieste: \n");
                        printf("  [a] Impianto idraulico\n");
                        printf("  [b] Impianto elettrico\n");
                        printf("  [c] Edili\n");
                        printf("  [d] Impianto termoidraulico\n");
                        printf("  [e] Ascensore\n");
                        printf("  [f] Serrature e metalli\n");
                        printf("Scelta: ");
                        checkD_C = getchar();
                        clearBuffer();
                        if (checkD_C < 'a' || checkD_C > 'f') {
                            printf("ERRORE: Tipologia inserita inesistente\n");
                            break;
                        }
                        printRequestsByType(pqueueRequest, checkD_C);
                        break;
                    case 'd':
                        int apartmentD;
                        printf("\nInserire l'appartamento per filtrare le richieste [0 per l'intero edificio]: ");
                        scanf("%d", &apartmentD);
                        clearBuffer();
                        printRequestsByApartment(pqueueRequest, apartmentD);
                        break;
                    default:
                        printf("\nERRORE: Opzione di visualizzazione non valida.\n");
                        break;
                }
                break;

            // --- Case E: View Technicians ---
            case 'e':
                printf("\n--- VISUALIZZAZIONE TECNICI ---\n");
                char checkE = 'm';
                printf(" Seleziona come visualizzare i tecnici: \n");
                printf("  [a] Stampa tutti i tecnici\n");
                printf("  [b] Stampa il tecnico con ID specifico\n");
                printf("  [c] Stampa tutti i tecnici di una specifica tipologia\n");
                printf("  [d] Stampa tutti i tecnici ordinati per carico di lavoro\n");
                printf("  [e] Stampa il tecnico con il carico di lavoro più alto\n");
                printf("Scelta: ");
                checkE = getchar();
                clearBuffer();

                switch (checkE) {
                    case 'a':
                        printAllTechnicians(treeTechnician);
                        break;
                    case 'b':
                        int tmpIdTech;
                        printf("\nInserisci l'ID del tecnico da visualizzare: ");
                        scanf("%d", &tmpIdTech);
                        clearBuffer();
                        technician tempTechById = techID[tmpIdTech];
                        if (tempTechById == NULL) {
                            printf("ERRORE: Non esiste un tecnico con questo ID\n");
                            break;
                        }
                        printTechnician(tempTechById);
                        break;
                    case 'c':
                        char checkE_C = 'l';
                        printf("\n Inserire la tipologia per filtrare i tecnici: \n");
                        printf("  [a] Idraulico\n");
                        printf("  [b] Elettricista\n");
                        printf("  [c] Impresa Edile\n");
                        printf("  [d] Termoidraulico\n");
                        printf("  [e] Ascensorista\n");
                        printf("  [f] Fabbro\n");
                        printf("Scelta: ");
                        checkE_C = getchar();
                        clearBuffer();
                        printTechniciansBySpecialization(treeTechnician, checkE_C);
                        break;
                    case 'd':
                        printTechniciansByWorkload(treeTechnician);
                        break;
                    case 'e':
                        printMostActiveTechnician(treeTechnician);
                        break;
                    default:
                        printf("\nERRORE: Opzione di visualizzazione non valida.\n");
                        break;
                }
                break;

            // --- Case F: View Interventions ---
            case 'f':
                printf("\n--- VISUALIZZAZIONE INTERVENTI ---\n");
                char checkCompleted;
                printf(" Selezionare lo stato degli interventi:\n");
                printf("  [a] Interventi COMPLETATI\n");
                printf("  [b] Interventi NON COMPLETATI (In Corso)\n");
                printf("Scelta: ");
                checkCompleted = getchar();
                clearBuffer();

                if (checkCompleted != 'a' && checkCompleted != 'b') {
                    printf("\nERRORE: Stato inserito non valido.\n");
                    break;
                }

                char checkF = 'm';
                printf("\n Seleziona come visualizzare gli interventi scelti: \n");
                printf("  [a] Stampa tutti gli interventi\n");
                printf("  [b] Stampa l'intervento in base all'ID della richiesta associata\n");
                printf("  [c] Stampa tutti gli interventi di una data specifica\n");
                printf("  [d] Stampa tutti gli interventi di un tecnico specifico\n");
                printf("  [e] Stampa gli interventi in base alla tipologia\n");
                printf("Scelta: ");
                checkF = getchar();
                clearBuffer();

                switch(checkF){
                    case 'a':
                        if (checkCompleted == 'a') {
                            printAllInterventions(completedIntervention);
                        } else if (checkCompleted == 'b') {
                            printAllInterventions(uncompletedIntervention);
                        }
                        break;
                    case 'b':
                        int tmpId;
                        printf("\nInserisci l'ID della richiesta associata: ");
                        scanf("%d", &tmpId);
                        clearBuffer();
                        if (checkCompleted == 'a') {
                            printInterventionById(completedIntervention, tmpId);
                        } else if (checkCompleted == 'b') {
                            printInterventionById(uncompletedIntervention, tmpId);
                        }
                        break;
                    case 'c':
                        char Date[11];
                        int checkValidity;
                        // Loop to ensure the provided date string is valid before searching
                        do {
                            printf("\nInserisci la data per la quale filtrare (Formato YYYY/MM/DD): ");
                            scanf("%10s", Date);
                            clearBuffer();

                            checkValidity = checkDateValidity(Date);

                            if (checkValidity == 0) {
                                printf("ERRORE: Data inserita non valida. Riprova.\n");
                            }
                        } while (checkValidity == 0);

                        if (checkCompleted == 'a') {
                            printInterventionsByDate(completedIntervention, Date);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByDate(uncompletedIntervention, Date);
                        }
                        break;
                    case 'd':
                        int tpId;
                        printf("\nInserisci l'ID del tecnico: ");
                        scanf("%d", &tpId);
                        clearBuffer();
                        if (checkCompleted == 'a') {
                            printInterventionsByTech(completedIntervention, tpId);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByTech(uncompletedIntervention, tpId);
                        }
                        break;
                    case 'e':
                        char checkF_E = 'l';
                        printf("\n Inserire la tipologia per filtrare gli interventi: \n");
                        printf("  [a] Impianto idraulico\n");
                        printf("  [b] Impianto elettrico\n");
                        printf("  [c] Edili\n");
                        printf("  [d] Impianto termoidraulico\n");
                        printf("  [e] Ascensore\n");
                        printf("  [f] Serrature e metalli\n");
                        printf("Scelta: ");
                        checkF_E = getchar();
                        clearBuffer();
                        if (checkCompleted == 'a') {
                            printInterventionsByType(completedIntervention, checkF_E);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByType(uncompletedIntervention, checkF_E);
                        }
                        break;
                    default:
                        printf("\nERRORE: Opzione di visualizzazione non valida.\n");
                }
                break;

            // --- Case G: Mark Intervention as Completed ---
            case 'g':
                printf("\n--- COMPLETA INTERVENTO ---\n");
                if (emptyList(uncompletedIntervention)) {
                    printf("Avviso: Non ci sono interventi in corso da completare.\n");
                    break;
                }

                int targetId;
                printf("Inserisci l'ID della richiesta associata all'intervento completato: ");
                scanf("%d", &targetId);
                clearBuffer();

                list current = uncompletedIntervention;
                intervention foundInter = NULL;
                int pos = 0;
                int targetPos = -1;

                // Search for the intervention and track its position index in the list
                while (!emptyList(current)) {
                    intervention inter = (intervention)getFirst(current);
                    request r = getRequestIntervention(inter);

                    if (getIdRequest(r) == targetId) {
                        foundInter = inter;
                        targetPos = pos;
                        break; // Intervention found!
                    }
                    current = tailList(current);
                    pos++;
                }

                if (foundInter != NULL) {
                    // 1. Update the associated technician's workload
                    technician t = getTechnicianIntervention(foundInter);
                    addIntervention(t);

                    // 2. Move the intervention into the completed list (front insertion)
                    completedIntervention = consList(completedIntervention, foundInter);

                    // 3. Remove the intervention node from the uncompleted list
                    uncompletedIntervention = removeList(uncompletedIntervention, targetPos);

                    printf("\nOperazione riuscita! L'intervento è stato completato e le statistiche del tecnico aggiornate.\n");
                } else {
                    printf("\nERRORE: Nessun intervento in corso trovato per la richiesta ID %d.\n", targetId);
                }
                break;
            case 'z':
                break;
            default:
                printf("\nERRORE: Selezione non valida. Per favore, scegli un'opzione dal menu.\n");
        }
    }


    // 1. Clear the Priority Queue (Richieste non assegnate)
    while (!emptyPQ(pqueueRequest)) {
        request r = getMax(pqueueRequest);
        deleteMax(pqueueRequest);
        deallocateRequest(r);
    }
    deallocatePQ(pqueueRequest);

    // 2. Clear Technicians
    for (int i = 0; i < MAX_TECH; i++) {
        if (techID[i] != NULL) {
            deleteTechnician(techID[i]);
            techID[i] = NULL;
        }
    }

    // 3. Clear Btree Nodes
    clearTreeNodes(treeTechnician);
    treeTechnician = NULL;

    // 4. Clear Completed Interventions
    while (!emptyList(completedIntervention)) {
        intervention inter = (intervention)getFirst(completedIntervention);

        deallocateRequest(getRequestIntervention(inter));

        completedIntervention = removeList(completedIntervention, 0);
        deallocateIntervention(inter);
    }

    // 5. Clear Uncompleted Interventions
    while (!emptyList(uncompletedIntervention)) {
        intervention inter = (intervention)getFirst(uncompletedIntervention);

        deallocateRequest(getRequestIntervention(inter));

        uncompletedIntervention = removeList(uncompletedIntervention, 0);
        deallocateIntervention(inter);
    }

    printf("\n==================================================\n");
    printf("                  GRAZIE!                       \n");
    printf("==================================================\n\n");

    return 0;
}
