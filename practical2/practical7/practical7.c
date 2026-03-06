#include <stdio.h>
#include <string.h>

char stack[20];
char input[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

void check() {
    int i;

    // Reduce id -> E
    for(i = 0; i <= top; i++) {
        if(stack[i] == 'i' && stack[i+1] == 'd') {
            printf("Reduce: id -> E\n");
            stack[i] = 'E';
            top--;
        }
    }

    // Reduce E+E -> E
    for(i = 0; i <= top; i++) {
        if(stack[i]=='E' && stack[i+1]=='+' && stack[i+2]=='E') {
            printf("Reduce: E+E -> E\n");
            stack[i] = 'E';
            top -= 2;
        }
    }

    // Reduce E*E -> E
    for(i = 0; i <= top; i++) {
        if(stack[i]=='E' && stack[i+1]=='*' && stack[i+2]=='E') {
            printf("Reduce: E*E -> E\n");
            stack[i] = 'E';
            top -= 2;
        }
    }

    // Reduce (E) -> E
    for(i = 0; i <= top; i++) {
        if(stack[i]=='(' && stack[i+1]=='E' && stack[i+2]==')') {
            printf("Reduce: (E) -> E\n");
            stack[i] = 'E';
            top -= 2;
        }
    }
}

int main() {
    int i = 0;
    printf("Enter input string: ");
    scanf("%s", input);

    printf("\nStack\tInput\tAction\n");

    while(input[i] != '\0') {
        push(input[i]);
        printf("%s\t%s\tShift\n", stack, input+i+1);
        check();
        i++;
    }

    check();

    if(stack[0] == 'E' && stack[1] == '\0')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected\n");

    return 0;
}