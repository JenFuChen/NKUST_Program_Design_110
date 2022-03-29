//
//  main.c
//  111-0328
//
//  Created by 徐崇皓 on 2022/3/28.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char* argv[]) {
    int t = 0;
    char d[5][99][99] = {'\0'};

    while (1) {
        int ii = 0;
        scanf("%d", &ii);

        char i[5][99] = {'\0'};

        if (ii == 1) {
            scanf("%s %s %s %s %s", i[0], i[1], i[2], i[3], i[4]);
            //商品編號
            int bb = 0;
            for (int x = 0; x < t; x++) {
                if (strcmp(d[0][x], i[0]) == 0) {
                    bb++;
                    break;
                }
            }
            if (bb != 0) {
                printf("ErrorInput\n");
                continue;
                ;
            }

            //日期
            if (strcmp(i[2], i[3]) == 1) {
                printf("ErrorInput\n");
                continue;
                ;
            }

            if (strcmp(i[2], "2022/03/28") > 0) {
                printf("ErrorInput\n");
                continue;
                ;
            }

            //正確讀取
            // printf("ok %d\n",t);
            for (int x = 0; x < 5; x++) {
                strcpy(d[x][t], i[x]);
            }
            t = t + 1;
        }

        if (ii == 2) {
            char ans[3][99][99];
            char ra[99] = {'\0'};

            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < t; y++) {
                    strcpy(ans[x][y], d[x][y]);
                }
            }

            for (int y = 0; y < t; y++) {
                for (int x = y + 1; x < t; x++) {
                    if (strlen(ans[2][x]) < strlen(ans[2][y])) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }
                    }

                    if ((strlen(ans[2][x]) == strlen(ans[2][y])) &&
                        strcmp(ans[2][x], ans[2][y]) < 0) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }

                    } else if ((strlen(ans[2][x]) == strlen(ans[2][y])) &&
                               strcmp(ans[2][x], ans[2][y]) == 0 &&
                               strlen(ans[0][x]) < strlen(ans[0][y])) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }

                    } else if ((strlen(ans[2][x]) == strlen(ans[2][y])) &&
                               strcmp(ans[2][x], ans[2][y]) == 0 &&
                               strlen(ans[0][x]) == strlen(ans[0][y]) &&
                               strcmp(ans[0][x], ans[0][y]) < 0) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }
                    }
                }
            }

            for (int x = 0; x < t; x++) {
                for (int y = 0; y < strlen(ans[1][x]); y++) {
                    printf("%c", ans[1][x][y]);
                }
                printf("\n");
            }
        }

        if (ii == 3) {
            char ans[3][99][99];
            char ra[99];

            for (int x = 0; x < t; x++) {
                strcpy(ans[0][x], d[0][x]);
                strcpy(ans[1][x], d[1][x]);
                strcpy(ans[2][x], d[3][x]);
            }

            for (int y = 0; y < t; y++) {
                for (int x = y + 1; x < t; x++) {
                    if (strlen(ans[2][x]) < strlen(ans[2][y])) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }
                    }

                    if ((strlen(ans[2][x]) == strlen(ans[2][y])) &&
                        strcmp(ans[2][x], ans[2][y]) < 0) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }

                    } else if ((strlen(ans[2][x]) == strlen(ans[2][y])) &&
                               strcmp(ans[2][x], ans[2][y]) == 0 &&
                               strlen(ans[0][x]) < strlen(ans[0][y])) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }

                    } else if ((strlen(ans[2][x]) == strlen(ans[2][y])) &&
                               strcmp(ans[2][x], ans[2][y]) == 0 &&
                               strlen(ans[0][x]) == strlen(ans[0][y]) &&
                               strcmp(ans[0][x], ans[0][y]) < 0) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }
                    }
                }
            }

            for (int x = 0; x < t; x++) {
                if (strcmp(ans[2][x], "2022/03/28") >= 0) {
                    for (int y = 0; y < strlen(ans[1][x]); y++) {
                        printf("%c", ans[1][x][y]);
                    }
                    printf("\n");
                }
            }
        }

        if (ii == 4) {
            char ans[3][99][99];
            char ra[99];

            for (int x = 0; x < t; x++) {
                strcpy(ans[0][x], d[0][x]);
                strcpy(ans[1][x], d[1][x]);
                strcpy(ans[2][x], d[4][x]);
            }

            for (int y = 0; y < t; y++) {
                for (int x = y + 1; x < t; x++) {
                    if (strcmp(ans[2][x], ans[2][y]) < 0) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }

                    } else if (strcmp(ans[2][x], ans[2][y]) == 0 &&
                               strlen(ans[0][x]) < strlen(ans[0][y])) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }

                    } else if (strcmp(ans[2][x], ans[2][y]) == 0 &&
                               strlen(ans[0][x]) == strlen(ans[0][y]) &&
                               strcmp(ans[0][x], ans[0][y]) < 0) {
                        char ra[99] = {'\0'};
                        for (int z = 0; z < 3; z++) {
                            strcpy(ra, ans[z][x]);
                            strcpy(ans[z][x], ans[z][y]);
                            strcpy(ans[z][y], ra);
                        }
                    }
                }
            }

            for (int x = 0; x < t; x++) {
                if (strcmp(ans[2][x], "2022/03/28") >= 0) {
                    for (int y = 0; y < strlen(ans[1][x]); y++) {
                        printf("%c", ans[1][x][y]);
                    }
                    printf("\n");
                }
            }
        }

        if (ii == 5) {
            break;
        }
    }
}
