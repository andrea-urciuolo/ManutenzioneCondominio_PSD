#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/request.h"
#include "../include/intervention.h"
#include "../include/list.h"
#include "../include/item.h"
#include "../include/PQueue.h"
#include "../include/opRequest.h"
#include "../tests/testing_include/testingRequest.h"
#include "../include/utils.h"

int main() {
    // Inizialization of the varius data structures
    list listTechnician = newList();
    list completedIntervention = newList();
    list uncompletedIntervention = newList();
    PQueue pqueueRequest = newPQ();

    // Counter for the size of the needed data structures
    int countRequest = 1;
    int countTechnician = 1;

    // Flag variable used to determine program flow
    char check = 'g';

    printf("BENVENUTO\n");

    while (check != 'z') {
        printf("Scegliere l'attività da svolgere:\n");
        printf("[a] Crea una nuova richiesta\n");
        printf("[b] Crea un nuovo tecnico\n");
        printf("[c] Crea un nuovo intervento\n");
        printf("[d] Visualizza le richieste attive\n");
        printf("[e] Visualizza i tecnici inseriti\n");
        printf("[f] Visualizza gli interventi\n");
        printf("[z] Terminare il programma\n");
        check = getchar();
        clearBuffer();
        switch (check) {
            case 'a':
                request req = newRequest(countRequest); //added id parameter for request
                clearBuffer();
                if (req == NULL) {
                    printf("Errore nella creazione della richiesta\n");
                    break;
                }
                if (insert(pqueueRequest, req) == 0) {
                    printf("Errore nella creazione della request\n");
                    deallocateRequest(req);
                    break;
                }
                countRequest++;
                break;
            case 'b':
                technician tech = createTechnician(countTechnician); //added id parameter for technician
                clearBuffer();
                if (tech == NULL) {
                    printf("Errore nella creazione del tecnico\n");
                    break;
                }
                listTechnician = consList(listTechnician, tech);
                if (listTechnician == NULL) {
                    printf("Errore nella creazione del tecnico\n");
                    deleteTechnician(tech);
                    break;
                }
                countTechnician++;
                break;
            case 'c':
                // TODO: FIX PLS
                break;
            case 'd':
                char checkD = 'e';
                printf("Seleziona come visualizzare le richieste attive: \n");
                printf("[a] Stampa tutte le richieste in ordine di urgenza\n");
                printf("[b] Stampa la richiesta con id specifico\n");
                printf("[c] Stampa tutte le richieste di una specifica tipologia\n");
                printf("[d] Stampa tutte le richieste relative ad un appartamento specifico\n");
                checkD = getchar();
                clearBuffer();
                switch (checkD) {
                    case 'a':
                        printAllRequests(pqueueRequest);
                        break;
                    case 'b':
                        int tmpID;
                        printf("Inserisci l'ID della richiesta da cercare: ");
                        scanf("%d", &tmpID);
                        clearBuffer();
                        printRequestById(pqueueRequest, tmpID);
                        break;
                    case 'c':
                        char checkD_C = 'l';
                        printf("Inserire la tipologia per filtrare le richieste: \n");
                        printf("[a] Richieste all'impianto idraulico\n");
                        printf("[b] Richieste all'impianto elettrico\n");
                        printf("[c] Richieste edili\n");
                        printf("[d] Richieste all'impianto termoidraulico\n");
                        printf("[e] Richieste sull'ascensore\n");
                        printf("[f] Richieste su serrature e metalli\n");
                        checkD_C = getchar();
                        clearBuffer();
                        printRequestsByType(pqueueRequest, checkD_C);
                        break;
                    case 'd':
                        int apartmentD;
                        printf("Inserire l'appartamento per filtrare le richieste [0 per l'ascensore]: ");
                        scanf("%d", &apartmentD);
                        clearBuffer();
                        printRequestsByApartment(pqueueRequest, apartmentD);
                        break;
                    default:
                        printf("ERRORE: Tipologia di visualizzazione errata\n");
                        break;
                }
                break;
            case 'e':
                char checkE = 'm';
                printf("Seleziona come visualizzare i tecnici: \n");
                printf("[a] Stampa tutti i tecnici\n");
                printf("[b] Stampa il tecnico con id specifico\n");
                printf("[c] Stampa tutti i tecnici di una specifica tipologia\n");
                printf("[d] Stampa tutti i tecnici in base al carico di lavoro\n");
                printf("[e] Stampa il tecnico con il carico di lavoro piu alto\n");
                checkE = getchar();
                clearBuffer();
                switch (checkE) {
                    case 'a':
                        printAllTechnicians(listTechnician);
                        break;
                    case 'b':
                        int tmpId;
                        printf("Inserisci l'Id del tecnico da visualizzare: ");
                        printTechnicianById(listTechnician, tmpId);
                        break;
                    case 'c':
                        char checkE_C = 'l';
                        printf("Inserire la tipologia per filtrare i tecnici: \n");
                        printf("[a] Idraulico\n");
                        printf("[b] Elettricista\n");
                        printf("[c] Impresa Edile\n");
                        printf("[d] Termoidraulico\n");
                        printf("[e] Teconico dell'ascensore\n");
                        printf("[f] Fabbro\n");
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
                        printf("ERRORE: Tipologia di visualizzazione errata\n");
                        break;

                }
                break;
            case 'f':
                char checkCompleted = 'c';
                printf("Visualizzare gli interventi completati [a], oppure visualizzare gli interventi non completati [b]");
                checkCompleted = getchar();
                clearBuffer();
                if (checkCompleted != 'a' || checkCompleted != 'b') {
                    printf("ERRORE : Carattere inserito non valido\n");
                    break;
                }
                char checkF = 'm';
                printf("Seleziona come visualizzare gli interventi: \n");
                printf("[a] Stampa tutti gli interventi\n");
                printf("[b] Stampa l'intervento in base all'Id della richiesta specifica\n");
                printf("[c] Stampa tutti gli interventi di una data specifica\n");
                printf("[d] Stampa tutti gli interventi di un tecnico specifico\n");
                printf("[e] Stampa l'intervento in base alla tipologia\n");
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
                        printf("Inserisci l'Id della richiesta specifica: ");
                        scanf("%d",&tmpId);
                        if (checkCompleted == 'a') {
                            printInterventionById(completedIntervention, tmpId);
                        } else if (checkCompleted == 'b') {
                            printInterventionById(uncompletedIntervention, tmpId);
                        }
                        break;
                    case 'c':
                        char Date[11];
                        int checkValidity;
                        
                        do {
                            printf("Inserisci la data per la quale si vuole filtrare gli interventi (Formato : YYYY/MM/DD): ");
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
                        int tmpId;
                        printf("Inserisci l'Id di un tecnico specifico");
                        scanf("%d", &tmpId);
                        clearBuffer();
                        if (checkCompleted == 'a') {
                            printInterventionsByTechnician(completedIntervention, tmpId);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByTechnician(uncompletedIntervention, tmpId);
                        }
                        break;
                    case 'e':
                        char checkF_E = 'l';
                        printf("Inserire la tipologia per filtrare gli interventi \n");
                        printf("[a] Interventi all'impianto idraulico\n");
                        printf("[b] Interventi all'impianto elettrico\n");
                        printf("[c] Interventi edili\n");
                        printf("[d] Interventi all'impianto termoidraulico\n");
                        printf("[e] Interventi sull'ascensore\n");
                        printf("[f] Interventi su serrature e metalli\n");
                        checkF_E = getchar();
                        clearBuffer();
                        if (checkCompleted == 'a') {
                            printInterventionsByType(completedIntervention, checkF_E);
                        } else if (checkCompleted == 'b') {
                            printInterventionsByType(uncompletedIntervention, checkF_E);
                        }
                        break;
                }
                break;
            case 'z':
                break;
            default:
                printf("ERRORE: Carattere inserito non valido.\n");
        } 
        printf("GRAZIEEEE\n");
    }




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
    run_test_suite_deallocateRequest("tests/cases/request/deallocateRequest/TS_input.txt", "tests/cases/request/deallocateRequest/oracle.txt");

    // TODO

    return 0;
}