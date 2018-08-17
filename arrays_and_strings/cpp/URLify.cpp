// Write a method to replace all spaces in a string with '%20'. You may assume that
// the string has suffice space at the end to hold the additional characters, and
// that you are given the "true" length of the string.
#include <iostream>
#include <string>
using namespace std;

string URLify(string s, int trueLen) {
    int spaceCount = 0;
    for (int i = 0; i < trueLen; i++) {
        if (s[i] == ' ') spaceCount++;
    }
    int idx = trueLen + spaceCount * 2;
    int len = s.length();
    if (trueLen <  len) s[trueLen] = '\0'; // end array
    for (int i = trueLen - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[idx - 1] = '0';
            s[idx - 2] = '2';
            s[idx - 3] = '%';
            idx = idx - 3;
        } else {
            s[idx - 1] = s[i];
            idx--;
        }
    }

    return s;
}

int main () {
    string s = "Mr John Smith    ";
    int str_length = 13;

    cout << URLify(s, str_length);

    cout << endl;
    return 0;
}
