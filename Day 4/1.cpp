#include <iostream>
using namespace std;

// Function to find whether the given
// string is Accepted by the DFA
void DFA(string str, int N) {
    // If N <= 1, then print "No"
    if (N <= 1) {
        cout << "No";
        return;
    }

    // To count the matched characters
    int count = 0;

    // Check if the first character is 'C'
    if (str[0] == 'C') {
        count++;

        // Traverse the rest of the string
        for (int i = 1; i < N; i++) {
            // If character is 'A' or 'B', increment count by 1
            if (str[i] == 'A' || str[i] == 'B') {
                count++;
            } else {
                break;
            }
        }
    } else {
        // If the first character is not 'C', print "No"
        cout << "No";
        return;
    }

    // If all characters match the DFA pattern
    if (count == N) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    string str = "CAABBAAB";
    int N = str.size();
    DFA(str, N);

    return 0;
}
