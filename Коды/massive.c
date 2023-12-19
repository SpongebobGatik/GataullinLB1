#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define MAX_STRING_LENGTH 256

// ����������� ��������� ��� ������� �����
typedef struct {
    char** array;
    size_t size;
} StringArray;

// ������� ������������� ������� �����
StringArray* initStringArray() {
    StringArray* sa = (StringArray*)malloc(sizeof(StringArray));
    sa->array = (char**)malloc(MAX_SIZE * sizeof(char*));
    for (size_t i = 0; i < MAX_SIZE; i++) {
        sa->array[i] = NULL;
    }
    sa->size = 0;
    return sa;
}

// ������� ���������� ������ � ������
void addString(StringArray* sa, int index, const char* value) {
    if (index < 0 || index > sa->size) {
        printf("������ ��� ���������.\n");
        return;
    }
    // �������� ��������, ����� ���������� ����� ��� ����� ������
    for (size_t i = sa->size; i > index; i--) {
        sa->array[i] = sa->array[i - 1];
    }
    // �������� ������ � �������� ������
    sa->size++;
    sa->array[index] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    strncpy(sa->array[index], value, MAX_STRING_LENGTH);
    printf("�� �������� ������� %s �� ������� %d\n", value, index);
}

// ������� �������� ������ �� �������
void removeString(StringArray* sa, int index) {
    if (index < 0 || index >= sa->size) {
        printf("������ ��� ���������.\n");
        return;
    }
    printf("�� ������� ������� %s �� ������� %d\n", sa->array[index], index);
    free(sa->array[index]);
    for (size_t i = index; i < sa->size - 1; i++) {
        sa->array[i] = sa->array[i + 1];
    }
    sa->size--;
}

// ������� ������ ������ �� �������
void printString(StringArray* sa, int index) {
    if (index < 0 || index >= sa->size) {
        printf("������ ��� ���������.\n");
        return;
    }
    printf("������� �� ������� %d: %s\n", index, sa->array[index]);
}

// ������� ��������� ����� �� ��������
void compareStrings(StringArray* sa, int index1, int index2) {
    if (index1 < 0 || index1 >= sa->size || index2 < 0 || index2 >= sa->size) {
        printf("������ ��� ���������.\n");
        return;
    }
    if (strcmp(sa->array[index1], sa->array[index2]) == 0) {
        printf("�������� �����.\n");
    }
    else {
        printf("�������� �� �����.\n");
    }
}

// ������� ������ ������� �����
void printStringArray(StringArray* sa) {
    printf("��� ������: ");
    for (size_t i = 0; i < sa->size; i++) {
        printf("%s  ", sa->array[i]);
    }
    printf("\n");
}

// ������� ������������ ������ ������� �����
void freeStringArray(StringArray* sa) {
    for (size_t i = 0; i < sa->size; i++) {
        free(sa->array[i]);
    }
    free(sa->array);
    free(sa);
}