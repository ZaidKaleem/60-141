// Zaid Kaleem
// 103619897
// Assignment #4

// ***************************************************************


// Libraries Included
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 40

// Structure of the data for each employee.
struct employee {
    int ID;
    char lastName[21];
    char firstName[21];
    char phone[20];
};

typedef struct employee Employee;

// Function Prototypes
void menu();
void searchID(Employee employee[], int numEmployee);
void searchLastName(Employee employee[], int numEmployee);
void editEmployee(Employee employee[], int numEmployee);
void inputEmployeeData(int ID, Employee *em, char *line);
void addEmployee(Employee employee[], int *numEmployee);

// Initializing function.
// Input is void.
// Output is void.
int main(){
    
    int choice, i, numEmployee;;
    char line[256], name[21];
    
    Employee em, employee[SIZE];
    
    numEmployee = 0;            // Starting numEmployee at 0 at the beginning of the program.
    
    while(scanf(" %s", line) != EOF){           // While the program has not reached the end of file...
    
        inputEmployeeData(numEmployee + 1, &employee[numEmployee], line);  // Calling inputEmployeeData function and adding 1 to the number of employees.
        numEmployee++;   // Updating the number of employees variable.
    }
    
    for(i = 0; i < numEmployee; i++){            // For loop setup to print all the employees and their corresponding data.
    
        printf("%d %s, %s. %s\n", employee[i].ID, employee[i].lastName, employee[i].firstName, employee[i].phone);  // Format of the data
    }
    
    freopen("input.csv", "r", stdin); // Opening input file to read its contents.
    
    do{
        menu(); // Printing menu.
        
        printf("\nChoice: ");
        scanf(" %d", &choice); // Reading the choice of the user from the keyboard.
        
        switch (choice) {
            case 1:            // If user picks 1...
                searchID(employee, numEmployee);    // Calling searchID function.
                break;
            case 2:            // If user picks 2...
                searchLastName(employee, numEmployee);  // Calling searchLastName function.
                break;
            case 3:           // If user picks 3...
                editEmployee(employee, numEmployee);    // Calling editEmployee function.
                break;
            case 4:           // If user picks 4...
                addEmployee(employee, &numEmployee);    // Calling addEmployee function.
                break;
            default:         // If user enters anything other than 1-4...
                printf("Incorrect Choice. Please try again.\n");     // This will get printed.
        }
        
    }
    
    while(1);   // Infinite loop to keep restarting the program.
    
}


// This function prints the menu so the user can choose what s/he wants to do.
// Input is void.
// Output is void.
void menu(){
    
    printf("\nWhat would you like to do? (Pick a number)...\n");
    printf("1) Search using ID\n");
    printf("2) Search using last name\n");
    printf("3) Edit data\n");
    printf("4) Add empolyee\n");
    
}


