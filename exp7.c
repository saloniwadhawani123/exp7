
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // Head pointer for the list

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {  // If the list is empty
        head = newNode;
        newNode->next = head;  // Points to itself to maintain circularity
    } else {
        struct Node* temp = head;
        while (temp->next != head) {  // Traverse to the last node
            temp = temp->next;
        }
        newNode->next = head;  // New node points to current head
        temp->next = newNode;  // Last node points to the new node
        head = newNode;  // Update head to the new node
    }
    printf("%d inserted at the beginning.\n", value);
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {  // If the list is empty
        head = newNode;
        newNode->next = head;  // Points to itself to maintain circularity
    } else {
        struct Node* temp = head;
        while (temp->next != head) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Last node points to the new node
        newNode->next = head;  // New node points to the head
    }
    printf("%d inserted at the end.\n", value);
}

// Function to delete a node by value
void deleteNode(int value) {
    if (head == NULL) {  // If the list is empty
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // Case 1: Deleting the head node
    if (head->data == value) {
        if (head->next == head) {  // Only one node in the list
            free(head);
            head = NULL;
        } else {
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;  // Last node points to the second node
            free(head);
            head = temp->next;  // Update head to the next node
        }
        printf("%d deleted from the list.\n", value);
        return;
    }

    // Case 2: Deleting a node other than the head
    temp = head;
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            printf("%d deleted from the list.\n", value);
            return;
        }
    } while (temp != head);

    printf("%d not found in the list.\n", value);
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");  // Indicates the list is circular
}

int main() {
    int choice, value;

    while (1) {
        printf("\n*** Circular Singly Linked List Menu ***\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
