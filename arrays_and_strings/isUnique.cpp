// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structure
#include <iostream>
#include <string>
using namespace std;

int main () {
    cout << "Enter a string: ";
    string str;
    getline(cin, str);
    int idx = 0;
    bool isUnique = true;
    bool hashTable[] = {false};
    for (size_t i = 0; i < str.length(); i++) {
        idx = str[i];
        if (hashTable[idx] == false) hashTable[idx] = true;
        else {
            cout << "not unique";
            isUnique = false;
            break;
        }
    }
    if (isUnique) cout << "unique";


    cout << endl;
    return 0;
}
