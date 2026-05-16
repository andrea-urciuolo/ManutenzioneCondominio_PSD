#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"
#include "../include/item.h"

// Defines the internal structure of a list node
struct node {
    item data;          // Generic pointer (void*) to the actual data (e.g., technician, request)
    struct node* next;  // Pointer to the next node in the linked list
};

// Initializes and returns a new empty list
list newList() {
    return NULL; // In C, an empty linked list is simply represented by a NULL pointer
}

// Checks if the given list is empty
int emptyList(list l) {
    return (l == NULL); // Returns 1 (true) if the list points to NULL, 0 (false) otherwise
}

// Retrieves the tail of the list (all elements except the head)
list tailList(list l) {
    if (l == NULL) return NULL; // Safety check to prevent dereferencing a NULL pointer
    return l->next;             // Returns the pointer to the second node
}

// Retrieves the data stored in the first node of the list
item getFirst(list l) {
    if (l == NULL) return NULL; // Safety check
    return l->data;             // Returns the generic item stored in the head node
}

// Inserts a new element at the head of the list (push operation)
list consList(list l, item val) {
    // Dynamically allocate memory for the new node
    node* newNode = (node*)malloc(sizeof(node));
    
    // Check if memory allocation was successful
    if (newNode != NULL) {
        newNode->data = val;    // Assign the generic item to the node
        newNode->next = l;      // Link the new node to the current head of the list
        l = newNode;            // Update the head pointer to the new node
    }
    
    return l; // Return the updated list
}

// Calculates the total number of nodes currently in the list
int sizeList(list l) {
    int count = 0;
    
    // Iterate through the list until the end (NULL) is reached
    while (!emptyList(l)) {
        count++;
        l = tailList(l); // Move to the next node
    }
    
    return count;
}

// Creates and returns a new list with elements in reverse order
list reverseList(list l) {
    list reversedList = newList(); // Initialize an empty list for the reversed elements
    
    // Traverse the original list
    while (!emptyList(l)) {
        // Insert the current head of the original list into the head of the new list
        reversedList = consList(reversedList, getFirst(l));
        l = tailList(l); // Move to the next node in the original list
    }
    
    return reversedList; // Return the newly created reversed list
}

// Inserts a new element at a specific index (position 'p') in the list
list insertList(list l, int p, item val) {
    // Special case: Inserting at the head (index 0)
    if (p == 0) return consList(l, val);
    
    int i = 0;
    list current = l;
    
    // Traverse the list to find the node just BEFORE the insertion point (index p - 1)
    while (i < p - 1 && current != NULL) {
        current = current->next;
        i++;
    }

    // If 'current' is NULL, the requested position 'p' is out of bounds
    if (current == NULL) return l;

    // Allocate memory for the new node
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = val;             // Assign the data
        newNode->next = current->next;   // Link the new node to the rest of the list
        current->next = newNode;         // Link the previous node to the new node
    }
    
    return l; // Return the updated list
}

// Removes the element at a specific index (position 'p') and frees its memory
list removeList(list l, int p) {
    // Safety check: Cannot remove from an empty list
    if (l == NULL) return NULL;

    // Special case: Removing the head node (index 0)
    if (p == 0) {
        list tmp = l;       // Temporarily store the head node
        l = tailList(l);    // Move the head pointer to the second node
        free(tmp);          // Prevent memory leaks by freeing the old head node
    } else {
        int i = 0;
        list current = l;

        // Traverse the list to find the node just BEFORE the one to be removed (index p - 1)
        while (i < p - 1 && current != NULL) {
            current = current->next;
            i++;
        }

        // Out of bounds check: either the previous node or the node to remove doesn't exist
        if (current == NULL || current->next == NULL) return l;

        // Bypass the node to be removed
        list nodeToRemove = current->next;
        current->next = nodeToRemove->next;
        
        // Prevent memory leaks by freeing the bypassed node
        free(nodeToRemove); 
    }

    return l; // Return the updated list
}