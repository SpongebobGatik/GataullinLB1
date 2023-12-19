#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "twolist.h"

// ������� ������������� ������
NodeL2* initListT() {
    return NULL;
}

// ������� ������������� ������ ����
NodeL2* createNodeT(char* data) {
    NodeL2* newNode = (NodeL2*)malloc(sizeof(NodeL2));
    newNode->data = _strdup(data); // ������������ ������ ��� �������� ������
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ������� ���������� � ������ ������
void prependT(NodeL2** head, const char* newData) {
    NodeL2* newNode = createNodeT(newData);
    printf("�� �������� ������� � ������ ������: %s\n", newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// ������� ���������� � ����� ������
void appendT(NodeL2** head, const char* newData) {
    NodeL2* newNode = createNodeT(newData);
    printf("�� �������� ������� � ����� ������: %s\n", newData);
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

// ������� �������� �� ������ ������
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
    printf("�� ������� ������� ������ �������.\n");
}

// ������� �������� �� ����� ������
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
    printf("�� ������� ������� ��������� �������.\n");
}

// ������� ������ ������
void printListT(NodeL2* head) {
    NodeL2* current = head;
    printf("��� ���������� ������: ");
    while (current != NULL) {
        printf("%s  ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ������� ������� ������
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
