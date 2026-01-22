#include <stdio.h>
#include <unistd.h>
#include "scheduler.h"
#include "can.h"
#include "safety.h"
#include <stdlib.h>

#define SAFE_DISTANCE 1.0
static int unsafe_count = 0;


/* TASKS */

void brake_task() {
    printf("Brake Control: Checking brake pressure\n");
    send_can_message("Brake ECU", "Brake OK");
}

void engine_task() {
    printf("Engine Control: Monitoring engine temperature\n");
    send_can_message("Engine ECU", "Engine Normal");
}

void enter_safe_mode() {
    // simulate safe mode actions
    printf("System is now in SAFE MODE.\n");
}

void sensor_fusion_task() {
    // Optional: make distance dynamic for testing
    float distance = ((rand() % 500) / 100.0); // 0.0m to 5.0m

    printf("Sensor Fusion: Distance = %.2fm\n", distance);

    if(distance < SAFE_DISTANCE) {
        printf("Sensor Fusion: Obstacle detected!\n");
        unsafe_count++;
        if(unsafe_count >= 2) {  // triggers after 2 consecutive unsafe readings
            printf("[SAFETY] Fault detected! Entering SAFE MODE\n");
            enter_safe_mode();  // your existing function
        }
    } else {
    unsafe_count = 0; // reset counter if safe
    }
}

void infotainment_task() {
    printf("Infotainment: Playing music\n");
}

int main() {
    Task brake = {"Brake Task", 10, 1, brake_task};
    Task engine = {"Engine Task", 20, 2, engine_task};
    Task sensor = {"Sensor Fusion Task", 30, 3, sensor_fusion_task};
    Task infotainment = {"Infotainment Task", 100, 4, infotainment_task};

    add_task(brake);
    add_task(engine);
    add_task(sensor);
    add_task(infotainment);

    while (1) {
        run_scheduler();
        sleep(2);
    }

    return 0;
}
