#include <stdio.h>
#include <string.h>
int binarySearchForWord(char arr[][100], int left, int right, char target[]) {
 while (left <= right) {
 int mid = left + (right - left) / 2;
 int cmp = strcmp(arr[mid], target);
 if (cmp == 0) {
 return mid;
 } else if (cmp < 0) {
 left = mid + 1;
 } else {
 right = mid - 1; 
 }
 }
 return -1;
}
int main() {
 int n;
 printf("Enter the number of words in the sorted array: ");
 scanf("%d", &n);
 char words[n][100];
 printf("Enter %d words in lexicographic order:\n", n);
 for (int i = 0; i < n; i++) {
 scanf("%s", words[i]);
 }
 char target[100];
 printf("Enter the target word to find: ");
 scanf("%s", target);
 int index = binarySearchForWord(words, 0, n - 1, target);
 if (index != -1) {
 printf("The target word '%s' is found at index: %d\n", target, index);
 } else {
 printf("The target word '%s' is not found in the array.\n", target);
 }
 return 0;
}
