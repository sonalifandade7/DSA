#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Insert an element
void enqueue(void) {
    int value;
    struct Node *newNode;

    printf("Enter value: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted successfully.\n", value);
}

// Remove an element
void dequeue(void) {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    temp = front;
    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// View the first element
void peek(void) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

// Display all elements
void display(void) {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Free allocated memory
void freeQueue(void) {
    struct Node *temp;

    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;
}

int main(void) {
    int choice;

    while (1) {
        printf("\n--- QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            freeQueue();
            return 1;
        }

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                freeQueue();
                printf("Exiting Queue program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
