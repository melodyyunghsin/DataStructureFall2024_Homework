#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

struct Stack {
    char element[100];
    int topIdx;
};

void push(struct Stack* stack, char newElement){
    stack->topIdx++;
    stack->element[stack->topIdx] = newElement;
}

void pop(struct Stack* stack){
    stack -> topIdx--;
}

int peek(struct Stack* stack){
    return stack -> element[stack -> topIdx];
}

bool isEmpty(struct Stack* stack){
    return stack->topIdx == -1;
}

int main() {

    char input[100];
    char output[100];
    int outputIdx = 0;
    struct Stack stack;
    stack.topIdx = -1;
    scanf("%s", input);  
    int i = 0;

    while (input[i] != '\0'){
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' ){
            push(&stack, input[i]);
        }
        else if (isalpha(input[i])){
            output[outputIdx] = input[i];
                outputIdx++;
            if (!isEmpty(&stack))
            {
                output[outputIdx] = peek(&stack);
                outputIdx++;
                //printf("%c", peek(&stack));
                pop(&stack);
            }
        }
        else{
            printf("ERROR: Invalid Input\n");
            return 0;
        }
        i++;
    }

    if(output[outputIdx - 1] == '+' || output[outputIdx - 1] == '-' || output[outputIdx - 1] == '*' || output[outputIdx - 1] == '/' ){
        printf("ERROR: Invalid Input\n");
        return 0;
    }
    i = 0;
    while (output[i] != '\0'){
        printf("%c", output[i]);
        i++;
    }

    printf("\n");

    return 0;
}