#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;          // Store the value of the node
    struct Node *next; // Pointer to the next node
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

// Function to display the linked list
void display()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    // Traverse and print each node
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to detect and find the length of a loop in the linked list
int detectAndCountLoop()
{
    struct Node *slow = head, *fast = head;

    // Step 1: Detect if there is a loop
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, a loop is detected
        if (slow == fast)
        {
            // Step 2: Count the number of nodes in the loop
            int loopLength = 1;
            struct Node *temp = slow;
            while (temp->next != slow)
            {
                loopLength++;
                temp = temp->next;
            }
            return loopLength;
        }
    }

    // No loop found
    return 0;
}

// Main function
int main()
{
    int n, value;
    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // Loop to create and insert node
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value); // Add the value to the list
    }

    // Create a loop for testing (optional)
    if (head != NULL && head->next != NULL)
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head->next; // Creating a loop
    }

    // Detect and count loop
    int loopLength = detectAndCountLoop();
    if (loopLength > 0)
    {
        printf("A loop is detected in the linked list. Length of the loop: %d\n", loopLength);
    }
    else
    {
        printf("No loop detected in the linked list.\n");
    }

    return 0;
}
