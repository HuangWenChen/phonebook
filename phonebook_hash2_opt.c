#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash_opt.h"

entry *findName(char lastName[], hashTable *ht)
{
    entry *e;
    unsigned int index =BKDRHash(lastName);

    for(e = ht->list[index]; e != NULL; e = e->pNext) {
        if (strcasecmp(lastName, e->lastName) == 0)
            return e;
    }
    return NULL;
}

void append(char lastName[], hashTable *ht)
{
    unsigned int index = BKDRHash(lastName);
    entry *e;
    e = (entry*)malloc(sizeof(entry));
    strcpy(e->lastName, lastName);
    e->pNext = ht->list[index];
    ht->list[index] = e;
}

hashTable *createHashTable(int tableSize)
{
    int i;
    hashTable *ht;
    ht = (hashTable*)malloc(sizeof(hashTable));
    ht->list = (entry **)malloc(sizeof(entry*)*tableSize);
    for (i = 0; i<tableSize; i++) {
        ht->list[i] = NULL;
    }
    return ht;
}

unsigned int BKDRHash(char *str)
{
    // djb2 hash function
    unsigned int hash = 0;
    while(*str != '\0'){
            hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

