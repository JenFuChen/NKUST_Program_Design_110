// 1116

// Author: 四子三丙 陳人輔 C110152319
// Class : 資料結構
// Description : Stack Practice

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAX_SIZE 100

using namespace std;

char expr[MAX_SIZE];
char postfix[MAX_SIZE];
char stack[MAX_SIZE];

char stack2[MAX_SIZE];

int top = -1;
bool isCorrect = true;

// in2post

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
    isCorrect = true;
    // Detect if the character is out of 0~9 or +-*/()
    while (infix[i] != '\0') {
        if (infix[i] < 40 || infix[i] > 57) {
            printf("Please input correct format!\n");
            isCorrect = false;
            break;
        }
        i++;
    }
    i = 0;
    while (infix[i] != '\0' && isCorrect == true) {
        if (infix[i] >= 49 && infix[i] <= 57) {
            // 0~9
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
// EVAL
void push2(int op) {
    if (top >= MAX_SIZE - 1)
        printf("\nSTACK FULL\n");
    else
        stack2[++top] = op;
}
int pop2() {
    return top < 0 ? -1 : stack2[top--];
}

int getToken(char* symbol, int* n) {
    *symbol = postfix[(*n)++];
    switch (*symbol) {
        case '(':
            return 5;
        case ')':
            return 6;
        case '+':
            return 1;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 4;
        case '\0':
            return 0;  // eos
        default:
            return -1;  // num
    }
}

int eval() {
    int token;
    char symbol;
    int op1, op2;
    int n = 0;  // count charcter num
    int top = -1;
    token = getToken(&symbol, &n);
    while (token != 0) {
        if (token == -1)
            push2(symbol - '0');
        else {
            op2 = pop2();
            op1 = pop2();
            switch (token) {
                case 1:
                    push2(op1 + op2);
                    break;
                case 2:
                    push2(op1 - op2);
                    break;
                case 3:
                    push2(op1 * op2);
                    break;
                case 4:
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
    // printf("\033[2J");
    printf(
        "\nPlease input \" 0~9  + - * / ) ( \" format arithmetic. Zero to "
        "exit.\n");
    while (1) {
        scanf("%s", expr);
        if (expr[0] == '0') {
            printf("EXIT\n");
            break;
        }
        in2post(expr, postfix);
        if (isCorrect) {
            printf("> %s", postfix);
            printf("\n> %d", eval());
        }
        printf("\n-------------------\n");
    }
    return 0;
}
