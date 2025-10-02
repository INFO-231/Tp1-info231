#include <stdio.h>
#include "liste_ldc.h"

int main() {
    ListeLDC liste = {NULL};

    insererQueueLDC(&liste, 10);
    insererQueueLDC(&liste, 20);
    insererQueueLDC(&liste, 30);
    insererQueueLDC(&liste, 40);

    afficherListeLDC(&liste);

    libererListeLDC(&liste);
    return 0;
}