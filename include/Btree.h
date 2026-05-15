#ifndef BTREE_H
#define BTREE_H

#include "technician.h"

// Definition of the node structure
typedef struct node node;
// Pointer to the Btree structure
typedef node *Btree;

/*
 * Function: newBtree
 * ----------------------
 * Initializes an empty binary tree
 *
 * Parameters:
 *   None (void)
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns an empty binary tree
 *
 * Returns:
 *   A new instance of Btree representing an empty tree
 */
Btree newBtree(void);

/*
 * Function: emptyBtree
 * ----------------------
 * Checks if the binary tree is empty
 *
 * Parameters:
 *   T: The binary tree to check
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns 1 if the tree is empty, 0 otherwise
 *
 * Returns:
 *   An int representing a boolean value
 */
int emptyBtree(Btree T);

/*
 * Function: figlioSX
 * ----------------------
 * Returns the left subtree of the given binary tree
 *
 * Parameters:
 *   T: The binary tree from which to extract the left child
 *
 * Pre-conditions:
 *   T != NULL
 *
 * Post-conditions:
 *   Returns the pointer to the left child node of T
 *
 * Returns:
 *   The left subtree (Btree) or NULL if T is NULL
 */
Btree figlioSX(Btree T);

/*
 * Function: figlioDX
 * ----------------------
 * Returns the right subtree of the given binary tree
 *
 * Parameters:
 *   T: The binary tree from which to extract the right child
 *
 * Pre-conditions:
 *   T != NULL
 *
 * Post-conditions:
 *   Returns the pointer to the right child node of T
 *
 * Returns:
 *   The right subtree (Btree) or NULL if T is NULL
 */
Btree figlioDX(Btree T);

/*
 * Function: consBtree
 * ----------------------
 * Constructs a new binary tree node with a given technician and subtrees
 *
 * Parameters:
 *   val: The technician structure to be stored in the new node
 *   sx: The left subtree (Btree) to be attached
 *   dx: The right subtree (Btree) to be attached
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns a new Btree node containing 'val', with 'sx' and 'dx'
 *   as its children. Returns NULL if memory allocation fails.
 *
 * Returns:
 *   The newly created Btree or NULL if allocation fails
 */
Btree consBtree(technician val, Btree sx, Btree dx);

/*
 * Function: getRoot
 * ----------------------
 * Returns the root node of the binary tree
 *
 * Parameters:
 *   T: The binary tree from which to get the root
 *
 * Pre-conditions:
 *   T != NULL
 *
 * Post-conditions:
 *   Returns the pointer to the root node of the tree
 *
 * Returns:
 *   The root node of the tree
 */
node* getRoot(Btree T);

/*
 * Function: getItem
 * ----------------------
 * Returns the technician stored within a specific tree node
 *
 * Parameters:
 *   N: The node from which to extract the technician data
 *
 * Pre-conditions:
 *   N != NULL
 *
 * Post-conditions:
 *   Returns the technician structure if the node exists; otherwise, returns NULL
 *
 * Returns:
 *   The technician pointer associated with the node
 */
technician getItem(node* N);

/*
 * Function: setItem
 * ----------------------
 * Updates the technician data stored within a specific tree node
 *
 * Parameters:
 *   N: The node where the technician will be stored
 *   tech: The technician structure to assign to the node
 *
 * Pre-conditions:
 *   N != NULL
 *   tech != NULL
 *
 * Post-conditions:
 *   The value field of node N is updated to point to 'tech',
 *   if N is not NULL.
 *
 * Returns:
 *   void
 */
void setItem(node* N, technician tech);


/*
 * Function: insertTechnician
 * ----------------------
 * Inserts a new technician into the binary tree (ordering it by type)
 *
 * Parameters:
 *   T: The binary tree where the technician will be inserted
 *   newTech: The technician structure to be added to the tree
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns a new tree structure containing the inserted technician.
 *   The insertion follows a BST logic: if the new technician's
 *   specialization is less than or equal to the root's, it is
 *   inserted into the left subtree; otherwise, into the right subtree.
 *
 * Side-effect:
 *   Allocates a new node and recursively reconstructs the path
 *   to the insertion point.
 *
 * Returns:
 *   The updated Btree containing the new technician
 */
Btree insertTechnician(Btree T, technician newTech);

/*
 * Function: sizeBtree
 * ----------------------
 * Calculates the total number of nodes in the binary tree
 *
 * Parameters:
 *   T: The binary tree to measure
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns the total count of technician nodes currently in the tree
 *
 * Returns:
 *   An int representing the size of the tree
 */
int sizeBtree(Btree T);

/*
 * Function: clearTreeNodes
 * ----------------------
 * Recursively deallocates all nodes within the binary tree
 *
 * Parameters:
 *   T: The binary tree to be cleared
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   All nodes in the tree are freed from memory.
 *
 * Side-effect:
 *   Frees the memory of every node in the tree. The technician within
 *   the node don't get freed.
 *
 * Returns:
 *   void
 */
void clearTreeNodes(Btree T);

// VISUALIZERS (for testing and --dev mode)

// Organizes the Tree to be able to be printed
void printTreeStructure(Btree T, char* prefix, int isLeft);

// Prints the organized Tree
void showTree(Btree T);

#endif
