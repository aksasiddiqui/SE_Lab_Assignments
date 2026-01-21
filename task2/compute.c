#include <string.h>
#include "compute.h"

void calculate(struct Student s[], int index) {
    int i;
    int sum = 0;

    for (i = 0; i < 5; i++)
    {
        sum = sum + s[index].marks[i];
    }

    s[index].total = sum;
    s[index].percentage = sum / 5.0;
}

void assignGrade(struct Student s[], int index) {
    float p;

    p = s[index].percentage;

    if (p >= 90) {
        strcpy(s[index].grade, "O");
    } else if (p >= 85) {
        strcpy(s[index].grade, "A+");
    } else if (p >= 75) {
        strcpy(s[index].grade, "A");
    } else if (p >= 65) {
        strcpy(s[index].grade, "B+");
    } else if (p >= 60) {
        strcpy(s[index].grade, "B");
    } else if (p >= 55) {
        strcpy(s[index].grade, "C");
    } else if (p >= 50) {
        strcpy(s[index].grade, "D");
    } else {
        strcpy(s[index].grade, "F");
    }
}
