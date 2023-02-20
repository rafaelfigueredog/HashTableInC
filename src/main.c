#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    HashTable *hashTable = createHashTable(10);

   // Test inserting and getting values
    insert(hashTable, "foo", 1);
    insert(hashTable, "bar", 2);

    printf("foo: %d\n", get(hashTable, "foo"));
    printf("bar: %d\n", get(hashTable, "bar"));
  
     // Test updating values
    insert(hashTable, "foo", 3);
    insert(hashTable, "baz", 4);
    
    printf("After update...\n");
    printf("foo: %d\n", get(hashTable, "foo"));
    printf("bar: %d\n", get(hashTable, "bar"));

    destroyHashTable(hashTable);

    return 0;
}