#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"

// �������� ������ ���� ������
NodeTr* createNodeTr(const char* value) {
    NodeTr* newNode = (NodeTr*)malloc(sizeof(NodeTr));
    newNode->value = _strdup(value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ��������������� ������� ��� ������ ������
void printTreeHelper(NodeTr* root, int space) {
    int i;
    if (root == NULL) return;
    space += 10; // ����������� ���������� ����� ��������
    printTreeHelper(root->right, space); // ������� �������� ������ ���������
    printf("\n");
    for (i = 10; i < space; i++) {
        printf(" "); // �������� ������� ����� �����
    }
    printf("%s\n", root->value); // �������� ������� ����
    printTreeHelper(root->left, space); // ����� �������� ����� ���������
}

void printTree(NodeTr* root) {
    printTreeHelper(root, 0); // ��������� ����� � �������� 0
}

// ������� ������
void clearTree(NodeTr** rootPtr) {
    if (*rootPtr == NULL) return;
    clearTree(&((*rootPtr)->left));
    clearTree(&((*rootPtr)->right));
    free((*rootPtr)->value);
    (*rootPtr)->value = NULL;
    free(*rootPtr);
    *rootPtr = NULL;
}

// ������������
void makeFullBinaryTree(NodeTr* root, int depth) {
    if (root == NULL || depth == 0) return;

    if (root->left == NULL) {
        root->left = createNodeTr("null");
    }
    else {
        makeFullBinaryTree(root->left, depth - 1);
    }
    if (root->right == NULL) {
        root->right = createNodeTr("null");
    }
    else {
        makeFullBinaryTree(root->right, depth - 1);
    }
}


// ������� ���� � ������
NodeTr* insertNode(NodeTr* root, const char* value, const char* path) {
    if (path[0] == 'C' || path[0] == '\0') {
        if (root == NULL) return createNodeTr(value);
        // ���� ���� ��� ����������, �������� ��� ��������
        free(root->value);
        root->value = _strdup(value);
        return root;
    }
    if (root == NULL) {
        // ���� ��������� ����� ���� � ������� ���� �� ����������, ������� ���
        root = createNodeTr("");
    }
    // ���������� ��������� �� ������ � ������������ � �����
    if (path[0] == 'L') {
        root->left = insertNode(root->left, value, path + 1);
    }
    else if (path[0] == 'R') {
        root->right = insertNode(root->right, value, path + 1);
    }
    makeFullBinaryTree(root, strlen(path));
    return root;
}

// ����� ���� � ������
NodeTr* findNode(NodeTr* root, const char* value) {
    if (root == NULL) return NULL;
    if (strcmp(root->value, value) == 0) return root;
    NodeTr* foundNode = findNode(root->left, value);
    if (foundNode == NULL) foundNode = findNode(root->right, value);
    return foundNode;
}

// ������������ ������ ���� ������
void freeTree(NodeTr* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node->value);
    free(node);
}


