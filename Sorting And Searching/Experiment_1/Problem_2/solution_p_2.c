#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

int isSeparator(char ch) {
    return (ch == ' ' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '\n' || ch == '\t');
}

void toLowerCase(char word[]) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

// Function to count word occurrences in the text
void countWordOccurrences(char text[]) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int numWords = 0;

    // Tokenize the text and count word occurrences
    char* word = strtok(text, " ,.?!;:\n\t");
    while (word != NULL && numWords < MAX_WORDS) {
        toLowerCase(word); // Convert word to lowercase for case-insensitive comparison

        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(words[i], word) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[numWords], word);
            counts[numWords]++;
            numWords++;
        }

        word = strtok(NULL, " ,.?!;:\n\t");
    }

    printf("Word occurrences:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }
}

int main() {
    char text[] = "Not how long, but how well you have lived is the main thing.";
    countWordOccurrences(text);
    return 0;
}
