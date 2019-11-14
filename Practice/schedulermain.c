#include <stdio.h>
#include "scheduler.h"

int main(){

    process* processes[3];
    process* p0 = create_process("P0", 0, 1);
    process* p1 = create_process("P1", 0, 10);
    process* p2 = create_process("P2", 0, 1);

    processes[0] = p0;
    processes[1] = p1;
    processes[2] = p2;

    fcfs_scheduler(processes, 3);

    process* temp;
    metrics* tempMet = compute_metrics(processes, 3);
    int i;
    for(i=0;i<3;i++){
        temp = processes[i];metrics* compute_metrics(process* processes[], int num);
        printf("Process %s compl time is %i and wait time is %i\n", temp->id, temp->completion_time, temp->wait_time);
        }
        printf("Metrics -> Avg wait: %f Avg turnaround: %f Avg throughput: %f\n", tempMet->avg_wait_time, tempMet->avg_turnaround_time, tempMet->throughput);
    
    return 0;
}