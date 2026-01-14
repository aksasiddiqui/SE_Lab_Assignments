#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char id[20];
    char name[30];
    int marks[5];
    int total;
    float percentage;
    char grade[3];
};

int checkID(char id[], struct Student s[], int count);
int checkName(char name[]);
int checkMarks(int m);
void calculate(struct Student s[], int index);
void assignGrade(struct Student s[], int index);

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
        if (!checkID(students[n].id, students, n)) {
            printf("Invalid ID skipped: %s\n", students[n].id);
            continue;
        }

        if (!checkName(students[n].name)) {
            printf("Invalid name skipped: %s\n", students[n].name);
            continue;
        }

        for (i = 0; i < 5; i++) {
            fscanf(fp, "%d", &students[n].marks[i]);

            if (!checkMarks(students[n].marks[i])) {
                printf("Invalid marks found. Student skipped.\n");
                break;
            }
        }

        if (i < 5)
            continue;

        calculate(students, n);
        assignGrade(students, n);

        n++;
    }

    fclose(fp);

    {
        float avg = 0;
        float highest = students[0].percentage;
        float lowest = students[0].percentage;
        int gradeCount[8] = {0};

        printf("\nID\tName\tTotal\tPercentage\tGrade\n");
        printf("-----------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%s\t%s\t%d\t%.2f\t\t%s\n",
                   students[i].id,
                   students[i].name,
                   students[i].total,
                   students[i].percentage,
                   students[i].grade);

            avg = avg + students[i].percentage;

            if (students[i].percentage > highest) {
                highest = students[i].percentage;
            }
          
            if (students[i].percentage < lowest) {
                lowest = students[i].percentage;
            }
          
            if (strcmp(students[i].grade, "O") == 0) {
                gradeCount[0]++;
            } else if (strcmp(students[i].grade, "A+") == 0) {
                gradeCount[1]++;
            } else if (strcmp(students[i].grade, "A") == 0) {
                gradeCount[2]++;
            } else if (strcmp(students[i].grade, "B+") == 0) {
                gradeCount[3]++;
            } else if (strcmp(students[i].grade, "B") == 0) {
                gradeCount[4]++;
            } else if (strcmp(students[i].grade, "C") == 0) {
                gradeCount[5]++;
            } else if (strcmp(students[i].grade, "D") == 0) { 
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

    return 0;
}

int checkID(char id[], struct Student s[], int count) {
    int i, j;

    for (i = 0; id[i] != '\0'; i++)
    {
        if (!((id[i] >= 'A' && id[i] <= 'Z') ||
              (id[i] >= 'a' && id[i] <= 'z') ||
              (id[i] >= '0' && id[i] <= '9')))
        {
            return 0;
        }
    }

    for (j = 0; j < count; j++) {
        if (strcmp(id, s[j].id) == 0)
            return 0;
    }

    return 1;
}

int checkName(char name[]){
    int i;

    for (i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z')))
        {
            return 0;
        }
    }

    return 1;
}

int checkMarks(int m) {
    if (m < 0 || m > 100)
        return 0;

    return 1;
}

void calculate(struct Student s[], int index) {
    int i;
    int sum = 0;

    for (i = 0; i < 5; i++) {
        sum = sum + s[index].marks[i];
    }

    s[index].total = sum;
    s[index].percentage = sum / 5.0;
}

void assignGrade(struct Student s[], int index) {
    float p = s[index].percentage;

    if (p >= 90)
        strcpy(s[index].grade, "O");
    else if (p >= 85)
        strcpy(s[index].grade, "A+");
    else if (p >= 75)
        strcpy(s[index].grade, "A");
    else if (p >= 65)
        strcpy(s[index].grade, "B+");
    else if (p >= 60)
        strcpy(s[index].grade, "B");
    else if (p >= 55)
        strcpy(s[index].grade, "C");
    else if (p >= 50)
        strcpy(s[index].grade, "D");
    else
        strcpy(s[index].grade, "F");
}
