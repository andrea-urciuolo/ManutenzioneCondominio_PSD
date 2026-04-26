#include "technician.h" //

typedef struct node* list;
typedef struct node node;

// TODO: Migliora le specifiche inserendo 'nil' in newList e getFirst

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
list consList(list l, technician tech);

/* Returns the first technician in the list
   Preconditions:
     l must not be an empty list
   Postconditions:
     l = <a1, a2, ..., an>  /  getFirst(l) -> a1 */
technician getFirst(list l);

/* Returns the number of nodes in the list */
int sizeList(list l);

/* Returns 1 if the technician (based on idCode) is present in the list, 0 otherwise */
int searchTechnician(list l, int targetIdCode);

/* If the technician is present in the list, the function returns the position
   of its first occurrence, otherwise -1 */
int posTechnician(list l, int targetIdCode);

/* Returns a reversed list
   Postconditions:
     l = <a1, a2, ..., an>  /  reverseList(l) -> l' = <an, ..., a2, a1> */
list reverseList(list l);

/* Removes every occurrence of the technician (based on idCode) in the list
   Postconditions:
     l = <a1, a2, tech, ..., an>  /  removeTechnician(l, targetIdCode) -> l' = <a1, a2, ..., an> */
list removeTechnician(list l, int targetIdCode);

/* Prints the list of technicians to the screen */
void outputList(list l);

/* Returns a list composed of n nodes created via input
   Preconditions:
     n >= 0; */
list inputList(int n);

/* Takes a list l as input, returns a list l' identical to l, with the addition of the tech at position p
   Preconditions:
     sizeList(l) >= p
     p >= 0
   Postconditions:
     l = <a1, a2, a3, ..., an> p = 2 / l' = <a1, a2, tech, a3, ..., an> */
list insertList(list l, int p, technician tech);

/* Takes a list l as input, returns a list l' identical to l, with the removal of the element at position p
   Preconditions:
     sizeList(l) >= p
     p >= 0
   Postconditions:
     p = k  /  l = <a1, a2, a3, ..., ak, ..., an>  /  l' = <a1, a2, a3, ..., an> */
list removeList(list l, int p);