
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(void) {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value: ");
    if (scanf("%d", &value) != 1) {
        printf("Invalid input!\n");
        return;
    }

    stack[++top] = value;
    printf("%d pushed successfully.\n", value);
}

void pop(void) {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    printf("Popped element: %d\n", stack[top--]);
}

void peek(void) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void display(void) {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom):\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(void) {
    int choice;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter an integer.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting Stack program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
