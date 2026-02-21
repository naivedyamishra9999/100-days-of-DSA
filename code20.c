#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    // Create prefix sum array
    long long prefix[n + 1];
    prefix[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    // Sort prefix array
    qsort(prefix, n + 1, sizeof(long long), compare);

    long long count = 0;
    long long freq = 1;

    // Count equal prefix sums
    for (int i = 1; i <= n; i++) {
        if (prefix[i] == prefix[i - 1]) {
            freq++;
        } else {
            count += (freq * (freq - 1)) / 2;
            freq = 1;
        }
    }

    count += (freq * (freq - 1)) / 2;

    printf("%lld\n", count);

    return 0;
}