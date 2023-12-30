#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"

// ������� ��� ��������, �������� �� ������ ������ �������� �������
int isFullBinaryTree(NodeTr* root) {
    // ���� ������ ������, ��� �������� ������ �������� �������
    if (root == NULL) return 1;

    // ���� � ���� ��� �����, ��� ������ �������� ������
    if (root->left == NULL && root->right == NULL) return 1;

    // ���� � ���� ���� ��� �������, ���������, �������� �� ���������� ������� ��������� ���������
    if (root->left != NULL && root->right != NULL) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    // � ��������� ������ ��� �� ������ �������� ������
    return 0;
}

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

// ������� ���� � ������
NodeTr* insertNode(NodeTr* root, const char* value1, const char* value2, char* path) {
    if (path[0] == 'C') {
        root = createNodeTr(value1);
        return root;
    }
    if (root == NULL) {
        root = createNodeTr("null");
    }
    if (path[0] != '\0' && path[1] == 'L' && root->right == NULL) root->right = createNodeTr("null");
    if (path[0] != '\0' && path[1] == 'R' && root->left == NULL) root->left = createNodeTr("null");
    if (path[1] == '\0') {
        if (path[0] == 'L') {
            if (root->left == NULL) {
                root->left = createNodeTr(value1);
            }
            else {
                free(root->left->value);
                root->left->value = _strdup(value1);
            }
            if (root->right == NULL) {
                root->right = createNodeTr(value2);
            }
            else {
                free(root->right->value);
                root->right->value = _strdup(value2);
            }
        }
        else if (path[0] == 'R') {
            if (root->right == NULL) {
                root->right = createNodeTr(value2);
            }
            else {
                free(root->right->value);
                root->right->value = _strdup(value2);
            }
            if (root->left == NULL) {
                root->left = createNodeTr(value1);
            }
            else {
                free(root->left->value);
                root->left->value = _strdup(value1);
            }
        }
    }
    if (path[0] == 'L') {
        root->left = insertNode(root->left, value1, value2, path + 1);
    }
    else if (path[0] == 'R') {
        root->right = insertNode(root->right, value1, value2, path + 1);
    }
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

// �������� ����� ���� �� ������
NodeTr* deleteNode(NodeTr* root, const char* value) {
    if (root == NULL) return NULL;
    if (strcmp(root->value, value) == 0) {
        freeTree(root->left);
        freeTree(root->right);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    root->left = deleteNode(root->left, value);
    root->right = deleteNode(root->right, value);
    return root;
}

