typedef struct node* list;
typedef struct node node;

//Crea una nuova lista vuota e restituisce la lista creata
list newList();


//Restituisce 1 se la lista è vuota, altrimenti 0
int emptyList(list l);


//Restituisce una lista che contiene tutti gli elementi di l, tranne il primo
//Precondizioni:
//  l non deve essere una lista vuota
//Postcondizioni:
//  l = <a1, a2, ..., an>  /  tailList(l) -> l' = <a2, ..., an>
list tailList(list l);


//Aggiunge un nodo alla lista, ponendolo in prima posizione
//PostCondizioni:
//  l = <a1, a2, ..., an>  /  consList(l, value) -> l' = <value, a1, a2, ..., an>
list consList(list l, item value);


//Restituisce il primo item della lista
//Precondizioni:
//  l non deve essere una lista vuota
//Postcondizioni:
//  l = <a1, a2, ..., an>  /  getfirst(l) -> a1
item getFirst(list l);


//Restituisce il numero di nodi della lista
int sizeList(list l);


//Restituisce 1 se value è presente nella lista, altrimenti 0
int searchItem(list l, item value);


//Se value è presente nella lista, la funzione restituisce la posizione nella lista
//della prima occorrenza di value, altrimenti -1
int posItem(list l, item value);


//Restituisce una lista di ordine inverso
//Postcondizioni:
//  l = <a1, a2, ..., an>  /  reverseList(l) -> l' = <an, ..., a2, a1>
list reverseList(list l);


//Rimuove ogni occorrenza di value nella lista
//Postcondizioni:
//  l = <a1, a2, value, ..., an>  /  removeItem(l, value) -> l' = <a1, a2, ..., an>
list removeItem(list l, item value);


//Stampa a schermo la lista
void outputList(list l);


//Restituisce una lista composta da n nodi
//Precondizioni:
//  n >= 0;
list inputList(int n);


//Presa una lista l in input, restituisce una lista l' identica a l, con l'aggiunta dell'elemento value alla posizione p
//Precondizioni:
//  sizeList(l) >= p
//  p >= 0
//Postcondizioni:
//  l = <a1, a2, a3, ..., an> p = 2 / l' = <a1, a2, value, a3, ..., an>
list insertList(list l, int p, item value);

//Presa una lista l in input, restituisce una lista l' identica a l, con la rimozione dell'elemento in posizione p
//Precondizioni:
//  sizeList(l) >= p
//  p >= 0
//Postcondizioni:
//  p = k  /  l = <a1, a2, a3, ..., ak, ..., an>  /  l' = <a1, a2, a3, ..., an;
list removeList(list l, int p)