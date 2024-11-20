/*Program to simulate a Turing Machine that finds one's compliment of input
string*/
#include <stdio.h>
#include <string.h>
int head = 0;
char str[20];
void q0(char c)
{
    if (c == '0')
    {
        str[head] = '1';
        head++;
        q0(str[head]);
    }
    else if (c == '1')
    {
        str[head] = '0';
        head++;
        q0(str[head]);
    }
    else
    {

        printf("Turing Machine Halts");
    }
}

int main()
{
    char c;
    int i;
    printf("Enter your string: ");
    scanf("%s", &str);
    str[strlen(str)] = 'B';
    q0(str[head]);
    printf("\nOne's complement: ");
    for (i = 0; i < strlen(str) - 1; i++)
    {
        printf("%c", str[i]);
    }
    return 0;
}