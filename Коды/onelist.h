#ifndef ONELIST_H
#define ONELIST_H

typedef struct Node {
    char* data;
    struct Node* next;
} NodeL;

typedef struct List {
    NodeL* head;
} List;

List* initList();

void prepend(List** list, char* data);

void removeFirst(List** list);

void printList(List** list);

void clearList(List** list);

void removeByValue(List** list, char* data);

NodeL* searchByValue(List** list, char* data);

#endif
