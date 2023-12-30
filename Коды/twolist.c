#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "twolist.h"

// ������������� ������
ListT* initListT() {
    ListT* list = (ListT*)malloc(sizeof(ListT)); // ��������� ������ ��� ������
    list->head = NULL; // ��������� ������ ������ � NULL
    list->tail = NULL; // ��������� ������ ������ � NULL
    return list; // ����������� ��������� �� ������
}

// ���������� �������� � ������ ������
void prependT(ListT** list, char* data) {
    NodeL2* node = (NodeL2*)malloc(sizeof(NodeL2)); // ��������� ������ ��� ����
    node->data = _strdup(data); // ����������� ������
    node->next = (*list)->head; // ��������� ��������� �� ��������� �������
    node->prev = NULL; // ��������� ��������� �� ���������� �������
    if ((*list)->head) {
        (*list)->head->prev = node; // ���� ������ ������ ����������, ������������� �� ���������� ������� ��� ������� ����
    }
    else {
        (*list)->tail = node; // ����� ������������� ����� ������ ��� ������� ����
    }
    (*list)->head = node; // ������������� ������ ������ ��� ������� ����
}

// ���������� �������� � ����� ������
void appendT(ListT** list, char* data) {
    NodeL2* node = (NodeL2*)malloc(sizeof(NodeL2)); // ��������� ������ ��� ����
    node->data = _strdup(data); // ����������� ������
    node->prev = (*list)->tail; // ��������� ��������� �� ���������� �������
    node->next = NULL; // ��������� ��������� �� ��������� �������
    if ((*list)->tail) {
        (*list)->tail->next = node; // ���� ����� ������ ����������, ������������� ��� ��������� ������� ��� ������� ����
    }
    else {
        (*list)->head = node; // ����� ������������� ������ ������ ��� ������� ����
    }
    (*list)->tail = node; // ������������� ����� ������ ��� ������� ����
}

// �������� ������� �������� ������
void removeFirstT(ListT** list) {
    if (!(*list)->head) {
        return; // ���� ������ ������ �� ����������, ������� �� �������
    }
    NodeL2* temp = (*list)->head; // ��������� ��������� �� ������ ������
    (*list)->head = (*list)->head->next; // ������������� ������ ������ �� ��������� �������
    if ((*list)->head) {
        (*list)->head->prev = NULL; // ���� ������ ������ ����������, ������������� �� ���������� ������� � NULL
    }
    else {
        (*list)->tail = NULL; // ����� ������������� ����� ������ � NULL
    }
    free(temp->data); // ����������� ������ �� ������
    free(temp); // ����������� ������ �� ����
}

// �������� ���������� �������� ������
void removeLastT(ListT** list) {
    if (!(*list)->tail) {
        return; // ���� ����� ������ �� ����������, ������� �� �������
    }
    NodeL2* temp = (*list)->tail; // ��������� ��������� �� ����� ������
    (*list)->tail = (*list)->tail->prev; // ������������� ����� ������ �� ���������� �������
    if ((*list)->tail) {
        (*list)->tail->next = NULL; // ���� ����� ������ ����������, ������������� ��� ��������� ������� � NULL
    }
    else {
        (*list)->head = NULL; // ����� ������������� ������ ������ � NULL
    }
    free(temp->data); // ����������� ������ �� ������
    free(temp); // ����������� ������ �� ����
}

// �������� �������� ������ �� ��������
void removeByValueT(ListT** list, char* data) {
    NodeL2* temp = (*list)->head; // �������� � ������ ������
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // ���� ������ ���������
            if (temp->prev) {
                temp->prev->next = temp->next; // ������������� ��������� ������� ��� ����������� ��������
            }
            else {
                (*list)->head = temp->next; // ����� ������������� ������ ������ �� ��������� �������
            }
            if (temp->next) {
                temp->next->prev = temp->prev; // ������������� ���������� ������� ��� ���������� ��������
            }
            else {
                (*list)->tail = temp->prev; // ����� ������������� ����� ������ �� ���������� �������
            }
            free(temp->data); // ����������� ������ �� ������
            free(temp); // ����������� ������ �� ����
            return; // ������� �� �������
        }
        temp = temp->next; // ��������� � ���������� ��������
    }
}

// ����� �������� ������ �� ��������
NodeL2* searchByValueT(ListT** list, char* data) {
    NodeL2* temp = (*list)->head; // �������� � ������ ������
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // ���� ������ ���������
            return temp; // ���������� ��������� �� ����
        }
        temp = temp->next; // ��������� � ���������� ��������
    }
    return NULL; // ���� ������� �� ������, ���������� NULL
}

// ����� ������
void printListT(ListT** list) {
    NodeL2* temp = (*list)->head; // �������� � ������ ������
    while (temp) {
        printf("%s ", temp->data); // ������� ������
        temp = temp->next; // ��������� � ���������� ��������
    }
    printf("\n"); // ��������� �� ����� ������ ����� ������ ���� ���������
}

// ������� ������
void clearListT(ListT** list) {
    while ((*list)->head) {
        removeFirstT(list); // ������� ������ �������, ���� ������ ������ ����������
    }
}
