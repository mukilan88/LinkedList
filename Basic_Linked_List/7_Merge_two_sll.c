#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node
{
    int data;          // Store the value of the node
    struct Node *next; // Pointer to the next node
};

// Function to append a node to the end of the list
struct Node *append(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
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
    }
    return head;
}

// Function to merge two sorted linked lists
struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
    // If either list is empty, return the other list
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    // Pointer for the merged list
    struct Node *mergedHead = NULL;

    // Initialize the merged list head
    if (list1->data <= list2->data)
    {
        mergedHead = list1;
        list1 = list1->next;
    }
    else
    {
        mergedHead = list2;
        list2 = list2->next;
    }

    struct Node *mergedTail = mergedHead;

    // Traverse both lists and merge them
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            mergedTail->next = list1;
            list1 = list1->next;
        }
        else
        {
            mergedTail->next = list2;
            list2 = list2->next;
        }
        mergedTail = mergedTail->next;
    }

    // Append any remaining nodes
    if (list1 != NULL)
    {
        mergedTail->next = list1;
    }
    if (list2 != NULL)
    {
        mergedTail->next = list2;
    }

    return mergedHead;
}

// Function to display the linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function
int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    int n1, n2, value;

    // Get the number of nodes for the first list
    printf("Enter the number of nodes in the first list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter data for node %d of the first list: ", i + 1);
        scanf("%d", &value);
        list1 = append(list1, value);
    }

    // Get the number of nodes for the second list
    printf("Enter the number of nodes in the second list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter data for node %d of the second list: ", i + 1);
        scanf("%d", &value);
        list2 = append(list2, value);
    }
    // Display the list1
    printf("list1: ");
    display(list1);
    // Display the list12
    printf("list2: ");
    display(list2);
    // Merge the lists
    struct Node *mergedList = mergeSortedLists(list1, list2);

    // Display the merged list
    printf("Merged sorted list: ");
    display(mergedList);

    return 0;
}