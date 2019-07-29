#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	int dataSet[] = {9,13,2,7,11,25}; //Data Set
	int len = sizeof(dataSet)/sizeof(int); //Get length of Data Set
	
	disVis(dataSet, len); //Display bar graph

	QuickSort(dataSet,0,len);
	disVis(dataSet, len);
	return 0;
	//bloop bloop
}
////////////////////////////////////////////////

void legend(int arr[], int len){
	char buffer [50];
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void disVis(int arr[], int len){//display visual
	char buffer [50];
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
