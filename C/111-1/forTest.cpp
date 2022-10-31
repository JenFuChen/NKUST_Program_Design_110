#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int S, N;  // S=科目數,N=學生數
    while (1) {
        map<int, vector<float> > student_grade;
        cin >> S >> N;
        if (N <= 0 || S <= 0) {
            break;
        }
        int index = 1;
        vector<string> subject(S);
        for (int i = 0; i < S; i++) {
            cin >> subject[i];
        }
        vector<float> Vector;
        float tmp;
        //資料輸入
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < S; j++) {  //科目
                cin >> tmp;
                Vector.push_back(tmp);
            }
            //將成績平均(個人)
            float average = 0;
            for (int j = 0; j < Vector.size(); j++) {
                average += Vector[j];
            }
            average /= Vector.size();
            Vector.push_back(average);
            student_grade[i] = Vector;
            Vector.clear();
        }

        cout << "學生編號"
             << " ";
        for (int i = 0; i < S; i++) {
            cout << subject[i] << " ";
        }
        cout << "學生平均" << endl;
        //按照學生編號輸出成績
        for (int i = 0; i < N; i++) {
            cout << index << " ";
            for (int j = 0; j < S; j++) {
                cout << setprecision(0) << fixed << student_grade[i][j] << " ";
            }
            float student_average = student_grade[i][S];
            cout << setprecision(2) << fixed << student_average;
            cout << endl;
            index++;
        }
        //輸出各科平均
        cout << "各科平均"
             << " ";
        for (int j = 0; j < S; j++) {
            float subject_average = 0;
            for (int i = 0; i < N; i++) {
                subject_average += student_grade[i][j];
            }
            subject_average /= N;
            cout << setprecision(2) << fixed << subject_average << " ";
        }
        cout << endl;
    }
    return 0;
}