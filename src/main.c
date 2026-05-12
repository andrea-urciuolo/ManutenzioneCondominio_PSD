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
#include "../include/opBtreeTechnician.h"
#include "../include/opTechnician.h"
#include "../include/opIntervention.h"
#include "../tests/testing_include/testingRequest.h"
#include "../tests/testing_include/testingTechnician.h"
#include "../tests/testing_include/testingIntervention.h"
#include "../tests/testing_include/testingUtils.h"
#include "../tests/testing_include/testingList.h"
#include "../tests/testing_include/pqueueTesting.h"
#include "../include/utils.h"

#define MAX_TECH 350
#define MAX_REQ 350


int main(int argc, char* argv[]) {
    
    // --- Command Line Argument Parsing ---
    
    if (argc != 2) {
        printf("\nERRORE: Numero di argomenti errato.\n");
        printf("Uso: ./manutenzione --exe (per avviare) oppure ./manutenzione --test (per i test)\n\n");
        return 1;
    }

    if (strcmp(argv[1], "--development") == 0) {
        printf("Software aperto in modalità developer\n");
        Btree myTree = newBtree();
        char specializations[] = {'a', 'b', 'c', 'd', 'e', 'f'};
        char tempName[30];

        printf("--- Avvio generazione automatica 100 tecnici ---\n");

        for (int i = 1; i <= 100; i++) {
            // Creates names like:  "Tecnico_1", "Tecnico_2", ecc...
            sprintf(tempName, "Tecnico_%d", i);

            char spec = specializations[i % 6];

            technician t = buildTechnician(i, tempName, spec);

            if (t != NULL) {
                myTree = insertTechnician(myTree, t);
            }
        }

        printf("\nAlbero generato. Visualizzazione delle specializzazioni:\n");
        printf("(La radice e' all'estrema sinistra, i rami crescono a destra)\n");

        showTree(myTree);

        printf("\n--- Fine Visualizzazione ---\n");





        return 0;
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
        run_test_suite_deallocateRequest("tests/cases/request/deallocateRequest/TS_input.txt", "tests/cases/request/deallocateRequest/oracle.txt");

        // TECHNICIAN MODULE TESTS
        run_test_suite_deleteTechnician("tests/cases/technician/deleteTechnician/TS_input.txt");
        run_test_suite_addIntervention("tests/cases/technician/addIntervention/TS_input.txt", "tests/cases/technician/addIntervention/oracle.txt");
        run_test_suite_getIdCode("tests/cases/technician/getIdCode/TS_input.txt", "tests/cases/technician/getIdCode/oracle.txt");
        run_test_suite_getInterventionCount("tests/cases/technician/getInterventionCount/TS_input.txt", "tests/cases/technician/getInterventionCount/oracle.txt");
        run_test_suite_getSpecialization("tests/cases/technician/getSpecialization/TS_input.txt", "tests/cases/technician/getSpecialization/oracle.txt");
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
        run_test_suite_newPQ("tests/cases/pqueue/newPQ/TS_input.txt", "tests/cases/pqueue/newPQ/oracle.txt");
        run_test_suite_emptyPQ("tests/cases/pqueue/emptyPQ/TS_input.txt", "tests/cases/pqueue/emptyPQ/oracle.txt");
        run_test_suite_getMax("tests/cases/pqueue/getMax/TS_input.txt", "tests/cases/pqueue/getMax/oracle.txt");
        run_test_suite_deleteMax("tests/cases/pqueue/deleteMax/TS_input.txt", "tests/cases/pqueue/deleteMax/oracle.txt");
        run_test_suite_insert("tests/cases/pqueue/insert/TS_input.txt", "tests/cases/pqueue/insert/oracle.txt");
        run_test_suite_deallocatePQ("tests/cases/pqueue/deallocatePQ/TS_input.txt", "tests/cases/pqueue/deallocatePQ/oracle.txt");
        return 0;
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
    char check = 'g';

    printf("\n==================================================\n");
    printf("               GESTIONALE MANUTENZIONI V2          \n");
    printf("==================================================\n");

    // Standard Execution Mode check
    if (strcmp(argv[1], "--exe") != 0) {
        printf("\nERRORE: Modalità di apertura errata.\n");
        return 1;
    }

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
                    uncompletedIntervention = consList(uncompletedIntervention, newInter);
                    printf("Intervento schedulato con successo!\n");
                } else {
                    printf("Selezione non valida\n"); // TODO: FIX Con una frase copiata da qualche altra parte
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
                            printInterventionsByTechnician(completedIntervention, tpId);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByTechnician(uncompletedIntervention, tpId);
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

    // 2. Clear Technicians (Usiamo l'Array per sicurezza e semplicità)
    for (int i = 0; i < MAX_TECH; i++) {
        if (techID[i] != NULL) {
            // Liberiamo l'oggetto tecnico una sola volta qui
            deleteTechnician(techID[i]);
            techID[i] = NULL;
        }
    }

    // 3. Clear Btree Nodes
    clearTreeNodes(treeTechnician);

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





    /*
    // --- Application Initialization ---

    // Initialization of the various data structures
    list listTechnician = newList();
    list completedIntervention = newList();
    list uncompletedIntervention = newList();
    PQueue pqueueRequest = newPQ();

    // ID Counters for the data structures to ensure unique identifiers
    int countRequest = 1;
    int countTechnician = 1;

    // Flag variable used to determine the main program flow
    char check = 'g';

    printf("\n==================================================\n");
    printf("        BENVENUTO NEL GESTIONALE MANUTENZIONI       \n");
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
                request req = newRequest(countRequest); // Passing the ID parameter
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
                listTechnician = consList(listTechnician, tech);
                if (listTechnician == NULL) {
                    printf("ERRORE: Inserimento del tecnico nella lista fallito.\n");
                    deleteTechnician(tech);
                    break;
                }
                printf("Tecnico inserito con successo! (ID assegnato: %d)\n", countTechnician);
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
                    if (tmpR == NULL) {
                        printf("\nAvviso: Non ci sono richieste in coda da processare.\n");
                        break;
                    }
                    char typeReq = getType(tmpR);
                    list curr = listTechnician;
                    technician foundTech = NULL;

                    // Scan the technician list to find one matching the required specialization
                    while (!emptyList(curr)) {
                        technician t = (technician)getFirst(curr);
                        if (getSpecialization(t) == typeReq) {
                            foundTech = t;
                            break;
                        }
                        curr = tailList(curr);
                    }

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
                    
                    request tempReqInter = getRequestById(pqueueRequest, idReqInter);
                    if (tempReqInter == NULL) {
                        printf("ERRORE: ID Richiesta non valido o non trovato.\n");
                        break;
                    }
                    
                    printf("Inserisci l'ID del tecnico da assegnare all'intervento: ");
                    scanf("%d", &idTechInter);
                    clearBuffer();
                    
                    technician tempTechInter = getTechnicianById(listTechnician, idTechInter);
                    if (tempTechInter == NULL) {
                        printf("ERRORE: ID Tecnico non valido o non trovato.\n");
                        break;
                    }

                    intervention newInter = newIntervention(tempReqInter, tempTechInter);
                    if (newInter == NULL) {
                        printf("ERRORE: Creazione dell'intervento fallita.\n");
                        break;
                    }
                    uncompletedIntervention = consList(uncompletedIntervention, newInter);
                    printf("Intervento schedulato con successo!\n");
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
                        printRequestById(pqueueRequest, tmpID);
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
                        printAllTechnicians(listTechnician);
                        break;
                    case 'b':
                        int tmpIdTech;
                        printf("\nInserisci l'ID del tecnico da visualizzare: ");
                        scanf("%d", &tmpIdTech);
                        clearBuffer();
                        printTechnicianById(listTechnician, tmpIdTech);
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
                        printTechniciansBySpecialization(listTechnician, checkE_C);
                        break;
                    case 'd':
                        printTechniciansByWorkload(listTechnician);
                        break;
                    case 'e':
                        printMostActiveTechnician(listTechnician);
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
                            printInterventionsByTechnician(completedIntervention, tpId);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByTechnician(uncompletedIntervention, tpId);
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
                
            // --- Case Z: Exit Program ---
            case 'z':
                break;
                
            default:
                printf("\nERRORE: Selezione non valida. Per favore, scegli un'opzione dal menu.\n");
        }
    }

    // 1. Clear the Priority Queue and its remaining requests
    while (!emptyPQ(pqueueRequest)) {
        request r = getMax(pqueueRequest);
        deleteMax(pqueueRequest);
        deallocateRequest(r); // Free each request object
    }
    deallocatePQ(pqueueRequest); // Free the queue structure itself

    // 2. Clear the Technician list and each technician struct
    while (!emptyList(listTechnician)) {
        technician t = (technician)getFirst(listTechnician);
        listTechnician = removeList(listTechnician, 0); // Remove the node from list
        deleteTechnician(t); // Free the technician object
    }

    // 3. Clear Completed Interventions
    while (!emptyList(completedIntervention)) {
        intervention inter = (intervention)getFirst(completedIntervention);
        // We must free the request inside the intervention as it was removed from the PQueue
        deallocateRequest(getRequestIntervention(inter));
        completedIntervention = removeList(completedIntervention, 0);
        deallocateIntervention(inter); // Free the intervention wrapper
    }

    // 4. Clear Uncompleted Interventions
    while (!emptyList(uncompletedIntervention)) {
        intervention inter = (intervention)getFirst(uncompletedIntervention);
        // We must free the request inside the intervention
        deallocateRequest(getRequestIntervention(inter));
        uncompletedIntervention = removeList(uncompletedIntervention, 0);
        deallocateIntervention(inter);
    }
    printf("\n==================================================\n");
    printf("                  GRAZIE!                       \n");
    printf("==================================================\n\n");

    return 0;
    */
}
