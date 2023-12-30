#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "onelist.h"

// Инициализация списка
List* initList() {
    List* list = (List*)malloc(sizeof(List)); // Выделение памяти под список
    list->head = NULL; // Установка головы списка в NULL
    return list; // Возвращение указателя на список
}

// Добавление элемента в начало списка
void prepend(List** list, char* data) {
    NodeL* node = (NodeL*)malloc(sizeof(NodeL)); // Выделение памяти под узел
    node->data = _strdup(data); // Копирование данных
    node->next = (*list)->head; // Установка указателя на следующий элемент
    (*list)->head = node; // Устанавливаем голову списка как текущий узел
}

// Удаление первого элемента списка
void removeFirst(List** list) {
    if (!(*list)->head) {
        return; // Если голова списка не существует, выходим из функции
    }
    NodeL* temp = (*list)->head; // Сохраняем указатель на голову списка
    (*list)->head = (*list)->head->next; // Устанавливаем голову списка на следующий элемент
    free(temp->data); // Освобождаем память от данных
    free(temp); // Освобождаем память от узла
}

// Вывод списка
void printList(List** list) {
    NodeL* temp = (*list)->head; // Начинаем с головы списка
    while (temp) {
        printf("%s ", temp->data); // Выводим данные
        temp = temp->next; // Переходим к следующему элементу
    }
    printf("\n"); // Переходим на новую строку после вывода всех элементов
}

// Очистка списка
void clearList(List** list) {
    while ((*list)->head) {
        removeFirst(list); // Удаляем первый элемент, пока голова списка существует
    }
}

// Удаление элемента списка по значению
void removeByValue(List** list, char* data) {
    NodeL* temp = (*list)->head; // Начинаем с головы списка
    NodeL* prev = NULL; // Инициализируем указатель на предыдущий элемент
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // Если данные совпадают
            if (prev) {
                prev->next = temp->next; // Устанавливаем следующий элемент для предыдущего элемента
            }
            else {
                (*list)->head = temp->next; // Иначе устанавливаем голову списка на следующий элемент
            }
            free(temp->data); // Освобождаем память от данных
            free(temp); // Освобождаем память от узла
            return; // Выходим из функции
        }
        prev = temp; // Сохраняем текущий узел как предыдущий
        temp = temp->next; // Переходим к следующему элементу
    }
}

// Поиск элемента списка по значению
NodeL* searchByValue(List** list, char* data) {
    NodeL* temp = (*list)->head; // Начинаем с головы списка
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // Если данные совпадают
            return temp; // Возвращаем указатель на узел
        }
        temp = temp->next; // Переходим к следующему элементу
    }
    return NULL; // Если элемент не найден, возвращаем NULL
}
