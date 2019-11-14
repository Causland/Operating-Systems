typedef struct process{
    char* id;
    int arrival_time;
    int cpu_burst;
    int wait_time;
    int completion_time;
}process;

typedef struct metrics{
    float avg_wait_time;
    float avg_turnaround_time;
    float throughput;
}metrics;

process* create_process(char* name, int arrival_time, int cpu_burst);
void fcfs_scheduler(process* processes[], int num);
metrics* compute_metrics(process* processes[], int num);