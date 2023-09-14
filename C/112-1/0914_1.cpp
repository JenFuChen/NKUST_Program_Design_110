/*
    ｜Practice 1｜
    Author: JEN-FU CHEN, C110152319
    Build Date: 2023.09.14
    Description: Compute the average, standard deviation of an array
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numbers[10] = {0};
    int sum = 0, average = 10, temp = 0;
    int standardDeviation = 0;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        numbers[i] = rand() % 100;
        // numbers[i] = 10;
        sum += numbers[i];
    }

    average = sum / 10;

    for (int i = 0; i < 10; i++) {
        temp += (numbers[i] - average) * (numbers[i] - average);
    }

    standardDeviation = sqrt(temp / 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Average = %d\n", average);
    printf("Standard Deviation = %d\n", standardDeviation);

    return 0;
}