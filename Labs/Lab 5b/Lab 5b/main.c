
// Zaid Kaleem
// 103619897
// Lab 5b

// -------------------------------------------------------

// Libraries included in the program.
#include<stdio.h>
#include<time.h>

#define SIZE 20

// Function prototypes
void FillArray ( int *array, int size );
void PrintArray ( int *array, int size );
void BubbleSort ( int *array, int size );
void Swap ( int *x, int *y );

// Initilizing function that will be used to call other functions.
int main(){
	int NumList[SIZE]; // Integer array declaration with the size of SIZE.
	FillArray( NumList, SIZE ); // Function call to populate the NumList array.
    
	printf("Unsorted:\n");
	PrintArray( NumList, SIZE ); // Function call to print the populated array
    
	BubbleSort( NumList, SIZE ); // Function call to sort the populated array using BubbleSort method.
    
	printf("Sorted:\n");
	PrintArray( NumList, SIZE ); // Function call to print sorted array.
    
	return 0;
}

// This function fills the array with random numbers from 0 - 100
// Input is integer pointer and integer variable
// Output is void
void FillArray ( int *array, int size ){
	int i;
    
	srand(time(NULL));
    
	for(i = 0; i < size; i++)
		*(array + i) = rand() % 101;
}

// This function prints the array
// Input is integer pointer and integer variable
// Output is void
void PrintArray ( int *array, int size ){
	int i;
    
	for(i = 0; i < size; i++)
		printf("%d ", *(array + i));
    
	printf("\n");
}

// This function is used to sort the array using Bubble Sort method
// Input is integer pointer and integer variable
// Output is void
void BubbleSort ( int *array, int size ){
	int x, y;
    
	for(x = 0; x < size; x++)
		for(y = 0; y < size - 1; y++)
			if(*(array+y) < *(array+y+1))
				Swap(array+y, array+y+1);
}

// This function is used to swap the values when soring the array using BubbleSort.
// Inputs are 2 integer pointers.
// Output is void
void Swap ( int *x, int *y ){
	int t = *x;
	*x = *y;
	*y = t;
}


// --------------------------------------------------------------
// END OF PROGRAM
// --------------------------------------------------------------
