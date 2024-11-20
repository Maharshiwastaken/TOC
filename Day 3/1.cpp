#include<stdio.h>

int current = 0;

void q0(char c) {
    if (c == 'T' || c == 't') 
        current = 1;
    else 
        current = -1;
}

void q1(char c) {
    if (c == 'H' || c == 'h') 
        current = 2;
    else 
        current = -1;
}

void q2(char c) {
    if (c == 'E' || c == 'e') 
        current = 3;
    else 
        current = -1;
}

void q3(char c) {
    if (c == 'O' || c == 'o') 
        current = 4;
    else 
        current = -1;
}

void q4(char c) {
    if (c == 'R' || c == 'r') 
        current = 5;
    else 
        current = -1;
}

void q5(char c) {
    if (c == 'Y' || c == 'y') 
        current = 6;
    else 
        current = -1;
}

void q6(char c) {
    current = -1;
}

int main() {
    char str[20], c;
    int i;
    
    printf("Enter your word: ");
    scanf("%s", str);  // No need for '&' with %s
    
    for (i = 0; str[i] != '\0'; i++) {
        c = str[i];
        switch (current) {
            case 0:
                q0(c);
                break;
            case 1:
                q1(c);
                break;
            case 2:
                q2(c);
                break;
            case 3:
                q3(c);
                break;
            case 4:
                q4(c);
                break;
            case 5:
                q5(c);
                break;
            case 6:
                q6(c);
                break;
            default:
                break;
        }
    }
    
    if (current == 6) {
        printf("\nYour word is accepted.");
    } else {
        printf("\nYour word is not accepted.");
    }
    
    return 0;
}
