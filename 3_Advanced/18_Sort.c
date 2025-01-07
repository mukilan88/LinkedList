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
void display(struct Node *head)
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

// Function to split the list into two halves
void splitList(struct Node *source, struct Node **front, struct Node **back)
{
    struct Node *slow = source;
    struct Node *fast = source->next;

    // Use fast and slow pointers to find the middle
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

// Function to merge two sorted lists
struct Node *mergeSortedLists(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;

    // Base cases
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    // Pick either a or b and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

// Function to perform merge sort on the linked list
void mergeSort(struct Node **headRef)
{
    struct Node *head = *headRef;
    struct Node *a;
    struct Node *b;

    // Base case: if the list is empty or has one element
    if (head == NULL || head->next == NULL)
        return;

    // Split the list into two halves
    splitList(head, &a, &b);

    // Recursively sort the two halves
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted halves
    *headRef = mergeSortedLists(a, b);
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
    display(head);

    // Sort the linked list using merge sort
    mergeSort(&head);

    // Display the sorted linked list
    printf("The sorted linked list is: ");
    display(head);

    return 0;
}
