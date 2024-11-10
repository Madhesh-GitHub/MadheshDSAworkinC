#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

// Structure for each data item in hash table
struct DataItem {
    int data;
    int key;
};

// Global variables
struct DataItem* hashArray[SIZE];  // The hash table array
struct DataItem* dummyItem;        // For marking deleted cells
struct DataItem* item;             // For temporary operations

// Hash function to get index
int hashCode(int key) {
    return key % SIZE;
}

// Search function
struct DataItem* search(int key) {
    // Get the hash index
    int hashIndex = hashCode(key);
    
    // Keep moving until empty cell is found
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];
        
        // Go to next cell
        ++hashIndex;
        
        // Wrap around the table
        hashIndex %= SIZE;
    }
    
    return NULL;
}

// Insert function
void insert(int key, int data) {
    // Create a new item
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;
    
    // Get the hash index
    int hashIndex = hashCode(key);
    
    // Move in array until an empty or deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    
    hashArray[hashIndex] = item;
}

// Delete function
struct DataItem* delete(struct DataItem* item) {
    int key = item->key;
    
    // Get the hash index
    int hashIndex = hashCode(key);
    
    // Move in array until empty
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];
            // Mark the position as deleted
            hashArray[hashIndex] = dummyItem;
            return temp;
        }
        
        ++hashIndex;
        hashIndex %= SIZE;
    }
    
    return NULL;
}

// Display function
void display() {
    printf("\nHash Table Contents:\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashArray[i] != NULL) {
            if(hashArray[i]->key == -1) {
                printf(" ~~ ");  // Show deleted spots
            } else {
                printf("(%d,%d) ", hashArray[i]->key, hashArray[i]->data);
            }
        } else {
            printf(" -- ");  // Show empty spots
        }
    }
    printf("\n");
}

int main() {
    // Initialize hash array to NULL
    for(int i = 0; i < SIZE; i++) {
        hashArray[i] = NULL;
    }
    
    // Create dummy item for deleted spaces
    dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;
    
    // Insert some items
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    
    printf("\nAfter Insertions:");
    display();
    
    // Search for an item
    item = search(37);
    if(item != NULL) {
        printf("\nElement found: %d\n", item->data);
    } else {
        printf("\nElement not found\n");
    }
    
    // Delete an item
    delete(item);
    printf("\nAfter Deletion of key 37:");
    display();
    
    // Try to search deleted item
    item = search(37);
    if(item != NULL) {
        printf("\nElement found: %d\n", item->data);
    } else {
        printf("\nElement not found\n");
    }
    
    return 0;
}
