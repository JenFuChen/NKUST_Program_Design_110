//#include <cstdlib>
//#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int i, j, k;
    // char num2[2][3][2] = {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
    //                       {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}}};
    int* ptr;
    int num2[2][3][2] = {{{1, -3}, {5, 7}, {-9, 11}},
                         {{13, -15}, {17, 19}, {-21, 23}}};

    ptr = &num2[0][0][0];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 2; k++) {
                cout << "num[" << i << "]"
                     << "[" << j << "]"
                     << "[" << k << "]=\t" << *ptr << "\tptr + " << i << "= "
                     << ptr << endl;
                ptr++;
            }
            cout << endl;
        }
    }

    // system("pause");
    return 0;
}