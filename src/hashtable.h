#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    int size;
    HashNode **nodes;
} HashTable;

unsigned int hash(char *key, int size);

HashTable *createHashTable(int size);

void destroyHashTable(HashTable *hashTable);

void insert(HashTable *hashTable, char *key, int value);

int get(HashTable *hashTable, char *key);

#endif /* HASHTABLE_H */