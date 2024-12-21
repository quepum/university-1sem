#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

typedef struct Queue {
    Stack *stack1;
    Stack *stack2;
} Queue;

Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    assert(stack != NULL);
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int data) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    assert(node != NULL);
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack *stack, int *data) {
    if (stack->top == NULL) {
        return -1;
    }
    StackNode *temp = stack->top;
    *data = temp->data;
    stack->top = temp->next;
    free(temp);
    return *data;
}

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    assert(queue != NULL);
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    return queue;
}

void enqueue(Queue *queue, int data) {
    push(queue->stack1, data);
}

int dequeue(Queue *queue, int *data) {
    if (pop(queue->stack2, data) == 0) {
        return 0;
    }

    int temp;
    while (pop(queue->stack1, &temp) == 0) {
        push(queue->stack2, temp);
    }

    return pop(queue->stack2, data);
}

void destroyStack(Stack *stack) {
    int data;
    while (pop(stack, &data) == 0) {
    }
    free(stack);
}

void destroyQueue(Queue *queue) {
    destroyStack(queue->stack1);
    destroyStack(queue->stack2);
    free(queue);
}