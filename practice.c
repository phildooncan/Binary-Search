#include <stdio.h>
#include <stdlib.h>

// create an array of size n with random numbers between 100, print the array, return the array
int *createArr(int size)
{
	// dynamically allocate memory for the array
	int i, *array = NULL;
	array = malloc(sizeof(int) * size);
	
	
	// populate the arrays with nums 1-100
	puts("This is the unsorted array: ");
	for(i = 0; i < size; i++)
	{
		array[i] = (rand() % 100 ) + 1;
		if(i == 20)
			printf("\n");
		printf("%d ", array[i]);
	}
	
	printf("\n\n");
	
	free(array);
	
	return array;
}

// sort the array in non-decreasing order, print it, then return the array
int *sortArr(int *arr, int size){
	
	// sort the array in non-decreasing order
	int i, j, temp;
	for(i = 0; i < size; i++)
	{
		for( j = i + 1; j < size; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	puts("This is the sorted array: ");
	
	// print the sorted array
	for(i = 0; i < size; i++){
		if(i == 20)
			printf("\n");
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	
	return arr;
}

//implement binary search  algorithm to find the given number
void findEl(int *sortedArr, int num, int size)
{
	int lo = 0, mid = (size - 1 )/ 2, hi = (size - 1), temp, complete = 0;
	
	while(complete != 1)
	{
		if(mid - lo == 0 | hi - mid == 0)
		{
			if(num == sortedArr[lo])
			{
				printf("The number %d was found at position %d", num, lo);
				complete = 1;
			}
			else if(num == sortedArr[hi])
			{
				printf("The number %d was found at position %d", num, hi);
				complete = 1;
			}
			else
			{
				printf("Sorry, the number %d is not in the array", num);
				complete = 1;
			}
		}
		else if(num == sortedArr[mid])
		{
			printf("The number %d was found at position %d", num, mid);
			complete = 1;
		}
		else if(num > sortedArr[mid])
		{
			lo = mid;
			mid = (hi + lo) / 2;
		}
		else if(num < sortedArr[mid])
		{
			hi = mid;
			mid = (hi + lo) / 2;
		}
		
	}
}

int main(void)
{
	int n, *unsortedArr, *sorted, key;
	puts("How big is the array?");
	scanf("%d", &n);
	
	unsortedArr = createArr(n);
	sorted = sortArr(unsortedArr, n);
	
	puts("What number do you wanna find?");
	scanf("%d", &key);
	findEl(sorted, key, n);
	
	return 0;
}