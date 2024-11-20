#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int table[2][2], i, j, l, status = 0, success;
    char input[100];

    printf("Implementing DFA of language (a+aa*b)*\nEnter Input String: ");
    
    // DFA transition table
    table[0][0] = 1;  // Transition from state 0 on 'a'
    table[0][1] = -1; // Invalid transition from state 0 on 'b'
    table[1][0] = 1;  // Transition from state 1 on 'a'
    table[1][1] = 0;  // Transition from state 1 on 'b'
    
    // Read input string
    scanf("%s", input);
    l = strlen(input);

    for (i = 0; i < l; i++) {
        // Check if input character is either 'a' or 'b'
        if (input[i] != 'a' && input[i] != 'b') {
            printf("The entered value is invalid.\n");
            getch();
            exit(0);
        }
        
        // Update DFA state based on the input character
        if (input[i] == 'a') {
            status = table[status][0]; // Transition on 'a'
        } else {
            status = table[status][1]; // Transition on 'b'
        }

        // If DFA moves to an invalid state
        if (status == -1) {
            printf("String not Accepted.\n");
            break;
        }
    }

    // If loop completes and DFA is in a valid state
    if (i == l) {
        printf("String Accepted.\n");
    }

    getch();
    return 0;
}
