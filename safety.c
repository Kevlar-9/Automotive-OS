#include <stdio.h>
#include "safety.h"

void safety_check(int fault) {
    if (fault) {
        printf("[SAFETY] Fault detected! Entering SAFE MODE\n");
    } else {
        printf("[SAFETY] System operating normally\n");
    }
}
