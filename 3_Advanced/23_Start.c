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

// Function to create a loop for testing
void createLoop(int pos)
{
    if (pos == 0)
        return;

    struct Node *temp = head;
    struct Node *loopNode = NULL;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
            loopNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = loopNode; // Create the loop
}

// Function to detect and find the starting node of a loop
struct Node *findLoopStart()
{
    struct Node *slow = head, *fast = head;

    // Detect loop using Floyd's Cycle Detection
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // Loop detected
        {
            // Find the starting node of the loop
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Starting node of the loop
        }
    }
    return NULL; // No loop
}

// Function to display the linked list (only for non-looped lists)
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

// Main function
int main()
{
    int n, value, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value);
    }

    printf("Enter the position to create a loop (0 for no loop): ");
    scanf("%d", &pos);

    createLoop(pos);

    struct Node *loopStart = findLoopStart();

    if (loopStart != NULL)
    {
        printf("Loop detected. The starting node of the loop is: %d\n", loopStart->data);
    }
    else
    {
        printf("No loop detected. The linked list is: ");
        display();
    }

    return 0;
}
