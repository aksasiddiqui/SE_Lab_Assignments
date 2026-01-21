#ifndef STUDENT_H
#define STUDENT_H

#define MAX 100

struct Student {
    char id[20];
    char name[30];
    int marks[5];
    int total;
    float percentage;
    char grade[3];
};

#endif