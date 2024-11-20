#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 20
char M[N] = "";
int i, n, accept;

void B() {
    char c = M[i];
    if (c == '0') {
        i= i+1;
        B();  // Recursive call for '0'
    } else if (c == '1') {
        if (i == n - 1)
            accept = 1;  // Accept if last character is '1'
        else
            accept = 0;  // Reject if more characters exist
    } else {
        accept = 0;  // Reject if not '0' or '1'
    }
}

void A() {
    char c = M[i];
    if (c == '1') {
        i= i+1;
        A();  // Recursive call for '1'
    } else if (c == '2') {
        i= i+1;
        B();  // Call B if '2' is encountered
    } else {
        accept = 0;  // Reject if not '1' or '2'
    }
}

void S() {
    char c = M[i];
    if (c == '0') {
        i= i+1;
        A();  // Call A if '0' is encountered
    } else {
        accept = 0;  // Reject if not '0'
    }
}

int main() {
    printf("This program tests whether a word belongs to the defined grammar as follows: \n");
    printf("\tS -> 0A \n\tA -> 1A | 2B \n\tB -> 0B | 1\n\n");
    
    printf("Enter a word to test: \n");
    scanf("%s", M);

    n = strlen(M);
    i = 0;
    S();

    if (accept == 1)
        printf("This word belongs to the language.\n");
    else
        printf("This word does not belong to the language.\n");

    return 0;
}
