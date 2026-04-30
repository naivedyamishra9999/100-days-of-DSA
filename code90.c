#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (currentPages + arr[i] > maxPages) {
            students++;
            currentPages = arr[i];

            if (students > m)
                return 0;
        } else {
            currentPages += arr[i];
        }
    }
    return 1;
}

// Main function
int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; // not possible

    int max = arr[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum;
    int result = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;  // increase limit
        }
    }

    return result;
}

int main() {
    int n = 4, m = 2;
    int arr[] = {12, 34, 67, 90};

    printf("%d\n", allocateBooks(arr, n, m));
    return 0;
}