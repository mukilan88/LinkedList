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

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode; // New node becomes the new head
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // If the list is empty, the new node is the head
    }
    struct Node* temp = head;
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
    return head;
}

// Function to insert a node in the middle (after a specific position)
struct Node* insertAtMiddle(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) { // If position is 1, insert at the beginning
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) { // Traverse to the node before the position
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of range.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode;       // Link the previous node to the new node
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 5);

    // Insert at the end
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    // Insert in the middle (after 2nd position)
    head = insertAtMiddle(head, 15, 3);

    // Display the list
    printf("Linked List: ");
    displayList(head);

    return 0;
}
