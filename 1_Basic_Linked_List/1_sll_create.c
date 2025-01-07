#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;

    // Get the number of nodes from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // If no nodes are required, exit
    if (n <= 0) {
        printf("No nodes to create.\n");
        return 0;
    }

    // Create the head node
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;

    // Loop to create and link nodes
    for (int i = 0; i < n; i++) {
        // Allocate memory for a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Get the data for the new node from the user
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;  // Assign data
        newNode->next = NULL;   // Initialize next to NULL

        // If it's the first node, set it as the head
        if (head == NULL) {
            head = newNode;
        } else {
            // Otherwise, link it to the previous node
            temp->next = newNode;
        }

        // Update temp to the current node
        temp = newNode;
    }

    // Display the list
    printf("Linked List: ");
    temp = head;  // Start from the head
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
