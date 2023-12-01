#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure for a key-value pair
struct KeyValuePair {
    char *key;
    int value;
    struct KeyValuePair *next;
};

// Structure for a hash table
struct HashTable {
    struct KeyValuePair *table[TABLE_SIZE];
};

// Hash function: a simple hash using the length of the key
unsigned int hash(const char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

// Initialize a hash table
struct HashTable* initializeHashTable() {
    struct HashTable *hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Insert a key-value pair into the hash table with chaining
void insert(struct HashTable *hashTable, const char *key, int value) {
    unsigned int index = hash(key);

    // Create a new key-value pair
    struct KeyValuePair *newPair = (struct KeyValuePair*)malloc(sizeof(struct KeyValuePair));
    newPair->key = strdup(key);
    newPair->value = value;
    newPair->next = NULL;

    // If the slot is empty, insert the new pair
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newPair;
    } else {
        // Handle collisions by adding to the linked list at the slot
        struct KeyValuePair *current = hashTable->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPair;
    }
}

// Search for a key and return its value
int search(struct HashTable *hashTable, const char *key) {
    unsigned int index = hash(key);

    // Search in the linked list at the slot
    struct KeyValuePair *current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

// Display the contents of the hash table
void display(struct HashTable *hashTable) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct KeyValuePair *current = hashTable->table[i];
        while (current != NULL) {
            printf("[%d] %s: %d\n", i, current->key, current->value);
            current = current->next;
        }
    }
}

// Cleanup the hash table
void cleanup(struct HashTable *hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct KeyValuePair *current = hashTable->table[i];
        while (current != NULL) {
            struct KeyValuePair *next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
    }
    free(hashTable);
}

int main() {
    struct HashTable *hashTable = initializeHashTable();
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert key-value pair\n");
        printf("2. Search for a key\n");
        printf("3. Display hash table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char key[100];
            int value;
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(hashTable, key, value);
            printf("Key-value pair inserted successfully.\n");
        } else if (choice == 2) {
            char key[100];
            printf("Enter key to search: ");
            scanf("%s", key);
            int result = search(hashTable, key);
            if (result != -1) {
                printf("Value for key '%s' is %d\n", key, result);
            } else {
                printf("Key not found.\n");
            }
        } else if (choice == 3) {
            display(hashTable);
        } else if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    cleanup(hashTable);

    return 0;
}
