#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Count the days that the date of that year(2022/06/25 is 176 day)
// Done: 14 % similar to others'

int main() {
    while (1) {
        int cnt = 0, total = 0, check = 0;
        int daysOfMonth[13] = {0,  31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};  //每月天數，起始值為0
        char input[99] = {'\0'};
        char currentDate[3][99] = {'\0'};
        char* cut;
        int isLeap = 0;
        scanf("%s", input);

        cut = strtok(input, "/");
        while (cut != NULL) {
            strcpy(currentDate[cnt++], cut);
            cut = strtok(NULL, "/");
        }

        int year = atoi(currentDate[0]);
        if (year <= -1) {
            break;
        }
        int month = atoi(currentDate[1]);
        int date = atoi(currentDate[2]);

        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
            isLeap = 1;
        }
        if ((month < 1) || (month > 12)) {
            // printf("Error in month");
            check = 1;
        } else if ((date > daysOfMonth[month + 1]) || (date < 0)) {
            if ((month == 2) && (date > 29) && (isLeap == 1)) {
                check = 2;
            } else {
                // printf("Error in date");
                check = 1;
            }
        }
        if (check == 1) {
            printf("Error!\n");
        } else {
            for (int i = 0; i < month; i++) {
                total += daysOfMonth[i];
            }
            total += date;
            if ((isLeap) && (month > 2)) {
                printf("%d\n", ++total);
            } else {
                printf("%d\n", total);
            }
        }
    }

    return 0;
}