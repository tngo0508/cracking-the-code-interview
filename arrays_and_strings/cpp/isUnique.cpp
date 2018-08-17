// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structure?
// Answer: if no additional data structure is used, it will take O(N^2) run time
// to do a linear search or O(N log N) run time in binary search
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// using hash table
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

// using binary search
bool isUniqueChars_noDS( string str) {

	sort(str.begin(), str.end()); // O(nlogn) sort from <algorithm>

	bool noRepeat = true;
	for (size_t i = 0 ; i < str.size() - 1; i++){
		if ( str[i] == str[i+1] ){
			noRepeat = false;
			break;
		}
	}

	return noRepeat;
}

int main () {
    // cout << "Enter a string: ";
    // string str;
    // getline(cin, str);
    // if (isUniqueChars(str)) cout << "unique";
    // else cout << "not unique";
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
	for (auto word : words)
	{
		cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
	}
    cout <<endl << "Using no Data Structures" <<endl;
	for (auto word : words)
	{
		cout << word << string(": ") << boolalpha << isUniqueChars_noDS(word) <<endl;
	}

    cout << endl;
    return 0;
}
