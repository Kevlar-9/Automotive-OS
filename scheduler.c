#include <stdio.h>
#include "scheduler.h"

#define SAFE_DISTANCE 1.0   // distance in meters that is considered safe
static int unsafe_count = 0; // counts consecutive unsafe readings
#define MAX_TASKS 10

Task tasks[MAX_TASKS];
int task_count = 0;

void add_task(Task task) {
    tasks[task_count++] = task;
}

void sort_tasks() {
    for (int i = 0; i < task_count - 1; i++) {
        for (int j = i + 1; j < task_count; j++) {
            if (tasks[i].period > tasks[j].period) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void run_scheduler() {
    sort_tasks();
    printf("\n[Scheduler] Running tasks (Rate Monotonic Scheduling)\n");

    for (int i = 0; i < task_count; i++) {
        printf("[Scheduler] Executing %s\n", tasks[i].name);
        tasks[i].task_function();
    }
}


