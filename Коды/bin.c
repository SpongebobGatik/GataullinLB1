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
    if (isFullBinaryTree(root)) {
        printTreeHelper(root, 0); // Начальный вызов с отступом 0
    }
    else {
        printf("Дерево не является полным бинарным деревом.\n");
    }
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
NodeTr* insertNode(NodeTr* root, const char* value, const char* path) {
    if (path[0] == 'C' || path[0] == '\0') {
        if (root == NULL) return createNodeTr(value);
        // Если узел уже существует, заменяем его значение
        free(root->value);
        root->value = _strdup(value);
        return root;
    }

    if (root == NULL) {
        // Если достигнут конец пути и текущий узел не существует, создаем его
        root = createNodeTr("");
    }

    // Рекурсивно двигаемся по дереву в соответствии с путем
    if (path[0] == 'L') {
        root->left = insertNode(root->left, value, path + 1);
    }
    else if (path[0] == 'R') {
        root->right = insertNode(root->right, value, path + 1);
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

// Удаление узла из дерева
NodeTr* deleteNode(NodeTr* root, const char* value) {
    if (root == NULL) return NULL;
    if (strcmp(root->value, value) == 0) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->value);
        free(root);
        return NULL;
    }
    root->left = deleteNode(root->left, value);
    root->right = deleteNode(root->right, value);
    return root;
}
