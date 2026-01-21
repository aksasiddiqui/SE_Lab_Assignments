#include <stdio.h>
#include "student.h"
#include "validation.h"
#include "compute.h"
#include "output.h"

int main() {
    struct Student students[MAX];
    FILE *fp;
    int n = 0;
    int i;

    fp = fopen("students_results.txt", "r");

    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    while (fscanf(fp, "%s %s", students[n].id, students[n].name) != EOF) {
        if (checkID(students[n].id, students, n) == 0) {
            continue;
        }

        if (checkName(students[n].name) == 0) {
            continue;
        }

        for (i = 0; i < 5; i++) {
            fscanf(fp, "%d", &students[n].marks[i]);

            if (checkMarks(students[n].marks[i]) == 0) {
                break;
            }
        }

        if (i < 5) {
            continue;
        }

        calculate(students, n);
        assignGrade(students, n);

        n++;
    }

    fclose(fp);

    displayResults(students, n);

    return 0;
}
