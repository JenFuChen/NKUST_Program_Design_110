#include <stdio.h>
#include <string.h>
int studentNum = 0;
int courseNum = 0;
int gradeNum = 0;
int check = 0;
struct course {
    int ID;
    int hour;
    int credit;
    char name[999];
};

struct grade {
    int studentID;
    int courseID;
    int grades;
};

struct student {
    int ID;
    char name[999];
    char address[999];
    char birth[11];
    int average;
};

void sortData(struct student* data, struct course* course) {
    struct student temp;
    struct course temp2;
    for (int i = 0; i < studentNum; i++) {
        for (int j = i; j < studentNum; j++) {
            if (data[j].ID < data[i].ID) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    for (int i = 0; i < courseNum; i++) {
        for (int j = i; j < courseNum; j++) {
            if (course[j].ID < course[i].ID) {
                temp2 = course[i];
                course[i] = course[j];
                course[j] = temp2;
            }
        }
    }
}

void showData(struct student* data, struct course* course, int type) {
    // printf("Show Student Data\n");
    sortData(data, course);
    switch (type) {
        case 1:
            for (int i = 0; i < studentNum; i++) {
                printf("%d %s %s %s\n", data[i].ID, data[i].name,
                       data[i].address, data[i].birth);
            }
            break;
        case 2:
            for (int i = 0; i < courseNum; i++) {
                printf("%d %s %d %d\n", course[i].ID, course[i].name,
                       course[i].hour, course[i].credit);
            }
            break;
    }
}

void checkData(struct student* data,
               struct student* temp,
               struct course* course,
               struct course* courseTemp,
               struct grade* grade,
               struct grade* gradeTemp,
               int num,
               int type) {
    for (int i = 0; i < num; i++) {
        if (type == 1) {
            if (temp[0].ID == data[i].ID) {
                printf("Duplicated\n");
                check = 1;
                break;
            }
        } else if (type == 2) {
            if (courseTemp[0].ID == course[i].ID) {
                printf("Duplicated\n");
                check = 1;
                break;
            }
        } else if (type == 3) {
            if (gradeTemp[0].studentID == grade[i].studentID &&
                gradeTemp[0].courseID == grade[i].courseID) {
                printf("Duplicated\n");
                check = 1;
                break;
            }
        }
    }
}

void addStudent(struct student* data) {
    check = 0;
    struct student temp[1];
    struct course none[1];
    struct grade none2[1];
    // printf("adding Student\n");
    scanf("%d %s %s %s", &temp[0].ID, temp[0].name, temp[0].address,
          temp[0].birth);
    checkData(data, temp, none, none, none2, none2, studentNum, 1);
    if (check == 0) {
        data[studentNum].ID = temp[0].ID;
        strcpy(data[studentNum].name, temp[0].name);
        strcpy(data[studentNum].address, temp[0].address);
        strcpy(data[studentNum].birth, temp[0].birth);
        studentNum++;
    }
}

void addCourse(struct course* course) {
    check = 0;
    struct course courseTemp[1];
    struct student none[1];
    struct grade none2[1];
    // printf("adding Course\n");
    scanf("%d %s %d %d", &courseTemp[0].ID, courseTemp[0].name,
          &courseTemp[0].hour, &courseTemp[0].credit);
    checkData(none, none, course, courseTemp, none2, none2, courseNum, 2);
    if (check == 0) {
        course[courseNum].ID = courseTemp[0].ID;
        course[courseNum].hour = courseTemp[0].hour;
        course[courseNum].credit = courseTemp[0].credit;
        strcpy(course[courseNum].name, courseTemp[0].name);
        courseNum++;
    }
}

void addGrade(struct grade* grade) {
    check = 0;
    struct grade gradeTemp[1];
    struct student none[1];
    struct course none2[1];
    // printf("adding Grade\n");
    scanf("%d %d %d", &gradeTemp[0].courseID, &gradeTemp[0].studentID,
          &gradeTemp[0].grades);
    checkData(none, none, none2, none2, grade, gradeTemp, gradeNum, 3);
    if (check == 0) {
        grade[gradeNum].studentID = gradeTemp[0].studentID;
        grade[gradeNum].courseID = gradeTemp[0].courseID;
        grade[gradeNum].grades = gradeTemp[0].grades;
        gradeNum++;
    }
}

void showCourseGrade(struct grade* grade,
                     struct student* data,
                     struct course* course) {
    int courseID, token;
    struct grade temp;
    scanf("%d", &courseID);
    for (int i = 0; i < gradeNum; i++) {
        for (int j = i; j < gradeNum; j++) {
            if (grade[i].courseID == courseID) {
                if (grade[j].grades > grade[i].grades) {
                    temp = grade[i];
                    grade[i] = grade[j];
                    grade[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < gradeNum; i++) {
        if (courseID == grade[i].courseID) {
            for (int j = 0; j < courseNum; j++) {
                if (grade[i].courseID == course[j].ID) {
                    printf("%s ", course[j].name);
                }
            }
            for (int k = 0; k < studentNum; k++) {
                if (grade[i].studentID == data[k].ID) {
                    printf("%s %s %d\n", data[k].name, data[k].address,
                           grade[i].grades);
                }
            }
        }
    }
}

void rankStudent(struct student* data,
                 struct course* course,
                 struct grade* grade) {
    struct student temp;
    for (int i = 0; i < studentNum; i++) {
        data[i].average = 0;
    }
    int studentCourseNum = 0, cnt = 0;
    int average[99][2] = {0};
    for (int i = 0; i < studentNum; i++) {
        for (int j = 0; j < gradeNum; j++) {
            if (grade[j].studentID == data[i].ID) {
                data[i].average = data[i].average + grade[j].grades;
                cnt++;
            }
        }
        data[i].average = data[i].average / cnt;
        cnt = 0;
    }
    for (int i = 0; i < studentNum; i++) {
        for (int j = i; j < studentNum; j++) {
            if (data[j].average > data[i].average) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    for (int i = 0; i < studentNum; i++) {
        printf("%s\n", data[i].name);
    }
}

int main() {
    struct student data[1000];
    struct course course[1000];
    struct grade grade[1000];
    int breakPoint = 0;
    char order[99] = {'\0'};
    while (breakPoint == 0) {
        scanf("%s", order);
        if (strcmp(order, "addstudent") == 0) {
            addStudent(data);
        } else if (strcmp(order, "addcourse") == 0) {
            addCourse(course);
        } else if (strcmp(order, "addgrade") == 0) {
            addGrade(grade);
        } else if (strcmp(order, "showstudinfo") == 0) {
            showData(data, course, 1);
        } else if (strcmp(order, "showcourseinfo") == 0) {
            showData(data, course, 2);
        } else if (strcmp(order, "showcoursegrade") == 0) {
            showCourseGrade(grade, data, course);
        } else if (strcmp(order, "ranking") == 0) {
            rankStudent(data, course, grade);
        } else if (strcmp(order, "exit") == 0) {
            break;
        }
    }
    return 0;
}