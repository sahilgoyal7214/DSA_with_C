#include <stdio.h>

// Function to merge two sorted subarrays
int merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int comparisons = 0;
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
        comparisons++;
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    return comparisons;
}

// Function to perform merge sort
int mergeSort(int arr[], int left, int right) {
    int comparisons = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);

        if (arr[mid] > arr[mid + 1]) {
            comparisons += merge(arr, left, mid, right);
        }
    }

    return comparisons;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int totalComparisons = mergeSort(arr, 0, n - 1);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTotal comparisons: %d\n", totalComparisons);

    return 0;
}
