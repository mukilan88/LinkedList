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

// Function to rotate the linked list to the left by k positions
void rotateLeft(int k)
{
    if (head == NULL || k <= 0)
        return;

    struct Node *current = head;
    int count = 1;

    // Find the kth node
    while (count < k && current->next != NULL)
    {
        current = current->next;
        count++;
    }

    // If k is greater than or equal to the length of the list, do nothing
    if (current->next == NULL)
        return;

    struct Node *kthNode = current;

    // Move to the end of the list
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Update the links to rotate
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}

// Function to rotate the linked list to the right by k positions
void rotateRight(int k)
{
    if (head == NULL || k <= 0)
        return;

    // Find the length of the list
    struct Node *current = head;
    int length = 1;
    while (current->next != NULL)
    {
        current = current->next;
        length++;
    }

    // Connect the last node to the head to make it circular
    current->next = head;

    // Find the new head after length - k rotations
    k = k % length;
    int skip = length - k;
    struct Node *prev = NULL;
    current = head;
    for (int i = 0; i < skip; i++)
    {
        prev = current;
        current = current->next;
    }

    // Break the circular link to form the new list
    head = current;
    prev->next = NULL;
}

// Main function
int main()
{
    int n, value, k, choice;
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

    // Rotate the list
    printf("Enter 1 to rotate left or 2 to rotate right: ");
    scanf("%d", &choice);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    if (choice == 1)
    {
        rotateLeft(k);
        printf("Linked list after left rotation: ");
    }
    else if (choice == 2)
    {
        rotateRight(k);
        printf("Linked list after right rotation: ");
    }
    else
    {
        printf("Invalid choice!\n");
        return 1;
    }

    display();
    return 0;
}
