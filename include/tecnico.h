#ifndef TECNICO_H
#define TECNICO_H

/* Definizione della struttura dati per il Tecnico */
typedef struct {
    int codiceIdentificativo;   //codice che identifica il tecnico
    char nome[50];
    char specializzazione[50];
    int disponibilita; /* 1 = disponibile, 0 = occupato */
} Tecnico;

/* Prototipi delle funzioni (Specifica Sintattica) */

/* Alloca dinamicamente un nuovo tecnico in memoria e inizializza i suoi dati */
Tecnico* creaTecnico(int codice, const char* nome, const char* specializzazione);

/* Stampa a schermo i dettagli di un singolo tecnico */
void stampaTecnico(const Tecnico* t);

/* Modifica lo stato di disponibilità del tecnico (es. dopo l'assegnazione di un intervento) */
void impostaDisponibilita(Tecnico* t, int stato);
/* Libera la memoria allocata per il tecnico quando non è più necessario */
void eliminaTecnico(Tecnico* t);

#endif