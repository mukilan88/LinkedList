#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node
{
    int data;          // To store the value of the node
    struct Node *next; // Pointer to the next node
};

// Head pointer for the list
struct Node *head = NULL;

// Function to add a node at the end of the circular linked list
void append(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        // If the list is empty, new node becomes the head
        head = newNode;
        newNode->next = head; // Make it circular
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
void display(struct Node *start)
{
    if (start == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = start;
    printf("The circular linked list is: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("(back to head)\n");
}

// Function to split the circular linked list into two halves
void splitCircularLinkedList(struct Node *start, struct Node **head1, struct Node **head2)
{
    if (start == NULL || start->next == start)
    {
        // If the list is empty or has only one node
        *head1 = start;
        *head2 = NULL;
        return;
    }

    struct Node *slow = start;
    struct Node *fast = start;

    // Use slow and fast pointers to find the middle of the list
    while (fast->next != start && fast->next->next != start)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    *head1 = start;
    *head2 = slow->next;

    // Make the first half circular
    slow->next = *head1;

    // Make the second half circular
    struct Node *temp = *head2;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = *head2;

    // Display the first half
    printf("First half: ");
    display(*head1);

    // Display the second half
    printf("Second half: ");
    display(*head2);
}

// Main function
int main()
{
    int n, value;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the circular linked list
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        append(value);
    }

    // Display the circular linked list
    display(head);

    // Split the list into two halves
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    splitCircularLinkedList(head, &head1, &head2);

    return 0;
}
