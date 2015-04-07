/* 
 
Zaid Kaleem
103619897
 
This program maintains a sample address book system stored in a sequential text file. It is able to interactively ask the user for input, and
support up to MAX (10) records. It saves the records to a sequential text file named "contactlistA.dat". It stores all the records in a format 
that you would be able to read back later when requested and display the contents accordingly.
 
 */

// Libraries included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max 10

// Structure definition for the records
typedef struct
{
    char firstName[30];
    char lastName [30];
    char address [100];
    char postalCode[7];
    char phone[11];
} contact;

contact contactList[Max];   // Array decalaration of the type contact

int recordNum = 0; // Initializing the record numbers at 0

// Function prototypes
void menu();
void addContact();
void displayContacts();
void displayContact(int index);
void searchContact();
void saveContacts();
void loadContacs();
void Exit();
void wordCap(char name[], int n);
void formatPhone(char string[]);
void formatPostal(char string[]);

// Initializing function with all the function calls
int main()
{
    int choice;
    
    printf("*** Personal Contact Book v1.0 ***\n");
    
    while(1)
    {
        menu(); // Calling the menu function to print the options available in this program
        scanf("%d", &choice);   // Reading the choice the user is going to make from the keyboard
        
        switch(choice)  // Switch case to make the program react depending on the choice of the user in the pervious step
        {
            case 1 :
                addContact();
                break;
            case 2 :
                displayContacts();
                break;
            case 3 :
                searchContact();
                break;
            case 4 :
                saveContacts();
                break;
            case 5 :
                loadContacs();
                break;
            case 6 :
                Exit();
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// This function prints the menu so the user can select the option he/she wants
// Input is void
// Output is void
void menu()
{
    printf("\t1. Add new contact\n");
    printf("\t2. Display current contacts\n");
    printf("\t3. Search for a contact\n");
    printf("\t4. Save contacts to file\n");
    printf("\t5. Load contacts from file\n");
    printf("\t6. Exit\n\t> ");
}


// This function takes the data entered from the user and then stores it in the "contact" structure format
// Input is void
// Output is void
void addContact()
{
    char answer = 'y';
    char buffer[100];

    
    while(answer == 'y' || answer == 'Y')
    {
        if(recordNum >= Max){   // Checking if the number of contacts has reached the max limit
        
            printf("Number of contacts have reached max limit. Cannot store more contacts.\n");
            return;
        }
        printf("\nAdding new contact:\n");  // Asking user to enter the first name of the contact
        printf("First name : ");
        scanf(" %s", buffer);
        wordCap(buffer, 1);
        strcpy(contactList[recordNum].firstName, buffer);
        
        printf("Last name : "); // Asking the user to enter the last name of the contact
        scanf(" %s", buffer);
        wordCap(buffer, 1);
        strcpy(contactList[recordNum].lastName, buffer);
        
        printf("Address : "); // Asking the user to enter the address of the contact
        scanf(" %[^\n]", buffer);
        wordCap(buffer, 1);
        strcpy(contactList[recordNum].address, buffer);
       
        printf("Postal Code : "); // Asking the user to enter the postal code of the contact
        scanf(" %s", buffer);
        wordCap(buffer, 2);
        strcpy(contactList[recordNum].postalCode, buffer);
        
        printf("Phone : "); // Asking the user to enter the phone number of the contact
        scanf(" %s", buffer);
        strcpy(contactList[recordNum].phone, buffer);
        recordNum++;
        
        printf("\nAdd another contact?(y/n): ");    // Asking the user if they will like to add another contact
        scanf(" %c", &answer);
    }
}



// This function can do two things. It can either capitalize the first letter of a word or it can format the postal code in required format
// Input is a string array and an integer
// Output is void
void wordCap(char string[], int n)
{
    int i = 0;
    
    while(string[i])
    {
        string[i] = toupper(string[i]); // Capitalizing the character at the i'th place
        i++;
        
        if(n == 1)
        {
            while(string[i] != ' ')
            {
                string[i] = tolower(string[i]);
                i++;
            }
            
            if(string[i])
                i++;
        }
    }
}

void displayContacts()
{
    int i = 0;
    while(i < recordNum) displayContact(i++);
}

void displayContact(int index)
{
    
    printf("First name : %s\n", contactList[index].firstName);
    printf("Last name  : %s\n", contactList[index].lastName);
    printf("Address    : %s\n", contactList[index].address);
    printf("Postal Code: ");
    formatPostal(contactList[index].postalCode);
    printf("Phone      : ");
    formatPhone(contactList[index].phone);
    
}

/*
 This function searches for a record
 */
void searchContact()
{
    int index = 0, count = 0;
    int iArray[Max] = {0};
    char lName[30];
    
    printf("What is the contact's last name? ");
    scanf("%s", lName);
    wordCap(lName, 1);
    while(index < recordNum)
    {
        if(strcmp(lName, contactList[index].lastName) == 0)
        {
            iArray[index] = 1;
            count++;
        }
        
        index++;
    }
    
    printf("Found %d record(s):\n", count);
    
    index = 0;
    while(index < recordNum)
    {
        if(iArray[index] == 1)
            displayContact(index);
        
        index++;
    }
}


/*Saves contact list into a text file*/
void saveContacts()
{
    FILE *out;
    int i;
    
    if((out = fopen("contactListA.dat", "w")) == NULL)
    {
        printf("Cannot open contactListA.dat for writing\n");
        exit(0);
    }
    
    fprintf(out, "%d\n", recordNum);
    
    for(i = 0; i < recordNum; i++)
    {
        fprintf(out, "%s\n", contactList[i].firstName);
        fprintf(out, "%s\n", contactList[i].lastName);
        fprintf(out, "%s\n", contactList[i].address);
        fprintf(out, "%s\n", contactList[i].postalCode);
        fprintf(out, "%s\n", contactList[i].phone);
    }
    
    fclose(out);
    
    printf("Contact List saved successfully.\n");
    
}


void loadContacs()
{
    FILE *in;
    int i;
    char temp[100];
    
    if((in = fopen("contactListA.dat", "r")) == NULL)
    {
        printf("Cannot open contactListA.dat for reading\n");
        exit(0);
    }
    
    fscanf(in, "%d", &recordNum);
    
    for(i = 0; i < recordNum; i++)
    {
        fscanf(in, " %s", contactList[i].firstName);
        fscanf(in, " %s", contactList[i].lastName);
        fscanf(in, " %[^\n]", contactList[i].address);
        fscanf(in, " %s", contactList[i].postalCode);
        fscanf(in, " %s", contactList[i].phone);
        
    }
    
    fclose(in);
    
    printf("Contact List loaded successfully.\n");
}

void Exit()
{
    char ans;
    
    printf("Save your contacts to file before leaving? (y/n): ");
    fflush(stdin);
    scanf("%c", &ans);
    if(ans == 'y' || ans == 'Y')
        saveContacts();
    
    printf("Bye!\n");
    exit(0);
}

void formatPostal(char string[])
{
    int i = 0;
    
    while(i < 3) putchar(string[i++]);
    putchar('-');
    while(string[i]) putchar(string[i++]);
    putchar('\n');
}

void formatPhone(char string[])
{
    int i = 0;
    
    putchar('(');
    while(i < 3) putchar(string[i++]);
    printf(") ");
    while(i < 6) putchar(string[i++]);
    putchar('-');
    while(string[i]) putchar(string[i++]);
    printf("\n\n");
}

