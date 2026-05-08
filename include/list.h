#ifndef LIST_H
#define LIST_H

#include "../include/item.h"

typedef struct node* list;
typedef struct node node;

/* Creates a new empty list and returns it */
list newList();

/* Returns 1 if the list is empty, 0 otherwise */
int emptyList(list l);

/* Returns a list containing all the elements of l, except the first one
   Preconditions:
     l must not be an empty list
   Postconditions:
     l = <a1, a2, ..., an>  /  tailList(l) -> l' = <a2, ..., an> */
list tailList(list l);

/* Adds a node to the list, placing it in the first position
   Postconditions:
     l = <a1, a2, ..., an>  /  consList(l, tech) -> l' = <tech, a1, a2, ..., an> */
list consList(list l, item val);

/* Returns the first technician in the list
   Preconditions:
     l must not be an empty list
   Postconditions:
     l = <a1, a2, ..., an>  /  getFirst(l) -> a1 */
item getFirst(list l);

/* Returns the number of nodes in the list */
int sizeList(list l);

/* Returns a reversed list
   Postconditions:
     l = <a1, a2, ..., an>  /  reverseList(l) -> l' = <an, ..., a2, a1> */
list reverseList(list l);

/* Takes a list l as input, returns a list l' identical to l, with the addition of the tech at position p
   Preconditions:
     sizeList(l) >= p
     p >= 0
   Postconditions:
     l = <a1, a2, a3, ..., an> p = 2 / l' = <a1, a2, tech, a3, ..., an> */
list insertList(list l, int p, item val);

/* Takes a list l as input, returns a list l' identical to l, with the removal of the element at position p
   Preconditions:
     sizeList(l) >= p
     p >= 0
   Postconditions:
     p = k  /  l = <a1, a2, a3, ..., ak, ..., an>  /  l' = <a1, a2, a3, ..., an> */
list removeList(list l, int p);

#endif
