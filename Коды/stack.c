#define _CRT_SECURE_NO_WARNINGS
#include "stack.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// ������� ��� ������������� �����
Stack* initStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// ������� ��� ���������� �������� � ����
void SPUSH(Stack* stack, char* element) {
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack)); // ��������� ������ ��� ����� ����
    newNode->element = _strdup(element); // ����������� �������� � ����
    newNode->next = stack->top; // ��������� ���������� ���� ����� ������ ����
    stack->top = newNode; // ��������� ������ ���� � �������� ������� �����
}

// ������� ��� �������� �������� �� �����
char* SPOP(Stack* stack) {
    // �������� ������� �����
    if (stack->top == NULL) {
        printf("���� ����\n");
        return NULL;
    }
    NodeStack* poppedNode = stack->top; // ��������� ���� ��� ��������
    stack->top = poppedNode->next; // ��������� ���������� ���� � �������� ������� �����
    char* element = poppedNode->element; // ��������� �������� �� ����
    free(poppedNode); // ������������ ������, ������� �����
    return element; // ������� ��������
}

// ������� ��� ������� �����
void SClear(Stack* stack) {
    while (stack->top != NULL) {
        NodeStack* temp = stack->top;
        stack->top = stack->top->next;
        free(temp->element); // ������������ ������, ������� ���������
        free(temp); // ������������ ������, ������� �����
    }
}

// ������� ��� ������ ����������� �����
void SPrint(Stack* stack) {
    NodeStack* current = stack->top;
    printf("���������� �����: ");
    while (current != NULL) {
        printf("%s  ", current->element);
        current = current->next;
    }
    printf("\n");
}
