#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define MAX_STRING_LENGTH 256

// Определение структуры для массива строк
typedef struct {
    char** array;
    size_t size;
} StringArray;

// Функция инициализации массива строк
StringArray* initStringArray() {
    StringArray* sa = (StringArray*)malloc(sizeof(StringArray));
    sa->array = (char**)malloc(MAX_SIZE * sizeof(char*));
    for (size_t i = 0; i < MAX_SIZE; i++) {
        sa->array[i] = NULL;
    }
    sa->size = 0;
    return sa;
}

// Функция добавления строки в массив
void addString(StringArray* sa, int index, const char* value) {
    if (index < 0 || index > sa->size) {
        printf("Индекс вне диапазона.\n");
        return;
    }
    // Сдвигаем элементы, чтобы освободить место для новой строки
    for (size_t i = sa->size; i > index; i--) {
        sa->array[i] = sa->array[i - 1];
    }
    // Выделяем память и копируем строку
    sa->size++;
    sa->array[index] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    strncpy(sa->array[index], value, MAX_STRING_LENGTH);
    printf("Вы добавили элемент %s на позицию %d\n", value, index);
}

// Функция удаления строки по индексу
void removeString(StringArray* sa, int index) {
    if (index < 0 || index >= sa->size) {
        printf("Индекс вне диапазона.\n");
        return;
    }
    printf("Вы удалили элемент %s на позицию %d\n", sa->array[index], index);
    free(sa->array[index]);
    for (size_t i = index; i < sa->size - 1; i++) {
        sa->array[i] = sa->array[i + 1];
    }
    sa->size--;
}

// Функция вывода строки по индексу
void printString(StringArray* sa, int index) {
    if (index < 0 || index >= sa->size) {
        printf("Индекс вне диапазона.\n");
        return;
    }
    printf("Элемент на индексе %d: %s\n", index, sa->array[index]);
}

// Функция сравнения строк по индексам
void compareStrings(StringArray* sa, int index1, int index2) {
    if (index1 < 0 || index1 >= sa->size || index2 < 0 || index2 >= sa->size) {
        printf("Индекс вне диапазона.\n");
        return;
    }
    if (strcmp(sa->array[index1], sa->array[index2]) == 0) {
        printf("Элементы равны.\n");
    }
    else {
        printf("Элементы не равны.\n");
    }
}

// Функция добавления строки в конец массива
void appendString(StringArray* sa, const char* value) {
    if (sa->size >= MAX_SIZE) {
        printf("Массив полон.\n");
        return;
    }
    sa->array[sa->size] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    strncpy(sa->array[sa->size], value, MAX_STRING_LENGTH);
    printf("Вы добавили элемент %s в конец массива\n", value);
    sa->size++;
}

// Функция проверки наличия строки в массиве
int containsString(StringArray* sa, const char* value) {
    for (size_t i = 0; i < sa->size; i++) {
        if (strcmp(sa->array[i], value) == 0) {
            return 1;
        }
    }
    return 0;
}

// Функция замены строки по индексу
void replaceString(StringArray* sa, int index, const char* value) {
    if (index < 0 || index >= sa->size) {
        printf("Индекс вне диапазона.\n");
        return;
    }
    strncpy(sa->array[index], value, MAX_STRING_LENGTH);
    printf("Вы заменили элемент на позиции %d на %s\n", index, value);
}

// Функция вывода массива строк
void printStringArray(StringArray* sa) {
    printf("Ваш массив: ");
    for (size_t i = 0; i < sa->size; i++) {
        printf("%s  ", sa->array[i]);
    }
    printf("\n");
}

// Функция освобождения памяти массива строк
void freeStringArray(StringArray* sa) {
    for (size_t i = 0; i < sa->size; i++) {
        free(sa->array[i]);
    }
    free(sa->array);
    free(sa);
}