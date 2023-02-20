# Hash Table
This is a simple implementation of a hash table in C. It provides functions to create a hash table, insert key-value pairs, and retrieve values by key.

## Usage
To use this hash table implementation, include the hashtable.h header file in your code and link against the hashtable.c implementation file. Here's an example usage:

~~~C
#include <stdio.h>
#include "hashtable.h"

int main()
{
    HashTable *hash_table = createHashTable(10);

    insert(hash_table, "foo", 42);
    insert(hash_table, "bar", 123);

    int foo_value = get(hash_table, "foo");
    printf("The value of foo is %d\n", foo_value);

    int bar_value = get(hash_table, "bar");
    printf("The value of bar is %d\n", bar_value);

    destroyHashTable(hash_table);

    return 0;
}
~~~

## API
The following functions are provided by this implementation:

`HashTable *createHashTable(int size)`
Create a new hash table with the given size.

`size`: The number of slots in the hash table.
Returns a pointer to the new hash table.

`void destroyHashTable(HashTable *hashTable)`
Destroy the given hash table and free all associated memory.
- `hashTable`: A pointer to the hash table to destroy.

`void insert(HashTable *hashTable, char *key, int value)` Insert a key-value pair into the hash table.

- `hashTable`: A pointer to the hash table to insert into.
- `key`: The key to insert.
- `value`: The value to associate with the key.

`int get(HashTable *hashTable, char *key)`
Returns the value associated with the given key in the hash table or 0 if the key is not found in the hash table.

  - `hashTable`: A pointer to the hash table to retrieve from.
  - `key`: The key to retrieve the value for.

## License
This implementation is provided under the MIT license.
