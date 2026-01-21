#include <stdio.h>
#include <string.h>
#include "output.h"

void displayResults(struct Student s[], int n) {
    int i;
    float avg = 0;
    float highest;
    float lowest;
    int gradeCount[8] = {0};

    highest = s[0].percentage;
    lowest = s[0].percentage;

    printf("\nID\tName\tTotal\tPercentage\tGrade\n");
    printf("-----------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%s\t%s\t%d\t%.2f\t\t%s\n",
               s[i].id,
               s[i].name,
               s[i].total,
               s[i].percentage,
               s[i].grade);

        avg = avg + s[i].percentage;

        if (s[i].percentage > highest) {
            highest = s[i].percentage;
        }

        if (s[i].percentage < lowest) {
            lowest = s[i].percentage;
        }

        if (strcmp(s[i].grade, "O") == 0) {
            gradeCount[0]++;
        } else if (strcmp(s[i].grade, "A+") == 0) {
            gradeCount[1]++;
        } else if (strcmp(s[i].grade, "A") == 0) {
            gradeCount[2]++;
        } else if (strcmp(s[i].grade, "B+") == 0) {
            gradeCount[3]++;
        } else if (strcmp(s[i].grade, "B") == 0) {
            gradeCount[4]++;
        } else if (strcmp(s[i].grade, "C") == 0) {
            gradeCount[5]++;
        } else if (strcmp(s[i].grade, "D") == 0) {
            gradeCount[6]++;
        } else {
            gradeCount[7]++;
        }
    }

    avg = avg / n;

    printf("\nClass Average: %.2f\n", avg);
    printf("Highest Percentage: %.2f\n", highest);
    printf("Lowest Percentage: %.2f\n", lowest);

    printf("\nGrade Count:\n");
    printf("O  : %d\n", gradeCount[0]);
    printf("A+ : %d\n", gradeCount[1]);
    printf("A  : %d\n", gradeCount[2]);
    printf("B+ : %d\n", gradeCount[3]);
    printf("B  : %d\n", gradeCount[4]);
    printf("C  : %d\n", gradeCount[5]);
    printf("D  : %d\n", gradeCount[6]);
    printf("F  : %d\n", gradeCount[7]);
}
