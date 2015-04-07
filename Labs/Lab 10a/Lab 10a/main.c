// Zaid Kaleem
// 103619897
// Lab 10a

// Libraries included
#include<stdio.h>
#include<stdlib.h>


// Struct declaration
struct employee{
    
    char firstName[40]; // Char variable declaration for first name
    char lastName[40];  // Char variable declaration for last name
    int ID; // Integer variable declaration for the ID
    
};


typedef struct employee Employee;


// Function prototypes
void InputEmpRecord(Employee *EmpList);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);

#define SIZE 3


// Initializing function
// Input is void
// Output is void
int main() {
    
    
    Employee EmpList[SIZE];
    
    InputEmpRecord(EmpList);    // Calling InputEmpRecord function
    PrintEmpList(EmpList);  // Calling PrintEmpList function
    SaveEmpList(EmpList, "employee.dat");   // Calling SaveEmpList function
    
    
    return 0;
    
}



/* Input the employee data interactively from the keyboard */
void InputEmpRecord(Employee *EmpList){
    
    int i;
    
    for(i=0; i<SIZE; i++)   // Loop to add all the employees
        
        for(i=0; i<SIZE; i++){  // Loop to add the information about the employee
            
            printf("Enter data for employee %d:\n", i+1);
            
            printf("Enter ID? ");
            
            scanf("%d", &EmpList[i].ID);    // Reading the ID
            
            printf("Enter First Name? ");
            
            scanf(" %s", EmpList[i].firstName); // Reading the Fist Name
            
            printf("Enter Last Name? ");
            
            scanf(" %s", EmpList[i].lastName);  // Reading the Last Name
            
        }
    
}



// Display the contents of Employee records from the list */
// Input is const Employee pointer
// Output is void
void PrintEmpList(const Employee *EmpList){
    
    int i;
    
    
    printf("ID FirstName LastName\n");
    
    for(i=0; i<SIZE; i++){  // Loop to print all the information about all the employees
        
        printf("%d %s %s\n", EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName);
        
    }
    
}



// Save the employee records from the list to the newly created text file specified by FileName
// Input is const Employee pointer and const char pointer
// Output is void
void SaveEmpList(const Employee *EmpList, const char *FileName){
    
    FILE *fp;   // Pointer for the file
    int i;
    
    if((fp = fopen(FileName, "w")) == NULL){    // Checking if data file equals NULL
        
        printf("Cannot open file.\n");
        
        exit(0);
        
    }
    
    fprintf(fp, "ID FirstName LastName\n"); // Printing formatted statement
    
    for(i=0; i<SIZE; i++){  // Loop to print the employee information for each employee
        
        fprintf(fp, "%d %s %s\n", EmpList[i].ID, EmpList[i].firstName, EmpList[i].lastName);
        
    }
    
    fclose(fp); // Closing the file
    
}

//==========================
// END OF PROGRAM