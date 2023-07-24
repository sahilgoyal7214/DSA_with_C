#include <stdio.h>

int findSmallestMissingPositive(int arr[], int size) {
    int missingPositive = 1; // Initialize the smallest missing positive integer

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] == missingPositive) {
            // Increment missingPositive if the current element is equal to it
            missingPositive++;
        } else if (arr[i] > missingPositive) {
            // If the current element is greater than missingPositive, we found the smallest missing integer
            return missingPositive;
        }
    }

    return missingPositive;
}

int main() {
    // Write C code here
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the sorted array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int smallestMissingPositive = findSmallestMissingPositive(arr, size);
    printf("The smallest missing positive integer is: %d\n", smallestMissingPositive);

    return 0;
}
