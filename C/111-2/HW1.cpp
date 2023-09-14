// Title    : HW1
// State    : Developing
// Dead Line: 3/21 23:59
// Author   : JenFu Chen
// DFS function....
// ===== Start ===== //
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int runTime = 0;
// Depth-First Search Function
void DFS(int start,
         int& maxNum,
         int depth,
         vector<int> collectPoint,
         const int pointNum,
         const vector<vector<int> > dataMatrix) {
    if (runTime == pointNum || depth == pointNum) {
        return;
    }
    for (int i = 0; i < pointNum; i++) {
        if (collectPoint[i]) {
            if (dataMatrix[start][i]) {
                return;
            }
        }
    }
    for (int i = start; i < pointNum; i++) {
        if (dataMatrix[start][i]) {
            // if connected: jump to next point to DFS again
            continue;
        } else {
            collectPoint[i] = 1;
            printf("[%d][%d]=====\n", start, i);
            DFS(i, maxNum, depth + 1, collectPoint, pointNum, dataMatrix);
        }
    }
}
void Searching(const int pointNum,
               const vector<vector<int> > dataMatrix,
               int& maxNum) {
    vector<int> collectPoint(pointNum, 0);  // Store available point
    for (int i = 0; i < pointNum; i++) {
        // printf("Finding... %d /\n", i);
        DFS(i, maxNum, 1, collectPoint, pointNum, dataMatrix);
        for (int i = 0; i < pointNum; i++) {
            if (collectPoint[i])
                maxNum += 1;
        }
    }
    maxNum = maxNum > pointNum ? pointNum : maxNum;
    return;
}
// ===== Main Code ===== //
int main() {
    int pointNum = 0;  // store the total point number
    // while (scanf("%d", &pointNum)) {
    //     if (pointNum <= 0) {
    //         break;
    //     }
    // }
    scanf("%d", &pointNum);
    vector<vector<int> > dataMatrix(pointNum,
                                    vector<int>(pointNum, 0));  // Store Graph

    // ----- Input graph ----- //
    for (int row = 0; row < pointNum; row++) {
        for (int column = 0; column < pointNum; column++) {
            cin >> dataMatrix[row][column];
        }
    }
    int maxNum = 0;
    Searching(pointNum, dataMatrix, maxNum);
    printf("Answer = %d\n", maxNum);
    return 0;
}