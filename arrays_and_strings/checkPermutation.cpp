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
        cout << str1 << " and " << str3 << " are permutation of each other\n";
    } else {
        cout << str1 << " and " << str4 << " are NOT permutation of each other\n";
    }

    cout << endl    ;
    return 0;
}
