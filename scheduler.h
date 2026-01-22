#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
    char name[30];
    int period;
    int priority;
    void (*task_function)();
} Task;

void add_task(Task task);
void run_scheduler();

#endif
