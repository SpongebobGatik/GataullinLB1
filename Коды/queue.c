#define _CRT_SECURE_NO_WARNINGS
#include "queue.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// ������� ������������� �������
Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;  // ��������� ��������� �� ������ ������� � NULL
    queue->rear = NULL;  // ��������� ��������� �� ����� ������� � NULL
    return queue;   // ������� ��������� �� �������
}

// ������� ���������� �������� � �������
void QPUSH(Queue* queue, char* element) {
    // ����� ����
    NodeQueue* newNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    newNode->element = _strdup(element);  // ����������� �������� � ����
    newNode->next = NULL;  // ��������� ��������� �� ��������� ���� � NULL
    if (queue->front == NULL) {  // ���� ������� �����
        queue->front = newNode;  // ��������� ��������� �� ������ ������� �� ����� ����
        queue->rear = newNode;  // ��������� ��������� �� ����� ������� �� ����� ����
    }
    else {  // ���� ������� �� �����
        queue->rear->next = newNode;  // ���������� ������ ���� � ����� �������
        queue->rear = newNode;  // ��������� ��������� �� ����� ������� �� ����� ����
    }
}

// ������� �������� �������� �� �������
char* QPOP(Queue* queue) {
    // �������� ������� �������
    if (queue->front == NULL) {
        printf("������� �����\n");
        return NULL;
    }
    NodeQueue* poppedNode = queue->front;  // ��������� �� ��������� ����
    char* element = poppedNode->element;  // ��������� �� ��������� �������
    queue->front = poppedNode->next;   // ����� ��������� �� ������ ������� �� ��������� ����
    if (queue->front == NULL) {  // ���� ������� ����� ������
        queue->rear = NULL;  // ��������� ��������� �� ����� ������� � NULL
    }
    free(poppedNode);  // ������������ ������ �� ���������� ����
    return element;  // ������� ��������� �� ��������� �������
}

// ������� ������� �������
void clearQueue(Queue* queue) {
    while (queue->front != NULL) {  // ���� ������� �� �����
        NodeQueue* temp = queue->front;  // ��������� ��������� �� ������ �������
        queue->front = queue->front->next;  // ����� ������ �������
        free(temp->element);  // ������������ ������ �� �������� ����
        free(temp);  // ������������ ������ �� ����
    }
    queue->rear = NULL;  // ��������� ��������� �� ����� ������� � NULL ����� �������
}

// ������� ������ ����������� �������
void printQueue(Queue* queue) {
    NodeQueue* current = queue->front;  // ��������� �� ������ �������
    printf("���������� �������: ");
    while (current != NULL) {  // ���� �� ��������� ����� �������
        printf("%s  ", current->element);  // ����� ��������
        current = current->next;  // ������� � ���������� ����
    }
    printf("\n");
}
