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
