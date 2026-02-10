#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student *s = NULL;
    int choice, n = 0, i, roll, found;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Add Records\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:  
            printf("Enter number of students to add: ");
            scanf("%d", &n);

            s = (struct Student *)malloc(n * sizeof(struct Student));
            if (s == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }

            for (i = 0; i < n; i++) {
                printf("\nEnter details of student %d\n", i + 1);

                printf("Roll number: ");
                scanf("%d", &s[i].roll);

                printf("Name: ");
                scanf(" %[^\n]", s[i].name);

                printf("Marks: ");
                scanf("%f", &s[i].marks);
            }
            break;

        case 2:  
            if (s == NULL || n == 0) {
                printf("No records to display\n");
            } else {
                printf("\nStudent Records:\n");
                for (i = 0; i < n; i++) {
                    printf("\nRoll: %d", s[i].roll);
                    printf("\nName: %s", s[i].name);
                    printf("\nMarks: %.2f\n", s[i].marks);
                }
            }
            break;

        case 3: 
            if (s == NULL || n == 0) {
                printf("No records to delete\n");
                break;
            }

            printf("Enter roll number to delete: ");
            scanf("%d", &roll);

            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                for (; i < n - 1; i++) {
                    s[i] = s[i + 1];
                }
                n--;
                printf("Record deleted successfully\n");
            } else {
                printf("Record not found\n");
            }
            break;

        case 4: 
            free(s);
            printf("Memory freed. Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
