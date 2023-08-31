#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10
1struct Stack {
    int items[MAX_SIZE];
    int top;
};
void initialize(struct Stack *stack) {
    stack->top = -1;
}
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push %d\n", value);
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop\n");
        return -1;
    } else {
        int value = stack->items[stack->top];
        stack->top--;
        return value;
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack)); 

    return 0;
}

