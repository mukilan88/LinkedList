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

    if (head == NULL) // If the list is empty
    {
        head = newNode;
        newNode->next = head; // Point to itself to make it circular
    }
    else
    {
        struct Node *temp = head;
        // Traverse to the last node
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Link the new node to the last node
        newNode->next = head; // Make it circular
    }
}

// Function to display the circular linked list
void display()
{
    if (head == NULL) // Check if the list is empty
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we circle back to the head
    printf("(head)\n");
}

// Function to delete a node by value
void deleteNode(int value)
{
    if (head == NULL) // Check if the list is empty
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head, *prev = NULL;

    // If the head node itself holds the value to be deleted
    if (head->data == value)
    {
        // Handle single node case
        if (head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }

        // Find the last node to update its next pointer
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return;
    }

    // Search for the node to be deleted
    do
    {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    // If the node was not found
    if (temp == head)
    {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// Main function
int main()
{
    int n, value, delValue;

    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Loop to create and insert nodes
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value);
    }

    // Display the created circular linked list
    printf("The circular linked list is: ");
    display();

    // Delete a node
    printf("Enter the value to delete: ");
    scanf("%d", &delValue);
    deleteNode(delValue);

    // Display the updated list
    printf("The circular linked list after deletion is: ");
    display();

    return 0;
}
