#include <stdio.h>



// Print the given array
void printArray(int arr[], int SIZE)
{
    int i;

    for(i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}

void rotateByOne(int arr[], int SIZE)
{
    int i, last;

    // Store last element of array
    last = arr[SIZE - 1];

    for(i=SIZE-1; i>1; i--)
    {
        // Move each array element to its right
        arr[i] = arr[i - 1];
    }

    // Copy last element of array to first
    arr[1] = last;
}

int main()
{
    int i, N;
    int SIZE;
    int temp;
	scanf("%d",&SIZE);
    
    if(SIZE>100 || SIZE<1)
    {
    	return 0;
	}
    
	int arr[SIZE];
	
    for(i=0; i<SIZE; i++)
    {
    	scanf("%d", &temp);
    	if(temp>100 || temp<-100)
    	{
    		return 0;
		}
		else
		{
			arr[i] = temp;	
		}
        
    }

    scanf("%d", &N);
	
	if(N>100 && N<1)
    {
    	return 0;
	}
	
    // Actual rotation
    N = N % SIZE;

    // Print array before rotation
    printf("Array before rotationn");
    printArray(arr, SIZE);

    
    for(i=1; i<=N; i++)
    {
        rotateByOne(arr, SIZE);
    }

    
    printf("\n\nArray after rotation\n");
    printArray(arr, SIZE);

    return 0;
}
