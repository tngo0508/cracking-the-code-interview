#include <iostream>

void insertion_sort(int arr[], int length) {
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
};

int main() {
    int a[10] = {1, 0, 3, 2, 5, 9, 8, 7, 6, 2};
    insertion_sort(a, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << '\n';
    return 0;
}
