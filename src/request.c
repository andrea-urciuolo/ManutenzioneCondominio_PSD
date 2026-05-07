#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/request.h"
#include "../include/utils.h"


struct c_request {
    int idCode;                  // Unique identifier for the request
    char type;                   // Category of the intervention (e.g., plumbing, electrical)
    int urgency;                 // Priority level from 1 (lowest) to 5 (highest)
    int apartment;               // Apartment number; 0 indicates a building-wide issue
    char submissionDate[11];     // Date the request was made, format: YYYY/MM/DD
    char* description;           // Dynamically allocated string for the problem description
};

request newRequest(int Id) {
    // Allocate memory for the request ADT (Abstract Data Type)
    request r = malloc(sizeof(struct c_request));
    if (r == NULL) return NULL;

    // Flag variable used to track input validation errors
    int error = 0;

    // Assign the unique ID passed as a parameter
    r->idCode = Id;
    
    // Type input loop: Ensures the user selects a valid category
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
        
        // Validate if the input character is strictly within the 'a' to 'f' ASCII range
        if (type < 97 || type > 102) {
            printf("ERRORE! Inserire una tipologia valida\n");
            error = 1;
            continue;
        }

        r->type = type;
        break;
    }

    // Urgency input loop: Ensures priority is between 1 and 5
    error = 0;
    int urgency;
    do {
        clearBuffer();
        if (!error) printf("Inserire l'urgenza della richiesta [1 (bassa) - 5 (alta)]: ");
        else printf("ERRORE! Inserire un livello di urgenza valido: ");
        error = 1;
    } while ((scanf("%d", &urgency) != 1) || (urgency < 1 || urgency > 5));

    r->urgency = urgency;

    // Apartment input loop: Elevator issues (type 'e') default to 0 (whole building)
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


    // Submission date input loop: Validates format and calendar correctness via checkDateValidity
    error = 0;
    char submissionDate[11];
    do {
        clearBuffer();
       if (!error) printf("Inserire la data di sottomissione (YYYY/MM/DD): ");
       else printf("ERRORE! Formato non valido o data inesistente. Riprova (YYYY/MM/DD): ");
       error = 1;
    } while (scanf("%10s", submissionDate) != 1 || !checkDateValidity(submissionDate)); 

    // Safely copy the validated date into the struct's array
    strncpy(r->submissionDate, submissionDate, sizeof(r->submissionDate) - 1);
    r->submissionDate[sizeof(r->submissionDate) - 1] = '\0';

    // Description input loop: Prevents empty strings
    error = 0;
    char buffer[512];

    do {
        clearBuffer();
       if (!error) printf("Inserire una breve descrizione del problema: ");
       else printf("ERRORE! La descrizione non può essere vuota: ");
       error = 1;
       if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
           buffer[strcspn(buffer, "\n")] = '\0'; // Remove the trailing newline character
       }
    } while (strlen(buffer) == 0);

    // Dynamically allocate the exact amount of memory needed for the description to save space
    r->description = malloc(strlen(buffer) + 1);
    if (r->description == NULL) {
        free(r); // Prevent memory leaks if allocation fails
        return NULL;
    }

    strcpy(r->description, buffer);

    return r;
}

// Retrieves the ID code of the request
int getIdRequest(request r) {
    if (r == NULL) return -1;
    return r->idCode;
}

// Retrieves the type of the request
char getType(request r) {
    if (r == NULL) return 'z'; // Return default error value 'z' if request is NULL
    return r->type;
}

// Retrieves the urgency level of the request
int getUrgency(request r) {
    if (r == NULL) return -1;
    return r->urgency;
}

// Retrieves the apartment number associated with the request
int getApartment(request r) {
    if (r == NULL) return -1;
    return r->apartment;
}

// Retrieves the submission date string
char* getSubmissionDate(request r) {
    if (r == NULL) return NULL;
    return r->submissionDate;
}

// Retrieves the dynamically allocated description string
char* getDescription(request r) {
    if (r == NULL) return NULL;
    return r->description;
}

// Prints formatted details of the request to the standard output
void printRequest(request r) {
    if (r == NULL) return;
    printf("------------------------------------------------------\n");
    printf("--- Richiesta id: %d ---\n", getIdRequest(r));
    
    // Map the internal character type to a readable Italian string
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
    
    // Word-wrapping logic: prints the description wrapping lines at approximately 25 characters
    // ensuring words are not cut mid-sentence but broken at the closest space.
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

// Safely frees the memory allocated for the request, including its description
void deallocateRequest(request r) {
    if (r == NULL) return;
    free(r->description); // Must free internal dynamically allocated string first
    free(r);
}

// Builder function exclusively used for testing environments (bypasses user input)
request createRequest_TESTING(int id, char type, int urgency, int apartment, const char* date, const char* desc) {
    request r = malloc(sizeof(struct c_request));
    if (r == NULL) return NULL;

    r->idCode = id;
    r->type = type;
    r->urgency = urgency;
    r->apartment = apartment;

    strncpy(r->submissionDate, date, 10);
    r->submissionDate[10] = '\0';

    r->description = malloc(strlen(desc) + 1);
    if (r->description == NULL) {
        free(r);
        return NULL;
    }
    strcpy(r->description, desc);

    return r;
}