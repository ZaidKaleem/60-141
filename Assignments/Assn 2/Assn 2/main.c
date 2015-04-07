#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 256


// Function Prototypes
 
void generate_key( int array[], int size ); // This function will generate key that will be used to decrypt
void encrypt_data( char out[], const char in[], const int key[], int size ); // This function will encrypt the data
void decrypt_data( char out[], const char in[], const int key[], int size ); // This function will decrypt the data

int main() {
    
    char inputStr[SIZE];
    char encrypt[SIZE];
    char decrypt[SIZE];
    int key[SIZE];
    int i, size;
    
    printf( "Enter a string to encrypt: " );
    scanf( " %[^\n]s", inputStr ); //to scan a sentence from the keyboard
    
    size = strlen( inputStr ); // strlen is a library function defined in
                                // string.h to find the length of a string
    
    printf( "\nGenerating key...\n" );
    generate_key( key, size ); //should randomly generate unique keys
    
    /** Print keys **/
    printf("Key = ");
	for(i = 0; i < size; i++){
		printf("%d ", key[i]);
	}
	printf("\n");
    
    printf( "Encrypting string...\n" );
    encrypt_data( encrypt, inputStr, key, size ); //Encrypt a string
	
    /** Print encrypted string **/
	printf("Encrypted string: \"%s\"\n", encrypt);
    
    printf( "Decrypting string...\n" );
    decrypt_data( decrypt, encrypt, key, size ); //Decrypt a string
	
    /** Print decrypted string **/
	printf("Decrypted string: \"%s\"\n", decrypt);
    
    return 0;
}




//This function generates unique key
//input is integer array and integer number "size" of the array
//output is void
void generate_key( int array[], int size ){
    
	srand( time( NULL ) );
	int x, y, t, s;
	
	for(x = 0; x < size; x++){
		s = 0;
		while(!s){
			s = 1;
			t = rand() % size;
			for(y = 0; y < x && s; y++){
				if(array[y] == t)
					s = 0;
			}
		}
		array[x] = t;
	}
}


//This function encrypts the data that was entered in by the user
//it has 4 inputs of the type char, const char, const int and int respectively
// output is void
void encrypt_data( char out[], const char in[], const int key[], int size ){
    
	int i;
	for(i = 0; i < size; i++){
		out[i] = in[key[i]];
	}
}


//This function decrypts the data back
//it has 4 inputs of the type char, const char, const int and int respectively
// output is void
void decrypt_data( char out[], const char in[], const int key[], int size ){
    
	int i;
	for(i = 0; i < size; i++){
		out[key[i]] = in[i];
	}
}


// ---------------------------------------------------------------------------
// END OF PROGRAM
// ---------------------------------------------------------------------------