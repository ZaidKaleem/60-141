// Zaid Kaleem
// 103619897
// Lab 8

// Libraries Included.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Struct Declaration.
struct myWord{
    
    char Word[21];
    int Length;
    
};


// Initializing Function.
// Input is void.
// Output is integer.
int main(){
    
    struct myWord WordList[20];
    char myString[] = "the cat in the hat jumped over the lazy fox";
    
    struct myWord holdWord; // To hold words from the list temporarily while sorting.
    char *activeWord;   // To single out words from the list and work on them individually.
    int i, j;
    int countWord = 0; // Starting the word count at 0 at the beginning of the program.
    
    activeWord = strtok(myString, " "); // Breaking down myString in to tokens where ever there is a space.
    
    while (activeWord != NULL){
        
        strcpy(WordList[countWord].Word, activeWord);   // Copying word to WordList
        WordList[countWord].Length = strlen(activeWord);    // Getting length of current word from the WordList and setting it to the Length in the struct.
        countWord++;
        
        activeWord = strtok(NULL, " "); // Breaking down myString where ever there is a space.
        
    }
    
    printf("Unsorted list:\n");
    
    for(i = 0; i < countWord; i++)  // Loop to print all the words in the string and their length.
        printf("%s\t%d\n", WordList[i].Word, WordList[i].Length);
    
    for(i = 0; i < countWord; i++){    // Loop to sort the unsorted list above.
        
        for(j = 0; j < countWord - 1; j++){
            if(strcmp(WordList[j].Word, WordList[j+1].Word) > 0) { // If there are more than one words in the list then starting the sorting.
                holdWord = WordList[j]; // Using holdWord to temporarily hold words while sorting them.
                WordList[j] = WordList[j+1];    // Moving the words up one position while sorting.
                WordList[j+1] = holdWord;
            }
            
        }
        
    }
    
    printf("\nSorted list:\n");

    for(i = 0; i < countWord; i++)  // Loop to print the sorted list.
        printf("%s\t%d\n", WordList[i].Word, WordList[i].Length);
    
    return 0;
    
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// END OF PROGRAM
