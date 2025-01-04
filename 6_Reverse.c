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

// Function to reverse the values in the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;   // Store the next node
        current->next = prev;   // Reverse the current node's pointer
        prev = current;         // Move prev to current node
        current = next;         // Move to the next node
    }

    return prev; // New head of the reversed list
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

    // Reverse the linked list
    head = reverseList(head);

    // Display the reversed linked list
    printf("Reversed Linked List: ");
    displayList(head);

    return 0;
}
