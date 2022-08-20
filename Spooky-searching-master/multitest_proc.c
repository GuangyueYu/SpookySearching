#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#define random(x) (rand()%x)

void fillArray_2(int n, int *arr)
{
	srand(time(NULL));
 	int value = 0; /* aux. to provide value to set */
	int i; /* loop index */
  	for (i = 0; i < n; ++i)
  	{
  		arr[i] = value;
  		value++;
  	}
  	int a,b,temp,j,k;
  	a = random(n);
  	for(j = 0; j < n*3/4; ++j)
  	{
  		b = random(n);
  		temp = arr[a];
  		arr[a] = arr[b];
  		arr[b] = temp;
  	}
}


void searchProc(int n, int *arr, int pivot)
{
	if(n > 250)
	{
		int numofproc = n / 250;
        int startindex = -250;
        int j = startindex;
        int endindex = 0;
        pid_t pid;
        int i = 0;
        int k;
        while(i < numofproc)
        {
        	startindex = startindex + 250;
        	endindex = endindex + 250;
        	pid = fork();
        	if(pid < 0)//error
        	{
        		printf("fork failed\n");
        		exit(1);
        	}
        	else if(pid == 0)//in child process 
        	{
        		  for(j = startindex; j < endindex; j++)
        		{
					   if(arr[j] == pivot) 
        			{
       					printf("This is multiprocess. Hit in child process %d. The index is %d. Pid is %d \n", i, j, getpid());
						i = j = 2001; 
						break;
					}


        		}
        		// printf("s: %d e:%d \n ", startindex, endindex);
        		exit(0);
        	}
		    	else	
        	{
            for(k = 0; k < numofproc; k++)
            {
              int zero = 0;
              wait(&zero);
            }
   
        	}
        	i++;
        }
	}
	else
	{
		int i = 0;
		for(i; i < n; i++)
		{
			if(arr[i] == pivot) 
			{
				printf("Hit %d in childprocess %d. Pid is %d\n", pivot, i, getpid());
				break;
			}
		}
	}
}



	// int n_2 = n / 2;
	// if(!n) return;
	//  printf("search %d...\n", pivot); /* assumes (int)pivot makes sense */
 // 	if (n_2 >= 1) {
 //    pid_t pid;
 //    pid = fork();
 //    // if (pid < 0) {
 //    //   fprintf(stderr, "ERROR: fork failed!\n");
 //    //   return;
 //    // }
 //    if (pid == 0) { /* in parent process */
 //      int i;
 //      for (i = n_2; i < n; ++i) {
 //        if (arr[i] == pivot) break;
 //      }
 //      if (i < n) { /* element at i is a hit */
 //        printf("Hit %d (found in parent) \n", i);
 //      }
 //    } else { /* in child process */
 //      int i;
 //      for (i = 0; i < n_2; ++i) {
 //        if (arr[i] == pivot) break;
 //      }
 //      if (i < n_2) { /* element at i is a hit */
 //        printf("Hit %d (found in child)\n", i);
 //      }
 //      /* terminate child process */
 //      exit(0); /* funny things happen if this were not here */
 //    }
 //  } else { /* special case: only 1 element in array */
 //    if (arr[0] == pivot) {
 //      printf("Hit 0 (found)\n");
 //    }
 //  }




