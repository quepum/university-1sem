#include "stack.h"

int main(void) {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);


    destroyQueue(q);
    return 0;
}