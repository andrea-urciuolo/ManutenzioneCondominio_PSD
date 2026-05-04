#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/request.h"
#include "../include/utils.h"

struct c_request {
    int idCode;                  // Id code for the request
    char type;                   // Type of request   Es: Fixing the plumbering
    int urgency;                 // Level of urgency  1 (low) - 5 (high)
    int apartment;               // Civic number who sent the request, 0 if it's for the whole building
    char submissionDate[11];     // Format: YYYY/MM/DD
    char* description;           // Description of the problem
};

request newRequest() {
    // Allocate memory for the request adt
	request r = malloc(sizeof(struct c_request));
	if (r == NULL) return NULL;

    // Declare a flag variable used to check if the user input is correct
	int error = 0;

    // idCode input
    // TODO: Modifica la firma della funzione così da accettare come parametro l'id della request (dal contatore nel main)
	int idCode;
	do {
		if (!error) {
		    printf("Inserire l'id della richiesta: ");
		} else {
		    clearBuffer();
		    printf("ERRORE! Inserire un id valido (solo cifre): ");
		}
		error = 1;
	} while (scanf("%d", &idCode) != 1);

	r->idCode = idCode;

    // type input
	error = 0;
	char type;
	while (1) {
	    clearBuffer();
		if (!error) {
			printf("Inserire la tipologia della richiesta\n");
			printf("[a] Intervento all'impianto idraulico\n");
			printf("[b] Intervento all'impianto elettrico\n");
			printf("[c] Intervento edile\n");
			printf("[d] Intervento all'impianto termoidraulico\n");
			printf("[e] Intervento sull'ascensore\n");
			printf("[f] Intervento su serrature e metalli\n");
		}
		printf(".. : ");
		type = getchar();
	    // Check if the input is within the 'a' to 'f' range
		if (type < 97 || type > 102) {
			printf("ERRORE! Inserire una tipologia valida\n");
			error = 1;
			continue;
		}

		r->type = type;
		break;
	}

    // urgency input
	error = 0;
	int urgency;
	do {
	    clearBuffer();
		if (!error) printf("Inserire l'urgenza della richiesta [1 (bassa) - 5 (alta)]: ");
		else printf("ERRORE! Inserire un livello di urgenza valido: ");
		error = 1;
	} while ((scanf("%d", &urgency) != 1) || (urgency < 1 || urgency > 5));

	r->urgency = urgency;

    // apartment input
	error = 0;
	int apartment;
	if (type == 'e') {
		apartment = 0;
	} else {
		do {
		    clearBuffer();
			if (!error) printf("Inserire il numero civico della richiesta: ");
			else printf("ERRORE! Inserire un numero civico valido: ");
			error = 1;
		} while ((scanf("%d", &apartment) != 1) || (apartment < 1));
	}

    r->apartment = apartment;


    // submmissionDate input
	// TODO: Aggiungere controlli in caso di data inesistente
	error = 0;
	char submissionDate[11];
    do {
        clearBuffer();
       if (!error) printf("Inserire la data di sottomissione (YYYY/MM/DD): ");
       else printf("ERRORE! Formato non valido. Riprova (YYYY/MM/DD): ");
       error = 1;
    } while (scanf("%10s", submissionDate) != 1);

    strncpy(r->submissionDate, submissionDate, sizeof(r->submissionDate) - 1);
    r->submissionDate[sizeof(r->submissionDate) - 1] = '\0';

    // description input
	error = 0;
	char buffer[512];

	do {
	    clearBuffer();
       if (!error) printf("Inserire una breve descrizione del problema: ");
       else printf("ERRORE! La descrizione non può essere vuota: ");
       error = 1;
       if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
           buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline '\n'
       }
    } while (strlen(buffer) == 0);

    // Allocate the exact memory needed for description
    r->description = malloc(strlen(buffer) + 1);
    if (r->description == NULL) {
        free(r);
        return NULL;
    }

    strcpy(r->description, buffer);

    return r;
}

int getIdRequest(request r) {
    if (r == NULL) return -1;
    return r->idCode;
}

char getType(request r) {
    if (r == NULL) return 'z'; // Return Default value for the type parameter
    return r->type;
}

int getUrgency(request r) {
    if (r == NULL) return -1;
    return r->urgency;
}

int getApartment(request r) {
    if (r == NULL) return -1;
    return r->apartment;
}

char* getSubmissionDate(request r) {
    if (r == NULL) return NULL;
    return r->submissionDate;
}

char* getDescription(request r) {
    if (r == NULL) return NULL;
    return r->description;
}

void printRequest(request r) {
	if (r == NULL) return;
	printf("------------------------------------------------------\n");
	printf("--- Richiesta id: %d ---\n", getIdRequest(r));
	switch (getType(r)) {
		case 'a':
			printf("- Intervento all'impianto idraulico\n");
			break;
		case 'b':
			printf("- Intervento all'impianto elettrico\n");
			break;
		case 'c':
			printf("- Intervento edile\n");
			break;
		case 'd':
			printf("- Intervento all'impianto termoidraulico\n");
			break;
		case 'e':
			printf("- Intervento sull'ascensore\n");
			break;
		case 'f':
			printf("- Intervento su serrature e metalli\n");
			break;
		default:
			printf("- ERRORE\n");
			return;
	}
	printf("- Livello di urgenza: %d\n", getUrgency(r));
	if (getApartment(r) == 0) {
		printf("- Intervento all'intero edificio\n");
	} else {
		printf("- Intervento all'appartamento n.%d\n", getApartment(r));
	}
	printf("- Data invio della richiesta: %s\n", getSubmissionDate(r));

	printf("- Descrizione:\n");
	// Printing the description around 25 char for row
	int i = 0;
	int charForRow = 0;
	char* tmpDescription = getDescription(r);

	while (tmpDescription[i] != '\0') {
		if (charForRow > 25 && tmpDescription[i] == ' ') {
			printf("\n");
			charForRow = 0;
		}else{
			putchar(tmpDescription[i]);
			charForRow++;
		}
		i++;
	}
    printf("\n------------------------------------------------------\n");
}

void deallocateRequest(request r) {
    if (r == NULL) return;
    free(r->description);
    free(r);
}
