int opt2(int x, char date1[99][99], char name[99][99]) {
    // printf("2");
    int made1[x] = {'\0'};
    int madetemp, i, j, h;
    char nametemp[99][99] = {'\0'};
    for (h = 0; h < x; h++) {
        made1[h] = (date1[h][0] - 48) * 10000000 +
                   (date1[h][1] - 48) * 1000000 + (date1[h][2] - 48) * 100000 +
                   (date1[h][3] - 48) * 10000 + (date1[h][5] - 48) * 1000 +
                   (date1[h][6] - 48) * 100 + (date1[h][8] - 48) * 10 +
                   date1[h][9] - 48;
        // printf(" %d",made1[h]);
    }

    for (i = 0; i < x; i++) {
        for (j = i + 1; j < x; j++) {
            if (made1[i] == made1[j]) {
                if (num[i] > num[j])  //待修
                {
                    madetemp = made1[i];
                    made1[i] = made1[j];
                    made1[j] = madetemp;
                    for (h = 0; h < 99; h++) {
                        nametemp[i][h] = name[i][h];
                        name[i][h] = name[j][h];
                        name[j][h] = nametemp[i][h];
                    }
                }
            } else if (made1[i] > made1[j]) {
                madetemp = made1[i];
                made1[i] = made1[j];
                made1[j] = madetemp;
                for (h = 0; h < 99; h++) {
                    nametemp[i][h] = name[i][h];
                    name[i][h] = name[j][h];
                    name[j][h] = nametemp[i][h];
                }
            }
        }
    }
    for (int i = 0; i < x; i++) {
        printf("%s\n", name[i]);
    }
}