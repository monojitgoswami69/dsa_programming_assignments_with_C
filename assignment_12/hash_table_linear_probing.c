/*
ASSIGNMENT 12:
Problem statement: Write a c program to perform the following operations (use division method for hash function)
(a) Insert an item x into a hash table (Resolve the collision using open Addressing with linear Probing).
(b) Search an element from hash table
*/

#include<stdio.h>
#include<stdlib.h>

#define EMPTY -1
#define DELETED -2

struct HashTable{
    int *table;
    int size;
    int count;
};

struct HashTable* createTable(int size){
    struct HashTable* ht = malloc(sizeof(struct HashTable));
    ht->size = size;
    ht->count = 0;
    ht->table = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) ht->table[i] = EMPTY;
    return ht;
}

int hash(int key, int size){
    return key % size;
}

int insert(struct HashTable* ht, int key){
    if (ht->count == ht->size){
        printf("Hash table full\n");
        return 0;
    }
    
    int index = hash(key, ht->size);
    int orig = index;
    int probes = 0;
    
    printf("Inserting %d: hash=%d\n", key, index);
    
    while (ht->table[index] != EMPTY && ht->table[index] != DELETED){
        if (ht->table[index] == key){
            printf("Key %d already exists at %d\n", key, index);
            return 0;
        }
        probes++;
        printf("  Collision at %d, probing...\n", index);
        index = (index + 1) % ht->size;
        if (index == orig){
            printf("Hash table full\n");
            return 0;
        }
    }
    
    ht->table[index] = key;
    ht->count++;
    printf("  Inserted at %d (Probes: %d)\n", index, probes);
    return 1;
}

int search(struct HashTable* ht, int key){
    int index = hash(key, ht->size);
    int orig = index;
    int probes = 0;
    
    printf("Searching %d: hash=%d\n", key, index);
    
    while (ht->table[index] != EMPTY){
        probes++;
        if (ht->table[index] == key){
            printf("  Found at %d (Probes: %d)\n", index, probes);
            return index;
        }
        printf("  Probing %d...\n", index);
        index = (index + 1) % ht->size;
        if (index == orig) break;
    }
    
    printf("  Not found (Probes: %d)\n", probes);
    return -1;
}

void display(struct HashTable* ht){
    printf("\nIndex\tValue\n");
    for (int i = 0; i < ht->size; i++){
        printf("%d\t", i);
        if (ht->table[i] == EMPTY) printf("EMPTY\n");
        else if (ht->table[i] == DELETED) printf("DELETED\n");
        else printf("%d\n", ht->table[i]);
    }
    printf("\nElements: %d/%d\n", ht->count, ht->size);
    printf("Load factor: %.2f\n", (float)ht->count / ht->size);
}

int deleteKey(struct HashTable* ht, int key){
    int index = search(ht, key);
    if (index == -1) return 0;
    ht->table[index] = DELETED;
    ht->count--;
    printf("Deleted %d from %d\n", key, index);
    return 1;
}

void freeTable(struct HashTable* ht){
    free(ht->table);
    free(ht);
}

int main(){
    int size, choice, key;
    printf("Enter hash table size: ");
    scanf("%d", &size);
    
    struct HashTable* ht = createTable(size);
    printf("Hash table created (size=%d)\n", size);
    printf("Hash function: h(k) = k %% %d\n", size);
    
    while (1){
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(ht, key);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(ht, key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(ht, key);
                break;
            case 4:
                display(ht);
                break;
            case 5:
                freeTable(ht);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
