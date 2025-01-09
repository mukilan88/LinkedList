#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a doubly linked list node
struct Node
{
    int key, value;           // Store key-value pairs
    struct Node *prev, *next; // Pointers to previous and next nodes
};

// Define the structure of the LRU cache
struct LRUCache
{
    int capacity;             // Maximum capacity of the cache
    int size;                 // Current size of the cache
    struct Node *head, *tail; // Pointers to head and tail of the doubly linked list
    struct Node **hashMap;    // Hash map for quick access (array of pointers)
};

#define HASH_SIZE 1000

// Function to create a new doubly linked list node
struct Node *createNode(int key, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to initialize the LRU cache
struct LRUCache *initCache(int capacity)
{
    struct LRUCache *cache = (struct LRUCache *)malloc(sizeof(struct LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = cache->tail = NULL;
    cache->hashMap = (struct Node **)calloc(HASH_SIZE, sizeof(struct Node *));
    return cache;
}

// Hash function to map keys to indices
int hashKey(int key)
{
    return key % HASH_SIZE;
}

// Function to remove a node from the doubly linked list
void removeNode(struct LRUCache *cache, struct Node *node)
{
    if (node->prev)
    {
        node->prev->next = node->next;
    }
    else
    {
        cache->head = node->next; // Update head if node is the first
    }
    if (node->next)
    {
        node->next->prev = node->prev;
    }
    else
    {
        cache->tail = node->prev; // Update tail if node is the last
    }
}

// Function to add a node to the front of the doubly linked list
void addNodeToFront(struct LRUCache *cache, struct Node *node)
{
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head)
    {
        cache->head->prev = node;
    }
    cache->head = node;
    if (!cache->tail)
    {
        cache->tail = node; // If the list was empty, update tail
    }
}

// Function to get a value from the cache
int get(struct LRUCache *cache, int key)
{
    int index = hashKey(key);
    struct Node *node = cache->hashMap[index];
    while (node)
    {
        if (node->key == key)
        {
            // Move the accessed node to the front
            removeNode(cache, node);
            addNodeToFront(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found
}

// Function to put a key-value pair into the cache
void put(struct LRUCache *cache, int key, int value)
{
    int index = hashKey(key);
    struct Node *node = cache->hashMap[index];

    // Check if the key is already in the cache
    while (node)
    {
        if (node->key == key)
        {
            node->value = value; // Update value
            removeNode(cache, node);
            addNodeToFront(cache, node);
            return;
        }
        node = node->next;
    }

    // Key is not in the cache, add a new node
    struct Node *newNode = createNode(key, value);
    if (cache->size == cache->capacity)
    {
        // Cache is full, remove the least recently used node
        int tailKey = cache->tail->key;
        removeNode(cache, cache->tail);
        int tailIndex = hashKey(tailKey);
        cache->hashMap[tailIndex] = NULL; // Remove from hash map
        free(cache->tail);
        cache->size--;
    }
    // Add the new node to the front of the list
    addNodeToFront(cache, newNode);
    cache->hashMap[index] = newNode;
    cache->size++;
}

// Function to display the contents of the cache
void displayCache(struct LRUCache *cache)
{
    struct Node *temp = cache->head;
    printf("Cache contents: ");
    while (temp)
    {
        printf("(%d, %d) -> ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the LRU cache
int main()
{
    int capacity;
    printf("Enter the capacity of the LRU cache: ");
    scanf("%d", &capacity);

    struct LRUCache *cache = initCache(capacity);

    put(cache, 1, 10);
    put(cache, 2, 20);
    put(cache, 3, 30);
    displayCache(cache);

    printf("Accessing key 2: %d\n", get(cache, 2));
    displayCache(cache);

    put(cache, 4, 40);
    displayCache(cache);

    printf("Accessing key 1: %d\n", get(cache, 1));
    displayCache(cache);

    put(cache, 5, 50);
    displayCache(cache);

    return 0;
}
