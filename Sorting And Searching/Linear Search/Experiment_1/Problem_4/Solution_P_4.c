#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearchWords(char* words[], int size, char* target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int compare = strcmp(words[mid], target);

        if (compare == 0) {
            return mid; // Found the target word, return the index
        } else if (compare > 0) {
            end = mid - 1; // Target word is before the mid word
        } else {
            start = mid + 1; // Target word is after the mid word
        }
    }

    return -1; // Target word not found
}

int main() {
    int size, i;
    printf("Enter the number of words: ");
    scanf("%d", &size);
    getchar(); // Clear the newline character left in the input buffer

    char** words = (char**)malloc(size * sizeof(char*));

    printf("Enter the sorted words:\n");
    for (i = 0; i < size; i++) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the trailing newline character from the input

        words[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(words[i], buffer);
    }

    char target[100];
    printf("Enter the target word to search for: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0'; // Remove the trailing newline character from the input

    int index = binarySearchWords(words, size, target);

    if (index != -1) {
        printf("The target word '%s' is found at index %d.\n", target, index);
    } else {
        printf("The target word '%s' is not found in the array.\n", target);
    }

    // Free dynamically allocated memory
    for (i = 0; i < size; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
