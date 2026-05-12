#include <stdio.h>
#include <stdlib.h>
#include "../include/technician.h"
#include "../include/Btree.h"

struct node {
    technician value;
    node* left;
    node* right;
};

technician getItem(node* N) {
    if (N == NULL) return NULL;
    return N->value;
}

void setItem(node* N, technician tech) {
    if (N == NULL) return;
    N->value = tech;
}

Btree newBtree(void) {
    return NULL;
}

int emptyBtree(Btree T) {
    return T == NULL;
}

node* getRoot(Btree T) {
    return T;
}

Btree consBtree(technician val, Btree sx, Btree dx) {
    node* nuovo = malloc(sizeof(node));
    if (nuovo != NULL) {
        setItem(nuovo, val);
        nuovo->left = sx;
        nuovo->right = dx;
    }
    return nuovo;
}

Btree figlioSX(Btree T) {
    if (T == NULL) return NULL;
    return T->left;
}

Btree figlioDX(Btree T) {
    if (T == NULL) return NULL;
    return T->right;
}

Btree insertTechnician(Btree T, technician newTech) {
    if (emptyBtree(T)) {
        return consBtree(newTech, newBtree(), newBtree());
    }

    technician rootTech = getItem(getRoot(T));

    if (getSpecialization(newTech) <= getSpecialization(rootTech)) {
        Btree newLeft = insertTechnician(figlioSX(T), newTech);
        return consBtree(rootTech, newLeft, figlioDX(T));
    } else {
        Btree newRight = insertTechnician(figlioDX(T), newTech);
        return consBtree(rootTech, figlioSX(T), newRight);
    }
}

int sizeBtree(Btree T) {
    if (emptyBtree(T)) return 0;

    return 1 + sizeBtree(figlioSX(T)) + sizeBtree(figlioDX(T));
}

// --- Functions to visualize the tree structure ---


void printTreeStructure(Btree T, char* prefix, int isLeft) {
    if (emptyBtree(T)) {
        return;
    }

    printf("%s", prefix);

    printf("%s", isLeft ? "|--(S) " : "'--(D) ");

    technician t = getItem(getRoot(T));
    printf("[%c]\n", getSpecialization(t));

    char newPrefix[256];
    sprintf(newPrefix, "%s%s", prefix, isLeft ? "|   " : "    ");

    if (!emptyBtree(figlioSX(T)) || !emptyBtree(figlioDX(T))) {
        printTreeStructure(figlioSX(T), newPrefix, 1);
        printTreeStructure(figlioDX(T), newPrefix, 0);
    }
}

void showTree(Btree T) {
    if (emptyBtree(T)) {
        printf("L'albero e' vuoto.\n");
        return;
    }
    printf("\n--- STRUTTURA ALBERO TECNICI ---\n");
    printf("ROOT\n");
    printTreeStructure(T, "", 0);
    printf("--------------------------------\n");
}