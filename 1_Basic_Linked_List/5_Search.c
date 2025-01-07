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

// Function to search for a value in the linked list
void searchValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("The list is empty. Nothing to search.\n");
        return;
    }

    struct Node* temp = head;
    int position = 1; // Position starts at 1
    int found = 0;    // Flag to check if value is found

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("Value %d not found in the list.\n", value);
    }
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
    int n, value, search;

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

    // Search for a value in the list
    printf("Enter a value to search in the linked list: ");
    scanf("%d", &search);
    searchValue(head, search);

    return 0;
}
