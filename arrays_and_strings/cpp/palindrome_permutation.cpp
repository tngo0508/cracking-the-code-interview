#include <iostream>
#include <string>
using namespace std;

int getCharIdx(char c) {
    int idx = -1;
    if (c >= 'a' && c <= 'z') idx = c - 'a';
    else if (c >= 'A' && c <= 'Z') idx = c - 'A';
    return idx;
}

bool isPermutationOfPalindrome(const string& str) {
    int oddCount = 0;
    int frequency[26] = {0};
    int idx = 0;
    for (const char& c : str)  {
        idx = getCharIdx(c);
        if (idx != -1) {
            frequency[idx]++;
            if (frequency[idx] % 2) oddCount++;
            else oddCount--;
        }
    }
    return (oddCount <= 1);
}

int main() {
    string pal = "Tact Coa";
    // string pal = "racecar";
    string isPermutation = isPermutationOfPalindrome(pal) ? "yes" : "no";
    cout << isPermutation << endl;


    cout << endl;
    return 0;
}
