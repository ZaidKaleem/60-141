// Zaid Kaleem
// 103619897
// Lab 7

// Libraries Included
#include<stdio.h>
#include<stdlib.h>

// Function Prototypes
int menu();
int AtoI ( const char * str );
int StrCmp ( const char * str1, const char * str2 );
char * StrCpy ( char * destination, const char * source );
char * StrCat ( char * destination, const char * source );
char * StrChr ( char * str, int character );

// Initializing function
int main()
{
	int ch, answer; // Integer variable declaration for the choice and final answer
	char character, source[256], destination[256];  // Char variable for source (input) and destination (output)
    
	ch = menu(); // Calling the menu function to get the user to select a function
    
	while(1)
	{
		switch (ch) {       // Switch case being used so program can run functions corresponding to the user's choice
			case 1 :
				printf("Enter a string to convert into integer (numbers only): ");
				fgets(source, 255, stdin);
				printf("%s converted to integer is %d\n", source, AtoI(source));
				break;
                
			case 2 :
				printf("Enter string 1: ");
				fgets(source, 255, stdin);  // Reading input from the keyboard for the source variable
				printf("Enter string 2: ");
				fgets(destination, 255, stdin); // Reading input from the keyboard for destination variable
				answer = StrCmp(source, destination);
				if(answer > 0)      // Checking if string 1 is greater than 0
					printf("String 1 > String 2\n");    // If it is then printing this statement
				else if(answer< 0)  // If string is not greater than 0 then checking if its less than 0
					printf("String 1 < String 2\n"); // If it is then printing this statement
				else    // Otherwise printing the statement below
					printf("String 1 = String 2\n");
				break;
                
			case 3 :
				printf("Enter a string: ");
				fgets(source, 255, stdin);  // Reading input from the keyboard for the source variable
				StrCpy(destination, source);    // Calling the StrCpy function
				printf("Original is: %s", source);  // Printing original input
				printf("Copied   is: %s", destination); // Printing copy of the input
				break;
                
			case 4 :
				printf("Enter string #1: ");
				fgets(destination, 255, stdin); // Reading input from the keyboard for the destination variable
				printf("Enter string #2: ");
				fgets(source, 255, stdin);  // Reading input from the keyboard for the source variable
				StrCat(destination, source);    // Calling the StrCat variable
				printf("String #1 catted with String #2 is %s\n", destination);
				break;
                
			case 5 :
				printf("Enter a string: ");
				fgets(source, 255, stdin);  // Reading input from the keyboard for the source variable
				printf("Enter a character to search in the string: ");
				character = getchar();
				printf("The character %c %s in the string", character, StrChr(source, character)?"is":"is not");
				break;
                
			default :
				printf("Invalid Choice. Try Again.\n");
		}
        
		ch = menu();
	}
}

// This function prints the menu so the user can see the functions available and choose one to run
// Input is void
// Output is integer
int menu()
{
	int ch, x;  // Integer variable declaration for ch and x
    
    // Printing the statements below
	printf("\nChoose a function to run:\n");
	printf(" 1. AtoI | 2. StrCmp | 3. StrCpy | 4. StrCat | 5. StrChr\n\n");
    printf("Choice: ");
	scanf("%d", &ch);   // Reading input for the variable ch
	x = getchar();
	return ch;
}

// This function converts a numerical input to integer form
// Input is a const char pointer
// Output is integer
int AtoI ( const char * str ){
	int i = 0, j = 0;       // Variable declaration for integer i and j
	while(str[i] != '\0'){      // While str[i] does not equal check for the statements below
		if(str[i] == '.') break;    // If str[i] is equal to a '.' then break the program
		if(str[i] >= '0' && str[i] <= '9')  // otherwise check if str[i] is greater than or equal to 0 and if its less than or equal to 9
			j = (j*10) + str[i] - '0';
		i++;
	}
	return j;
}

// This function compares size of two strings then prints if string #1 is greater, less or equal to string #2
// Input is const char pointers for the two strings
// Output is integer
int StrCmp ( const char * str1, const char * str2 ){
	int i = 0, j = 0;       // Variable declaration for integer i and j
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] < str2[i]) return -1;
		if(str1[i] > str2[i]) return 1;
        if(str1[i] == str2[i]) return 0;
		i++;
	}
	if(str1[i] == '\0') return -1;
	if(str2[i] == '\0') return 1;
	return 0;
}

// This function copies the first string then makes a copy of it in another variable. Then it prints both original and copied strings
// Input is char and const char pointers
// Output is char
char * StrCpy ( char * destination, const char * source ){
	int i = 0;      // Variable declaration for integer i
    
	while(source[i] != '\0'){
		destination[i] = source[i];   // Copying source string to destination string
		i++;    // Incrementing i++
	}
	destination[i] = '\0';
    
	return destination;
}

// This function cats two inputs together and then prints them
// Input is char and const char pointers
// Output is of type char
char * StrCat ( char * destination, const char * source ){
	int i = 0, j = 0;
    
	while(destination[i] != '\n' && destination[i] != '\0') i++;
    
	while(source[j] != '\n' && source[j] != '\0'){
		destination[i] = source[j];     // Assigning destination[i] to source [i]
		i++; j++;     // Incrementing i and j
	}
	destination[i] = '\0';
    
	return destination;
}

// This function lets the user input a string and a character then it checks to see if the character is in the string.
// Input is char pointer and int variable
// Output is of type char
char * StrChr ( char * str, int character ){
	int i = 0;      // Variable declaration for integer i
	while(str[i] != character && str[i] != '\0') i++;   // Going through each character of the string to check for the character
    
	if(str[i] == character) return &str[i]; // If character exists in the string then returning that character
	return NULL;
}

// ===========================================================================================
// END OF PROGRAM

