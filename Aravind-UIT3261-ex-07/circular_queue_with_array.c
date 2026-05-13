#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int x;
    printf("Enter element: ");
    scanf("%d", &x);

    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    printf("Queue elements:\n");

    while (1) {
        printf("| %d | ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

void isEmpty() {
    if (front == -1)
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");
}

void isFull() {
    if ((rear + 1) % MAX == front)
        printf("Queue is full\n");
    else
        printf("Queue is not full\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Is Empty\n");
        printf("6. Is Full\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: isEmpty(); break;
            case 6: isFull(); break;
            case 7: return 0;
            default: printf("Invalid choice\n");
        }
    }
}