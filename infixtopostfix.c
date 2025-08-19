#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char c;

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    while ((c = infix[i++]) != '\n' && c != '\0') {
        if (isalnum(c)) {
           
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
          
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }
        else {
        
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}

