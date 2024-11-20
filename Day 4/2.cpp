#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main() {
    char S[30];
    int l, i;
    int count = 0;

    cout << "Enter input string: ";
    scanf("%s", S);

    l = strlen(S);

    for (i = 0; i < l; i++) {
        if (S[i] != 'a') {
            cout << "Entered string is NOT ACCEPTED";
            getch();
            exit(0);
        }

        if (S[i] == 'a') {
            count++;
        } else {
            cout << "Invalid input";
        }
    }

    if (count == l && count != 0) {
        cout << "Entered string is accepted";
    }

    return 0;
}
