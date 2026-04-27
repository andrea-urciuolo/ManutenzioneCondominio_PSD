#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/request.h"
#include "../include/report.h"
#include "../include/intervention.h"
#include "../include/list.h"
#include "../include/item.h"

int main() {
    // TODO: Crea una lista di intervention completate, separate dall'array di queue

    request r = newRequest();
    printRequest(r);
    deallocateRequest(r);
    return 0;
}