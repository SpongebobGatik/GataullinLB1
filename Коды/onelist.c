#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "onelist.h"

// ������� ������������� ������
NodeL1* initList() {
    return NULL;
}

// ������� ������������� ������ ����
NodeL1* createNode(char* data) {
    NodeL1* newNode = (NodeL1*)malloc(sizeof(NodeL1));
    newNode->data = _strdup(data); // ������������ ������ ��� �������� ������
    newNode->next = NULL;
    return newNode;
}

// ������� ������ ������
void printList(NodeL1* head) {
    NodeL1* current = head;
    printf("��� ����������� ������: ");
    while (current != NULL) {
        printf("%s  ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ������� ���������� � ����� ������
void append(NodeL1** head, const char* newData) {
    NodeL1* newNode = (NodeL1*)malloc(sizeof(NodeL1));
    // ��������� ������ ��� ����� ������
    newNode->data = malloc(strlen(newData) + 1);
    // ����������� ������ � ����� ������
    strcpy(newNode->data, newData);
    newNode->next = NULL;
    printf("�� �������� ������� %s\n", newData);
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

// ������� �������� �� ����� ������
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
    printf("�� ������� ������� �������.\n");
}

// ������� �������� ������� ��������
bool contains(NodeL1* head, const char* searchData) {
    NodeL1* current = head;
    while (current != NULL) {
        // ��������� ����� � ������ �����������
        if (strcmp(current->data, searchData) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// ������� ������� ������
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