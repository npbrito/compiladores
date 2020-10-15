/* ------------------------------------------------
 * Author: Natália Paz Brito
 * Email: npbrito@inf.ufrgs.br
 * Date  : 2020-10-14
 * ------------------------------------------------ */

#ifndef HASH_H_
#define HASH_H_

// Hash table size 
#define HASH_SIZE 10

// Store the values of the hash table elements
typedef struct hash_element{
    char* name;
    int line;
    int nature;
    int type;
    int type_size;
} hash_element;

// A table that contains: a key and an element
typedef struct HashTable{
    int key;
    int occuped;
    hash_element * value;

} HashTable;

HashTable* hash_create();
void hash_insert(HashTable**, hash_element*);
int hash_search(HashTable*, char*);
void hash_print(HashTable*);
int calc_index(char*);
int calc_type_size(int);

#endif // HASH_H_