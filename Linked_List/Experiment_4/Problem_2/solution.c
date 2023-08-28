#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct Student *next;
} Student;

void printStudentInfo(Student *student) {
    printf("Roll Number: %d\n", student->rollNumber);
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("\n");
}

int main() {
    Student *head = NULL;
    char choice;

    do {
        Student *newStudent = (Student *)malloc(sizeof(Student));
        printf("Enter Roll Number: ");
        scanf("%d", &newStudent->rollNumber);
        printf("Enter Name: ");
        scanf("%s", newStudent->name);
        printf("Enter Age: ");
        scanf("%d", &newStudent->age);
        newStudent->next = NULL;

        if (head == NULL) {
            head = newStudent;
        } else {
            Student *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }

        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to consume the newline character

    } while (choice == 'y' || choice == 'Y');

    // Print the information of all students
    Student *temp = head;
    while (temp != NULL) {
        printStudentInfo(temp);
        temp = temp->next;
    }

    // Free the allocated memory for the temp
    temp = head;
    while (temp != NULL) {
        Student *nextStudent = temp->next;
        free(temp);
        temp = nextStudent;
    }

    return 0;
}
