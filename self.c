#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    FILE *entry; 
    // code to open the file selfDescribing.in 
    entry = fopen("selfDescribing.in", "r");

    // if statement to display error if file cannot be opened
    if (entry==NULL){
            printf("File cannot be Found or Error in Opening File");
            exit(1);
        }

    int testCases;
   // code to read the first line containing number of testcases
    fscanf(entry, "%d", &testCases);
   
    int numberArray[100];
    int counter = 0;
    int len;
    char selfDescribing = 'T';

    for (int i=0; i<testCases; i++){
    // code to run the loop according to the number of testcases
        char num[100];
        fscanf(entry, "%s", num);
    // code to read the next line from the file and store as the variable num
        len = strlen(num);
    // code to get the length of the text from the file
        for (int j = 0; j < len; j++) {
    // code to store each character into an array
            numberArray[j] =num[j] - '0';
        }
        for (int steps = 0; steps < len; steps++) {
            for (int i = 0; i< len; i++) {
                if (numberArray[i] == steps) 
                counter++;
            }
            if(counter == numberArray[steps]){
                selfDescribing = 'T';
            }
            else{
                selfDescribing = 'F';
                printf("Not self-describing\n");
                break;
            }
            counter = 0;
            if (selfDescribing!= 'F'){
                printf("Self-describing\n");
                break;
            }
        }
        
    }
    fclose(entry);
    return 0;
}