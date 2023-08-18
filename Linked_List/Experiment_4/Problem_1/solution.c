#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student node
struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct Student *next;
};

// Function to print the details of a student
void printStudent(struct Student *student) {
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("-----------------------\n");
}

int main() {
    // Create three student nodes
    struct Student n1, n2, n3;

    // Fill in the details for each student
    n1.rollNumber = 101;
    strcpy(n1.name, "John");
    n1.age = 20;
    n1.next = &n2;

    n2.rollNumber = 102;
    strcpy(n2.name, "Jane");
    n2.age = 21;
    n2.next = &n3;

    n3.rollNumber = 103;
    strcpy(n3.name, "Michael");
    n3.age = 22;
    n3.next = NULL;

    // Print details of each student
    printf("Details of Student 1:\n");
    printStudent(&n1);

    printf("Details of Student 2:\n");
    printStudent(&n2);

    printf("Details of Student 3:\n");
    printStudent(&n3);

    return 0;
}
