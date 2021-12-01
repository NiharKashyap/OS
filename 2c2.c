#include<stdio.h>
#include<conio.h>
#include <stdlib.h>


typedef struct process
{
    int arrival_time;
    int burst_time;
    int priority;
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

int PriorityBasedPreemptive(process_arr *p)
{
	int currTime,i,completed=0, prev;
	int time=0;
	currTime = p->list[0].arrival_time;
	
	int index;
	int currLargest;
	printf("Scheduling Sequence: \n\n");
	
	while(completed!=p->count)
	{
		index = -1;
		currLargest=0;
		
		for(i=0;i<p->count;i++)
		{
			if(p->list[i].arrival_time<=currTime && p->list[i].isCompleted==0)
			{
				if(p->list[i].priority>currLargest)
				{
					currLargest = p->list[i].priority;
					index = i;
				}
			}
		}
		
		if(index!=-1)
		{			
				if (prev != index)
            	{
                	printf("p%d ", p->list[index].Id + 1);
            	}
				p->list[index].remain_time--;
            	currTime++;
    			prev = index;
    			
            	if (p->list[index].remain_time == 0)
           	 	{
	                p->list[index].completion_time = currTime;
	                p->list[index].TAT = p->list[index].completion_time - p->list[index].arrival_time;
	                p->list[index].waiting_time = p->list[index].TAT - p->list[index].burst_time;
	                p->list[index].isCompleted = 1;
	                completed++;
	                //printf("p%d ",index+1);
            	}
				
			}
			else
			{
				currTime++;
			}
	}
}

//Non-Premtive
int PriorityBased(process_arr *p)
{
	int currTime,i,completed=0;
	int time=0;
	currTime = p->list[0].arrival_time;
	
	int index;
	int currLargest;
	printf("Scheduling Sequence: \n\n");
	
	while(completed!=p->count)
	{
		index = -1;
		currLargest=0;
		
		for(i=0;i<p->count;i++)
		{
			if(p->list[i].arrival_time<=currTime && p->list[i].isCompleted==0)
			{
				if(p->list[i].priority>currLargest)
				{
					currLargest = p->list[i].priority;
					index = i;
				}
			}
		}
		
		if(index!=-1)
			{
					time=time + p->list[index].burst_time;
					currTime+=p->list[index].burst_time;
					p->list[index].waiting_time = time - p->list[index].burst_time;
					completed+=1;
					p->list[index].isCompleted=1;
					p->list[index].completion_time=time;
					p->list[index].TAT = p->list[index].completion_time - p->list[index].arrival_time;
					printf("p%d ",index+1);
			}
			else
			{
				currTime++;
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

int main()
{
	process_arr *p;

    int n, at, bt,pr;

    printf("Enter the no of processes: ");
    scanf("%d", &n);
	
	p =(process_arr*)malloc(sizeof(process_arr));
	
    p->list = (process *)malloc(sizeof(process) * n);
    p->count = n;
	
	int i;
    for (i = 0; i < p->count; i++)
    {
        printf("Enter the Arrival, Burst time and Priority of p%d ", i + 1);
        scanf("%d %d %d", &at, &bt, &pr);
        p->list[i].arrival_time = at;
        p->list[i].burst_time = bt;
        p->list[i].remain_time = bt;
        p->list[i].priority=pr;
        p->list[i].isCompleted = 0;
        p->list[i].completion_time = 0;
        p->list[i].TAT = 0;
        p->list[i].waiting_time = 0;
        p->list[i].Id = i;
    }

    sort(p);
    printf("\n");
    printf("Premtive Priority Scheduling\n\n");
    PriorityBasedPreemptive(p);
    disp(p);
    printf("\n");

    return 0;
}
