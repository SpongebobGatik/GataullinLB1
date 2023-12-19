#define _CRT_SECURE_NO_WARNINGS
#include "queue.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Функция инициализации очереди
Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;  // Установка указателя на начало очереди в NULL
    queue->rear = NULL;  // Установка указателя на конец очереди в NULL
    return queue;   // Возврат указателя на очередь
}

// Функция добавления элемента в очередь
void QPUSH(Queue* queue, char* element) {
    // Новый узел
    NodeQueue* newNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    newNode->element = _strdup(element);  // Копирование элемента в узел
    newNode->next = NULL;  // Установка указателя на следующий узел в NULL
    if (queue->front == NULL) {  // Если очередь пуста
        queue->front = newNode;  // Установка указателя на начало очереди на новый узел
        queue->rear = newNode;  // Установка указателя на конец очереди на новый узел
    }
    else {  // Если очередь не пуста
        queue->rear->next = newNode;  // Добавление нового узла в конец очереди
        queue->rear = newNode;  // Установка указателя на конец очереди на новый узел
    }
}

// Функция удаления элемента из очереди
char* QPOP(Queue* queue) {
    // Проверка пустоты очереди
    if (queue->front == NULL) {
        printf("Очередь пуста\n");
        return NULL;
    }
    NodeQueue* poppedNode = queue->front;  // Указатель на удаляемый узел
    char* element = poppedNode->element;  // Указатель на удаляемый элемент
    queue->front = poppedNode->next;   // Сдвиг указателя на начало очереди на следующий узел
    if (queue->front == NULL) {  // Если очередь стала пустой
        queue->rear = NULL;  // Установка указателя на конец очереди в NULL
    }
    free(poppedNode);  // Освобождение памяти от удаляемого узла
    return element;  // Возврат указателя на удаляемый элемент
}

// Функция очистки очереди
void clearQueue(Queue* queue) {
    while (queue->front != NULL) {  // Пока очередь не пуста
        NodeQueue* temp = queue->front;  // Временный указатель на начало очереди
        queue->front = queue->front->next;  // Сдвиг начала очереди
        free(temp->element);  // Освобождение памяти от элемента узла
        free(temp);  // Освобождение памяти от узла
    }
    queue->rear = NULL;  // Установка указателя на конец очереди в NULL после очистки
}

// Функция вывода содержимого очереди
void printQueue(Queue* queue) {
    NodeQueue* current = queue->front;  // Указатель на начало очереди
    printf("Содержимое очереди: ");
    while (current != NULL) {  // Пока не достигнут конец очереди
        printf("%s  ", current->element);  // Вывод элемента
        current = current->next;  // Переход к следующему узлу
    }
    printf("\n");
}
