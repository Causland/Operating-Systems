#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"

process* create_process(char* name, int arrival_time, int cpu_burst){
    process* p = malloc(sizeof(process));
    p->id = strdup(name);
    p->arrival_time = arrival_time;
    p->cpu_burst = cpu_burst;
    return p;
}

void fcfs_scheduler(process* processes[], int num){
    int i;
    int comp_time = 0;
    process* temp;
    for(i=0;i<num;i++){
        temp = processes[i];
        temp-> wait_time = comp_time;
        temp->completion_time = comp_time + temp->cpu_burst;
        comp_time += temp->cpu_burst;
    }
}

metrics* compute_metrics(process* processes[], int num){
    int i;
    float sum_wait = 0;
    float sum_completion = 0;
    float total_time = 0;
    process* temp;
    metrics* m = malloc(sizeof(metrics));
    for(i=0;i<num;i++){
        temp = processes[i];
        sum_wait += temp->wait_time;
        sum_completion += temp->completion_time;
        total_time += temp->cpu_burst;
    }
    m->avg_wait_time = sum_wait/num;
    m->avg_turnaround_time = sum_completion/num;
    m->throughput = num/total_time;
    return m;
}