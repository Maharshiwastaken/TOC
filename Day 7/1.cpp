// Program to simulate a Turing Machine for language L = {0n1n | n >= 1}

#include <stdio.h>
#include <string.h>
int head = 0;
char str[20];
void q0(char);
void q1(char);
void q2(char);
void q3(char);
void q4(char);
void q0(char c)
{
    if (c == '0')
    {
        str[head] = 'X';
        head = head + 1;
        q1(str[head]);
    }
    else if (c == 'Y')
    {
        head = head + 1;
        q3(str[head]);
    }

    else
        printf("String Not Accepted");
}
void q1(char c)
{
    if (c == '0')
    {
        head = head + 1;
        while (str[head] == '0')
        {
            head++;
        }
        q1(str[head]);
    }
    else if (c == '1')
    {

        str[head] = 'Y';
        head = head - 1;
        q2(str[head]);
    }
    else if (c == 'Y')
    {
        head = head + 1;

        while (str[head] == 'Y')
        {
            head++;
        }
        q1(str[head]);
    }

    else
        printf("String Not Accepted");
}
void q2(char c)
{
    if (c == 'X')
    {
        head = head + 1;
        q0(str[head]);
    }
    else if (c == 'Y')
    {
        head = head - 1;
        while (str[head] == 'Y')
        {
            head--;
        }
        q2(str[head]);
    }
    else if (c == '0')
    {
        head = head - 1;
        while (str[head] == '0')
        {
            head--;
        }
        q2(str[head]);
    }

    else
        printf("String Not Accepted");
}
void q3(char c)
{
    if (c == 'Y')
    {
        head++;
        while (str[head] == 'Y')
        {
            head++;
        }
        q4(str[head]);
    }

    else if (c == 'B')
    {
        printf("String Accepted ");
    }
    else
        printf("String Not Accepted");
}
void q4(char c)
{
    if (c == 'B')
    {
        printf("String Accepted ");
    }
    else
        printf("String Not Accepted");
}
int main()
{
    char c;
    int i;
    printf("Enter your string: ");
    scanf("%s", &str);
    str[strlen(str)] = 'B';
    q0(str[head]);

    return 0;
}