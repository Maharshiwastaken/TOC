#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

stack<char> s;
int pda = 0;

void state2() {
    cout << "At State 2\n";
    if (s.top() == '$') {
        s.pop();
        pda = 2;
    } else {
        pda = -1;
    }
}

void state1(char c) {
    cout << "At State 1\n";
    if (c == 'a' && s.top() != '$') {
        if (s.top() == 'a') {
            s.pop();
            cout << "Going to State 1\n";
            pda = 1;
        }
    } else if (c == 'b' && s.top() != '$') {
        if (s.top() == 'b') {
            s.pop();
            cout << "Going to State 1\n";
            pda = 1;
        }
    } else {
        state2();
    }
}

void state0(char c, bool flag) {
    if (flag) {
        state1(c);
    } else {
        cout << "At State 0\n";
        if (c == 'a') {
            s.push('a');
            cout << "Going to State 0\n";
            pda = 0;
        } else if (c == 'b') {
            s.push('b');
            cout << "Going to State 0\n";
            pda = 0;
        } else {
            pda = -1;
        }
    }
}

int isAccepted(char str[]) {
    // Store length of string
    int i, len = strlen(str);
    int half = len / 2;

    for (i = 0; i <= len; i++) {
        if (half == i) {
            bool flag = true;
            if (pda == 0)
                state0(str[i], flag);
            else if (pda == 1)
                state1(str[i]);
            else
                return 0;
        } else {
            bool flag = false;
            if (pda == 0)
                state0(str[i], flag);
            else if (pda == 1)
                state1(str[i]);
            else
                return 0;
        }
    }

    if (pda == 0 || pda == 2)
        return 1;
    else
        return 0;
}

int main() {
    s.push('$');
    char str[100];
    cout << "Enter string: ";
    cin >> str;

    if (isAccepted(str))
        cout << "ACCEPTED";
    else
        cout << "NOT ACCEPTED";

    return 0;
}
