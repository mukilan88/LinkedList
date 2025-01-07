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

// Function to delete the last node
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == NULL) { // If there's only one node
        printf("Deleted node value: %d\n", head->data);
        free(head);
        return NULL; // The list is now empty
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) { // Traverse to the second last node
        temp = temp->next;
    }
    printf("Deleted node value: %d\n", temp->next->data);
    free(temp->next); // Free the memory of the last node
    temp->next = NULL; // Set the second last node's next to NULL
    return head;
}

// Function to delete a node at a specific position
struct Node* deleteNodeAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }
    if (position == 1) { // If the position is the first node
        return deleteFirstNode(head);
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next; // Traverse to the node before the position
    }
    if (temp->next == NULL) { // If position is out of range
        printf("Position is out of range.\n");
        return head;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // Unlink the node to be deleted
    printf("Deleted node value: %d\n", nodeToDelete->data);
    free(nodeToDelete); // Free memory of the node to delete
    return head;
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
    int n, value, position;

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
    printf("Linked List after deleting the first node: ");
    displayList(head);

    // Delete the last node
    head = deleteLastNode(head);
    printf("Linked List after deleting the last node: ");
    displayList(head);

    // Delete a node at a specific position
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);
    head = deleteNodeAtPosition(head, position);
    printf("Linked List after deleting the node at position %d: ", position);
    displayList(head);

    return 0;
}
