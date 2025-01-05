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

// Function to detect and remove a loop without using an algorithm
void detectAndRemoveLoop()
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Traverse the linked list
    while (temp != NULL)
    {
        // If the node is already marked as visited (loop detected)
        if (temp->next == head)
        {
            printf("Loop detected in the linked list.\n");

            // Remove the loop by setting the previous node's next to NULL
            prev->next = NULL;

            printf("Loop removed from the linked list.\n");
            return;
        }

        // Move to the next node
        prev = temp;
        temp = temp->next;
    }
    printf("No loop detected in the linked list.\n");
}

// Main function
int main()
{
    int n, value;
    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // Loop to create and insert nodes
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
        // Create a loop by connecting the last node to the head
        temp->next = head; // Remove/comment this line for a non-looped list
    }

    // Detect and remove the loop
    detectAndRemoveLoop();

    // Display the linked list after removing the loop
    printf("The linked list is: ");
    display();

    return 0;
}
