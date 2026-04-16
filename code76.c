#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int sum = 0, maxLength = 0;

    // Hash map (prefix sum -> first index)
    int hash[2001];

    // Initialize all values as -2 (means not visited)
    for (int i = 0; i < 2001; i++) {
        hash[i] = -2;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum becomes 0
        if (sum == 0) {
            maxLength = i + 1;
        }

        // Adjust index (to handle negative sums)
        int index = sum + 1000;

        // Case 2: sum seen before
        if (hash[index] != -2) {
            int length = i - hash[index];
            if (length > maxLength) {
                maxLength = length;
            }
        } else {
            hash[index] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}