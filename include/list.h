#ifndef LIST_H
#define LIST_H

#include "../include/item.h"

typedef struct node* list;
typedef struct node node;

/*
 * Function: newList
 * ----------------------
 * Creates a new empty list and returns it
 *
 * Parameters:
 * None
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns a pointer to an empty list (NULL)
 *
 * Returns:
 * The created empty list
 */
list newList();

/*
 * Function: emptyList
 * ----------------------
 * Returns 1 if the list is empty, 0 otherwise
 *
 * Parameters:
 * l: The list to be checked
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns 1 if l == NULL, otherwise returns 0
 *
 * Returns:
 * 1 if the list is empty, 0 otherwise
 */
int emptyList(list l);

/*
 * Function: tailList
 * ----------------------
 * Returns a list containing all the elements of l, except the first one
 *
 * Parameters:
 * l: The list of which we want to get the tail
 *
 * Pre-conditions:
 * l != NULL (l must not be an empty list)
 *
 * Post-conditions:
 * l = <a1, a2, ..., an>  /  tailList(l) -> l' = <a2, ..., an>
 *
 * Returns:
 * The tail of the list
 */
list tailList(list l);

/*
 * Function: consList
 * ----------------------
 * Adds a node to the list, placing it in the first position (head)
 *
 * Parameters:
 * l: The list to which we want to add the element
 * val: The generic item to be inserted into the list
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * l = <a1, a2, ..., an>  /  consList(l, val) -> l' = <val, a1, a2, ..., an>
 * If memory allocation fails, the original list is returned or handled accordingly
 *
 * Returns:
 * The updated list with the new item at the head
 */
list consList(list l, item val);

/*
 * Function: getFirst
 * ----------------------
 * Returns the first item in the list
 *
 * Parameters:
 * l: The list from which we want to extract the first item
 *
 * Pre-conditions:
 * l != NULL (l must not be an empty list)
 *
 * Post-conditions:
 * l = <a1, a2, ..., an>  /  getFirst(l) -> a1
 *
 * Returns:
 * The first item of the list
 */
item getFirst(list l);

/*
 * Function: sizeList
 * ----------------------
 * Returns the number of nodes currently in the list
 *
 * Parameters:
 * l: The list of which we want to calculate the size
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * Returns an integer n >= 0 representing the total number of elements
 *
 * Returns:
 * The number of nodes in the list
 */
int sizeList(list l);

/*
 * Function: reverseList
 * ----------------------
 * Returns a reversed version of the list
 *
 * Parameters:
 * l: The list to be reversed
 *
 * Pre-conditions:
 * None
 *
 * Post-conditions:
 * l = <a1, a2, ..., an>  /  reverseList(l) -> l' = <an, ..., a2, a1>
 *
 * Returns:
 * The reversed list
 */
list reverseList(list l);

/*
 * Function: insertList
 * ----------------------
 * Takes a list l as input and returns a list l' identical to l, 
 * with the addition of the generic item val at position p
 *
 * Parameters:
 * l: The list where the item will be inserted
 * p: The index position for the insertion
 * val: The generic item to be inserted
 *
 * Pre-conditions:
 * sizeList(l) >= p
 * p >= 0
 *
 * Post-conditions:
 * l = <a1, a2, a3, ..., an> p = 2 / l' = <a1, a2, val, a3, ..., an>
 *
 * Returns:
 * The updated list with the new item inserted at position p
 */
list insertList(list l, int p, item val);

/*
 * Function: removeList
 * ----------------------
 * Takes a list l as input and returns a list l' identical to l, 
 * with the removal of the element at position p
 *
 * Parameters:
 * l: The list from which the element will be removed
 * p: The index position of the element to remove
 *
 * Pre-conditions:
 * sizeList(l) >= p (technically sizeList(l) > p for valid index)
 * p >= 0
 *
 * Post-conditions:
 * p = k  /  l = <a1, a2, a3, ..., ak, ..., an>  /  l' = <a1, a2, a3, ..., an>
 *
 * Side-effect:
 * Frees the memory of the removed node 
 *
 * Returns:
 * The updated list without the removed item
 */
list removeList(list l, int p);

#endif