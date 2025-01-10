// The Josephus problem involves finding the position of a person who survives when people are arranged in a circle and every 𝑘-th person is eliminated in a sequence until only one remains.

// To implement the Josephus problem using your circular linked list structure, we will use the following logic:

// Traverse the circular linked list, counting up to 𝑘.
// Remove the 𝑘-th person from the list by adjusting the next pointers.
// Continue this process until only one node remains.
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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
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

// Function to solve the Josephus problem
int josephus(int k)
{
    if (head == NULL)
    {
        return -1; // If the list is empty
    }

    struct Node *prev = NULL;
    struct Node *curr = head;

    // Continue until only one node is left in the circular linked list
    while (curr->next != curr)
    {
        // Count to k-1
        for (int count = 1; count < k; count++)
        {
            prev = curr;
            curr = curr->next;
        }

        // Remove the k-th node
        prev->next = curr->next;
        printf("Eliminated: %d\n", curr->data);
        free(curr);
        curr = prev->next;
    }

    head = curr; // The last remaining node
    return curr->data;
}

// Main function
int main()
{
    int n, value, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value);
    }

    printf("The circular linked list is: ");
    display();

    printf("Enter the value of k (step): ");
    scanf("%d", &k);

    int survivor = josephus(k);
    printf("The survivor is: %d\n", survivor);

    return 0;
}
