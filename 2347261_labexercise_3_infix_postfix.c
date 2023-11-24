// A C PROGRAM TO CONVER THE GIVEN INFIX EXPRESSION TO POSTFIX EXPRESSION
// SUVAJIT KARMAKAR
//24/11/2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        switch (token) {
            case '(':
                stack[++top] = token;
                break;
            case ')':
                while (top >= 0 && stack[top] != '(') {
                    postfix[j++] = stack[top--];
                }
                top--;  
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(token)) {
                    postfix[j++] = stack[top--];
                }
                stack[++top] = token;
                break;
            default:
                
                postfix[j++] = token;
                break;
        }
    }

    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    
    printf("ENTER THE INFIX EXPRESSION TO CONVERT ->  ");
    scanf("%s", infix);

    
    infixToPostfix(infix, postfix);

    
    printf("\n");
    printf("THE POSTFIX EXPRESSION TO THE GIVEN INFIX IS ->  %s\n", postfix);

    return 0;
}
