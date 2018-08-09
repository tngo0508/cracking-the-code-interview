// Given two strings, write a method to decide if one is a permutation of the other
#include <iostream>
#include <algorithm>
using namespace std;

bool checkPermuationSort(string s, string t) {
    // check if 2 strings have the same length
    if (s.length() != t.length()) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
};

bool checkPermByCharCount(string s, string t) {
    if (s.length() != t.length()) { // permuation must be the same length
        return false;
    }

    // mapping each character to its frequency in hash table
    // increment through the first thing, then decrement through the second
    // string. If strings are permutation, then array will be all zeroes at
    // the end.
    int hashTable[128] = {0}; // assuming that we are using ASCII
    for (size_t i = 0; i < s.length(); i++) {
        int x = s[i];
        hashTable[x]++;
    }

    for (size_t i = 0; i < t.length(); i++) {
        int x = t[i];
        hashTable[x]--;
        if (hashTable[x] < 0) return false; // strings do not have same characters
    }
    return true;
};

int main() {
    string str1 = "hello";
    string str2 = "olhle";
    string str3 = "world";
    string str4 = "orlda";

    cout << "Using sort\n";
    if (checkPermuationSort(str1, str2)) {
        cout << str1 << " and " << str2 << " are permutation of each other\n";
    } else {
        cout << str1 << " and " << str2 << " are NOT permutation of each other\n";
    }
    if (checkPermuationSort(str3, str4)) {
        cout << str3 << " and " << str4 << " are permutation of each other\n";
    } else {
        cout << str3 << " and " << str4 << " are NOT permutation of each other\n";
    }
    cout << "Using character count\n";
    if (checkPermByCharCount(str1, str2)) {
        cout << str1 << " and " << str2 << " are permutation of each other\n";
    } else {
        cout << str1 << " and " << str2 << " are NOT permutation of each other\n";
    }
    if (checkPermByCharCount(str3, str4)) {
        cout << str3 << " and " << str4 << " are permutation of each other\n";
    } else {
        cout << str3 << " and " << str4 << " are NOT permutation of each other\n";
    }

    cout << endl    ;
    return 0;
}
