#include <stdio.h>
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
    
    char words[size][100]; // Assuming each word has a maximum length of 100 characters

    printf("Enter the sorted words:\n");
    for (i = 0; i < size; i++) {
        scanf("%s", words[i]);
    }

    char target[100];
    printf("Enter the target word to search for: ");
    scanf("%s", target);

    int index = binarySearchWords(words, size, target);

    if (index != -1) {
        printf("The target word '%s' is found at index %d.\n", target, index);
    } else {
        printf("The target word '%s' is not found in the array.\n", target);
    }

    return 0;
}
