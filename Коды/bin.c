#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"

// Функция для проверки, является ли дерево полным бинарным деревом
int isFullBinaryTree(NodeTr* root) {
    // Если дерево пустое, оно является полным бинарным деревом
    if (root == NULL) return 1;

    // Если у узла нет детей, это полное бинарное дерево
    if (root->left == NULL && root->right == NULL) return 1;

    // Если у узла есть оба ребенка, проверяем, являются ли поддеревья полными бинарными деревьями
    if (root->left != NULL && root->right != NULL) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    // В противном случае это не полное бинарное дерево
    return 0;
}

// Создание нового узла дерева
NodeTr* createNodeTr(const char* value) {
    NodeTr* newNode = (NodeTr*)malloc(sizeof(NodeTr));
    newNode->value = _strdup(value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Вспомогательная функция для печати дерева
void printTreeHelper(NodeTr* root, int space) {
    int i;
    if (root == NULL) return;
    space += 10; // Увеличиваем расстояние между уровнями
    printTreeHelper(root->right, space); // Сначала печатаем правое поддерево
    printf("\n");
    for (i = 10; i < space; i++) {
        printf(" "); // Печатаем пробелы перед узлом
    }
    printf("%s\n", root->value); // Печатаем текущий узел
    printTreeHelper(root->left, space); // Затем печатаем левое поддерево
}

void printTree(NodeTr* root) {
    printTreeHelper(root, 0); // Начальный вызов с отступом 0
}

// Очистка дерева
void clearTree(NodeTr** rootPtr) {
    if (*rootPtr == NULL) return;
    clearTree(&((*rootPtr)->left));
    clearTree(&((*rootPtr)->right));
    free((*rootPtr)->value);
    (*rootPtr)->value = NULL;
    free(*rootPtr);
    *rootPtr = NULL;
}

// Вставка узла в дерево
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

// Поиск узла в дереве
NodeTr* findNode(NodeTr* root, const char* value) {
    if (root == NULL) return NULL;
    if (strcmp(root->value, value) == 0) return root;
    NodeTr* foundNode = findNode(root->left, value);
    if (foundNode == NULL) foundNode = findNode(root->right, value);
    return foundNode;
}

// Освобождение памяти узла дерева
void freeTree(NodeTr* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node->value);
    free(node);
}

// Удаление детей узла из дерева
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

