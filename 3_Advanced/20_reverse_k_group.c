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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
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
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse k nodes of the linked list
struct Node *reverseKGroup(struct Node *head, int k)
{
    if (head == NULL || k <= 1)
        return head;

    struct Node *prev = NULL, *curr = head, *next = NULL;
    int count = 0;

    // Count k nodes
    struct Node *temp = head;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }

    // If there are at least k nodes, reverse them
    if (count == k)
    {
        count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Reverse the remaining nodes in groups of k
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        // prev is the new head of the reversed group
        return prev;
    }

    // If less than k nodes remain, reverse them as well
    prev = NULL;
    curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
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

    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("Original linked list: ");
    display();

    head = reverseKGroup(head, k);

    printf("Linked list after reversing in k-groups: ");
    display();

    return 0;
}
