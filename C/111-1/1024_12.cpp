#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    char runChartData[99] = {'\0'};  // Store the input
    int runChart[99][99] = {'\0'};   // Store the chart R = 1; C = 0; F = -1
    char up = 'R', fall = 'F', calm = 'C';
    int x = 0, y = 0;
    int yD = 0;
    scanf("%s", runChartData);
    for (int i = strlen(runChartData) - 1; i >= 0; i--) {
        if (i > 0 &&
            ((runChartData[i - 1] == up && runChartData[i] == fall) ||
             (runChartData[i - 1] == fall && runChartData[i] == calm) ||
             (runChartData[i - 1] == fall && runChartData[i] == up) ||
             (runChartData[i - 1] == calm && runChartData[i] == up))) {
            // "/\" "\_" "\/" "_/"
            y += 0;
        } else if (runChartData[i] == up) {
            // /
            y -= 1;
        } else if (runChartData[i] == fall) {
            y += 1;
        }
    }

    if (y < 0) {
        yD = y * -1;
    }
    y += yD;
    printf("y: %d, yD: %d\n", y, yD);
    for (int i = 0; i < strlen(runChartData); i++) {
        // in same 'y' position
        if (i > 0 &&
            ((runChartData[i - 1] == up && runChartData[i] == fall) ||
             (runChartData[i - 1] == fall && runChartData[i] == calm) ||
             (runChartData[i - 1] == fall && runChartData[i] == up) ||
             (runChartData[i - 1] == calm && runChartData[i] == up))) {
            // "/\" "\_" "\/" "_/"
            y += 0;
        } else if (runChartData[i] == up) {
            // '/'
            y -= 1;
        } else if (runChartData[i] == fall) {
            // '\'
            y += 1;
        } else if (runChartData[i] == calm) {
            // '_'
            y += 0;
        }
        if (runChartData[i] == up) {
            runChart[y][x] = 1;
        } else if (runChartData[i] == calm) {
            runChart[y][x] = 0;
        } else if (runChartData[i] == fall) {
            runChart[y][x] = -1;
        }
        x += 1;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", runChart[i][j]);
        }
        printf("\n");
    }
    return 0;
}
