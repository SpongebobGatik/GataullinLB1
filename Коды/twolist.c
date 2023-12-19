#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "twolist.h"

// Функция инициализации списка
NodeL2* initListT() {
    return NULL;
}

// Функция инициализации нового узла
NodeL2* createNodeT(char* data) {
    NodeL2* newNode = (NodeL2*)malloc(sizeof(NodeL2));
    newNode->data = _strdup(data); // Дублирование строки для хранения данных
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Функция добавления в начало списка
void prependT(NodeL2** head, const char* newData) {
    NodeL2* newNode = createNodeT(newData);
    printf("Вы добавили элемент в начало списка: %s\n", newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Функция добавления в конец списка
void appendT(NodeL2** head, const char* newData) {
    NodeL2* newNode = createNodeT(newData);
    printf("Вы добавили элемент в конец списка: %s\n", newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    NodeL2* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Функция удаления из начала списка
void removeFirstT(NodeL2** head) {
    if (*head == NULL) {
        return;
    }

    NodeL2* first = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(first);
    printf("Вы успешно удалили первый элемент.\n");
}

// Функция удаления из конца списка
void removeLastT(NodeL2** head) {
    if (*head == NULL) {
        return;
    }

    NodeL2* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    if (last->prev != NULL) {
        last->prev->next = NULL;
    }
    else {
        *head = NULL;
    }
    free(last);
    printf("Вы успешно удалили последний элемент.\n");
}

// Функция вывода списка
void printListT(NodeL2* head) {
    NodeL2* current = head;
    printf("Ваш двусвязный список: ");
    while (current != NULL) {
        printf("%s  ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Функция очистки списка
void clearListT(NodeL2** head) {
    NodeL2* current = *head;
    NodeL2* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
