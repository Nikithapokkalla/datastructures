#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void initialize(Stack* stack) {
    stack->top = -1;
}
void push(Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}
typedef struct {
    Stack stack1;
    Stack stack2;
} Queue;
void enqueue(Queue* queue, int item) {
    push(&(queue->stack1), item);
}
int dequeue(Queue* queue) {
    if (queue->stack1.top == -1 && queue->stack2.top == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    if (queue->stack2.top == -1) {
        while (queue->stack1.top != -1) {
            int item = pop(&(queue->stack1));
            push(&(queue->stack2), item);
        }
    }

    int item = pop(&(queue->stack2));
    return item;
}

int main() {
    Queue queue;
    initialize(&(queue.stack1));
    initialize(&(queue.stack2));

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    return 0;
}

