#define _CRT_SECURE_NO_WARNINGS
#include "table.h" 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_SIZE 100000 

// ������� ��� ������������� ���-�������
HashTable* initHashTable() {
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	ht->nodes = (NodeHashTable**)malloc(MAX_SIZE * sizeof(NodeHashTable*));
	ht->count = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		ht->nodes[i] = NULL;
	}
	return ht;
}

// ������� ��� ���������� ����
int calculateHashT(const char* element) {
	int hash = 0;
	for (int i = 0; element[i] != '\0'; i++) {
		hash = 31 * hash + element[i];
	}
	return abs(hash) % MAX_SIZE;
}

// ������� ��� ���������� �������� � ���-�������
void HSET(HashTable* ht, char* key, char* value) {
	int hash = calculateHashT(key);
	// ������� ����� ���� ��� �������� ����� � ��������
	NodeHashTable* newNode = (NodeHashTable*)malloc(sizeof(NodeHashTable));
	newNode->key = _strdup(key);
	newNode->element = _strdup(value);
	newNode->next = NULL; // ������������� ��������� �� ��������� ���� ��� NULL
	newNode->prev = NULL; // ������������� ��������� �� ���������� ���� ��� NULL
	// ��������� �������� � �������� �� ��������� ������
	NodeHashTable* current = ht->nodes[hash]; // �������� ���� �� ���-�����
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) { // ���� ���� ��� ����������
			// ����������� ������ ������ ����
			free(newNode->key);
			free(newNode->element);
			free(newNode);
			printf("���� ��� ����������.\n");
			return;
		}
		if (current->next == NULL) { // ���� �������� ����� �������
			break;
		}
		current = current->next; // ��������� � ���������� ����
	}
	// ���������� ������ ����
	if (current == NULL) { // ���� ������� �����
		ht->nodes[hash] = newNode; // ������������� ����� ���� ��� ������ �������
	}
	else {
		current->next = newNode; // ��������� ����� ���� � ����� �������
		newNode->prev = current; // ������������� ���������� ���� ��� ������ ����
	}
	ht->count++;
}

// ������� ��� ��������� �������� �� ���-�������
char* HGET(HashTable* ht, const char* key) {
	int hash = calculateHashT(key);
	NodeHashTable* current = ht->nodes[hash]; // �������� ���� �� ���-�����
	while (current != NULL) { // ���������� ���� � �������
		if (strcmp(current->key, key) == 0) { // ���� ���� ���������
			return current->element;
		}
		current = current->next; // ��������� � ���������� ����
	}
	return NULL;
}

// ������� ��� �������� �������� �� ���-�������
void HDEL(HashTable* ht, const char* key) {
	int hash = calculateHashT(key);
	NodeHashTable* current = ht->nodes[hash]; // �������� ���� �� ���-�����
	NodeHashTable* nodeToRemove = NULL;
	while (current != NULL) { // ���������� ���� � �������
		if (strcmp(current->key, key) == 0) { // ���� ���� ���������
			nodeToRemove = current; // ������������� ���� ��� ��������
			break;
		}
		current = current->next; // ��������� � ���������� ����
	}

	if (nodeToRemove != NULL) {
		if (nodeToRemove->prev != NULL) { // ���� � ���� ���� ���������� ����
			nodeToRemove->prev->next = nodeToRemove->next; // ������� ���� �� �������
		}
		else {
			ht->nodes[hash] = nodeToRemove->next; // ������������� ��������� ���� ��� ������ �������
		}
		if (nodeToRemove->next != NULL) { // ���� � ���� ���� ��������� ����
			nodeToRemove->next->prev = nodeToRemove->prev; // ������������� ���������� ���� ��� ���������� ����
		}
		// ����������� ������ ���������� ����
		free(nodeToRemove->key);
		free(nodeToRemove->element);
		free(nodeToRemove);
		ht->count--;
	}
	else {
		printf("���� �� ������.\n");
	}
}

// ������� ��� ������������ ������ ���-�������
void freeHashTable(HashTable* ht) {
	for (int i = 0; i < MAX_SIZE; i++) {
		NodeHashTable* current = ht->nodes[i];
		while (current != NULL) {
			NodeHashTable* temp = current;
			current = current->next;
			free(temp->key);
			free(temp->element);
			free(temp);
		}
	}
	free(ht->nodes);
	free(ht);
}

// ������� ��� ������ ���-�������
void printHashTable(HashTable* ht) {
	printf("���-�������:\n");
	for (int i = 0; i < MAX_SIZE; i++) {
		NodeHashTable* current = ht->nodes[i];
		if (current != NULL) {
			printf("������ %d: ", i);
			while (current != NULL) {
				printf("(%s, %s) ", current->key, current->element);
				current = current->next;
			}
			printf("\n");
		}
	}
}