// Zaid Kaleem
// 103619897
// Lab 9

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct
struct myWord{
    char Word[21];
    int len;
};

// Initializing function
int main() {
    struct myWord wordList[20]; // Array declaration of the type myWord
    struct myWord t_Word, *ptrWordList;
    char *c_Word;
    int i, j, w_Count = 0;
    
    char myString[] = "the cat in the hat jumped over the lazy fox";
    
    ptrWordList = wordList;
    c_Word = strtok(myString, " "); // Breaking down myString into tokens where ever there is a space
    
    while (c_Word != NULL) {    // Loop to go through myString and copy words to ptrWordList
        strcpy((ptrWordList+w_Count)->Word, c_Word);
        (ptrWordList+w_Count)->len = strlen(c_Word);
        w_Count++;
        
        c_Word = strtok(NULL, " ");
    }
    
    printf("Unsorted list:\n"); // Printing the unsorted word list
    for(i = 0; i < w_Count; i++)
        printf("%s\t%d\n", (ptrWordList+i)->Word, (ptrWordList+i)->len);
    
    for(i = 0; i < w_Count; i++) {  // Loop to sort the word list alphabetically
        for(j = 0; j < w_Count - 1; j++) {
            if(strcmp((ptrWordList+j)->Word, (ptrWordList+j+1)->Word) > 0) {
                t_Word = *(ptrWordList+j);
                *(ptrWordList+j) = *(ptrWordList+j+1);
                *(ptrWordList+j+1) = t_Word;
            }
        }
    }
    printf("\nSorted list:\n");   // Printing sorted word list
    for(i = 0; i < w_Count; i++)    // Loop to print the ordered list
        printf("%s\t%d\n", (ptrWordList+i)->Word, (ptrWordList+i)->len);
    
    return 0;
}

// ========================
// END OF PROGRAM