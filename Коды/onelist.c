#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "onelist.h"

// ������������� ������
List* initList() {
    List* list = (List*)malloc(sizeof(List)); // ��������� ������ ��� ������
    list->head = NULL; // ��������� ������ ������ � NULL
    return list; // ����������� ��������� �� ������
}

// ���������� �������� � ������ ������
void prepend(List** list, char* data) {
    NodeL* node = (NodeL*)malloc(sizeof(NodeL)); // ��������� ������ ��� ����
    node->data = _strdup(data); // ����������� ������
    node->next = (*list)->head; // ��������� ��������� �� ��������� �������
    (*list)->head = node; // ������������� ������ ������ ��� ������� ����
}

// �������� ������� �������� ������
void removeFirst(List** list) {
    if (!(*list)->head) {
        return; // ���� ������ ������ �� ����������, ������� �� �������
    }
    NodeL* temp = (*list)->head; // ��������� ��������� �� ������ ������
    (*list)->head = (*list)->head->next; // ������������� ������ ������ �� ��������� �������
    free(temp->data); // ����������� ������ �� ������
    free(temp); // ����������� ������ �� ����
}

// ����� ������
void printList(List** list) {
    NodeL* temp = (*list)->head; // �������� � ������ ������
    while (temp) {
        printf("%s ", temp->data); // ������� ������
        temp = temp->next; // ��������� � ���������� ��������
    }
    printf("\n"); // ��������� �� ����� ������ ����� ������ ���� ���������
}

// ������� ������
void clearList(List** list) {
    while ((*list)->head) {
        removeFirst(list); // ������� ������ �������, ���� ������ ������ ����������
    }
}

// �������� �������� ������ �� ��������
void removeByValue(List** list, char* data) {
    NodeL* temp = (*list)->head; // �������� � ������ ������
    NodeL* prev = NULL; // �������������� ��������� �� ���������� �������
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // ���� ������ ���������
            if (prev) {
                prev->next = temp->next; // ������������� ��������� ������� ��� ����������� ��������
            }
            else {
                (*list)->head = temp->next; // ����� ������������� ������ ������ �� ��������� �������
            }
            free(temp->data); // ����������� ������ �� ������
            free(temp); // ����������� ������ �� ����
            return; // ������� �� �������
        }
        prev = temp; // ��������� ������� ���� ��� ����������
        temp = temp->next; // ��������� � ���������� ��������
    }
}

// ����� �������� ������ �� ��������
NodeL* searchByValue(List** list, char* data) {
    NodeL* temp = (*list)->head; // �������� � ������ ������
    while (temp) {
        if (strcmp(temp->data, data) == 0) { // ���� ������ ���������
            return temp; // ���������� ��������� �� ����
        }
        temp = temp->next; // ��������� � ���������� ��������
    }
    return NULL; // ���� ������� �� ������, ���������� NULL
}
