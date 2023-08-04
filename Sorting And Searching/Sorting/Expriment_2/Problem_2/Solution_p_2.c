#include <stdio.h>

// Function to perform Bubble Sort in descending order
void bubbleSortDescending(int arr[], int n) {
    int i, j, temp;
    int isSorted;

    for (i = 0; i < n - 1; i++) {
        isSorted = 1; // Assume the array is sorted

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // Compare adjacent elements for descending order
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0; // Array is not sorted
            }
        }

        if (isSorted) {
            break; // If the array is already sorted, terminate early
        }
    }
}

int main() {
    int arr[100];
    int size;

    printf("Enter the size of the array (maximum size: 100): ");
    scanf("%d", &size);

    if (size <= 0 || size > 100) {
        printf("Invalid size. Size should be between 1 and 100.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSortDescending(arr, size);

    printf("\nSorted array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
