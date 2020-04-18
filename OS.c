#include<stdio.h>

struct process
{
char p_name;
int at, bt, ct, wt, tat, priority; int status;
}p_queue[10]; int limit;
void at_Sorting()
{
struct process temp; int i, j;
for(i = 0; i < limit - 1; i++)
{
for(j = i + 1; j < limit; j++)
{
if(p_queue[i].at > p_queue[j].at)
{
temp = p_queue[i]; p_queue[i] = p_queue[j]; p_queue[j] = temp;
}
}
}
}

void main()
{
int i, time = 0, bt = 0, largest; char c;
float wait_time = 0, tat = 0, Avg_wt, Avg_tat; printf("\nEnter Total Number of Processes:\t"); scanf("%d", &limit);
for(i = 0, c = 'A'; i < limit; i++, c++)
{
p_queue[i].p_name = c;
printf("\nEnter Details For Process[%C]:\n", p_queue[i].p_name); printf("Enter Arrival Time:\t");
scanf("%d", &p_queue[i].at ); printf("Enter Burst Time:\t");
 
scanf("%d", &p_queue[i].bt); printf("Enter Priority:\t"); scanf("%d", &p_queue[i].priority); p_queue[i].status = 0;
bt = bt + p_queue[i].bt;
}
at_Sorting(); p_queue[9].priority = -9999;
printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time"); for(time = p_queue[0].at; time < bt;)
{
largest = 9;
for(i = 0; i < limit; i++)
{
if(p_queue[i].at <= time && p_queue[i].status != 1 && p_queue[i].priority
> p_queue[largest].priority)
{
largest = i;
}
}
time = time + p_queue[largest].bt; p_queue[largest].ct = time;
p_queue[largest].wt = p_queue[largest].ct - p_queue[largest].at - p_queue[largest].bt;
p_queue[largest].tat = p_queue[largest].ct - p_queue[largest].at; p_queue[largest].status = 1;
wait_time = wait_time + p_queue[largest].wt; tat = tat + p_queue[largest].tat;
printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", p_queue[largest].p_name, p_queue[largest].at, p_queue[largest].bt, p_queue[largest].priority, p_queue[largest].wt);
}
Avg_wt = wait_time / limit; Avg_tat = tat / limit;
printf("\n\nAvg waiting time:\t%f\n", Avg_wt); printf("Avg Turnaround Time:\t%f\n", Avg_tat);

}
