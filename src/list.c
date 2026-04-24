#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node {
    item data;
    node* next;
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


item getFirst(list l) {
    if (l == NULL) {
        return NULLITEM;
    }

    return l->data;
}


list consList(list l, item value) {
    node* newNode = (node* ) malloc(sizeof(node));
    if (newNode != NULL) {
        newNode->data = value;
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


int searchItem(list l, item value) {
    list temp_next = l;
    while (temp_next != NULL) {
        if (temp_next->data == value) {
            return 1;
        }
        temp_next = temp_next->next;
    }

    return 0;
}


int posItem (list l, item value) {
    int i = 0;
    int found = 0;
    while (!emptyList(l) && !found) {
        if (eq(getFirst(l), value)) {
            found = 1;
        } else {
            i++;
            l = tailList(l);
        }
    }

    if(!found) {
        return -1;
    }

    return i;
}


item getItem(list l, int pos) {
    int i = 0;
    while (!emptyList(l)) {
        if (i == pos) {
            return getFirst(l);
        }
        i++;
        l = tailList(l);
    }

    return NULLITEM;
}


list reverseList(list l) {
    list l1 = newList();
    while (!emptyList(l)) {
        l1 = consList(l1, getFirst(l));
        l = tailList(l);
    }

    return l1;
}


list removeItem(list l, item value) {
    list l1 = newList();
    while (!emptyList(l)) {
        if (!eq(getFirst(l), value)) {
            l1 = consList(l1, getFirst(l));
        }
        l = tailList(l);
    }

    list reverse = reverseList(l1);

    return reverse;
}


void outputList(list l) {
    if (emptyList(l)) {
        printf("Empty list");
    }

    while (!emptyList(l)) {
        printf("|%d|", getFirst(l));
        l = tailList(l);
        if (!emptyList(l)) {
            printf(" -> ");
        }
    }

    printf("\n");
}


list inputList(int n) {
    item temp;
    list l = newList();
    for (int i = 0; i < n; i++) {
        inputItem(&temp);
        l = consList(l, temp);
    }

    l = reverseList(l);

    return l;
}


list insertList(list l, int p, item value) {
    if (p == 0) {
        return consList(l, value);
    }
    int i = 0;
    list prec = l;
    while (i < p-1 && prec != NULL) {
        prec = prec->next;
        i++;
    }

    if (prec == NULL) {
        printf("List too short");
        return l;
    }

    list l1 = consList(prec->next, value);
    prec->next = l1;

    return l;
}


list removeList(list l, int p) {
    if (l == NULL) {
        return NULL;
    }

    if (p == 0) {
        list tmp = l;
        l =  tailList(l);
        free(tmp);
    } else {
        int i = 0;
        list prec = l;

        while (i < p-1 && prec != NULL) {
            prec = prec->next;
            i++;
        }

        if (prec == NULL || prec->next == NULL) {
            printf("List too short");
            return l;
        }

        list remove = prec->next;
        list l1 = (remove)->next;
        prec->next = l1;
        free(remove);
    }

    return l;
}