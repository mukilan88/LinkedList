#include <stdio.h>
#include <stdlib.h>

// Define the node structure
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

// Function to find pairs with a given sum
void findPairsWithSum(int target)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *start = head;
    struct Node *end = head;

    // Move `end` to the last node
    while (end->next != NULL)
    {
        end = end->next;
    }

    int found = 0;

    // Use two pointers to find pairs with the given sum
    while (start != NULL && end != NULL && start != end && end->next != start)
    {
        int sum = start->data + end->data;

        if (sum == target)
        {
            printf("Pair found: (%d, %d)\n", start->data, end->data);
            found = 1;
            start = start->next;
            end = end->prev;
        }
        else if (sum < target)
        {
            start = start->next;
        }
        else
        {
            end = end->prev;
        }
    }

    if (!found)
    {
        printf("No pairs found with the sum %d.\n", target);
    }
}

// Main function
int main()
{
    int n, value, target;

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

    // Display the created linked list
    printf("The linked list is: ");
    display();

    // Get the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Find pairs with the given sum
    findPairsWithSum(target);

    return 0;
}
