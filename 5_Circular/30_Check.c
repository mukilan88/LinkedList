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

// Function to add a node at the end of a singly linked list (non-circular or circular)
void append(int value, int isCircular)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, initialize the head
    if (head == NULL)
    {
        head = newNode;
        if (isCircular)
        {
            newNode->next = head; // Make it circular
        }
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL && temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        if (isCircular)
        {
            newNode->next = head; // Make it circular
        }
    }
}

// Function to check if the linked list is circular
int isCircular(struct Node *head)
{
    if (head == NULL)
    {
        return 0; // An empty list is not circular
    }

    struct Node *temp = head->next;

    // Traverse the list
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    // If we find the head again, it's circular
    return (temp == head);
}

// Function to check if the linked list is not circular
int isNotCircular(struct Node *head)
{
    return !isCircular(head); // If not circular, return 1
}

// Main function
int main()
{
    int n, value, isCircularList;

    printf("Do you want to create a circular list? (1 for Yes, 0 for No): ");
    scanf("%d", &isCircularList);

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Loop to create and insert nodes
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value, isCircularList);
    }

    // Check if the list is circular or not
    if (isCircular(head))
    {
        printf("The list is circular.\n");
    }
    else if (isNotCircular(head))
    {
        printf("The list is not circular.\n");
    }

    return 0;
}
