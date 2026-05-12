#ifndef BTREE_H
#define BTREE_H

#include "technician.h"

typedef struct node node;
typedef node *Btree;

Btree newBtree(void);

int emptyBtree(Btree T);
Btree figlioSX(Btree T);
Btree figlioDX(Btree T);
Btree consBtree(technician val, Btree sx, Btree dx);
node* getRoot(Btree T);
technician getItem(node* N);
void setItem(node* N, technician tech);
Btree insertTechnician(Btree T, technician newTech);
int sizeBtree(Btree T);
void printTreeStructure(Btree T, char* prefix, int isLeft);
void showTree(Btree T);

#endif
