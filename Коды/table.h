#ifndef TABLE_H
#define TABLE_H

typedef struct NodeHashTable {
    char* key;
    char* element;
    struct NodeHashTable* next;
    struct NodeHashTable* prev;
} NodeHashTable;

typedef struct HashTable {
    NodeHashTable** nodes;
    int count;
} HashTable;

HashTable* initHashTable();

void printHashTable(HashTable* ht);

void freeHashTable(HashTable* ht);

void HSET(HashTable* hashtable, char* key, char* value);

void HDEL(HashTable* hashtable, char* key);

char* HGET(HashTable* hashtable, char* key);

#endif