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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode; // If list is empty, make the new node the head
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL) // Traverse to the end of the list
        {
            temp = temp->next;
        }
        temp->next = newNode; // Attach the new node to the end
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

    while (temp != NULL) // Traverse and print each node
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to check if the linked list is a palindrome
int isPalindrome()
{
    if (head == NULL || head->next == NULL)
    {
        return 1; // A list with 0 or 1 element is always a palindrome
    }

    // Reverse the list
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next; // Save next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move prev to current node
        current = next;       // Move to next node
    }

    // Now 'prev' is the new head of the reversed list
    struct Node *reversedHead = prev;
    struct Node *original = head;
    struct Node *reversed = reversedHead;

    // Compare the original list with the reversed list
    while (original != NULL && reversed != NULL)
    {
        if (original->data != reversed->data)
        {
            return 0; // If they don't match, it's not a palindrome
        }
        original = original->next;
        reversed = reversed->next;
    }

    return 1; // If all values matched, it's a palindrome
}

// Main function
int main()
{
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Add nodes to the list
    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        append(value); // Add the value to the list
    }

    printf("The linked list is: ");
    display(); // Display the linked list

    // Check if the linked list is a palindrome
    if (isPalindrome())
    {
        printf("The linked list is a palindrome.\n");
    }
    else
    {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
