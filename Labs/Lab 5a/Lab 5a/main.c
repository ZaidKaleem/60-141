#include <stdio.h> // Library included

int main() // Initializing function

{
    
    int a = 7 ; // Integer variable declaration
    
    int *aPtr ; // Integer pointer declaration
    
    aPtr = &a ; // Address of variable a allocated to pointer aPtr
    
    printf( "%p\n", &a ); // Prints address of variable a
    
    printf( "%p\n", aPtr ); // Prints address of variable a that is allocated to pointer aPtr
    
    printf( "%p\n", &aPtr ); // Prints address of pointer aPtr
    
    printf( "%d\n", a ); // Prints value stored at variable a
    
    printf( "%d\n", *aPtr ); // Prints value pointed to pointer aPtr
    
    printf( "%p\n", *&aPtr ); // Prints address
    
    printf( "%p\n", &*aPtr ); // Prints address
    
    printf( "%d\n", *&a ); // Prints value stored at the address of variable a
    
    printf( "%d", &*a ); // Does not work because value is part of the memory and address does not exist
    
    
    return 0; 
    
} 
