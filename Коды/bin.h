#ifndef BIN_H
#define BIN_H

typedef struct NodeTr {
    char* value;
    struct NodeTr* left;
    struct NodeTr* right;
} NodeTr;

NodeTr* insertNode(NodeTr* root, const char* value1, const char* value2, const char* path);

NodeTr* findNode(NodeTr* root, const char* value);

NodeTr* deleteNode(NodeTr* root, const char* value);

int isFullBinaryTree(NodeTr* root);

void printTree(NodeTr* root);

void clearTree(NodeTr** rootPtr);

#endif
