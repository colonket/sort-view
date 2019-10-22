#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAX_DATA_SIZE 4
unsigned int sleep(unsigned int seconds);

void swap(int *x, int *y);
int Partition(int A[], int start, int end);
void QuickSort(int A[], int start, int end);
void disVis(int arr[], int len);
void legend(int arr[], int len);
int max(int arr[], int len);
int digits(int val);

////////////////////////////////////////////////
int main()
{
	int dataSet[MAX_DATA_SIZE] = {};
	srand(time(0));
	for(int i = 0; i<MAX_DATA_SIZE; i++){
		dataSet[i] = rand();
	}
	//int MAX_DATA_SIZE = sizeof(dataSet)/sizeof(int); //Get MAX_DATA_SIZEgth of Data Set
	
	disVis(dataSet, MAX_DATA_SIZE); //Display bar graph

	//QuickSort(dataSet,0,MAX_DATA_SIZE);
	//disVis(dataSet, MAX_DATA_SIZE);
	return 0;
	//bloop bloop
}
////////////////////////////////////////////////

void legend(int arr[], int len){
	char buffer [MAX_DATA_SIZE];
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void disVis(int arr[], int len){//display visual
	char buffer [MAX_DATA_SIZE];
	int hMax = max(arr, len);//height
	int hMin = 0;
	int wMax = len;//width
	int wMin = 0;
	for(int i=hMax; i>hMin; i=i-1)//Line Print
	{
		for(int j=wMin; j<wMax; j++)//Character Print
		{
			if(arr[j] < i){
				for(int k=0; k<digits(arr[j]); k++){
					printf(" ");
				}
				printf(" ");
			}
			else{
				for(int k=0; k<digits(arr[j]); k++){
					printf("#");
				}
				printf(" ");
			}
		}
		printf("\n");
	}
	legend(arr, len);
	//fflush(stdout);
	//sleep(1);
}

int max(int arr[], int len){
	int max = arr[0];
	for(int i=0; i<len; i++){
		if (arr[i] > max){
			max = arr[i];
		}
	}
	return max;
}

int digits(int val){
	int count = 0;
	while(val != 0)
	{
		val /= 10;
		++count;
	}
	return count;
}

void swap(int *x, int *y)//Swap two integers
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
 
int Partition(int A[], int start, int end)
{
	int pivot = A[end];
	int pIndex = start;
	
	for(int i=start; i<end; i++)
	{
		if( A[i] <= pivot )
		{
			swap(&A[i],&A[pIndex]);
			pIndex++;
		}
	}
	swap(&A[end],&A[pIndex]);
	return pIndex;
}
 
void QuickSort(int A[], int start, int end)
{
	if(start<end)//Make sure input is valid
	{
		int pIndex = Partition(A,start,end);
		QuickSort(A,start,pIndex-1);
		QuickSort(A,pIndex+1,end);
		//disVis(A, end);
	}
}
