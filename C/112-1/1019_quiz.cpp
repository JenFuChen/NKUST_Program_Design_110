// 1019 Quiz

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : QUIZ

#include <stdio.h>
#include <stdlib.h>

// Create a vector of three dimension <x, y, z>
struct vector {
    float x;
    float y;
    float z;
} typedef Vector;

// Inner Product of A, B
float inProduct(Vector A, Vector B) {
    return (A.x * B.x + A.y * B.y + A.z * B.z);
}

// Cross Product of A, B
Vector outProduct(Vector A, Vector B) {
    Vector result;

    result.x = A.y * B.z - A.z * B.y;
    result.y = A.z * B.x - A.x * B.z;
    result.z = A.x * B.y - A.y * B.x;

    return result;
}

int main() {
    Vector A = {1, -2, 3};
    Vector B = {2, -3, -1};
    printf("\n A = {%.1f, %.1f, %.1f} ｜ B = {%.1f, %.1f, %.1f}\n", A.x, A.y,
           A.z, B.x, B.y, B.z);
    printf("(A, B) Inner Product = %.3f\n", inProduct(A, B));

    Vector C = outProduct(A, B);

    printf("(A, B) Cross Product = <%.3f, %.3f, %.3f>\n", C.x, C.y, C.z);

    return 0;
}
