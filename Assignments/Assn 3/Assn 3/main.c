/*
 
 Zaid Kaleem
 103619897
 Assignment 3
 
 This program reads and selects specific values from the data that is entered into the program.
 It then calculates unknown values based on the formula P = U * I

 Where:
 
 P = Power consumed or produced by a device expressed in unit Watts (W).
 U = Voltage used in the system expressed in unit Volts (V).
 I = Current flow through the circuit expressed in unit Amperes (A).
 
Input Format:
 
DataField ::= Concept=RealNumber[Prefix]Unit

 */



//+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+



// Libraries included
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


// Function prototypes

float ch_data(float data, char *s);

void calc_val(char *s1, char *s2, float *val, char *concept);

// Initializing function
// Input is void
// Output is integer

int main(){
    
    float val;    // Float variable declaration
    int problem_num, data_num, active_problem;  // Integer variable declarations
    char buffer[40], s1[40], s2[40], concept;   // Char variable declarations
    
    scanf("%d", &problem_num);   // This scans the number of problems that need to be solved
    printf("\n");
    
	active_problem = 0;     // Starting the active problem count at 0
    
    while(active_problem < problem_num){  	// This initiates the solving procedure for each of the problems

        active_problem++;       // Incrementing the counter for the current problem to move to the next problem
        
        printf("Problem: #%d\n", active_problem);
        
        data_num = 0;       // Starting the amount of values extracted at 0
        
        while(data_num < 2){   	// Two values are needed to calculate the third
        
        scanf("%s", buffer);
            
        if(buffer[1] == '='){ 	// Makes program go through data to find wherever there is a "=". Means theres a data field there
            if(data_num < 1)	// This makes sure the program stores the values extracted, separately so they aren't overwritten
            strcpy(s1, buffer);
        
        else
        strcpy(s2, buffer);
                
        data_num++;
            
            }
        }
        
        calc_val(s1, s2, &val, &concept); // Calling the calc_val function to calculate the value given the input s1,s2, value and concept
        
        if(concept == 'P')
        printf("P = %.2fW\n", val);
        
        if(concept == 'U')
        printf("U = %.2fV\n", val);
        
        if(concept == 'I')
        printf("I = %.2fA\n", val);
}
    
return 0;
    
}


// This function calculates the values that are unknown in the formula mentioned at the top and also determines the concept being used
// Inputs are char and float pointers
// Output is void

void calc_val(char* s1, char* s2, float* val, char* concept){
    
    float first_data, second_data;
    
    first_data = atof(s1+2);   	// Converting value from string to float from the first value to second value
    
    second_data = atof(s2+2);
    
    first_data = ch_data(first_data, s1); // Calling ch_data function to convert the value in the right format
    
    second_data = ch_data(second_data, s2); // Calling ch_data function to convert the value in the right format
    
    
    if(s1[0] == 'P'){			// Checking if the first value extracted is for the letter P from the formula
        if(s2[0] == 'U')		// Same as above but checking for U this time
        *concept = 'I';		// Since we only need two values to find unknown variable so now calculating I
       
        else //if(str2[0] == 'I'),
        *concept = 'U';		// Calculating for the letter U
        
        *val = first_data / second_data;
}
    
    else if(s1[0] == 'U'){		// Checking if the first value extracted from data is for U
        
    if(s2[0] == 'P'){		// Checking if the second value extracted from data is for P
        *concept = 'I';		// If it is then time to calculate I
        *val = second_data / first_data;
            
        }
       
        else{
            
        *concept = 'P';
            
        *val = first_data * second_data;
            
        }
    }
    
    // Same stuff going on below as before, just checking and solving for different variables
    
    else{
        
    if(s2[0] == 'P'){
    *concept = 'U';
           
    *val = second_data / first_data;
        
    }
        
    else{
    *concept = 'P';
            
    *val = first_data * second_data;
        
    }
        
}
    
}


// Lastly, this function makes sure the data is in correct units such as mili, kilo and mega
// Input is float and char pointer
// Output is float

float ch_data(float data, char *s){
    
if(strchr(s, 'm'))      // Checking if unit is in mili, if not then converting it into mili
data /= 1000;
    
else if
(strchr(s, 'k'))    // Checking if unit is in kilo, if not then converting it into kilo
data *= 1000;
    
else if
(strchr(s, 'M'))    // Checking if unit is in mega, if not then converting it into mega
data *= 1000000;
    
    
return data;
    
}

/*
 
 ___________.__             ___________           .___
 \__    ___/|  |__   ____   \_   _____/ ____    __| _/
 |    |   |  |  \_/ __ \   |    __)_ /    \  / __ | |
 |    |   |   Y  \  ___/   |        \   |  \/ /_/   |
 |____|   |___|  /\___  > /_______  /___|  /\_______|
 \/     \/          \/     \/      \/  \/
 
 
 */


