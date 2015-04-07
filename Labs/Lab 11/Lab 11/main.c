// Zaid Kaleem
// 103619897
// Lab 11

// Libraries Included
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct declaration
struct student {
    int ID;
    char name[40];
    struct student *next;
};
typedef struct student Student;

// Function Prototypes
int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
void printListRR(Student *List);
void searchList(Student *List);

// Initializing Function
int main() {
    int choice = 0;
    Student *SLIST = NULL;
    
    choice = getChoice();
    
    while(choice >= 0) {    // Checking the choice made by the user
        switch(choice) {    // Based on the choice of the user, selecting the appropriate switch case
            case 0 : printf("Bye...\n"); exit(0);   // If choice = 0 then printing this statement
            case 1 : SLIST = addToList(SLIST); break;   // If choice = 1 then calling addtoList function with SLIST as input
            case 2 : printList(SLIST); break;   // If choice = 2 then calling printList function with SLIST as input
            case 3 : printListRR(SLIST); break; // If choice = 3 then calling printListRR function with SLIST as input
            case 4 : searchList(SLIST); break;  // If choice = 4 then calling searchList function with SLIST as input
            default: printf("That is not a valid choice\n");    // If choice is anything other than the above then printing this statement
        }
        choice = getChoice();   // Calling choice function to keep printing the menu
    }
    
    if(SLIST) free(SLIST);  // Using free() to release memory where SLIST is stored
    return 0;
}

// Function to print the menu so user can select desired action
// Input is void
// Output is integer
int getChoice() {
    int choice = 0;
    
    printf("\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}


/*
 
 “addToList” will ask for the ID and name of a new student from the user, dynamically create
 a new Student structure, assign the values for the members, add the new student structure at the
 END of the student list “SLIST” and return the modified list.
 
 Input is a pointer pointing to type Student
 Output is Student
 */

Student *addToList(Student *List){
    
    Student *stud = (Student *) malloc(sizeof(Student));    // Allocating memory corressponding to the size of the struct Student to pointer stud
    
    printf("Enter student's ID number: ");
    scanf("%d", &(stud->ID));   // Reading ID into ID in stud
    printf("Enter student's name: ");
    scanf(" %[^\n]", stud->name);   // Reading name into name in stud
    
    if (List == NULL) return stud;
    
    Student *stud_p = List; // Pointer declaration of the type stud pointing to List
    
    while(stud_p->next != NULL)
        stud_p = stud_p->next;  // Assigning stud_p pointing to next in struct to stud_p
    
    stud_p->next = stud;    // Assigning stud to stud_p which is pointing to next in struct
    
    return List;
}


/*
 
 “printList” will traverse through the list from the beginning to the end and will print info for
 each student in the format “ID Name\n”.
 
 // Input is pointer
 // Output is void
 */

void printList(Student *List){
    while(List != NULL) {   // Loop to print everything in List
        printf("%d %s\n", List->ID, List->name);
        List = List->next;
    }
}


/*

 “printListRR” will print the list, RECURSIVELY, starting from the END of the list, in the
 format “ID Name\n”.
 
 // Input is pointer
 // Output is void
 
*/

void printListRR(Student *List){
    if(List == NULL) return;    // If nothing is exists in list then return void
    
    printListRR(List->next);    // Recursive call to print the next record in list
    printf("%d %s\n", List->ID, List->name);
}

/*
 
 “searchList” will ask the user to enter a student’s ID, search the list for the student having that
 ID and will print the data in the format “ID Name\n”. If failed, it will print “ID "ID" not
 found”.
 
 // Input is pointer
 // Output is void
 
 */

void searchList(Student *List){
    
    int s_ID;
    
    printf("Enter student's ID number: ");
    scanf("%d", &s_ID); // Reading student ID to search in the list
    
    while(List != NULL) {   // While list is not empty...
        if(List->ID == s_ID){   // Checking if current ID in list is equal to ID being searched
            printf("%d %s\n", List->ID, List->name);    // If it is equal then printing that record
            return;
        }
        
        List = List->next;  // Going to the next ID in the list so it can be checked
    }
    
    printf("Cannot find ID %d in list", s_ID);  // Printing this statement if no ID matches found in list
}

// ==================================================
// END OF PROGRAM