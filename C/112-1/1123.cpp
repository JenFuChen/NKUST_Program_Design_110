// 1116

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Stack Practice

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX_SIZE 100

#define lparen 1
#define rparen 2
#define plus 3
#define minus 4
#define times 5
#define divide 6
#define operand 7
#define eos -1

using namespace std;

char original[MAX_SIZE];  // 原式
char postfix[MAX_SIZE];   // 後置式
char stack[MAX_SIZE];     // 堆疊計算
char stack2[MAX_SIZE];    // 還原堆疊計算

int top = -1;
int top2 = -1;
bool isCorrect = true;  // 輸入正確與否

// in2post //

void push(char op) {
    if (top >= MAX_SIZE - 1)
        printf("\nSTACK FULL\n");
    else
        stack[++top] = op;
}

char pop() {
    return ((top == -1) ? -1 : stack[top--]);
}

int priority(char op) {
    return ((op == '+' || op == '-')
                ? 1
                : ((op == '*' || op == '/')
                       ? 2
                       : (op == '(' || op == ')' ? -1 : -2)));
}

void in2post(char* infix, char* postfix) {
    int i = 0, j = 0;
    // Detect if the character is out of 0~9 or +-*/()
    while (infix[i] != '\0') {
        if (infix[i] < 40 || infix[i] > 57) {
            printf("Please input correct format!\n");
            isCorrect = false;
            break;
        } else {
            isCorrect = true;
        }
        i++;
    }
    i = 0;
    while (infix[i] != '\0' && isCorrect == true) {
        if (infix[i] >= 49 && infix[i] <= 57) {  // 0~9
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
            i++;
        } else {
            while (priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }
    char op;
    while ((op = pop()) != -1) {
        postfix[j++] = op;
    }
    postfix[j++] = '\0';
}

// EVAL //

void push2(int op) {
    if (top2 >= MAX_SIZE - 1)
        printf("\nSTACK FULL\n");
    else
        stack2[++top2] = op;
}

int pop2() {
    return top2 < 0 ? -1 : stack2[top2--];
}

int getToken(char* symbol, int* n) {
    *symbol = postfix[(*n)++];
    switch (*symbol) {
        case '(':
            return lparen;
        case ')':
            return rparen;
        case '+':
            return plus;
        case '-':
            return minus;
        case '*':
            return times;
        case '/':
            return divide;
        case '\0':
            return eos;  // eos
        default:
            return operand;  // num
    }
}

int eval() {
    int token;
    char symbol;
    int op1, op2;
    int n = 0;  // count character num
    token = getToken(&symbol, &n);
    while (token != eos) {
        if (token == operand)
            push2(symbol - '0');
        else {
            op2 = pop2();
            op1 = pop2();
            switch (token) {
                case plus:
                    push2(op1 + op2);
                    break;
                case minus:
                    push2(op1 - op2);
                    break;
                case times:
                    push2(op1 * op2);
                    break;
                case divide:
                    if (op1 == 0)
                        push2(0);
                    else
                        push2(op1 / op2);
                    break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop2();
}

int main() {
    system("clear");
    printf(
        "\nPlease input \" 0~9  + - * / ) ( \" format arithmetic. Zero to "
        "EXIT.\n");
    while (1) {
        scanf("%s", original);
        if (original[0] == '0') {
            printf("EXIT\n");
            break;
        }
        in2post(original, postfix);
        if (isCorrect) {
            printf("> %s", postfix);
            printf("\n> %d", eval());
        }
        printf("\n-------------------\n");
    }
    return 0;
}