// This function...
void inputEmployeeData(int id, Employee *em, char *line){
    
    char *stringPtr = NULL, phone[15];  // Variable declaraction for the individual strings and the phone numbers in the input file.
    int i;
    
    if(line){
        em->ID = id;         // Accessing ID from the struct made earlier.
        stringPtr = strtok(line, " ,");          // Breaking down string into tokens wherever there is a " ," in "line".
        
        stringPtr[0] = toupper(stringPtr[0]);       // Converting the first character to uppercase in the string.
        
        i = 1;          // Setting i equal to 1 because we want to keep the first character capital.
        
        while(stringPtr[i] != '\0'){           // While the program is not at the end of the string...
            stringPtr[i] = tolower(stringPtr[i]);         // Converting specific characters in string to lowercase starting at the second character.
            i++;            // Incrementing 'i' to make the loop go through all characters of the string starting at i = 1.
        }
        
        strcpy(em->firstName, stringPtr);      // Copying the string value firstName into an array that is being accessed from the struct that was
                                            // made earlier.
        stringPtr = strtok(NULL, " ,");        // Breaking down string into token whereever there is a " ," in the string.
        i = 0;
        
        while(stringPtr[i] != '\0'){            // While the program has not reached the end of the string...
        
            stringPtr[i] = toupper(stringPtr[i]);         // Converting specific characters in the string to uppercase.
            i++;            // Incrementing 'i' so the loop goes through all the characters of the string.
            
        }
        
        strcpy(em->lastName, stringPtr);   // Copying the string value lastName into an array that is being accessed from the struct that was
                                        // made earlier.
        stringPtr = strtok(NULL, " ,");    // Breaking down string into tokens whereever there is a " ," in the string.
        
        strcpy(phone, "(");             // Copying "(" in the phone array.
        
        strcpy(phone+1, stringPtr);        // Copying string to the phone array starting at the 2nd character space.
        strcpy(phone+4, ") ");          // Copying ") " to the phone array starting at the 5th character space.
        
        stringPtr = strtok(NULL, " ,");       // Breaking down string into tokens wherever there is a " ," in the string
        strncpy(phone+6, stringPtr, 3);       // Copying string to the phone array starting at the 7th character space.
        strcpy(phone+9, "-");               // Copying string "-" to the phone array at the 10th character space.
        
        strcpy(phone+10, stringPtr+3);      // Copying string to the phone array at the 11th character space.
        
        strcpy(em->phone, phone);           // Copying the value for the phone string by accessing it through the struct that was made earlier.
        
    }
    
    else        // If input file does not have the data...
        printf("Data not found.\n");       // Print this.
    
}

// This function lets the user search the employee data using employee ID.
// Input is array and integer.
// Output is void.
void searchID(Employee employee[], int numEmployee){
    
    int i, ID;  // Integer variable declarations.
    
    printf("Enter employee id to search: ");
    scanf(" %d", &ID);  // Reading ID that will be used to search the data.
    
    for(i = 0; i < numEmployee; i++){   // Loop to go through all the data.
        if(employee[i].ID == ID)    // If the ID provided by the user matches ID for any of the employees then...
            printf("%d %s, %s. %s\n", employee[i].ID, employee[i].lastName, employee[i].firstName, employee[i].phone);  // Printf this statement.

        
    }
    
}

// This function lets the user search the employee data using employee last name.
// Input is array and integer.
// Output is void.
void searchLastName(Employee employee[], int numEmloyee){
    
    int i;
    char lName[30];
    
    printf("Enter employee's last name to search: ");
    scanf(" %s", lName); // Reading the last name provided by the user to search through the data.
    
    for(i = 0; i < numEmloyee; i++){ // Loop to go through all the data.
        
        if(strcmp(employee[i].lastName, lName) == 0)    // If the string of last name provided by user matches a string in the last name field in the data then...
            printf("%d %s, %s. %s\n", employee[i].ID, employee[i].lastName, employee[i].firstName, employee[i].phone);  // Print the statement below.
    }
}


// This function lets the user edit existing employee's data.
// Input is array and integer.
// Output is void.
void editEmployee(Employee employee[], int numEmployee){
    
    int ID; // Integer variable declaration.
    char line[256]; // Char variable declaration.
    
    printf("Enter ID of the employee you want to edit [1 - %d]: ", numEmployee);
    scanf("%d", &ID);   // Reading ID of the employee that the user wants to change the data of.
    
    printf("Enter list of new data (separate by commas): ");
    scanf(" %s", line); // Reading a line of updated data in the format specified in the struct above.
    
    inputEmployeeData(ID, &employee[ID-1], line);   // Calling inputEmployee function to input the updated data in the input file.
}

// This function lets the user add new employees.
// Input is array and integer pointer.
// Output is void.
void addEmployee(Employee employee[], int *numEmployee){
    
    char line[256]; // Char variable declaration.
    
    printf("Enter list of new data (separate by commas): ");
    scanf(" %s", line); // Reading the line of the data typed in by the user in the struct format.
    
    inputEmployeeData(*numEmployee+1, &employee[*numEmployee], line);   // Calling function to input the data into the data file.
    
    (*numEmployee)++;   // Incrementing the number of employees because the function added new employee data.
}


// ****************************************************************************
//                                 END OF PROGRAM
// ****************************************************************************
