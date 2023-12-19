#ifndef QUEUE_H
#define QUEUE_H

typedef struct NodeQueue {
    char* element;
    struct NodeQueue* next;
} NodeQueue;

typedef struct Queue {
    NodeQueue* front;
    NodeQueue* rear;
} Queue;

Queue* initQueue();

void clearQueue(Queue* queue);

void printQueue(Queue* queue);

void QPUSH(Queue* queue, char* element);

char* QPOP(Queue* queue);

#endif
