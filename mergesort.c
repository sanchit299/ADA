#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a[20], n;

void merge_sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main() {
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nTime taken to sort: %f seconds\n", time_taken);

    return 0;
}

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);          // Sort the first half
        merge_sort(a, mid + 1, high);     // Sort the second half
        merge(a, low, mid, high);         // Merge both halves
    }
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[high + 1];  // Temporary array to hold merged results

    // Merging the two halves
    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    // Copy remaining elements from the left half (if any)
    while (i <= mid) {
        c[k++] = a[i++];
    }

    // Copy remaining elements from the right half (if any)
    while (j <= high) {
        c[k++] = a[j++];
    }

    // Copy the merged result back to the original array
    for (i = low; i <= high; i++) {
        a[i] = c[i];
    }
}
