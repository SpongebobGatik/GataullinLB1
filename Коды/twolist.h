#ifndef TWOLIST_H
#define TWOLIST_H

typedef struct NodeT {
    char* data;
    struct NodeT* prev;
    struct NodeT* next;
} NodeL2;

typedef struct ListT {
    NodeL2* head;
    NodeL2* tail;
} ListT;

ListT* initListT();

void prependT(ListT** list, char* data);

void appendT(ListT** list, char* data);

void removeFirstT(ListT** list);

void removeLastT(ListT** list);

void printListT(ListT** list);

void clearListT(ListT** list);

void removeByValueT(ListT** list, char* data);

NodeL2* searchByValueT(ListT** list, char* data);

#endif
