#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/technician.h"

// TODO: Aggiungi l'aliasing con item.c e item.h

struct node {
    technician data;
    struct node* next;
};

list newList() {
    return NULL;
}

int emptyList(list l) {
    if (l == NULL) {
        return 1;
    }
    return 0;
}

list tailList(list l) {
    if (l == NULL) {
        return NULL;
    }
    l = l->next;
    return l;
}

technician getFirst(list l) {
    if (l == NULL) {
        return NULL;
    }
    return l->data;
}

list consList(list l, technician tech) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode != NULL) {
        newNode->data = tech;
        newNode->next = l;
        l = newNode;
    }
    return l;
}

int sizeList(list l) {
    int count = 0;
    list current = l;
    while (!emptyList(current)) {
        count++;
        current = tailList(current);
    }
    return count;
}

int searchTechnician(list l, int targetIdCode) {
    list current = l;
    while (current != NULL) {
        if (getIdCode(current->data) == targetIdCode) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int posTechnician(list l, int targetIdCode) {
    int i = 0;
    int found = 0;
    list current = l;
    
    while (!emptyList(current) && !found) {
        if (getIdCode(getFirst(current)) == targetIdCode) {
            found = 1;
        } else {
            i++;
            current = tailList(current);
        }
    }

    if (!found) {
        return -1;
    }
    return i;
}

/* Helper function to get a technician at a specific position */
technician getTechnicianAt(list l, int pos) {
    int i = 0;
    list current = l;
    while (!emptyList(current)) {
        if (i == pos) {
            return getFirst(current);
        }
        i++;
        current = tailList(current);
    }
    return NULL;
}

list reverseList(list l) {
    list reversedList = newList();
    list current = l;
    while (!emptyList(current)) {
        reversedList = consList(reversedList, getFirst(current));
        current = tailList(current);
    }
    return reversedList;
}

list removeTechnician(list l, int targetIdCode) {
    list temp = newList();
    list current = l;
    
    while (!emptyList(current)) {
        if (getIdCode(getFirst(current)) != targetIdCode) {
            temp = consList(temp, getFirst(current));
        }
        current = tailList(current);
    }

    list finalReversedList = reverseList(temp);
    return finalReversedList;
}

void outputList(list l) {
    if (emptyList(l)) {
        printf("Empty list of technicians.\n");
        return;
    }

    list current = l;
    while (!emptyList(current)) {
        printf("[Tech ID: %d] ", getIdCode(getFirst(current)));
        current = tailList(current);
        if (!emptyList(current)) {
            printf("-> ");
        }
    }
    printf("\n");
}

list inputList(int n) {
    technician tempTech;
    list l = newList();
    
    for (int i = 0; i < n; i++) {
        printf("Creating technician %d of %d...\n", i + 1, n);
        tempTech = createTechnician(); // Uses the function from your ADT
        if (tempTech != NULL) {
            l = consList(l, tempTech);
        }
    }

    l = reverseList(l);
    return l;
}

list insertList(list l, int p, technician tech) {
    if (p == 0) {
        return consList(l, tech);
    }
    
    int i = 0;
    list current = l;
    
    while (i < p - 1 && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("List is too short to insert at position %d.\n", p);
        return l;
    }

    list newNode = consList(current->next, tech);
    current->next = newNode;

    return l;
}

list removeList(list l, int p) {
    if (l == NULL) {
        return NULL;
    }

    if (p == 0) {
        list tmp = l;
        l = tailList(l);
        // Note: we free the node, but we DO NOT call deleteTechnician(tmp->data) 
        // because usually lists don't destroy the data they hold unless specified.
        free(tmp); 
    } else {
        int i = 0;
        list current = l;

        while (i < p - 1 && current != NULL) {
            current = current->next;
            i++;
        }

        if (current == NULL || current->next == NULL) {
            printf("List is too short to remove element at position %d.\n", p);
            return l;
        }

        list nodeToRemove = current->next;
        current->next = nodeToRemove->next;
        free(nodeToRemove);
    }

    return l;
}