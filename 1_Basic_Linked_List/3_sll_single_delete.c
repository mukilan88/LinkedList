#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node becomes the head
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode;
    return head;
}

// Function to delete the first node
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;    // Store the current head node
    head = head->next;          // Move the head pointer to the next node
    printf("Deleted node value: %d\n", temp->data);
    free(temp);                 // Free memory of the old head
    return head;                // Return the updated head
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    // Get the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Loop to create and insert nodes
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    // Display the created linked list
    printf("Created Linked List: ");
    displayList(head);

    // Delete the first node
    head = deleteFirstNode(head);

    // Display the linked list after deletion
    printf("Linked List after deleting the first node: ");
    displayList(head);

    return 0;
}
