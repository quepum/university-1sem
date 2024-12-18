#pragma once

typedef struct Queue Queue;

// the function that creates the queue
Queue *createQueue();

// the function that makes a push to the first stack
void enqueue(Queue *queue, int data);

// the function that makes a pop from 2 stack or shifts values from the first stack to the second
int dequeue(Queue *queue, int *data);

// the function that deletes the queue
void destroyQueue(Queue *queue);