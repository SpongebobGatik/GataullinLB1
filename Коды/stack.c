#define _CRT_SECURE_NO_WARNINGS
#include "stack.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Функция для инициализации стека
Stack* initStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Функция для добавления элемента в стек
void SPUSH(Stack* stack, char* element) {
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack)); // Выделение памяти под новый узел
    newNode->element = _strdup(element); // Копирование элемента в узел
    newNode->next = stack->top; // Установка следующего узла после нового узла
    stack->top = newNode; // Установка нового узла в качестве вершины стека
}

// Функция для удаления элемента из стека
char* SPOP(Stack* stack) {
    // Проверка пустоты стека
    if (stack->top == NULL) {
        printf("Стек пуст\n");
        return NULL;
    }
    NodeStack* poppedNode = stack->top; // Получение узла для удаления
    stack->top = poppedNode->next; // Установка следующего узла в качестве вершины стека
    char* element = poppedNode->element; // Получение элемента из узла
    free(poppedNode); // Освобождение памяти, занятой узлом
    return element; // Возврат элемента
}

// Функция для очистки стека
void SClear(Stack* stack) {
    while (stack->top != NULL) {
        NodeStack* temp = stack->top;
        stack->top = stack->top->next;
        free(temp->element); // Освобождение памяти, занятой элементом
        free(temp); // Освобождение памяти, занятой узлом
    }
}

// Функция для вывода содержимого стека
void SPrint(Stack* stack) {
    NodeStack* current = stack->top;
    printf("Содержимое стека: ");
    while (current != NULL) {
        printf("%s  ", current->element);
        current = current->next;
    }
    printf("\n");
}
