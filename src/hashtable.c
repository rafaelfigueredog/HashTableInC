#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define HASH_MULTIPLIER 65599

unsigned int hash(char *key, int size)
{
    unsigned int h;
    unsigned char *p;
    h = 0;
    for (p = (unsigned char *)key; *p != '\0'; p++) {
        h = HASH_MULTIPLIER * h + *p;
    }
    return h % size;
}

HashTable *createHashTable(int size)
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->nodes = (HashNode **)calloc(size, sizeof(HashNode *));
    return hashTable;
}

void destroyHashTable(HashTable *hashTable)
{
    int i;
    HashNode *node, *temp;
    for (i = 0; i < hashTable->size; i++) {
        node = hashTable->nodes[i];
        while (node != NULL) {
            temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable->nodes);
    free(hashTable);
}

void insert(HashTable *hashTable, char *key, int value)
{
    unsigned int index = hash(key, hashTable->size);
    HashNode *node = hashTable->nodes[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    node = (HashNode *)malloc(sizeof(HashNode));
    node->key = (char *)malloc(strlen(key) + 1);
    strcpy(node->key, key);
    node->value = value;
    node->next = hashTable->nodes[index];
    hashTable->nodes[index] = node;
}

int get(HashTable *hashTable, char *key)
{
    unsigned int index = hash(key, hashTable->size);
    HashNode *node = hashTable->nodes[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}
