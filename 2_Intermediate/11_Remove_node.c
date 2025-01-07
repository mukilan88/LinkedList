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

// Function to remove duplicate nodes from an unsorted linked list
void removeDuplicates()
{
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *temp;

    while (current != NULL && current->next != NULL)
    {
        prev = current;
        temp = current->next;
        while (temp != NULL)
        {
            if (current->data == temp->data)
            {
                // Remove duplicate node
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
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
    // Display the created linked list
    printf("The linked list is: ");
    display();

    // Remove duplicates from the linked list
    removeDuplicates();

    // Display the linked list after removing duplicates
    printf("The linked list after removing duplicates is: ");
    display();

    return 0;
}
