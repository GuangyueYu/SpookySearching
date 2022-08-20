#include "multitest.h" 
 
// init a first array 
void fillArray(int n, int *arr) 
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
 
//create a new array from the previous array 
void newArray(int n, int *arr, int index){ 
	int newindex = random(n); 
	int temp = arr[index]; 
	arr[index] = arr[newindex]; 
	arr[newindex] = temp; 
} 
 
//test A 
	//test one time search on both process and thread 
	//we use size of array 20000 for it 
void testA(){ 
	int n = 20000;    
	int arr[n]; 
  	fillArray(n, arr); 
  	int pivot = random(n); 
	search(n, arr, pivot); 
	newArray(n, arr, random(n));
} 
void testAP(){ 
	int n = 20000;    
	int arr[n]; 
  	fillArray(n, arr); 
  	int pivot = random(n); 
	searchProc(n, arr, pivot); 
	newArray(n, arr, random(n));

}
 
//test B will try different size of array to and collect the runtime for them  
void testB(){ 
    //implementation 
} 
 
 
int main(int argc, char **argv) 
{ 
	struct timeval startTime,endTime; 
	int i;
	double span[50];
	for (i = 0; i < 50; i++)
	{
		gettimeofday(&startTime, NULL); 
		testA(); 
 		gettimeofday(&endTime, NULL); 
		span[i] = endTime.tv_sec-startTime.tv_sec + (endTime.tv_usec-startTime.tv_usec)/1000000.0; 
	}
	double min = span[0];
	double max = span[0];
	double total = 0.0;
	double avg;
	double differ, varsum, SD;
	for(i = 0; i < 50; i++)
	{
		if(span[i] < min) min = span[i];
		if(span[i] > max) max = span[i];
		total += span[i];
	}
	avg = total / 50.0;
	for(i = 0; i < 50; i++)
	{
		differ = span[i] - avg;
		varsum = varsum + pow(differ, 2);
	}
	SD = sqrt(varsum / 50.0);
	printf("The size of arr is %d\nnumber of process = %d\n", 20000, 80); 
 	printf("max time = %.12f\nmin time = %.12f\navg time = %.12f\nstandard deviation = %.12f\n", max, min, avg, SD); 
	for (i = 0; i < 50; i++)
	{
		
		gettimeofday(&startTime, NULL); 
		testAP(); 
 		gettimeofday(&endTime, NULL); 
		span[i] = endTime.tv_sec-startTime.tv_sec + (endTime.tv_usec-startTime.tv_usec)/1000000.0; 
	}
	min = span[0];
	max = span[0];
	total = 0.0;
	avg = 0.0;
	differ = 0.0;
	varsum = 0.0;
	SD = 0.0;
	for(i = 0; i < 50; i++)
	{
		if(span[i] < min) min = span[i];
		if(span[i] > max) max = span[i];
		total += span[i];
	}
	avg = total / 50.0;
	for(i = 0; i < 50; i++)
	{
		differ = span[i] - avg;
		varsum = varsum + pow(differ, 2);
	}
	SD = sqrt(varsum / 50.0);
	printf("The size of arr is %d\nnumber of process = %d\n", 20000, 80); 
 	printf("max time = %.12f\nmin time = %.12f\navg time = %.12f\nstandard deviation = %.12f\n", max, min, avg, SD); 

 	return 0; 
} 
 