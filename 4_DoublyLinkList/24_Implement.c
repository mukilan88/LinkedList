#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;          // Store the value of the node
    struct Node *prev; // Pointer to the previous node
    struct Node *next; // Pointer to the next node
};

// Initialize the head pointer
struct Node *head = NULL;

// Function to insert a node at the end of the list
void append(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
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
        newNode->prev = temp;
    }
}

// Function to delete a node with a specific value
void deleteNode(int value)
{
    struct Node *temp = head;

    // Traverse to find the node to delete
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // If the node to be deleted is the head
    if (temp == head)
    {
        head = temp->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        // Update the links of the previous and next nodes
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }

    // Free the memory of the node
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

// Function to display the linked list in forward direction
void displayForward()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    // Traverse and print each node
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Display forward\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            append(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 3:
            displayForward();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
