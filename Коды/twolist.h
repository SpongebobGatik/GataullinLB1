#ifndef TWOLIST_H
#define TWOLIST_H

typedef struct Node {
    char* data;
    struct Node* prev;
    struct Node* next;
} NodeL2;

NodeL2* initListT();

void prependT(NodeL2** head, const char* newData);

void appendT(NodeL2** head, const char* newData);

void removeFirstT(NodeL2** head);

void removeLastT(NodeL2** head);

void printListT(NodeL2* head);

void clearListT(NodeL2** head);

#endif
