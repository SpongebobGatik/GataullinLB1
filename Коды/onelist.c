#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "onelist.h"

// Функция инициализации списка
NodeL1* initList() {
    return NULL;
}

// Функция инициализации нового узла
NodeL1* createNode(char* data) {
    NodeL1* newNode = (NodeL1*)malloc(sizeof(NodeL1));
    newNode->data = _strdup(data); // Дублирование строки для хранения данных
    newNode->next = NULL;
    return newNode;
}

// Функция вывода списка
void printList(NodeL1* head) {
    NodeL1* current = head;
    printf("Ваш односвязный список: ");
    while (current != NULL) {
        printf("%s  ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Функция добавления в конец списка
void append(NodeL1** head, const char* newData) {
    NodeL1* newNode = (NodeL1*)malloc(sizeof(NodeL1));
    // Выделение памяти для новой строки
    newNode->data = malloc(strlen(newData) + 1);
    // Копирование данных в новую строку
    strcpy(newNode->data, newData);
    newNode->next = NULL;
    printf("Вы добавили элемент %s\n", newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    NodeL1* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Функция удаления из конца списка
void removeLast(NodeL1** head) {
    if (*head == NULL) {
        return;
    }

    NodeL1* last = *head;
    NodeL1* prev = NULL;

    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }

    if (prev == NULL) {
        free(*head);
        *head = NULL;
    }
    else {
        free(last);
        prev->next = NULL;
    }
    printf("Вы успешно удалили элемент.\n");
}

// Функция проверки наличия элемента
bool contains(NodeL1* head, const char* searchData) {
    NodeL1* current = head;
    while (current != NULL) {
        // Сравнение строк с учётом содержимого
        if (strcmp(current->data, searchData) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Функция очистки списка
void clearList(NodeL1** head) {
    NodeL1* current = *head;
    NodeL1* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}