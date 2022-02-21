#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bigENGLISH 65
#define smallENGLISH 71
#define midrange 26
#define maxrange 52
#define small_ENGLISH_bigrange 122
#define small_ENGLISH_samllrange 97
#define big_ENGLISH_bigrange 90
#define input_max 2147483647
#define input_small 0
int plus(int a, int b);
int plus(int a, int b) {
    return a + b;
}
bool ans = false;
char** word = {NULL};
struct s {
    char a;
    int b;
};

void addup(char s[100]) {
    int h = 0;
    int m = 0;
    int n[256] = {0};
    struct s a[256];
    struct s b[256];
    for (int i = 0; i < 52; i++) {
        m = (int)s[i];
        n[m]++;
    }
    for (int j = 65; j <= 90; j++) {
        if (n[j] != 0) {
            a[h].a = (char)j;
            a[h].b = n[j];
            h++;
        }
    }
    for (int j = 97; j <= 122; j++) {
        if (n[j] != 0) {
            a[h].a = (char)j;
            a[h].b = n[j];
            h++;
        }
    }
    for (int i = 0; i <= 52; i++) {
        for (int j = 0; j < h - i; j++) {
            if (a[j].b < a[j + 1].b) {
                b[j] = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b[j];
            }
        }
    }
    for (int i = 0; i < h; i++) {
    }
}
int power(int x) {
    if (x <= 0) {
        return 1;
    } else {
        return 10 * power(x - 1);
    }
}

int active(int N) {
    int count[200] = {0};
    char String1[999][999];
    int ascii_count[maxrange] = {0};  // A~Z and a~z saved
    int max = input_small;
    for (int x = input_small; x < N; x++) {
        scanf("%s", String1[x]);
    }
    // for (int x = 0; x < N; x++) {
    // printf("%s", String1[x]);
    //}
    for (int z = input_small; z < N; z++) {  //��N�����
        for (int y = input_small; y < strlen(String1[z]); y++) {  //��N����ƪ���
            if (String1[z][y] >= bigENGLISH &&
                String1[z][y] <= big_ENGLISH_bigrange) {
                ++ascii_count[((String1[z][y]) - bigENGLISH)];
                // printf("%d\n", ((String1[z][y])-bigENGLISH));
            }
            if (String1[z][y] >= small_ENGLISH_samllrange &&
                String1[z][y] <= small_ENGLISH_bigrange) {
                ++ascii_count[((String1[z][y]) - smallENGLISH)];
                // printf("%d\n", ((String1[z][y])- bigENGLISH));
            }
        }
    }
    for (int run = input_small; run < maxrange; run++) {
        if (ascii_count[run] > max) {
            max = ascii_count[run];
        }
    }
    // printf("%d", ascii_count[0]);
    // printf("%d", max);
    int save_runtime = max;
    while (save_runtime > input_small) {
        for (int v = input_small; v < midrange; v++) {
            if (ascii_count[v] == save_runtime) {
                printf("%c(%d) ", v + bigENGLISH, save_runtime);
            }
        }
        for (int v = midrange; v < maxrange; v++) {
            if (ascii_count[v] == save_runtime) {
                printf("%c(%d) ", v + smallENGLISH, save_runtime);
            }
        }
        --save_runtime;
    }
}
int assume(int N, int start_count, int end_count) {
    int saveN = N;  //�O�d�쥻���r��
    int NEW_N = N;  //�r��屼index�����ӼƭȡA1��
    if (start_count == end_count) {  //���j����P�_
        return 0;
    } else {
        int find = saveN;       //�ҭn�䪺�ƭ�
        if (saveN % 48 == 0) {  //�P�_�O�_���l����0
            start_count = start_count + 1;  //�U�ӷj�M��
            find = find + 1;                //�U��find��index��
            // printf("T");
            return assume(saveN, start_count, end_count);  //���s�I�s
        } else {
            start_count = start_count + 1;  //�U�ӷj�M��
            find = find + 1;                //�U��find��index��
            // printf("F");
            return assume(saveN, start_count, end_count);  //���s�I�s
        }
    }
}
void fun1(char* str, bool* used, int p1, int p2);

void fun1(char* str, bool* used, int p1, int p2) {
    if (p2 == (p1))
        p2 = 0;
    int len = strlen(word[p2]);
    if (!strcmp(str, "")) {
        ans = true;
        return;
    } else {
        for (int i = 0; i < p1; i++) {
            if (!strncmp(str, word[i], len)) {
                used[i] = true;
                while (!strncmp(str, word[i], len))
                    str += len;
                return fun1(str, used, p1, p2 += 1);
            }
        }
    }
}

void quickSort(int arr[], int low, int high) {
    int first = low;
    int last = high;
    int key = arr[first];
    if (low >= high)
        return;
    while (first < last) {
        while (first < last && arr[last] >= key) {
            last--;
        }
        arr[first] = arr[last];

        while (first < last && arr[first] <= key) {
            first++;
        }
        arr[last] = arr[first];
    }
    arr[first] = key;

    quickSort(arr, low, first - 1);
    quickSort(arr, first + 1, high);
}

int main() {
    int N, newN, temp;
    while (scanf("%d", &N)) {
        newN = N;
        if (N <= 0) {
            break;
        } else {
            int* list = (int*)calloc(N, sizeof(int));
            for (int cnt = 0; cnt < N; cnt++) {
                scanf("%d", &list[cnt]);
            }
            quickSort(list, 0, N - 1);
            printf("Minimum value is %d\n", list[0]);
            printf("Maximum value is %d\n", list[N - 1]);
            for (int i = newN - 1; i >= 0; i--) {
                printf("%d ", list[i]);
            }
            printf("\n");
            free(list);
        }
    }
    return 0;
}