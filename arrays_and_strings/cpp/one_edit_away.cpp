#include <iostream>
#include <string>
#include <cmath>

bool oneEditAway(const std::string & str1, const std::string & str2) {
    if (std::abs(int(str1.length() - int(str1.length()))) > 1)
        return false;

    int len1 = str1.length();
    int len2 = str2.length();
    std::string smaller = len1 < len2 ? str1 : str2;
    std::string bigger = len1 < len2 ? str2 : str1;

    size_t i = 0, j = 0;
    bool mismatchDone = false;
    while (i < smaller.length() && j < bigger.length()) {
        if (smaller[i] != bigger[j]) {
            if (mismatchDone)
                return false;
            mismatchDone = true;
            if (len1 == len2)
                i++; // case of replace
        } else {
            i++; // move short pointer if it is a match, do not move it in case
                 // of first mismatch
        }
        j++;
    }
    return true;
}

void translate(bool result, const std::string str1, const std::string str2) {
    if (result == true) {
        std::cout << str1 << " and " << str2 << " are one edit away\n";
    } else {
        std::cout << str1 << " and " << str2 << " are not one edit away\n";
    }
}
int main() {
    translate(oneEditAway("pale", "ple"), "pale", "ple");
    translate(oneEditAway("pales", "pale"), "pales", "pale");
    translate(oneEditAway("pale", "pales"), "pale", "pales");
    translate(oneEditAway("pale", "bale"), "pale", "bale");
    translate(oneEditAway("pale", "bake"), "pale", "bake");
}
