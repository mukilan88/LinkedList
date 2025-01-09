#include <stdio.h>
#include <stdlib.h>

// Define the node structure for a doubly linked list
struct Node
{
    int data;          // Store the value of the node
    struct Node *next; // Pointer to the next node
    struct Node *prev; // Pointer to the previous node
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
    newNode->prev = NULL;

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
        newNode->prev = temp;
    }
}

// Function to reverse the doubly linked list
void reverse()
{
    struct Node *temp = NULL;
    struct Node *current = head;

    // Swap next and prev for all nodes
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node in the original order
    }

    // Update the head to the new first node
    if (temp != NULL)
    {
        head = temp->prev;
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
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    // Display the created linked list
    printf("The original linked list is: ");
    display();

    // Reverse the linked list
    reverse();

    // Display the reversed linked list
    printf("The reversed linked list is: ");
    display();

    return 0;
}
