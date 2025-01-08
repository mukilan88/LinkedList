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

// Function to rearrange the linked list into zigzag order
void rearrangeZigzag()
{
    if (head == NULL || head->next == NULL)
        return;

    struct Node *current = head;
    int flag = 1; // Flag to alternate between < and >

    while (current->next != NULL)
    {
        if (flag)
        {
            // If the current node's data is greater than the next node's data, swap them
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
        else
        {
            // If the current node's data is less than the next node's data, swap them
            if (current->data < current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
        }
        // Alternate the flag
        flag = !flag;
        current = current->next;
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
    printf("Original linked list: ");
    display();

    // Rearrange the linked list in zigzag order
    rearrangeZigzag();

    // Display the rearranged linked list
    printf("Zigzag linked list: ");
    display();

    return 0;
}
