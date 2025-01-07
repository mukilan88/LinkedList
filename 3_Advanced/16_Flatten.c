#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;           // Store the value of the node
    struct Node *next;  // Pointer to the next node
    struct Node *prev;  // Pointer to the previous node
    struct Node *child; // Pointer to the child node (for multilevel list)
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to append a node at the end of the doubly linked list
struct Node *append(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        return newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

// Function to flatten a multilevel doubly linked list while maintaining order
struct Node *flatten(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *curr = head;
    struct Node *tail = head;

    // Find the tail of the main list
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    while (curr != NULL)
    {
        if (curr->child != NULL)
        {
            // Append the child list to the end of the current list
            tail->next = curr->child;
            curr->child->prev = tail;

            // Find the new tail after appending
            struct Node *childTail = curr->child;
            while (childTail->next != NULL)
            {
                childTail = childTail->next;
            }

            // Update the tail
            tail = childTail;
            curr->child = NULL; // Remove the child pointer
        }
        curr = curr->next;
    }

    return head;
}

// Function to display the doubly linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int n, m, value, childNodes;

    // Create the main doubly linked list
    printf("Enter the number of nodes in the main list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = append(head, value);
    }

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("Does node with value %d have a child list? (1 for Yes, 0 for No): ", temp->data);
        scanf("%d", &childNodes);
        if (childNodes)
        {
            printf("Enter the number of nodes in the child list: ");
            scanf("%d", &m);

            struct Node *childHead = NULL;
            for (int j = 0; j < m; j++)
            {
                printf("Enter value for child node %d: ", j + 1);
                scanf("%d", &value);
                childHead = append(childHead, value);
            }
            temp->child = childHead;
        }
        temp = temp->next;
    }

    // Display the multilevel list before flattening
    printf("Original list: \n");
    display(head);

    // Flatten the list
    head = flatten(head);

    // Display the flattened list
    printf("Flattened list: \n");
    display(head);

    return 0;
}
