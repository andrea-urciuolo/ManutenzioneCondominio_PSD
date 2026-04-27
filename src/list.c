#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

// TODO: Aggiungi l'aliasing con item.c e item.h

struct node {
    item data;
    struct node* next;
};

list newList() {
    return NULL;
}

int emptyList(list l) {
    return (l == NULL);
}

list tailList(list l) {
    if (l == NULL) return NULL;
    return l->next;
}

technician getFirst(list l) {
    if (l == NULL) return NULL;
    return l->data;
}

list consList(list l, item val) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode != NULL) {
        newNode->data = val;
        newNode->next = l;
        l = newNode;
    }
    return l;
}

int sizeList(list l) {
    int count = 0;
    while (!emptyList(l)) {
        count++;
        l = tailList(l);
    }
    return count;
}

// TODO: Eventually add this function to a module separated form list.h (es. techListOperations)

/*
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
*/

// Helper function to get a technician at a specific position
/*
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
*/

list reverseList(list l) {
    list reversedList = newList();
    while (!emptyList(l)) {
        reversedList = consList(reversedList, getFirst(l));
        l = tailList(l);
    }
    return reversedList;
}

/*
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
*/

void outputList(list l) {
    if (emptyList(l)) {
        printf("Empty list\n");
        return;
    }
    while (!emptyList(l)) {
        outputItem(getFirst(l)); // TODO: add outputItem()
        l = tailList(l);
        if (!emptyList(l)) printf(" -> ");
    }
    printf("\n");
}

list insertList(list l, int p, item val) {
    if (p == 0) return consList(l, tech);
    
    int i = 0;
    list current = l;
    
    while (i < p - 1 && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) return l;

    struct node* newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = val;
        newNode->next = current->next;
        current->next = newNode;
    }
    return l;
}

list removeList(list l, int p) {
    if (l == NULL) return NULL;

    if (p == 0) {
        list tmp = l;
        l = tailList(l);
        free(tmp);
    } else {
        int i = 0;
        list current = l;

        while (i < p - 1 && current != NULL) {
            current = current->next;
            i++;
        }

        if (current == NULL || current->next == NULL) return l;

        list nodeToRemove = current->next;
        current->next = nodeToRemove->next;
        free(nodeToRemove);
    }

    return l;
}