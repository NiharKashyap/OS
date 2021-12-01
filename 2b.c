#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

typedef struct process
{
    int arrival_time;
    int burst_time;
    int remain_time;
    int isCompleted;
    int TAT;
    int waiting_time;
    int completion_time;
    int Id;
} process;

typedef struct process_arr
{
    int count;
    process *list;
} process_arr;

int swap(process *a, process *b)
{
    process temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
    return 0;
}

int sort(process_arr *p)
{
	int i, j;
	process temp;
	
    for (i = 0; i < p->count; i++)
    {
        for (j = 1; j < p->count - i; j++)
        {
            if (p->list[j - 1].arrival_time > p->list[j].arrival_time)
            {
				swap(&p->list[j - 1], &p->list[j]);
            }
        }
    }
}

int disp(process_arr *p)
{
	int i;
	float avTAT=0;
	float avWT=0;
	printf("\n\nPROCESS TABLE\n");
	printf("\n------------------------------\n");
	printf("PNo | AT | BT | TAT | WT | CT\n");
	printf("------------------------------\n");
	for(i=0;i<p->count;i++)
	{
		avTAT = avTAT + p->list[i].TAT;
		avWT  = avWT +  p->list[i].waiting_time;
		
		printf(" %d  |", i+1);
		printf("  %d |", p->list[i].arrival_time);
		printf("  %d |", p->list[i].burst_time);
		printf("  %d  |", p->list[i].TAT);
		printf("  %d |", p->list[i].waiting_time);
		printf("  %d\n", p->list[i].completion_time);
		printf("------------------------------\n");
	}
	avTAT = avTAT/p->count;
	avWT = avWT/p->count;
	
	printf("Average Turn Around Time: %f\n", avTAT);
	printf("Average Waiting Time: %f", avWT);
	
	return 0;
}

int roundRobinScheduling(process_arr *p, int q)
{
	int currTime,i, completed=0;
	int time=0;
	currTime = p->list[0].arrival_time;
	printf("Scheduling Sequence: \n\n");
	
	while(completed!=p->count)
	{
		for(i=0;i<p->count;i++)
		{
			if(p->list[i].arrival_time<=currTime && p->list[i].isCompleted==0)
			{
				if(p->list[i].remain_time>q)
				{
					time=time+q;
					currTime+=q;
					p->list[i].remain_time-=q;
					printf("p%d ",i+1);
				}
				else
				{
					time=time + p->list[i].remain_time;
					currTime+=p->list[i].remain_time;
					p->list[i].waiting_time = time-p->list[i].burst_time;
					completed+=1;
					p->list[i].isCompleted=1;
					p->list[i].completion_time=time;
					p->list[i].TAT = p->list[i].completion_time - p->list[i].arrival_time;
					printf("p%d ",i+1);
				}
			}	
		}	
	}
}

int main()
{
	process_arr *p;
    int n, at, bt, q;

    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &q);

	p = (process_arr *)malloc(sizeof(process_arr) * n);
    p->list = (process *)malloc(sizeof(process) * n);
    p->count = n;
	
	int i;
	
    for (i = 0; i < p->count; i++)
    {
        printf("Enter the Arrival and Burst time of p%d ", i + 1);
        scanf("%d %d", &at, &bt);
        p->list[i].arrival_time = at;
        p->list[i].burst_time = bt;
        p->list[i].remain_time = bt;
        p->list[i].isCompleted = 0;
        p->list[i].completion_time = 0;
        p->list[i].TAT = 0;
        p->list[i].waiting_time = 0;
        p->list[i].Id = i;
    }
    
	sort(p);
    printf("\n");
    printf("Round Robin Scheduling\n");
    roundRobinScheduling(p, q);
	disp(p);
    printf("\n");

    return 0;
}
