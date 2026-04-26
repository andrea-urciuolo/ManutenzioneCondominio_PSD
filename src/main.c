#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/technician.h"
#include "../include/request.h"
#include "../include/report.h"
#include "../include/intervention.h"

int main() {
    // TEST request adt
    request r = newRequest();
    printRequest(r);
    deallocateRequest(r);
    return 0;
}