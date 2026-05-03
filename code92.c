#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1;   // size of left half
    int n2 = right - mid;      // size of right half

    // temporary arrays
    int L[n1], R[n2];

    // copy data into temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; // index for L
    j = 0; // index for R
    k = left; // index for main array

    // compare and merge
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements (if any)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    // base case: if single element, already sorted
    if (left < right) {
        int mid = left + (right - left) / 2;

        // divide left part
        mergeSort(arr, left, mid);

        // divide right part
        mergeSort(arr, mid + 1, right);

        // merge both sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    // calling merge sort
    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}