// Zaid Kaleem
// 103619897
// Lab 6

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

// Libraries included
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Prototypes
void Reverse(char *str);
void ParseSentence(char *str);

// Initializing function
// Input is void and Output is integer
int main()
{
    char buffer1[] = {'t', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'f', 'i', 'r', 's', 't', ' ', 'b', 'u', 'f', 'f', 'e', 'r', '\0'};
    char buffer2[] = "this is the second buffer";
    char buffer3[80];
    char str[] = "Hello";
    
    printf("Enter a string: ");
    scanf(" %[^\n]s ", buffer3); // To read whitespace.
    
    printf("%s\n", buffer1);
    printf("%s\n", buffer2);
    printf("%s\n", buffer3);
    
    char *pBuffer = buffer3;
    printf("%s\n", pBuffer);
    
    pBuffer += 4;
    printf("%s\n", pBuffer);
    
    printf("\nReversing \"%s\"\n", str);
    Reverse(str);
    printf("%s\n", str);
    
    char str2[] = "Hello world, how are you today.";
    printf("\nParsing sentence\n\n");
    ParseSentence(str2);
    return 0;
}

// This function reverses the contents of the array (or string) being passed.
// Input is char pointer
// Output is void
void Reverse(char *str)
{
    char temp;
    int x, xs;
    
    x = xs = 0;
    
    while(str[xs] != '\0') xs++;
    xs--;
    
    while (x <= xs)
    {
        temp = str[x];
        str[x] = str[xs];
        str[xs] = temp;
        x++;
        xs--;
    }
    
}

// The function extracts each word from the sentence (without any punctuation or spacing) and then prints one word per line.
// Input is char pointer
// Output is void
void ParseSentence(char *str)
{
    char *token;
    
    token = strtok(str, " ,;.");
    
    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ,;.");
    }
}

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// END OF PROGRAM
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
