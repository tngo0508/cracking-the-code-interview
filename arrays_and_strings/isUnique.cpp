// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structure
#include <iostream>
#include <string>
using namespace std;

bool isUniqueChars(string str) {
    // the string length cannot exceed the number of the number of unique
    // characters in the alphabet in ASCII
    if (str.length() > 128) return false;

    bool char_set[128] = {false};
    for (size_t i = 0; i < str.length(); i++) {
        int val = str[i];

        // already found this char in string
        if (char_set[val]) return false;

        char_set[val] = true;
    }
    return true;
}

int main () {
    cout << "Enter a string: ";
    string str;
    getline(cin, str);
    if (isUniqueChars(str)) cout << "unique";
    else cout << "not unique";


    cout << endl;
    return 0;
}
