#include<stdio.h>
 
int findPage(int time[], int n)
{
	int i, minimum = time[0], pos = 0;
	 
	for(i = 1; i < n; ++i)
	{
		if(time[i] < minimum)
		{
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
 
int main()
{
    int numFrames=3, numPages=11, counter=0, faults = 0;
	int frames[3], time[3], flag1, flag2, i, j, pos;
	
	numFrames = 3;
	numPages = 11;
	
	int pages[] = {3, 2, 1, 3, 4, 1, 6, 2, 4, 1, 6};

    
	for(i = 0; i < numFrames; i++)
	{
     frames[i] = -1;
    }
    
    printf("Given Sequence is: ");
    
    for(i=0;i<numPages;i++)
    {
    	printf("%d ", pages[i]);
	}
    
    printf("\n\n");
    
	printf("Frame1 Frame2 Frame3    Result");
	
    for(i = 0; i < numPages; i++)
	{
		
     flag1 = flag2 = 0;
    
     for(j = 0; j < numFrames; j++)
	 {
	     if(frames[j] == pages[i])
		 {
		     counter++;
		     time[j] = counter;
		   	 flag1 = flag2 = 1;
		   	 break;
	     }
     }
    
     if(flag1 == 0)
	 {
     	
		for(j = 0; j < numFrames; j++)
		{
		     if(frames[j] == -1)
			 {
			     counter++;
			     faults++;
			     frames[j] = pages[i];
			     time[j] = counter;
			     flag2 = 1;
			     break;
		     }
     	}
     }
    
     if(flag2 == 0)
	 {
	     pos = findPage(time, numFrames);
	     counter++;
	     faults++;
	     frames[pos] = pages[i];
	     time[pos] = counter;
     }
    
     printf("\n");
    
     for(j = 0; j < numFrames; j++)
	 {
     	printf("%d\t", frames[j]);
     }
     if(flag1==0 || flag2==0)
     {
     	printf("Miss\n");
	 }
	 else
	 {
	 	printf("Hit\n");
	 }
	}
printf("\nNumber of Page Faults = %d", faults);
    
    return 0;
}

