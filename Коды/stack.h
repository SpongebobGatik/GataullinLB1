#ifndef STACK_H
#define STACK_H

typedef struct NodeStack {
    char* element;
    struct NodeStack* next;
} NodeStack;

typedef struct Stack {
    NodeStack* top;
} Stack;

Stack* initStack();

void SClear(Stack* stack);

void SPrint(Stack* stack);

void SPUSH(Stack* stack, char* element);

char* SPOP(Stack* stack);

#endif
