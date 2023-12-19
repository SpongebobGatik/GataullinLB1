#ifndef ONELIST_H
#define ONELIST_H
#include <stdbool.h>

typedef struct NodeL1 {
    char* data;
    struct NodeL1* next;
} NodeL1;

NodeL1* initList();

void append(NodeL1** head, char* data);

void removeLast(NodeL1** head);

bool contains(NodeL1* head, char* data);

void printList(NodeL1* head);

void clearList(NodeL1** head);

#endif
