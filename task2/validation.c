#include <string.h>
#include "validation.h"

int checkID(char id[], struct Student s[], int count) {
    int i;
    int j;

    for (i = 0; id[i] != '\0'; i++) {
        if (!((id[i] >= 'A' && id[i] <= 'Z') ||
              (id[i] >= 'a' && id[i] <= 'z') ||
              (id[i] >= '0' && id[i] <= '9'))) {
            return 0;
        }
    }

    for (j = 0; j < count; j++) {
        if (strcmp(id, s[j].id) == 0) {
            return 0;
        }
    }

    return 1;
}

int checkName(char name[]) {
    int i;

    for (i = 0; name[i] != '\0'; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z') ||
              (name[i] >= 'a' && name[i] <= 'z'))) {
            return 0;
        }
    }

    return 1;
}

int checkMarks(int m) {
    if (m < 0) {
        return 0;
    }

    if (m > 100) {
        return 0;
    }

    return 1;
}