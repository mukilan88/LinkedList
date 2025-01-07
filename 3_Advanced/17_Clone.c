#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;            // Store the value of the node
    struct Node *next;   // Pointer to the next node
    struct Node *random; // Pointer to a random node
};

// Initialize the head pointer
struct Node *head = NULL;

// Function to add a node at the end of the list
void append(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->random = NULL; // Initialize random pointer to NULL

    // If the list is empty, the new node becomes the head
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        // Traverse to the last node
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Link the new node to the last node
        temp->next = newNode;
    }
}

// Function to set random pointers based on user input
void setRandomPointers()
{
    int i = 1;
    struct Node *temp = head;

    printf("Set random pointers for each node (enter position or -1 for NULL):\n");
    while (temp != NULL)
    {
        printf("Random pointer for node %d (data = %d): ", i++, temp->data);
        int pos;
        scanf("%d", &pos);

        if (pos == -1)
        {
            temp->random = NULL;
        }
        else
        {
            struct Node *randomNode = head;
            for (int j = 1; j < pos && randomNode != NULL; j++)
            {
                randomNode = randomNode->next;
            }
            temp->random = randomNode;
        }
        temp = temp->next;
    }
}

// Function to clone the linked list with random pointers
struct Node *cloneLinkedList()
{
    if (head == NULL)
        return NULL;

    // Step 1: Insert cloned nodes in between original nodes
    struct Node *temp = head;
    while (temp != NULL)
    {
        struct Node *cloneNode = (struct Node *)malloc(sizeof(struct Node));
        cloneNode->data = temp->data;
        cloneNode->next = temp->next;
        cloneNode->random = NULL;
        temp->next = cloneNode;
        temp = cloneNode->next;
    }

    // Step 2: Set random pointers for cloned nodes
    temp = head;
    while (temp != NULL)
    {
        if (temp->random != NULL)
        {
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }

    // Step 3: Separate the original and cloned lists
    struct Node *original = head;
    struct Node *cloneHead = head->next;
    struct Node *clone = cloneHead;

    while (original != NULL)
    {
        original->next = original->next->next;
        if (clone->next != NULL)
        {
            clone->next = clone->next->next;
        }
        original = original->next;
        clone = clone->next;
    }

    return cloneHead;
}

// Function to display the linked list with random pointers
void displayWithRandom(struct Node *start)
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("Data: %d, Random: %d\n", temp->data, temp->random ? temp->random->data : -1);
        temp = temp->next;
    }
}

// Main function
int main()
{
    int n, value;

    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value);
    }

    // Set random pointers
    setRandomPointers();

    // Display the original list
    printf("Original linked list with random pointers:\n");
    displayWithRandom(head);

    // Clone the linked list
    struct Node *clonedList = cloneLinkedList();

    // Display the cloned list
    printf("Cloned linked list with random pointers:\n");
    displayWithRandom(clonedList);

    return 0;
}
