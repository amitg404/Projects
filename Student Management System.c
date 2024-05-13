#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void addStudent(struct Student students[], int* count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    (*count)++;
}

void displayStudents(const struct Student students[], int count) {
    printf("Student Details:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Roll Number: %d, Marks: %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }
}

float calculateAverageMarks(const struct Student students[], int count) {
    float totalMarks = 0;
    for (int i = 0; i < count; i++) {
        totalMarks += students[i].marks;
    }
    return totalMarks / count;
}

int main() {
    struct Student students[100];
    int count = 0;
    char choice;
    
    do {
        printf("MENU:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Calculate Average Marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                addStudent(students, &count);
                break;
            case '2':
                displayStudents(students, count);
                break;
            case '3':
                if (count > 0) {
                    printf("Average Marks: %.2f\n", calculateAverageMarks(students, count));
                } else {
                    printf("No students added yet.\n");
                }
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '4');
    
    return 0;
}
