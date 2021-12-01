#include<stdio.h>
int main()
{
    int numFrames=3, numPages=11,faults = 0;
	int frames[3], temp[10], flag1, flag2, flag3, fflag, i, j, k, pos, max;
    
	
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
        fflag=0;
        for(j = 0; j < numFrames; j++)
		{
            if(frames[j] == pages[i])
				{
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
                    faults++;
                    fflag=1;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
		{
         flag3 =0;
        
            for(j = 0; j < numFrames; j++)
			{
             temp[j] = -1;
            
             for(k = i + 1; k < numPages; k++)
			 {
	             if(frames[j] == pages[k])
				 {
	             	temp[j] = k;
	             	break;
	             }
             }
            }
            
            for(j = 0; j < numFrames; j++)
			{
             if(temp[j] == -1)
			 {
             pos = j;
             flag3 = 1;
             break;
             }
            }
            
            if(flag3 ==0)
			{
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < numFrames; j++)
			 {
	             if(temp[j] > max)
				 {
	             max = temp[j];
	             pos = j;
	             }
             }            
            }
			frames[pos] = pages[i];
			faults++;
			fflag=1;
        }
        
        printf("\n");
        
        for(j = 0; j < numFrames; j++)
		{
            printf("%d\t", frames[j]);
        }
        if(fflag==0)
        {
        	printf("Hit\n");
		}
		else
		{
			printf("Miss\n");
		}
    }
    
    printf("\nNumber of Page Faults = %d", faults);
    
    return 0;
}
