#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "twolist.h"

// Инициализация списка
ListT* initListT() {
    ListT* list = (ListT*)malloc(sizeof(ListT)); // Выделение памяти под список
    list->head = NULL; // Установка головы списка в NULL
    list->tail = NULL; // Установка хвоста списка в NULL
    return list; // Возвращение указателя на список
}

// Добавление элемента в начало списка
void prependT(ListT** list, char* data) {
    NodeL2* node = (NodeL2*)malloc(sizeof(NodeL2)); // Выделение памяти под узел
    node->data = _strdup(data); // Копирование данных
    node->next = (*list)->head; // Установка указателя на следующий элемент
    node->prev = NULL; // Установка указателя на предыдущий элемент
    if ((*list)->head) {
        (*list)->head->prev = node; // Если голова списка существует, устанавливаем ее предыдущий элемент как текущий узел
    }
    else {
        (*list)->tail = node; // Иначе устанавливаем хвост списка как текущий узел
    }
    (*list)->head = node; // Устанавливаем голову списка как текущий узел
}

// Добавление элемента в конец списка
void appendT(ListT** list, char* data) {
    NodeL2* node = (NodeL2*)malloc(sizeof(NodeL2)); // Выделение памяти под узел
    node->data = _strdup(data); // Копирование данных
    node->prev = (*list)->tail; // Установка указателя на предыдущий элемент
    node->next = NULL; // Установка указателя на следующий элемент
    if ((*list)->tail) {
        (*list)->tail->next = node; // Если хвост списка существует, устанавливаем его следующий элемент как текущий узел
    }
    else {
        (*list)->head = node; // Иначе устанавливаем голову списка как текущий узел
    }
    (*list)->tail = node; // Устанавливаем хвост списка как текущий узел
}

// Удаление первого элемента списка
void removeFirstT(ListT** list) {
    if (!(*list)->head) {
        return; // Если голова списка не существует, выходим из функции
    }
    NodeL2* temp = (*list)->head; // Сохраняем указатель на голову списка
    (*list)->head = (*list)->head->next; // Устанавливаем голову списка на следующий элемент
    if ((*list)->head) {
        (*list)->head->prev = NULL; // Если голова списка существует, устанавливаем ее предыдущий элемент в NULL
    }
    else {
        (*list)->tail = NULL; // Иначе устанавливаем хвост списка в NULL
    }
    free(temp->data); // Освобождаем память от данных
    free(temp); // Освобождаем память от узла
}

// Удаление последнего элемента списка
void removeLastT(ListT** list) {
    if (!(*list)->tail) {
        return; // Если хвост списка не существует, выходим из функции
    }
    NodeL2* temp = (*list)->tail; // Сохраняем указатель на хвост списка
    (*list)->tail = (*list)->tail->prev; // Устанавливаем хвост списка на предыдущий элемент
    if ((*list)->tail) {
        (*list)->tail->next = NULL; // Если хвост списка существует, устанавливаем его следующий элемент в NULL
    }
    else {
        (*list)->head = NULL; // Иначе устанавливаем голову списка в NULL
    }
    free(temp->data); // Освобождаем память от данных
    free(temp); // Освобождаем память от узла
}

// Удаление элемента списка по значению
void removeByValueT(ListT** list, char* data) {
    NodeL2* temp = (*list)->head; // Начинаем с головы списка
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // Если данные совпадают
            if (temp->prev) {
                temp->prev->next = temp->next; // Устанавливаем следующий элемент для предыдущего элемента
            }
            else {
                (*list)->head = temp->next; // Иначе устанавливаем голову списка на следующий элемент
            }
            if (temp->next) {
                temp->next->prev = temp->prev; // Устанавливаем предыдущий элемент для следующего элемента
            }
            else {
                (*list)->tail = temp->prev; // Иначе устанавливаем хвост списка на предыдущий элемент
            }
            free(temp->data); // Освобождаем память от данных
            free(temp); // Освобождаем память от узла
            return; // Выходим из функции
        }
        temp = temp->next; // Переходим к следующему элементу
    }
}

// Поиск элемента списка по значению
NodeL2* searchByValueT(ListT** list, char* data) {
    NodeL2* temp = (*list)->head; // Начинаем с головы списка
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // Если данные совпадают
            return temp; // Возвращаем указатель на узел
        }
        temp = temp->next; // Переходим к следующему элементу
    }
    return NULL; // Если элемент не найден, возвращаем NULL
}

// Вывод списка
void printListT(ListT** list) {
    NodeL2* temp = (*list)->head; // Начинаем с головы списка
    while (temp) {
        printf("%s ", temp->data); // Выводим данные
        temp = temp->next; // Переходим к следующему элементу
    }
    printf("\n"); // Переходим на новую строку после вывода всех элементов
}

// Очистка списка
void clearListT(ListT** list) {
    while ((*list)->head) {
        removeFirstT(list); // Удаляем первый элемент, пока голова списка существует
    }
}
