#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> 
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h> 
#include <math.h>

#define random(x) (rand()%x)
#include <pthread.h> 
#include <math.h>


#ifndef _MULTITEST_H
#define _MULTITEST_H

void searchProc(int n, int *arr, int pivot);

void search(int n, int *arr, int pivot);
 
#endif
