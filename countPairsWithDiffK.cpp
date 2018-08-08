// given an array of distinct integer values, count the number of pairs of
// integers that have difference K. For example, given the array {1,7,5,9,2,12,3}
// and the difference k = 2, there are four pairs with difference 2: (1,3),
// (3,5), (5,7), (7,9)

#include <iostream>
using namespace std;

int countPairsWithDiffK(int a[], int size, int k) {
    int count = 0;
    const int MAX = 10000;
    int hashTable[MAX] = {0};
    // throw everything in the array into the hash table
    for (int i = 0; i < size; i++) {
        cout << size;
        hashTable[a[i]] = 1;
    }

    // look up if x + k or x -k exists in the array, we just look it up in the
    // hash table
    int x = 0;
    for (int i = 0; i < size; i++) {
        x = a[i];
        if (hashTable[x+k]) {
            count++;
        }
    }

    return count;
}

int main() {
    int a[] = {1,7,5,9,2,12,3};
    int a_size = sizeof(a)/sizeof(a[0]);
    int k = 2;
    int numOfPairs = countPairsWithDiffK(a, a_size, k);

    cout << "number of pairs integers that have difference k: " << numOfPairs;
    cout << endl;
    return 0;
}
