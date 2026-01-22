#include <stdio.h>
#include "can.h"

void send_can_message(char sender[], char message[]) {
    printf("[CAN BUS] %s sent: %s\n", sender, message);
}
