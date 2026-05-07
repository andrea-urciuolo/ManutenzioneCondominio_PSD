#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/item.h"

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

item getFirst(list l) {
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

list reverseList(list l) {
    list reversedList = newList();
    while (!emptyList(l)) {
        reversedList = consList(reversedList, getFirst(l));
        l = tailList(l);
    }
    return reversedList;
}
list insertList(list l, int p, item val) {
    if (p == 0) return consList(l, val);
    
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