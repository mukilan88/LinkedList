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

// Function to add a node at the end of the circular linked list
void append(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, the new node becomes the head and points to itself
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        // Traverse to the last node
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        // Link the new node to the last node and make it circular
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to display the circular linked list
void display()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function
int main()
{
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    // Loop to create and insert nodes
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value);
    }
    // Display the created linked list
    printf("The circular linked list is: ");
    display();

    return 0;
}
